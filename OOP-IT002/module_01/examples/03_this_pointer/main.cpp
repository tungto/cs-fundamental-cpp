#include <iostream>

using namespace std;

// this: tham chieu den doi tuong dang goi ham thanh phan

class PhanSo
{
private:
	int TuSo, MauSo;

public:
	PhanSo RutGon();
	void Nhap();
	void Xuat();
};

// Cach dung 1 cua this: tro den cac thanh phan cua class hien tai
void PhanSo::Nhap()
{
	cout << "Nhap tu so: " << endl;
	cin >> this->TuSo;
	cout << "Nhap mau so: " << endl;
	cin >> this->MauSo;
}

// cach dung 2: tra ve object hien tai
PhanSo PhanSo::RutGon()
{
	int a, b;
	a = abs(this->TuSo);
	b = abs(this->MauSo);

	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	this->TuSo /= a;
	this->MauSo /= a;
	// this is pointer, *this is value of pointer this
	return *this;
}

void PhanSo::Xuat()
{
	cout << "Phan so rut gon: " << this->TuSo << " /" << this->MauSo << endl;
};

int main()
{

	PhanSo ps;
	ps.Nhap();
	ps.RutGon();
	ps.Xuat();

	return 0;
}