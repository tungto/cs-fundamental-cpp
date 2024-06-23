#include <iostream>
using namespace std;

typedef int *pInt;

int main()
{
	char c = 'F';
	int x = 10;
	double y = 1.8;

	cout
		<< "x value = " << x << endl;
	cout << "x address = " << &x << endl;

	// * lay gia tri tai dia chi &x
	cout << "x value again" << *(&y) << endl;

	// double - kieu gia tri cua bien y
	double *p = &y;
	pInt p1 = &x;

	cout << "x = " << *p1 << endl;

	// khai bao nhieu pointer tren 1 dong
	int *p2, *p3, *p4;

	return 0;
}