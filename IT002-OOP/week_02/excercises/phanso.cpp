#include <iostream>
using namespace std;

/**
 * using friend function to override operator
 */

class PhanSo
{
private:
	int mau, tu;

public:
	PhanSo() {}
	PhanSo(int tu, int mau)
	{
		this->tu = tu;
		this->mau = mau;
	};

	// destructor function
	~PhanSo() {};

	friend istream &operator>>(istream &is, PhanSo &ps);
	friend ostream &operator<<(ostream &os, PhanSo &ps);
};

istream &operator>>(istream &is, PhanSo &ps)
{
	cout << "Nhap tu so: ";
	is >> ps.tu;
	cout << "Nhap mau so: ";
	is >> ps.mau;
	return is;
};

ostream &operator<<(ostream &os, PhanSo &ps)
{
	cout << "Phan so la: " << ps.tu << "/" << ps.mau << endl;
	return os;
}

int main()
{
	PhanSo a, b;
	cin >> a >> b;
	cout << a << b;

	return 0;
}