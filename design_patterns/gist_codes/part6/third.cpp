#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <unistd.h>
#include <chrono>

#include <condition_variable>

using namespace std;

template<class T>
class concurrentQueue
{
private:
	queue<T> que;
	mutex sync;
public:
	void add(const T& item)
	{
		lock_guard<mutex> guard(sync);
		que.push(item);
	}
	T remove()
	{
		lock_guard<mutex> guard(sync);
		T elem = que.front();
		que.pop();
		return elem;
	}
	bool is_empty()
	{
		lock_guard<mutex> guard(sync);
		return que.empty();
	}
};

class Uploader
{
private:
	thread t;
	concurrentQueue<string> filenames;
	condition_variable cv;
	mutex m;
public:
	Uploader()
	{
		t = thread(bind(&Uploader::perform_upload, this));
	}
	void perform_upload()
	{
		while(true)
		{
			if(filenames.is_empty()) {
				cout << "Entering the wait state" << endl;
				unique_lock<mutex> lk(m);
				cv.wait(lk);
				cout << "Has come out of the wait state" << endl;
			}

			string filename = filenames.remove();
			cout << filename << " upload started" << endl;
			this_thread::sleep_for(chrono::milliseconds(10000));
			cout << filename << " upload completed" << endl;
		}
	}

	void upload(const string& filename) {
		filenames.add(filename);
		cout << filename << " queued" << endl;
		cv.notify_one();
	}
};

class ConsoleUI
{
private:
	Uploader uploader;
public:
	void start() {
		string filename;
		while(true) {
			cin >> filename;
			uploader.upload(filename);
		}
	}
};

int main()
{
	ConsoleUI cui;
	cui.start();

	return 0;
}
