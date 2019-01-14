#include <iostream>
#include <string>
#include <map>

using namespace std;

class Command
{
public:
	static map<string, Command*> commands;
protected:

	Command(string command_name)
	{
		commands[command_name] = this;
	}
public:
	virtual void process(double commandData, double& value){

	}
};
map<string, Command*> Command::commands;

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
			if (Command::commands.find(commandName) != Command::commands.end()){
				Command::commands[commandName]->process(commandData, value);
			}
			else{
				cout << "Command not supported" << endl;
			}
		}
	}
};

int main(){

	ConsoleUI cui;
	cui.show();

	return 0;
}

class AddCommand : public Command
{
public:
	AddCommand(const string &cmd_name) : Command(cmd_name)
	{
	}

	void process(double commandData, double& value){
		value += commandData;
	}
};
AddCommand ac("add");

class MulCommand : public Command
{
public:
	MulCommand(const string &cmd_name) : Command(cmd_name)
	{
	}
	void process(double commandData, double& value){
		value *= commandData;
	}
};
MulCommand mc("mul");

class SubCommand : public Command
{
public:
	SubCommand(const string &cmd_name) :Command(cmd_name)
	{
	}
	void process(double commandData, double& value){
		value -= commandData;
	}
};
SubCommand sb("sub");
