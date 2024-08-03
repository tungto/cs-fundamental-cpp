
#include <stdio.h>
#include <iostream>
using namespace std;

// write a program to input a fraction .Determine whether the fraction is negative, positive  or zero;

struct phanso
{
	int tu;
	int mau;
};

typedef struct phanso PHANSO;
void Nhap(PHANSO &);
void Xuat(PHANSO);
int XetDau(PHANSO);

class CPhanSo
{
private:
	int tu;
	int mau;

public:
	friend ostream &operator<<(ostream &os, CPhanSo &x);
	friend istream &operator>>(istream &is, CPhanSo &x)
	{
		cout << "nhap tu: ";
		cin >> &x.tu;
		cout << "nhap mau: ";
		cin >> &x.mau;
	}

	istream &operator>>(istream &is,
						CPhanSo &x)
	{
		cout << x.tu << " /" << x.mau;
	}
};

void Nhap(CPhanSo &x)
{
	cout << "nhap tu: ";
	cin >> &x.tu;
	cout << "nhap mau: ";
	cin >> &x.mau;
}

void Xuat(CPhanSo X)
{
	cout << x.tu << " /" << x.mau;
};

int main()
{
	CPhanSo a;
	Nhap(a);

	int kq = XetDau(a);
	switch (kq)
	{
	case 1:
		cout << "so duong";
		break;
	case -1:
		cout << "so am";
	case 0:
		cout << "bang 0";
	}

	return 0;
}