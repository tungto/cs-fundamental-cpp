#include <iostream>
using namespace std;

/**
 * early binding: the function call is fixed before the program is executed
 * virtual function is in base class
 * late binding: the function call is decided when the program is executed
 * pure virtual function
 */
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

	virtual int area()
	{
		cout << "Area of the shape: " << width * height << endl;
		return width * height;
	}

	virtual void print() { cout << "this is pure virtual function" << endl; }
};

class Rectangle : public Shape
{
protected:
	string name;

public:
	int getArea() { return width * height; }
	Rectangle(int w, int h) : Shape(w, h)
	{
		// this->name = name;
	}
	int area()
	{
		cout << "Area of the Rectangle: " << width * height << endl;
		return width * height;
	}

	void print()
	{
		cout << width << " " << height << endl;
	}
};

class Triangle : public Shape
{
public:
	Triangle(int x, int y) : Shape(x, y) {}
	int area()
	{
		cout << "Area of the Triangle: " << 0.5 * width * height << endl;
		return 0.5 * width * height;
	}
};

int main()
{

	// Rectangle rect = Rectangle(3, 4, "name");
	// cout << rect.getArea();

	Shape *shape;
	Rectangle rect(10, 7);
	Triangle tri(10, 5);

	// store the address of Rectangle
	shape = &rect;

	// call rect area
	shape->area();

	// store the address of Triangle
	shape = &tri;

	// call tri area
	shape->area();

	return 0;
}