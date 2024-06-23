#include <iostream>
using namespace std;

int main()
{

	// dia chi bat ki?
	int *p1;

	// 0x0
	int *p2 = NULL;

	int n = 36;
	int *p3 = &n;

	cout << p1 << " " << p2 << " " << p3 << endl;

	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;

	cout << "size of pointer p2 is: " << sizeof(p2) << endl;
	cout << "size of pointer p3 is: " << sizeof(p3) << endl;
	n = 38;
	cout << "I just change n value: " << n << endl;

	return 0;
}