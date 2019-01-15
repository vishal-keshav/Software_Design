#include <iostream>
#include <vector>

using namespace std;

class m_table
{
private:
	int number;
public:
	void generate_table(){
		for (int i = 1; i <= 10; i++){
			cout << number << " * " << i << " = " << number*i << endl;
		}
	}
	void set_number(int i){
		number = i;
	}
};


int main()
{
	int input;
	m_table t;
	while (true){
		cin >> input;
		t.set_number(input);
		t.generate_table();
	}

	return 0;
}
