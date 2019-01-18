#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DrawingLibrary
{
public:
	static DrawingLibrary *dl;
	DrawingLibrary() {
		cout << "created";
		dl = this;
	}
	virtual void drawRectangle(int x1, int y1, int x2, int y2,
							   int borderColor, int fillColor,
							   vector<int> borderRadius) = 0;
};
DrawingLibrary *DrawingLibrary::dl;


class DirectXAdapter : public DrawingLibrary
{
	void drawRectangle(int x1, int y1, int x2, int y2,
					   int borderColor, int fillColor,
					   vector<int> borderRadius) {
		cout << "Rectangle using DirectX" << endl;
	}
};

class OpenGLAdapter : public DrawingLibrary {
	void drawRectangle(int x1, int y1, int x2, int y2,
					   int borderColor, int fillColor,
					   vector<int> borderRadius) {
		cout << "Rectangle using OpenGL" << endl;
	}
} oa; // Declared here because we are on linux

class MetalAdapter : public DrawingLibrary {
	void drawRectangle(int x1, int y1, int x2, int y2,
					   int borderColor, int fillColor,
					   vector<int> borderRadius) {
		cout << "Rectangle using Metal" << endl;
	}
};

class UIControl
{
protected:
	DrawingLibrary *dl = nullptr;
public:
	UIControl() {
		dl = DrawingLibrary::dl;
	}
	virtual void drawUI() = 0;
};

class ListBox : public UIControl
{
public:
	void drawUI() {
		dl->drawRectangle(0,0,0,0,0,0, vector<int>(5));
		// TODO: Draw text
	}
};

class Grid : public UIControl
{
public:
	void drawUI() {

	}
};

class Button : public UIControl
{
public:
	void drawUI() {
		// TODO: Draw Circle
		// TODO: Draw text
	}
};


class App1
{
private:
	ListBox lb;
public:
	void show() {
		lb.drawUI();
	}
};

int main()
{
	App1 application;
	application.show();
	return 0;
}
