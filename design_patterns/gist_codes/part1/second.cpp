#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Command
{
public:
	static vector<Command*> commands;
protected:
	Command()
	{
		commands.push_back(this);
	}
public:
	virtual void process(const string& commandName, double commandData, double& value){

	}
};
vector<Command*> Command::commands;

class ConsoleUI
{
public:
	void show(){
		double value = 0;
		double commandData;
		string commandName;
		while (true){
			cout << value << endl;
			cin >> commandName >> commandData;
			for (Command *command : Command::commands){
				command->process(commandName, commandData, value);
			}
		}
	}
};

class AddCommand : public Command
{
	void process(const string& commandName, double commandData, double& value){
		if (commandName == "add"){
			value += commandData;
		}
	}
};
AddCommand a;

class MulCommand : public Command
{
	void process(const string& commandName, double commandData, double& value){
		if (commandName == "mul"){
			value *= commandData;
		}
	}
};
MulCommand mc;

int main(){

	ConsoleUI cui;
	cui.show();
	return 0;
}
