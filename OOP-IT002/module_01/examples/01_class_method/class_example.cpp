#include <iostream>
#include <string>
using namespace std;

// ten, dc, toan, van;
class HocSinh
{
private:
	string HoTen, DiaChi;

	float Toan, Van;

public:
	// cach 1: khai bao va dinh nghia trong class
	void Nhap()
	{
		cout << "\n Nhap ten cua hoc sinh: ";
		getline(cin, HoTen);

		cout << "\n Nhap dia chi cua hoc sinh: ";
		getline(cin, DiaChi);

		cout << "\n Nhap diem toan: ";
		cin >> Toan;

		cout << "\n Nhap diem van: ";
		cin >> Van;
	};
	// cach 2: khai bao trong class va dinh nghia ngoai
	void Xuat();
};

void HocSinh::Xuat()
{
	cout << "Ten hoc sinh la: " << HoTen << endl;
	cout << "Dia chi: " << DiaChi << endl;
	cout << "Toan: " << Toan << endl;
	cout << "Van: " << Van << endl;
}

int main()
{
	HocSinh HS;
	HS.Nhap();
	HS.Xuat();

	return 0;
}