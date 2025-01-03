#include <iostream>
using namespace std;

class Diem
{
private:
	float x, y;

public:
	// overloading operator
	friend istream &operator>>(istream &is, Diem &d);
	friend ostream &operator<<(ostream &os, Diem &d);
	Diem operator=(const Diem &d);

	// constructor
	Diem()
	{
		this->x = 0;
		this->y = 0;
	};
	Diem(float a, float b)
	{
		this->x = a;
		this->y = b;
	};

	Diem(Diem &d)
	{
		this->x = d.x;
		this->y = d.y;
	}
	// destructor
	~Diem()

	{
		return;
	}

	// getter setter
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
	void SetX(float xx)
	{
		x = xx;
	}
	void SetY(float yy)
	{
		y = yy;
	}
};

Diem Diem::operator=(const Diem &d)
{
	this->x = d.x;
	this->y = d.y;
	return *this;
}

istream &operator>>(istream &is, Diem &d)
{
	cout << "x: ";
	float temp;
	is >> temp;
	d.x = temp;
	cout
		<< "y: ";
	is >> temp;
	d.y = temp;
	return is;
};
// tra ve toa do &
ostream &operator<<(ostream &os, Diem &d)
{
	// cout << "toa do diem x la: " << d.x << endl
	// 	 << "toa do diem y la: " << d.y << endl;
	os << "(" << d.x << "," << d.y << ")" << endl;
	return os;
}

/**
 * Tam giac
 */

class Tamgiac
{
private:
	Diem x, y, z;

public:
	Tamgiac() {};
	Tamgiac(Diem a, Diem b, Diem c)
	{
		x = a;
		y = b;
		z = c;
	}

	// destructor
	~Tamgiac() {};

	// operators
	friend istream &operator>>(istream &is, Tamgiac &td);
	friend ostream &operator<<(ostream &os, Tamgiac &td);

	Tamgiac operator=(const Tamgiac &tg);
};

Tamgiac Tamgiac::operator=(const Tamgiac &tg)
{
	this->x = tg.x;
	this->y = tg.y;
	this->z = tg.z;

	return *this;
}

istream &operator>>(istream &is, Tamgiac &tg)
{
	cout << "Nhap vao toa do dinh A" << endl;
	// cin >> tg.x;
	is >> tg.x;
	cout << "Nhap vao toa do dinh B" << endl;
	// cin >> tg.y;
	is >> tg.y;
	cout << "Nhap vao toa do dinh C" << endl;
	// cin >> tg.z;
	is >> tg.z;
	return is;
}

ostream &operator<<(ostream &os, Tamgiac &tg)
{
	// cout << "Tam giac co cach dinh la: " << "A (" << tg.x << " )" << endl
	// 	 << "B ( " << tg.y << " )" << endl
	// 	 << "C - " << tg.z << endl;

	os << "Diem thu nhat: " << tg.x;
	os << "Diem thu hai: " << tg.y;
	os << "Diem thu ba: " << tg.z << endl;

	return os;
}

int main()
{

	Tamgiac g, h;
	cin >> g >> h;
	cout << g << h << endl;
	g = h;
	cout << "toa do moi cua g la" << endl;
	cout << g;

	return 0;
}
