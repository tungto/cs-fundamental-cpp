#include <iostream>
using namespace std;
int main()
{

	int *ptr = new int;

	delete ptr;	   // tra lai vung nho con tro cho hdh
	ptr = nullptr; // gan con tro thanh null

	cout << "input length: ";
	int length;
	cin >> length;

	int *arr = new int[length];

	delete[] arr;

	return 0;
}
