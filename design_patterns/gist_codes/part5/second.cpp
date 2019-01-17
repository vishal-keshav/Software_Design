#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <mutex>
#include <unistd.h>
#include <chrono>

using namespace std;

template<class TSignature>
class Event
{
private:
	vector<function<TSignature>> eventHandlers;
	mutex m;
public:
	void operator += (const function<TSignature>& eventHandler) {
		lock_guard<mutex> gaurd1(m);
		eventHandlers.push_back(eventHandler);
	}
	void operator -= (const function<TSignature>& eventHandler) {
		lock_guard<mutex> gaurd2(m);
		auto compare_func = [&eventHandler](const function<TSignature>& eh) {
			return eh == eventHandler;
		};
		eventHandlers.erase(find_if(begin(eventHandlers),
									end(eventHandlers),
									compare_func),
							end(eventHandlers));
	}

	template<class ... TArgs>
	void raiseNotification(TArgs ... args)
	{
		lock_guard<mutex> gaurd3(m);
		for(const function<TSignature>& eventHandler : eventHandlers)
		{
			eventHandler(forward<TArgs>(args)...);
		}
	}
};

class CameraDeviceDriver {
private:
	thread t;
public:
	Event<void(int)> VideoFeed;
	Event<void()> Error;
	void Start()
	{
		thread temp_thread([this]() {
			int count = 1;
			while(true)
			{
				count++;
				this->VideoFeed.raiseNotification(count);
				this_thread::sleep_for(chrono::milliseconds(2000));
			} });
			temp_thread.detach();
			this->t = move(temp_thread);
	}

};

class CameraFeedReceiver {
private:
	vector<CameraDeviceDriver*> Cameras;
	CameraFeedReceiver()
	{
	}
public:
	CameraFeedReceiver(const CameraFeedReceiver&) = delete;
	CameraFeedReceiver& operator=(const CameraFeedReceiver&) = delete;

	static CameraFeedReceiver cfr;
	static CameraFeedReceiver& get()  {
		return cfr;
	}
	void feedReceiver(int count)
	{
		cout << "A Camera is sending the data: " << count << endl;
		cout << "Here, we need to analyze the camera data " << count << endl;
		cout << endl;
	}

	void addCamera(CameraDeviceDriver* cdd)
	{
		cdd->VideoFeed += bind(&CameraFeedReceiver::feedReceiver, this,
								placeholders::_1);
		Cameras.push_back(cdd);
	}
	void removeCamera(CameraDeviceDriver* cdd) {
		//TODO: remove device driver object (we dont want to handle feed
		//anymore becasue camera is removed)
	}
};

CameraFeedReceiver CameraFeedReceiver::cfr;

int main()
{
	CameraDeviceDriver cdd1, cdd2;

	CameraFeedReceiver &cfr1 = CameraFeedReceiver::get();
	cfr1.addCamera(&cdd1);
	cfr1.addCamera(&cdd2);
	cdd1.Start();
	// Lets start the second camera after sometime.
	this_thread::sleep_for(chrono::milliseconds(500));
	cdd2.Start();
	while(1){
		//Infinite loop, the system is always running
	}
	return 0;
}
