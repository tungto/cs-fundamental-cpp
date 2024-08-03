#include <iostream>
using namespace std;

/**
 * Tạo các class tên: SoPhuc có thuộc tính float PhanThuc, PhanAo.
ThoiGian có thuộc tính float Gio, Phut, Giay.
HocSinh có thuộc tính HoTen, Tuoi, DiaChi, DiemToan, DiemLy, DiemVan
 */

class SoPhuc
{
private:
	int PhanThuc, PhanAo;

public:
	SoPhuc()
	{
		this->PhanThuc = this->PhanAo = 1;
	};
	SoPhuc(int phanThuc, int phanAo)
	{
		this->PhanThuc = phanThuc;
		this->PhanAo = phanAo;
	};
};

class ThoiGian
{
private:
	int Gio, Phut, Giay;

public:
	ThoiGian(int gio, int phut)
	{
		this->Gio = gio;
		this->Phut = phut;
		this->Giay = 0;
	};
	ThoiGian(int gio, int phut, int giay)
	{
		this->Gio = gio;
		this->Phut = phut;
		this->Giay = giay;
	};
};

class HocSinh
{
private:
	string HoTen, DiaChi;
	int Tuoi;
	float Toan, Van, NgoaiNgu;

public:
	// default constructor
	HocSinh(){};

	// parameterized constructor
	HocSinh(string hoten, int tuoi, string diachi, float toan, float van, float NN)
	{
		this->HoTen = hoten;
		this->Tuoi = tuoi;
		this->DiaChi = diachi;
		this->Toan = toan;
		this->Van = van;
		this->NgoaiNgu = NN;
	};

	// copy constructor
	HocSinh(HocSinh &hs)
	{
		this->HoTen = hs.HoTen;
		this->DiaChi = hs.DiaChi;
	};

	void Nhap();
	void Xuat()
	{
		cout << "Ho ten: " << this->HoTen << ", dia chi: " << this->DiaChi << endl;
	}
};
void HocSinh::Nhap() {}

int main()
{

	SoPhuc sp;
	SoPhuc sp1(1, 2);

	ThoiGian tim1(3, 2, 1);
	ThoiGian time2(4, 4);

	HocSinh hs;
	HocSinh hs1("ted to", 19, "vung tau", 10, 10, 10);
	HocSinh hs2(hs1);
	hs2.Xuat();
	return 0;
}