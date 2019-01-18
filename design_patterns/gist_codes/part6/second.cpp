#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <unistd.h>
#include <chrono>

using namespace std;

class Uploader
{
private:
	thread t;
	queue<string> filenames;
public:
	Uploader()
	{
		t = thread(bind(&Uploader::perform_upload, this));
		t.detach();
	}
	void perform_upload()
	{
		while(true)
		{
			string filename = filenames.front();
			filenames.pop();
			cout << filename << " upload started" << endl;
			this_thread::sleep_for(chrono::milliseconds(10000));
			cout << filename << " upload completed" << endl;
		}
	}

	void upload(const string& filename) {
		filenames.push(filename);
		cout << filename << " queued" << endl;
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
