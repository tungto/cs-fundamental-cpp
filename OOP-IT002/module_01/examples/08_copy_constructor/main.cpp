#include <iostream>
using namespace std;

class HocSinh
{
private:
	string Hoten;
	int MaSv;

public:
	HocSinh(){};
	HocSinh(int maSv, string hoten)
	{
		this->Hoten = hoten;
		this->MaSv = maSv;
	}
	// truyen tham chieu
	// neu truyen tham tri => tao 1 vung copy, nhung vi chua co gia tri
	HocSinh(const HocSinh &hs)
	{
		Hoten = hs.Hoten;
	};
};

int main()
{
	HocSinh hs(1, "Khoa"), hs2;
	hs2 = HocSinh(hs);

	return 0;
}