#include "CDanhSachTS.h"
#include <iostream>
using namespace std;

int main()
{
	CDanhSachTS ds;
	int choice;

	do
	{
		cout << "\n=== CHUONG TRINH QUAN LY THI SINH ===\n";
		cout << "1. Nhap danh sach thi sinh\n";
		cout << "2. Xuat danh sach thi sinh co tong diem > 15\n";
		cout << "3. Sap xep theo diem mon hoc\n";
		cout << "0. Thoat\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			ds.Nhap();
			break;
		case 2:
			ds.XuatDSTheoDK();
			break;
		case 3:
			int chon;
			ds.SapXep(chon);
			break;
		case 0:
			cout << "Cam on ban da su dung chuong trinh!\n";
			break;
		default:
			cout << "Lua chon khong hop le!\n";
		}
	} while (choice != 0);

	return 0;
}
