#include "CThiSinh.h"
#include <iostream>
#include <string.h>
using namespace std;

CThiSinh::CThiSinh()
{
	MaThiSinh = 0;
	strcpy(Ten, "");
	strcpy(NgaySinh, "");
	Toan = Van = Anh = 0;
}

CThiSinh::~CThiSinh()
{
	// destructor
}

CThiSinh::CThiSinh(const CThiSinh &x)
{
	MaThiSinh = x.MaThiSinh;
	strcpy(Ten, x.Ten);
	strcpy(NgaySinh, x.NgaySinh);
	Toan = x.Toan;
	Van = x.Van;
	Anh = x.Anh;
}

istream &operator>>(istream &is, CThiSinh &x)
{
	cout << "Ma thi sinh: ";
	is >> x.MaThiSinh;
	is.ignore();
	cout << "Ten thi sinh: ";
	is.getline(x.Ten, 51);
	cout << "Ngay sinh: ";
	is.getline(x.NgaySinh, 11);
	cout << "Toan: ";
	is >> x.Toan;
	cout << "Van: ";
	is >> x.Van;
	cout << "Anh: ";
	is >> x.Anh;

	return is;
}

ostream &operator<<(ostream &os, const CThiSinh &x)
{
	os << "Ma thi sinh: " << x.MaThiSinh << endl;
	os << "Ten thi sinh: " << x.Ten << endl;
	os << "Ngay sinh: " << x.NgaySinh << endl;
	os << "Diem Toan: " << x.Toan << endl;
	os << "Diem Van: " << x.Van << endl;
	os << "Diem Anh: " << x.Anh << endl;
	os << "Tong diem: " << x.TongDiem() << endl;
	return os;
}

int CThiSinh::TongDiem() const
{
	return Toan + Van + Anh;
}

int CThiSinh::getDiemToan()
{
	return Toan;
}

int CThiSinh::getDiemVan()
{
	return Van;
}

int CThiSinh::getDiemAnh()
{
	return Anh;
}
