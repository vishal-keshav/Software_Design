#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int i;
mutex m;

template <class T>
class guard
{
private:
	T &m;
public:
	guard(T &m) : m(m)
	{
		m.lock();
	}
	~guard()
	{
		m.unlock();
	}
};

void F1(){
	guard<mutex> g1(m);
	i++;
	cout << "F1: " << i << endl;
	i++;
	cout << "F1: " << i << endl;
	return; // Exception occured here
}

void F2(){
	guard<mutex> g2(m);
	i++;
	cout << "F2: " << i << endl;
	return; // Exception occured here
	i++;
	cout << "F2: " << i << endl;
}

int main()
{
	thread th1(F1);
	F2();
	th1.join();

	return 0;
}
