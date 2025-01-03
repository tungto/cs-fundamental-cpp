#include "CDanhSachTS.h"
#include <iostream>
using namespace std;

CDanhSachTS::CDanhSachTS()
{
	n = 0;
}

CDanhSachTS::~CDanhSachTS()
{
	// destructor
}

void CDanhSachTS::Nhap()
{
	do
	{
		cout << "Nhap so luong thi sinh (>0, <=100): ";
		cin >> n;
	} while (n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
		cin >> DanhSachTS[i];
	}
}

void CDanhSachTS::XuatDSTheoDK()
{
	cout << "\nDanh sach thi sinh co tong diem > 15:\n";
	bool found = false;

	for (int i = 0; i < n; i++)
	{
		if (DanhSachTS[i].TongDiem() > 15)
		{
			cout << DanhSachTS[i] << "\n";
			found = true;
		}
	}

	if (!found)
	{
		cout << "Khong co thi sinh nao co tong diem > 15\n";
	}
}

void CDanhSachTS::SapXepTheoToan()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (DanhSachTS[i].getDiemToan() < DanhSachTS[j].getDiemToan())
			{
				swap(DanhSachTS[i], DanhSachTS[j]);
			}
		}
	}
	cout << "\nDanh sach sau khi sap xep theo diem Toan:\n";
	for (int i = 0; i < n; i++)
	{
		cout << DanhSachTS[i] << "\n";
	}
}

void CDanhSachTS::SapXepTheoVan()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (DanhSachTS[i].getDiemVan() < DanhSachTS[j].getDiemVan())
			{
				swap(DanhSachTS[i], DanhSachTS[j]);
			}
		}
	}
	cout << "\nDanh sach sau khi sap xep theo diem Van:\n";
	for (int i = 0; i < n; i++)
	{
		cout << DanhSachTS[i] << "\n";
	}
}

void CDanhSachTS::SapXepTheoAnh()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (DanhSachTS[i].getDiemAnh() < DanhSachTS[j].getDiemAnh())
			{
				swap(DanhSachTS[i], DanhSachTS[j]);
			}
		}
	}
	cout << "\nDanh sach sau khi sap xep theo diem Anh:\n";
	for (int i = 0; i < n; i++)
	{
		cout << DanhSachTS[i] << "\n";
	}
}

void CDanhSachTS::SapXep(int &chon)
{
	do
	{
		cout << "\nChon mon hoc de sap xep (1-Toan, 2-Van, 3-Anh): ";
		cin >> chon;
	} while (chon < 1 || chon > 3);

	switch (chon)
	{
	case 1:
		SapXepTheoToan();
		break;
	case 2:
		SapXepTheoVan();
		break;
	case 3:
		SapXepTheoAnh();
		break;
	}
}
