#include <iostream>
using namespace std;

// forwarding declare: khai bao truoc su dung sau
class Pig;
class Chicken
{
	int khoiluong;
	friend void LamThit(Chicken, Pig);

public:
	Chicken(int khoiluong)
	{
		this->khoiluong = khoiluong;
	}
};

class Pig
{
	int khoiluong;
	friend void LamThit(Chicken, Pig);

public:
	Pig(int khoiluong)
	{
		this->khoiluong = khoiluong;
	}
};

void LamThit(Chicken c, Pig p)
{
	cout << c.khoiluong << " " << p.khoiluong << endl;
};

int main()
{

	Chicken chicken(100);
	Pig pig(200);
	LamThit(chicken, pig); // chay duoc, vi LamThit la friend cua cac class Chicken va Pig

	return 0;
}