#include <iostream>
using namespace std;

int main()
{
	int x = 10;
	int *iPtr = &x;

	int *ptr = &x;

	// con tro ptr chua dia chi cua bien x
	// gia tri tri cua con tro la dia chia cua bien x
	// con tro cua con tro la dia chia cua bien x
	cout << *ptr << " " << *iPtr << " " << endl;

	// ban than arr chua dia chi tro toi mang
	int arr[4] = {5, 6, 8, 9};

	cout << "in ra dia chi cua arr: " << arr << endl;
	cout << "dia chi cua arr: " << &arr << endl;
	cout << "in ra dia chi cua arr[1]: " << &arr[0] << endl;
	cout << "in ra gia tri tai  dia chi cua arr[2]: " << *&arr[2] << endl;

	// in ra gia tri cua tro tro arr
	cout << "vi arr luu gia tri dia chi cua arr, nen con tro cua arr la gi tri tai phan tu dau tien cua arr" << *arr << endl;

	int *arrPtr = arr;
	cout << *arrPtr << endl; // in ra gia tri dau tien?

	char name[] = "Nguyen";
	cout << "In ra gia tri dau tien cua char " << *name << endl;

	cout << "in ra loai arr" << typeid(arr).name() << endl;
	cout << "size of arr: " << sizeof(arr) << endl;

	cout << "size of arrPtr " << sizeof(arrPtr) << endl;

	return 0;
}