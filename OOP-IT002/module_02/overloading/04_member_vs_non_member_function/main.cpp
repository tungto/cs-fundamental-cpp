#include <iostream>
using namespace std;

class PhanSo
{
private:
	int TuSo, MauSo;

public:
	PhanSo(); // Default constructor declaration
	PhanSo(int tuSo, int mauSo)
	{
		this->TuSo = tuSo;
		this->MauSo = mauSo;
	}

	int getTuSo() { return TuSo; }
	void setTuSo(int tuSo) { this->TuSo = tuSo; }
	int getMauSo() { return MauSo; }
	void setMauSo(int mauSo) { this->MauSo = mauSo; }

	void Xuat()
	{
		cout << TuSo << "/" << MauSo << endl;
	};

	void operator-();
	PhanSo operator+(PhanSo);
	PhanSo operator+(int);
};

// Default constructor definition
PhanSo::PhanSo() : TuSo(0), MauSo(1)
{
	// Initialize to a default fraction, e.g., 0/1
}

void PhanSo::operator-()
{
	this->TuSo = -this->TuSo;
}

PhanSo PhanSo::operator+(PhanSo ps)
{
	PhanSo kq;
	kq.TuSo = this->TuSo * ps.MauSo + ps.TuSo * this->MauSo;
	kq.MauSo = this->MauSo * ps.MauSo;

	return kq;
}

PhanSo PhanSo::operator+(int so)
{
	PhanSo kq;
	kq.TuSo = so * this->MauSo + this->TuSo;
	kq.MauSo = this->MauSo;

	return kq;
}

PhanSo operator+(int &x) {}

int main()
{
	PhanSo A(1, 3);
	-A;
	A.Xuat();
	PhanSo B(3, 7);
	PhanSo C = B + A;
	C.Xuat();

	return 0;
}
