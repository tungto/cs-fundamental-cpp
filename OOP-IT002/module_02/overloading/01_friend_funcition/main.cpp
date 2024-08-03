#include <iostream>
using namespace std;

class HinhChuNhat
{
private:
	float a, b;

public:
	HinhChuNhat();
	HinhChuNhat(float a, float b)
	{
		this->a = a;
		this->b = b;
	};

	// needed for DienTich method access HinhChuNhat  private variables
	friend float DienTich(HinhChuNhat);
};

float DienTich(HinhChuNhat H)
{
	return H.a * H.b;
};

int main()
{
	HinhChuNhat H(4, 5);
	cout << "dien tich la: " << DienTich(H) << endl;

	return 0;
}