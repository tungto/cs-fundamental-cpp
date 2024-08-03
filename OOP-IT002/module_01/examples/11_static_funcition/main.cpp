#include <iostream>
using namespace std;

class PhanSo
{
private:
	int TuSo, MauSo;

public:
	static int dem;
	static void print();
	PhanSo(int tu, int mau)
	{
		this->TuSo = tu;
		this->MauSo = mau;
		dem++;
	}
};

int PhanSo::dem = 0;
void PhanSo::print()
{
	cout << PhanSo::dem << endl;
}

int main()
{

	PhanSo ps1(1, 5), ps2(3, 8);
	cout << ps1.dem << endl;
	cout << ps2.dem << endl;
	ps1.print();
	return 0;
}