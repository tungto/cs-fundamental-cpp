
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

void printMangTD(ToaDo *a, int *n)
{

	for (int i = 0; i < *n; i++)
	{
		printToaDo(a + i);
	}
};

void initGiaTriMangTD(ToaDo *a, int *n)
{

	*(a + 0) = {1, 2};
	*(a + 1) = {3, 4};
	*(a + 2) = {5, 6};

	*n = 3;
}

int main()
{

	ToaDo *a = new ToaDo[100];

	a[0] = {1, 2};
	a[1] = {3, 4};

	// best practice: chua dung gi de la 0
	int *n = new int(0);

	initGiaTriMangTD(a, n);

	printMangTD(a, n);

	return 0;
}