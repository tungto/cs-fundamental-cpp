#include "HocSinh.h"

HocSinh::HocSinh()
{
}

HocSinh::~HocSinh()
{
}

void HocSinh::Nhap()
{
	cout << "\n Nhap ten cua hoc sinh: ";
	getline(cin, HoTen);

	cout << "\n Nhap dia chi cua hoc sinh: ";
	getline(cin, DiaChi);

	cout << "\n Nhap diem toan: ";
	cin >> Toan;

	cout << "\n Nhap diem van: ";
	cin >> Van;
}

void HocSinh::Xuat()
{
	cout << "Ten hoc sinh la: " << HoTen << endl;
	cout << "Dia chi: " << DiaChi << endl;
	cout << "Toan: " << Toan << endl;
	cout << "Van: " << Van << endl;
}
