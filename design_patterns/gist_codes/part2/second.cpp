#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Shape
{
public:
	virtual void take_input() = 0;
	virtual void draw() = 0;
};

class ShapeFactory{
public:
	static vector<ShapeFactory*> factory_list;
	virtual string getShapeName() = 0;
	virtual Shape* createShape() = 0;
protected:
	ShapeFactory()
	{
		factory_list.push_back(this);
	}
};

vector<ShapeFactory*> ShapeFactory::factory_list;

class ConsoleUI
{
public:
	void show()
	{
		vector<Shape*> all_shapes;
		int choice;
		while (true){
			cout << "0 Draw all" << endl;
			int index = 1;
			for (ShapeFactory *sp : ShapeFactory::factory_list){
				cout << index++ << " " << sp->getShapeName() << endl;
			}
			cout << "Select a shape" << endl;
			cin >> choice;
			if (choice == 0){
				for (Shape* s : all_shapes){
					s->draw();
				}
			}
			else{
				Shape *shape = ShapeFactory::factory_list[choice - 1]->createShape();
				shape->take_input();
				shape->draw();
				all_shapes.push_back(shape);
			}
			cout << "-----------------------------" << endl;
		}
	}

};

int main()
{
	ConsoleUI cui;
	cui.show();
	return 0;
}

class Rectangle : public Shape
{
private:
	double _x, _y, _height, _width;
public:
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
};

class Circle : public Shape
{
private:
	double _x, _y, _radius;
public:
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
};

class RectangleFactory : public ShapeFactory
{
public:
	string getShapeName(){
		return "rectangle";
	}
	Shape* createShape()
	{
		Rectangle *rect = new Rectangle;
		return rect;
	}
};
//No body cares if factory object is created only once, because it is
// required only once.
RectangleFactory rf;

class CircleFactory : public ShapeFactory
{
public:
	string getShapeName(){
		return "circle";
	}
	Shape* createShape()
	{
		Circle *rect = new Circle;
		return rect;
	}
};
CircleFactory cf;
