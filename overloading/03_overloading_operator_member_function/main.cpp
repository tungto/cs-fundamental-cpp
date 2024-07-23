#include <iostream>
using namespace std;

// cach 1: member function
class PhanSo
{
private:
	int TuSo, MauSo;

public:
	PhanSo();
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

	// toán tử số đối sử dụng member function
	// void operator-();
	// void operator<<();
};

// CÁCH 1
// void PhanSo::operator-()
// {
// 	this->TuSo = -this->TuSo;
// 	// this->MauSo = -this->MauSo;
// }

// cach 2 su dung non-member function
// * note to pass by reference here, not by value
void operator-(PhanSo &h)
{
	h.setTuSo(-h.getTuSo());
};

int main()
{

	PhanSo A(1, 3);
	// cout << -A << endl;
	-A;
	A.Xuat();

	return 0;
}