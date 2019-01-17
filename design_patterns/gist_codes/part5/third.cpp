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
using namespace std::placeholders;

class CameraDeviceDriver_company1 {
	template<class TSignature>
	class Event {
	private:
		vector<function<TSignature>> eventHandlers;
		mutex sync;
	public:
		void operator += (const function<TSignature>& eventHandler) {
			lock_guard<mutex> gaurd1(sync);
			eventHandlers.push_back(eventHandler);
		}

		void operator -= (const function<TSignature>& eventHandler) {
			lock_guard<mutex> gaurd2(sync);
			auto compare_func = [&eventHandler](const function<TSignature>& eh)
			{
				return eh == eventHandler;
			};
			eventHandlers.erase(find_if(begin(eventHandlers),
										end(eventHandlers),
										compare_func),
								end(eventHandlers));
		}

		template<class ... TArgs>
		void raiseNotification(TArgs ... args) {
			lock_guard<mutex> gaurd3(sync);
			for(const function<TSignature>& eventHandler : eventHandlers) {
				eventHandler(forward<TArgs>(args)...);
			}
		}
	};
private:
	thread t;
public:
	string driver_name = "Company1";
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

class CameraDeviceDriver_company2 {
	// Lets assume company 2 also implements the events just like 1 did
	template<class TSignature>
	class Event {
	private:
		vector<function<TSignature>> eventHandlers;
		mutex sync;
	public:
		void operator += (const function<TSignature>& eventHandler) {
			lock_guard<mutex> gaurd1(sync);
			eventHandlers.push_back(eventHandler);
		}

		void operator -= (const function<TSignature>& eventHandler) {
			lock_guard<mutex> gaurd2(sync);
			auto compare_func = [&eventHandler](const function<TSignature>& eh)
			{
				return eh == eventHandler;
			};
			eventHandlers.erase(find_if(begin(eventHandlers),
										end(eventHandlers),
										compare_func),
								end(eventHandlers));
		}

		template<class ... TArgs>
		void raiseNotification(TArgs ... args) {
			lock_guard<mutex> gaurd3(sync);
			for(const function<TSignature>& eventHandler : eventHandlers) {
				eventHandler(forward<TArgs>(args)...);
			}
		}
	};
private:
	thread t;
public:
	Event<void(int)> Feed;
	void Start_driver()
	{
		thread temp_thread([this]() {
			int count = 1;
			while(true)
			{
				count+=5;
				this->Feed.raiseNotification(count);
				this_thread::sleep_for(chrono::milliseconds(1800));
			} });
			temp_thread.detach();
			this->t = move(temp_thread);
	}
};

/* Code below is not provided by the company 1*/
class CameraDeviceDriver
{
public:
	virtual void register_handler(const function<void(int)>& eventHandler) = 0;
	//virtual void unregister_handler(const function<void(int)>& eventHandler) = 0;
	virtual void start() = 0;
	virtual string get_name() = 0;
};


class Company1Adapter : public CameraDeviceDriver
{
private:
	CameraDeviceDriver_company1 cdd;
public:
	void register_handler(const function<void(int)>& eventHandler){
		cdd.VideoFeed += eventHandler;
	}
	/*void unregister_handler(const function<void(int)>& eventHandler){
		cdd.VideoFeed -= eventHandler;
	}*/
	void start(){
		cdd.Start();
	}
	string get_name(){
		return cdd.driver_name;
	}
};

class Company2Adapter : public CameraDeviceDriver
{
private:
	CameraDeviceDriver_company2 cdd;
public:
	void register_handler(const function<void(int)>& eventHandler){
		cdd.Feed += eventHandler;
	}
	/*void unregister_handler(const function<void(int)>& eventHandler){
		cdd.Feed -= eventHandler;
	}*/
	void start(){
		cdd.Start_driver();
	}
	string get_name(){
		return "Unkown";
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
	static CameraFeedReceiver& get(){
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
		cdd->register_handler(bind(&CameraFeedReceiver::feedReceiver, this,
								placeholders::_1));
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
	Company1Adapter cdd1;
	Company2Adapter cdd2;
	cdd1.start();
	cdd2.start();


	CameraFeedReceiver &cfr = CameraFeedReceiver::get();
	cfr.addCamera(&cdd1);
	cfr.addCamera(&cdd2);
	while(1){

	}

	return 0;
}
