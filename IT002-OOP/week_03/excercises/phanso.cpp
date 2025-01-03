#include <iostream>
using namespace std;

class CPhanSo
{
private:
	int tu;
	int mau;

public:
	friend istream &operator>>(istream &is, CPhanSo &x);
	friend ostream &operator<<(ostream &os, CPhanSo &x);
	CPhanSo();
	CPhanSo(int t, int m)
	{
		this->tu = t;
		this->mau = m;
	}
	CPhanSo(const CPhanSo &);
	~CPhanSo();
	CPhanSo operator=(const CPhanSo &);
};

istream &operator>>(istream &is, CPhanSo &x)
{
	cout << "Nhap tu: ";
	is >> x.tu;
	cout << "Nhap mau: ";
	is >> x.mau;
	return is;
}

ostream &operator<<(ostream &os, CPhanSo &x)
{
	os << x.tu << "/" << x.mau << endl;
	return os;
}

CPhanSo::CPhanSo()
{
	tu = 0;
	mau = 0;
}

CPhanSo::CPhanSo(int t, int m)
{
	tu = t;
	mau = m;
}

CPhanSo::CPhanSo(const CPhanSo &ps)
{
	tu = ps.tu;
	mau = ps.mau;
}

CPhanSo::~CPhanSo()
{
	return;
}

CPhanSo CPhanSo::operator=(const CPhanSo &ps)
{
	tu = ps.tu;
	mau = ps.mau;
	return *this;
}

int main()
{
	CPhanSo a, b, d;
	cin >> a >> b;
	cout << a << b;
	CPhanSo c(5, 6);
	d = a;
	cout << c << d;
}