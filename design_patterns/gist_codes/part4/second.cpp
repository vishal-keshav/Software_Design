#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class m_table
{
private:
	int number;
public:
	void generate_table(function<void(int, int, int)> callback){
		for (int i = 1; i <= 10; i++){
			callback(number, i, number*i);
		}
	}
	void set_number(int i){
		number = i;
	}
};

void receiver1(int number, int i, int result){
	cout << number << " * " << i << " = " << result << endl;
}

void receiver2(int number, int i, int result){
	cout << number << " X " << i << " == " << result << endl;
}

class Sample
{
public:
	void receiver3(int number, int i, int result){
		cout << number << " x " << i << " ~ " << result << endl;
	}
};

class Sample_functor
{
public:
	void operator() (int number, int i, int result)
	{
		cout << number << " x " << i << " -> " << result << endl;
	}
};

int main()
{
	int input;
	m_table t;
	while (true){
		cin >> input;
		t.set_number(input);
		t.generate_table(receiver2);
		Sample s1;
		t.generate_table(bind(&Sample::receiver3, &s1,
			placeholders::_1, placeholders::_2, placeholders::_3));
		t.generate_table([](int number, int i, int result)
		{
			cout << number << " * " << i << " = " << result << endl;
		});
		t.generate_table(Sample_functor());
	}

	return 0;
}
