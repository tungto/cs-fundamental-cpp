#include "Shape.cpp"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(radius)
	{
		radius = radius;
	};
	double getArea()
	{
		return 3.14 * radius * radius;
	};
	double getPerimeter()
	{
		return 2 * 3.14 * radius;
	};
}