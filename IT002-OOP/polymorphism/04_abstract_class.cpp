
// C++ program to calculate the area of a square and a circle

#include <iostream>
using namespace std;

/**
 * Abstract class is class contains pure virtual methods
 */
class Shape
{
protected:
	float dimension;

public:
	void getDimension()
	{
		cin >> dimension;
	}
	Shape(float dimension) {}
	// this is pure virtual function
	virtual float calculateArea() = 0;
};

// Derived class
class Square : public Shape
{
public:
	float calculateArea()
	{
		return dimension * dimension;
	}
};

int main()
{

	Shape s;
	s.getDimension();

	return 0;
}