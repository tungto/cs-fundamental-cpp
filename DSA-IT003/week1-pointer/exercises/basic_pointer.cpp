#include <iostream>
using namespace std;

int main()
{
	// & dia chi
	// * con tro
	int x = 10;

	// dia chi bien x
	cout << "X address: " << &x << endl;

	// tro toi gia tri tai dia chi bien x
	cout << "value in x address: " << *&x << endl;

	*&x = 6999;

	cout << "gan lai value in x address: " << *&x << endl;

	// bien con tro - luu dia chi tro den 1 gia tri so nguyen
	int *ptr = &x;

	cout << *ptr << " dia chi la: " << ptr << endl;

	*ptr = 100;

	cout << "gia tri tai dia chi ptr da duoc thay doi: " << *ptr << endl;

	int iValue = 5;
	double dValue = 7.0;

	int *iPtr = &iValue;
	double *dPtr = &dValue;

	/// iPtr = &dValue; // dia chi bien int k luu duoc dia chi bien double
	//	dPtr = &iValue; // tuong tu

	// int *ptr1 = 5;			 // ptr1 la bien con tro, chi luu dia chi co gia tri loai int, k luu gia tri
	// double *dPtr1 = 0x00001; // tuongtu, bien dia chi gia tri loai double, chi luu gia tri dia chi, k luu gia tri

	return 0;
}