
#include <iostream>
using namespace std;

struct ToaDo
{
	int x;
	int y;
};

void printToaDo(ToaDo t)
{
	// cout << t.x << " " << t.y << endl;
	printf("%d; %d\n", t.x, t.y);
}

// lay vao dia chi => in ra gia chi cua dia chi
// overloading
void printToaDo(ToaDo *t)
{
	printf("%d; %d\n", (t->x), t->y);
}

int main()
{

	int x = 5;
	// cap phat tinh
	ToaDo a = {1, 5};

	// printToaDo(a);
	// printToaDo(&a);

	ToaDo *p = &a;

	ToaDo *p1 = new ToaDo({3, 6});
	// * vs & ??
	printToaDo(p1);
	printToaDo(*p1);

	cout << p1->x << endl;
	cout << (*p1).x << endl;

	return 0;
}
