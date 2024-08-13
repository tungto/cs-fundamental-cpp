#include <iostream>
using namespace std;

/**
 * Here we achieve polymorphism by overloading the functions
 */
class Shape
{
protected:
	int width, height;

public:
	int area()
	{
		return width * height;
	};
	int area(string name)
	{
		cout << "Area of shape " << name << " is " << width * height << endl;
		return width * height;
	}
	Shape(int w, int h)
	{
		this->width = w;
		this->height = h;
	}

	~Shape() {}
};

/**
 * Here we achieve polymorphism through override functions
 */

class Triangle : public Shape
{
public:
	Triangle(int width, int height) : Shape(width, height) {};
	int area()
	{
		cout << "Area of triangle" << endl;

		return 0.5 * this->width * this->height;
	}
};

int main()
{
	Shape shape = Shape(3, 5);

	shape.area();
	shape.area("Rectangle");

	Triangle triangle = Triangle(3, 5);
	triangle.area();

	return 0;
}