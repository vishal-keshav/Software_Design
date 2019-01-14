#include <iostream>
#include <string>
#include <map>

using namespace std;

class Shape
{

public:
	static map<int, Shape*> command_map;
	static int nr_registered;
	Shape(string & shape_name)
	{
		nr_registered++;
		command_map[nr_registered] = this;
	}
	virtual void show(){
		//Do nothing
	}
	virtual void take_input(){
		// Do nothing
	}
	virtual void draw(){
		// Do nothing
	}

};
int Shape::nr_registered;
map<int, Shape*> Shape::command_map;

class ConsoleUI
{
public:
	void show()
	{
		int command;
		while (true){
			cout << "Following shapes are supported" << endl;
			cout << "0 Print all" << endl;
			for (std::map<int, Shape*>::iterator it = Shape::command_map.begin(); it != Shape::command_map.end(); ++it){
				cout << it->first << " ";
				it->second->show();
			}
			cin >> command;
			if (command == 0){
				for (std::map<int, Shape*>::iterator it = Shape::command_map.begin(); it != Shape::command_map.end(); ++it){
					it->second->draw();
				}
			}
			else{
				Shape::command_map[command]->take_input();
				Shape::command_map[command]->draw();
			}

		}
	}

};

int main()
{
	ConsoleUI cui;
	cui.show();
	return 0;
}

//-----------------------------------------------------------------------------------

class Rectangle : public Shape
{

private:
	double _x, _y, _height, _width;
	string commandName;
public:
	Rectangle(string shape_name) : Shape(shape_name)
	{
		commandName = shape_name;
	}
	string return_command(){
		return commandName;
	}
	void take_input(){
		double x, y, height, width;
		cout << "Give input in (x,y,height,width)" << endl;
		cin >> x >> y >> height >> width;
		_x = x;
		_y = y;
		_height = height;
		_width = width;
	}
	void draw(){
		cout << "Drawing Rectangle" << endl;
		cout << _x << " " << _y << " " << _height << " " << _width << endl;
	}
	void show(){
		cout << commandName << endl;
	}
};
Rectangle r("rect");

class Circle : public Shape
{

private:
	double _x, _y, _radius;
	string commandName;
public:
	Circle(string shape_name) : Shape(shape_name)
	{
		commandName = shape_name;
	}
	string return_command(){
		return commandName;
	}
	void take_input(){
		double x, y, radius;
		cout << "Give input in (x,y,radius)" << endl;
		cin >> x >> y >> radius;
		_x = x;
		_y = y;
		_radius = radius;
	}
	void draw(){
		cout << "Drawing Circle" << endl;
		cout << _x << " " << _y << " " << _radius << endl;
	}
	void show(){
		cout << commandName << endl;
	}
};
Circle ra("cir");
