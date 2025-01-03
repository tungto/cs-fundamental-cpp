#include <iostream>
using namespace std;

/**
 * double linked list
 * - each node have pNext and pPrev pointing
 */

struct Node
{
	int data;
	Node *pNext, *pPrev;
};

Node *initNode(int value)
{
	Node *p = new Node();
	p->data = value;
	p->pNext = nullptr;
	p->pPrev = nullptr;

	return p;
}

/**
 * List have pHead, pTail
 */
struct List
{
	Node *pHead, *pTail;
};

List *initList(List &l)
{

	l.pHead = NULL;
	l.pTail = NULL;
}

/**
 * ADD TO HEAD
 */

void addToHead(List &l, Node *p)
{
	if (p == nullptr) // check if node is initialized
		return;

	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}

void checkEmptyList(List &l, Node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
}

/**
 * add to tail
 * -input: List, Node
 * - output: new List with added node
 */

void addToTail(List &l, Node *p)
{
	if (p == nullptr) // check if node is initialized
		return;

	// initialize the node next and prev pointers
	p->pNext = nullptr;
	p->pPrev = nullptr;

	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}

	// new tail = p
	// tail.next = p;
	// p.prev = tail
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

/**
 * Print list
 * input: list
 * output: log
 */

void printList(List &l)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
}

int main()
{
	// init list
	List l = List();
	// init node
	initList(l);

	addToTail(l, initNode(10));
	addToTail(l, initNode(8));
	addToTail(l, initNode(3));
	addToTail(l, initNode(20));

	printList(l);

	return 0;
}
