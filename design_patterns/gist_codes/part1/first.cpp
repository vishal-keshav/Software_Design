#include <iostream>
#include <string>

using namespace std;

int apply_op(string op_name, int val, int *result){
	int sig;
	if (op_name == "add"){
		*result += val;
		sig = 1;
	}
	else if (op_name == "mul"){
		*result *= val;
		sig = 1;
	}
	else{
		sig = -1;
	}
	return sig;
}

int main(){

	string operation;
	int result = 0, op_val, sig=1;
	while (1){
		if (sig == -1){
			cout << "Command not supported" << endl;
		}
		else{
			cout << result << endl;
		}
		cin >> operation >> op_val;
		sig = apply_op(operation, op_val, &result);
	}
	return 0;
}
