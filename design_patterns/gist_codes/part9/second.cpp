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
	void add(UIElement * const element)
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
