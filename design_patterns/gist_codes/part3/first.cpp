#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int i; //Global variable
mutex m;

void F1(){
	m.lock();
	i++;
	cout << "F1: " << i << endl;
	i++;
	cout << "F1: " << i << endl;
	return; // Here exception may occur
	m.unlock();
}

void F2(){
	cout << "I am starving" << endl;
	m.lock();
	i++;
	cout << "F2: " << i << endl;
	i++;
	cout << "F2: " << i << endl;
	m.unlock();
}

int main()
{
	thread th1(F1);
	F2();
	th1.join();

	return 0;
}
