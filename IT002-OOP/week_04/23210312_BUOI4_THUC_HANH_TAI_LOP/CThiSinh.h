#ifndef CTHISINH_H
#define CTHISINH_H
#include <iostream>
#include <string.h>
using namespace std;

class CThiSinh
{
private:
	int MaThiSinh;
	char Ten[51];
	char NgaySinh[11];
	int Toan;
	int Van;
	int Anh;

public:
	CThiSinh();
	CThiSinh(const CThiSinh &x);
	friend istream &operator>>(istream &is, CThiSinh &x);
	friend ostream &operator<<(ostream &os, const CThiSinh &x);
	int TongDiem() const;
	int getDiemToan();
	int getDiemVan();
	int getDiemAnh();
	~CThiSinh();
};

#endif
