#include <iostream>
using namespace std;

int main()
{

	// k can khai bao so luong phan tu [5]
	int a[] = {5, 3, 7, 5, 9, 1};

	// 3 phan tu lu vao 3 vung nho dau tien trong 100 vung
	// cap phat tinh cho mang, k the thu hoi
	int b[100] = {1, 2, 3};

	cout << sizeof(a) / sizeof(a[0]) << endl;

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		/* code */
		// tai sao la dia chi cua a + i?
		cout << *(a + i) << endl;
	}

	// cap phat dong cho mang => co the thu hoi
	int *c = new int[10];

	return 0;
}