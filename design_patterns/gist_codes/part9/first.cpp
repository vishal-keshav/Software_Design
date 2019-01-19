#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Element
{
protected:
	vector<Element*> elems;
	string elem_name;
public:
	virtual void show(){
		cout << elem_name << " show" << endl;
		for (Element* e : elems){
			e->show();
		}
	}
	virtual void hide(){
		cout << elem_name << " hide" << endl;
		for (Element* e : elems){
			e->hide();
		}
	}
	virtual void add(Element *elem){
		elems.push_back(elem);
	}
};

class Window : public Element
{
public:
	Window(string name){
		elem_name = name;
	}
};

class Button : public Element
{
public:
	Button(string name){
		elem_name = name;
	}

};

class Panel : public Element
{
public:
	Panel(string name){
		elem_name = name;
	}

};

int main()
{
	Window w1("w1");
	Button b1("b1");
	Button b2("b2");

	w1.add(&b1);
	w1.add(&b2);

	w1.show();
	w1.hide();

	Panel p1("p1");

	Button b3("b3");
	Button b4("b4");
	p1.add(&b3);
	p1.add(&b4);
	w1.add(&p1);

	w1.show();

	p1.show();
	p1.hide();

	return 0;
}
