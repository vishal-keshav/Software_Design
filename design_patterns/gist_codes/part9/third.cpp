#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UIElement
{
private:
	string name;
public:
	UIElement(string name) :name(name)
	{
	}
	const string& getName() const
	{
		return name;
	}
	virtual void show() = 0;
	virtual void hide() = 0;
	virtual ~UIElement() {};
};

class Composite : public UIElement
{
protected:
	vector<UIElement*> elements;
protected:
	Composite(string name) :UIElement(name)
	{

	}
public:
	void add( UIElement * const element)
	{
		elements.push_back(element);
	}
	void remove(UIElement * const element)
	{
		// TODO: remove element from a vector
	}
};

class Window : public Composite
{

public:
	Window(string name) :Composite(name){

	}
	void show()
	{
		cout << getName() << " - show" << endl;
		for (UIElement *element : elements)
		{
			element->show();
		}
	}
	void hide()
	{
		cout << getName() << " - hide" << endl;
		for (UIElement *element : elements)
		{
			element->hide();
		}
	}
};

class Button : public UIElement
{
public:
	Button(string name):UIElement(name)
	{
	}

	void show()
	{
		cout << getName() << " - show" << endl;
	}
	void hide()
	{
		cout << getName() << " - hide" << endl;
	}

};

class Panel : public Composite
{
public:
	Panel(string name) :Composite(name)
	{
	}
	void show()
	{
		cout << getName() << " - show" << endl;
		for (UIElement *element : elements)
		{
			element->show();
		}
	}
	void hide()
	{
		cout << getName() << " - hide" << endl;
		for (UIElement *element : elements)
		{
			element->hide();
		}
	}

};

int main()
{
	vector<UIElement*> elem = { new Window("w1"),
								new Button("b1"),
								new Panel("p1") };
	for (UIElement* e : elem){
		Composite *composite = dynamic_cast<Composite*> (e);
		if (composite != nullptr){
			cout << e->getName() << " is composite" << endl;
		}
		else{
			cout << e->getName() << " is not composite" << endl;
		}
	}
	/* The below code is dangerous, it will deallocate the base class memory,
	   but not the derived class memory. */
	/* To deallocate derived class memory also, we have made destructor of
	   derived class virtual.*/
	for (UIElement* e : elem){
		delete e;
	}

	return 0;
}
