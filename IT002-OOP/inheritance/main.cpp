#include <iostream>
using namespace std;

class Shape
{
	// default access specifier is private
protected: // access by own and children
	int width, height;

public:
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	Shape(int w, int h)
	{
		this->width = w;
		this->height = h;
	}
};

class Rectangle : public Shape
{
protected:
	string name;

public:
	int getArea() { return width * height; }
	Rectangle(int w, int h, string name) : Shape(w, h)
	{
		this->name = name;
	}

	void print()
	{
		cout << width << " " << height << endl;
	}
};

int main()
{

	Rectangle rect = Rectangle(3, 4, "name");
	cout << rect.getArea();

	return 0;
}