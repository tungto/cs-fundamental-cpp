#include <iostream>
using namespace std;

class PhanSo
{
private:
	int TuSo, MauSo;

public:
	static int dem;
	PhanSo(int tu, int mau)
	{
		this->TuSo = tu;
		this->MauSo = mau;
		dem++;
	}
};

int PhanSo::dem = 0;
int main()
{

	PhanSo ps1(1, 5), ps2(3, 8);
	cout << ps1.dem << endl;
	cout << ps2.dem << endl;
	return 0;
}