#include <iostream>
using namespace std;

class PhanSo
{
private:
	int TuSo, MauSo;

public:
	PhanSo()
	{
		this->TuSo = 0;
		this->MauSo = 1;
	}

	PhanSo(int Tu, int Mau)
	{
		this->TuSo = Tu;
		this->MauSo = Mau;
	}

	void Xuat()
	{
		cout << TuSo << "/ " << MauSo << endl;
	};
};

int main()
{

	// cach 1
	PhanSo ps = PhanSo(3, 4);
	ps.Xuat();

	// cach 2
	PhanSo ps1(5, 6);
	ps1.Xuat();

	// cach 3
	PhanSo ps3;
	ps3 = PhanSo(3, 8);
	ps3.Xuat();

	system("pause");
	return 0;
}