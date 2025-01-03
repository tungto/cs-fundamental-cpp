#include <iostream>
using namespace std;

/**
 * arguments: value
 * parameters:  variables
 * pass by value is not a good option
 * - actual value cause memory
 * - giam hieu suat vi phai sao chep vlaue
 * - ham chi co the tra ve 1 gia tri duy nhat
 */
int add(int x, int y)
{
	cout << x + y << endl;
	return x + y;
}

/**
 * PASS BY REFERENCE
 * - more effecive: not copy value, just pass the address of the variable, save memory
 */

void add(int x, int y, int &result)
{
	result = x + y;
}

/**
 * PASS BY CONST REFERENCE
 * using to prevent change of value
 * - k bị thay dổi ngoài ý muốn
 * - có thẻ truyền hằng số hoặc biến sổ
 * - khi truyền tham chiếu cho hàm, luôn sử dụng const reference, trừ khi cần thay đổi giá trị của các đối số
 */
void printValue(const int &value)
{

	value = 69;
	cout << "Value inside the function: " << value << endl;
}

int main()
{
	add(5, 7);
	cout << "CPP Easy Snippet" << endl;
	return 0;
}
