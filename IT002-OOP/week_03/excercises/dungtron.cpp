#include <iostream>
using namespace std;

class Diem
{
private:
	float x, y;

public:
	//  constructor
	Diem() {};
	Diem(float a, float b)
	{
		this->x = a;
		this->y = b;
	};
	Diem(const Diem &d)
	{
		this->x = d.x;
		this->y = d.y;
	};

	// destructor
	~Diem();

	// override operators

	// todo why return pointer but output type here is Object
	// Diem operator=(const Diem &d)
	// {
	// 	this->x = d.x;
	// 	this->y = d.y;
	// 	return *this;
	// };

	Diem operator=(const Diem &);

	// friend functions
	friend ostream &operator<<(ostream &out, const Diem &x);
	friend istream &operator>>(istream &in, Diem &x);
};

Diem Diem::operator=(Diem const &p)
{
	x = p.x;
	y = p.y;
	return *this;
}

// destructor
Diem::~Diem()
{
	return;
}

istream &operator>>(istream &in, Diem &x)
{
	cout << "input x" << endl;
	cin >> x.x;
	cout << "input y" << endl;

	cin >> x.y;

	return in;
};

ostream &operator<<(ostream &out, const Diem &x)
{
	cout << "( " << x.x << ", " << x.y << " )" << endl;

	return out;
};

/**
 * Class duowng tron
 */

class Duongtron
{
private:
	Diem a;
	int R;

public:
	Duongtron() {};
	Duongtron(Diem, int);
	// overload operators
	friend ostream &operator<<(ostream &os, Duongtron &dt);
	friend istream &operator>>(istream &in, Duongtron &c);

	Duongtron operator=(const Duongtron &);

	// constructor

	// destructor

	~Duongtron();
};

// this is non-member function
Duongtron::Duongtron(Diem xx, int yy)
{
	this->a = xx;
	this->R = yy;
}

// * overloading operator - this is friend function
istream &operator>>(istream &in, Duongtron &dt)
{
	cout << "input toa do diem la tam duong tron" << endl;
	cin >> dt.a;
	cout << "input ban kinh" << endl;
	cin >> dt.R;
	return in;
}
ostream &operator<<(ostream &os, Duongtron &dt)
{
	os << "Duong tron co tam: " << dt.a << " co R = " << dt.R << endl;
	return os;
};
Duongtron Duongtron::operator=(Duongtron const &dt)
{
	this->a = dt.a;
	this->R = dt.R;
	return *this;
}

Duongtron::~Duongtron()
{
	return;
}

int main()
{
	Duongtron a, b;
	cin >> a >> b;
	cout << a << b;

	return 0;
}
