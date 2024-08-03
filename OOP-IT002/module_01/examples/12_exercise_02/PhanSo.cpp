#include "PhanSo.h"
#include <iostream>
using namespace std;

PhanSo::PhanSo()
{
}

PhanSo::~PhanSo()
{
}

void PhanSo::Nhap()
{
	cout << "nhap tu so: " << endl;
	cin >> TuSo;

	do
	{
		cout << "nhap mau so: " << endl;
		cin >> MauSo;
	} while (MauSo == 0);
}

void PhanSo::Xuat()
{
	cout << TuSo << "/ " << MauSo << endl;
};

PhanSo PhanSo::Cong(PhanSo ps)
{
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.MauSo + this->MauSo * ps.TuSo;
	KQ.MauSo = this->MauSo * ps.MauSo;

	return KQ;
}

PhanSo PhanSo::Tru(PhanSo ps)
{
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.MauSo - this->MauSo * ps.TuSo;
	KQ.MauSo = this->MauSo * ps.MauSo;

	return KQ;
};

PhanSo PhanSo::Nhan(PhanSo ps)
{
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.TuSo;
	KQ.MauSo = this->MauSo * ps.MauSo;

	return KQ;
}

PhanSo PhanSo::Chia(PhanSo ps)
{
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.MauSo;
	KQ.MauSo = this->MauSo * ps.TuSo;

	return KQ;
}
