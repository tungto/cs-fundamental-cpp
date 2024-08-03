#include <iostream>
using namespace std;
// Doi tuong la tham so truyen vao

class Thoigian
{
private:
	int Gio, Phut;

public:
	void Nhap(int Gio, int Phut)
	{
		this->Gio = Gio;
		this->Phut = Phut;
	}

	void Xuat()
	{
		cout << Gio << "h, " << Phut << " phut" << endl;
	};

	// Doi tuong la tham so truyen vao
	Thoigian Tong(Thoigian T1, Thoigian T2)
	{
		Phut = T1.Phut + T2.Phut;
		Gio = Phut / 60;
		Phut = Phut % 60;
		Gio = Gio + T1.Gio + T2.Gio;

		return *this;
	};
};

int main()
{

	// Thoigian tg;
	// int gio, phut;
	// cout << "Nhap vao gio: " << endl;
	// cin >> gio;
	// cout << "Phut vao phut: " << endl;
	// cin >> phut;
	// tg.Nhap(gio, phut);
	// tg.Xuat();

	Thoigian T1, T2, T3;
	T1.Nhap(2, 50);
	T2.Nhap(3, 15);

	T3.Tong(T1, T2);
	T3.Xuat();

	return 0;
}