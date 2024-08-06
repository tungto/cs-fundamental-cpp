#include <iostream>
using namespace std;

/**
 * There are three primary ways to overload operators:
 * https://learn.microsoft.com/vi-vn/cpp/cpp/operator-overloading?view=msvc-170
 *

Member Function Overloading
Non-Member (Friend) Function Overloading
Non-Member Function Overloading
 */
class PhanSo
{
private:
	int TuSo, MauSo;

public:
	PhanSo() {};
	PhanSo(int tuSo, int mauSo)
	{
		this->TuSo = tuSo;
		this->MauSo = mauSo;
	};

	int getTuSo() { return TuSo; }
	void setTuSo(int tuSo) { this->TuSo = tuSo; }
	int getMauSo() { return MauSo; }
	void setMauSo(int mauSo) { this->MauSo = mauSo; };

	void Xuat()
	{
		cout << TuSo << "/" << MauSo << endl;
	};

	// toán tử số đối sử dụng member function
	// void operator-();
	// void operator<<();

	// cach 3 dung ham ban
	friend PhanSo operator+(int, PhanSo &ps);
	// friend istream &operator<<();

	// overloading input operator using friend + member function
	friend istream &operator>>(istream &input, PhanSo &ps)
	{
		int a, b;
		cout << "Nhap tu so: ";
		input >> a;

		do
		{
			cout << "Nhap mau so: ";
			input >> b;
		} while (b == 0);

		ps = PhanSo(a, b);
		return input;
	};
	friend ostream &operator<<(ostream &output, PhanSo &ps)
	{
		return output << ps.TuSo << " / " << ps.MauSo << endl;
	};

	// OVERLOADING TIEN TO <prefix>, HAU TO: ++
	PhanSo &operator++()
	{
		TuSo = TuSo + MauSo;

		return *this;
	}
	PhanSo &operator++(int);
};

// (int) here just syntax to separate with prefix
PhanSo &PhanSo::operator++(int)
{
	PhanSo temp = *this;
	++*this;
	return temp;
}

/**
 *
 * CÁCH 1
void PhanSo::operator-()
{
	this->TuSo = -this->TuSo;
}
 */

/**
 * CÁCH 2 su dung non-member function
 *  *note to pass by reference here, not by value
 */
void operator-(PhanSo &h)
{
	h.setTuSo(-h.getTuSo());
};

/**
 * CÁCH 3: su dung friend function va non-member function
 * Ngan gon hon non-member function vi k phai get, set
 * Flexible hon member function vi
 */
PhanSo operator+(int a, PhanSo &ps)
{
	PhanSo temp;
	temp.TuSo = a * ps.MauSo + ps.TuSo;
	temp.MauSo = ps.MauSo;
	return temp;
};

/**
 * overloading input operator using friend + non-member function
 */
// istream &operator>>(istream &input, PhanSo &ps)
// {
// 	int a, b;
// 	cout << "Nhap tu so: ";
// 	input >> a;

// 	do
// 	{
// 		cout << "Nhap mau so: ";
// 		input >> b;
// 	} while (b == 0);

// 	ps = PhanSo(a, b);
// 	return input;
// }

/**
 * overloading output operator using friend + member function
 */
// ostream &operator<<(ostream &output, PhanSo &ps)
// {
// 	return output << ps.getTuSo() << " / " << ps.getMauSo() << endl;
// }

/**
 * overloading ouput operator using friend + non-member function
 */

int main()
{

	PhanSo A(1, 3), B(2, 3), C;
	C = 2 + A;
	C.Xuat();
	// cout << -A << endl;
	-A;
	// A.Xuat();

	// input, output operator
	PhanSo D;
	cin >> D;
	cout << D;
	++D;
	cout << D;

	C = D;
	D++;
	cout << "D " << D << endl;
	cout << "C " << C << endl;

	return 0;
}