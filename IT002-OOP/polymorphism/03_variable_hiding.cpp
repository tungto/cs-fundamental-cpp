#include <iostream>

using namespace std;

class SuperClass
{
public:
	int x = 10;

	virtual void display()
	{
		cout << "Superclass " << x << endl;
	}
};

class SubClass : public SuperClass
{
public:
	int x = 20;

	void display()
	{
		cout << "Subclass " << x << endl;
	}
};

int main()
{

	SuperClass *s = new SubClass();
	// s -> x should be valueof subclass instead of superclass
	cout << "Display x of Subclass " << s->x << endl;
	s->display();
	return 0;
}