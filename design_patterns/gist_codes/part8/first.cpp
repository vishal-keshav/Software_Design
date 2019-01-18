#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Window
{
public:
	virtual vector<string> getStatusBarItems(){
		cout << "Created GenericWindow status bar" << endl;
		return vector<string>();
	}
	virtual vector<string> getTitleBarItems(){
		cout << "Created GenericWindow title bar" << endl;
		return vector<string>();
	}
	void Create(){
		this->getTitleBarItems();
		this->getStatusBarItems();
	}
};

class NotePadWindow : public Window
{
public:
	vector<string> getTitleBarItems() override{
		vector<string> menuItem = { "File", "Edit" };
		cout << "Created NotePadWindow title bar" << endl;
		return menuItem;
	}
};

class PaintWindow : public Window
{
public:
	vector<string> getTitleBarItems() override{
		vector<string> menuItem = { "File", "Colors" };
		cout << "Created PaintWindow title bar" << endl;
		return menuItem;
	}
	vector<string> getStatusBarItems() override{
		vector<string> statusBar = { "ColorBar" };
		cout << "Created PaintWindow status bar" << endl;
		return statusBar;
	}
};

class Application
{
public:
	void Start(Window *w){
		w->Create();
	}
};

void SartingPointofOurCode(){
	Application app;
	app.Start(new NotePadWindow());
	app.Start(new PaintWindow());
}

int main()
{
	SartingPointofOurCode();
	return 0;
}
