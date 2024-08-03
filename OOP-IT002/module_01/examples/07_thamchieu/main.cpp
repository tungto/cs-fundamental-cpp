#include <iostream>

using namespace std;

// pass by value - tham chieu
void thamTri(int x)
{
	cout << "gia tri cua x: " << x << endl;
	x++;
}

// tham chieu - pass by reference
void thamChieu(int &x)
{

	cout << "thamChieu - gia tri cua x: " << x << endl;
	cout << "dia chi cua x: " << &x << endl;
	// x++;
};

int main()
{
	int a = 12;
	int &b = a;
	thamTri(b);
	thamChieu(b);

	// changeValue(b);
	cout
		<< b;
	return 0;
}