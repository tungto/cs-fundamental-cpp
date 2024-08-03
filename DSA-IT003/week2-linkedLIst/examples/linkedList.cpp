#include <iostream>
using namespace std;

// 1. Create Node Struct
struct Node
{
	int data;
	Node *pNext;
};

// 2. Init Node from value

Node *initNode(int value)
{
	Node *p = new Node();
	p->data = value;
	p->pNext = NULL;

	return p;
}

// 3. create Struct List

struct List
{
	Node *pHead;
	Node *pTail;
};

// 4. Init List
// why &l not *l
void initList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// 5. add Head
void addHead(List &l, Node *p)
{
	// if list is empty then make both head and tail point to new Node
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}

	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
};

int main()
{

	Node *p1 = initNode(10);
	Node *p2 = initNode(20);
	Node *p3 = initNode(15);

	List l;

	// &l really?
	initList(l);

	cout << "p1: " << p1 << " Data: " << p1->data << endl;

	return 0;
}