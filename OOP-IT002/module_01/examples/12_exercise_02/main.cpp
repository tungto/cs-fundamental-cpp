#include "PhanSo.cpp"

int main()
{
	PhanSo ps1, ps2, psKq;
	ps1.Nhap();
	ps2.Nhap();
	psKq = ps1.Cong(ps2);
	psKq.Xuat();
	psKq = ps1.Tru(ps2);
	psKq.Xuat();
	psKq = ps1.Nhan(ps2);
	psKq.Xuat();
	psKq = ps1.Chia(ps2);
	psKq.Xuat();
	return 0;
}