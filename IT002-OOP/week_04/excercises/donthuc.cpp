#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CDonThuc
{
private:
	int heso;
	vector<pair<char, int>> bienMu;

public:
	friend istream &operator>>(istream &is, CDonThuc &a);
	friend ostream &operator<<(ostream &os, const CDonThuc &a);

	// constructor
	CDonThuc();
	CDonThuc(int, vector<pair<char, int>>);
	CDonThuc(CDonThuc &);
	// destructor
	~CDonThuc();

	// overloading operators

	CDonThuc &operator=(const CDonThuc &dt);
	CDonThuc operator*(const CDonThuc &x) const;
	CDonThuc operator/(const CDonThuc &x) const;

	CDonThuc &operator*=(const CDonThuc &x);
	CDonThuc &operator/=(const CDonThuc &x);
};

CDonThuc::CDonThuc() {}
CDonThuc::CDonThuc(int hs, vector<pair<char, int>> bm)
{
	this->heso = hs;
	this->bienMu = bm;
}

CDonThuc::~CDonThuc()
{
	// should i return here?
}

// overloading operators
istream &operator>>(istream &is, CDonThuc &dt)
{
	cout << "nhap vao he so: " << endl;
	is >> dt.heso;
	int varAmount;
	cout << "nhap vao so luong bien: " << endl;
	is >> varAmount;
	dt.bienMu.resize(varAmount);
	for (int i = 0; i < varAmount; i++)
	{
		cout << "nhap vao bien thu " << i + 1 << endl;
		is >> dt.bienMu[i].first;
		cout << "nhap vao so mu cua bien thu " << i + 1 << endl;

		is >> dt.bienMu[i].second;
	};

	return is;
}

ostream &operator<<(ostream &os, const CDonThuc &a)
{
	os << a.heso;
	for (const auto &bm : a.bienMu)
	{
		os << bm.first << "^" << bm.second << " ";
	}
	return os;
}

CDonThuc &CDonThuc::operator=(const CDonThuc &dt)
{
	this->heso = dt.heso;
	this->bienMu = dt.bienMu;
	return *this;
}

CDonThuc CDonThuc::operator*(const CDonThuc &dt) const
{
	CDonThuc temp;
	temp.heso = this->heso * dt.heso;
	temp.bienMu = this->bienMu;

	for (auto &bmA : temp.bienMu)
	{
		bool found = false;
		for (const auto &bmB : dt.bienMu)
		{
			if (bmA.first == bmB.first)
			{
				found = true;
				bmA.second += bmB.second;
				break;
			}
		}
		// todo remember this
		if (!found)
		{
			temp.bienMu.push_back(make_pair(bmA.first, bmA.second));
		}
	}

	return temp;
}

CDonThuc CDonThuc::operator/(const CDonThuc &dt) const
{
	CDonThuc temp;
	temp.heso = this->heso / dt.heso;
	temp.bienMu = this->bienMu;

	// chia so mu
	for (auto &bmA : temp.bienMu)
	{
		bool found = false;
		for (const auto &bmB : dt.bienMu)
		{
			if (bmA.first == bmB.first)
			{
				found = true;
				bmA.second -= bmB.second;
				break;
			}
		}

		if (!found)
		{
			temp.bienMu.push_back(make_pair(bmA.first, bmA.second));
		}
	}
}

int main()
{

	CDonThuc a;
	cin >> a;
	cout << a;

	return 0;
}