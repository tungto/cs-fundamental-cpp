#include <iostream>
using namespace std;

int main()
{

	int *p = new int(6789);
	// *p = 369;
	cout << "Dia chi da cap phat p = " << p << endl;

	cout << "Gia tri vung nho = " << *p << endl;

	// thu hoi
	delete p;

	p = NULL;

	cout
		<< "Dia chi sau khi thu hoi = "
		<< p
		<< endl;
	// crash
	// cout << "Gia tri vung nho sau khi thu hoi = " << *p << endl;

	return 0;
}