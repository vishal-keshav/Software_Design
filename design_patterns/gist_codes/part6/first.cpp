#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>
#include <chrono>

using namespace std;

class upload_util
{
private:
	mutex sync;
public:
	void upload_file(string filename) {
		lock_guard<mutex> gaurd1(sync);
		cout << filename << " is getting uploaded" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << filename << " uploaded" << endl;
	}
};

int main()
{
	upload_util u;
	string filename;
	while(true) {
		cout << "Enter file to upload" << endl;
		cin >> filename;
		thread t([&]() {u.upload_file(filename); });
		t.detach();
	}

	return 0;
}
