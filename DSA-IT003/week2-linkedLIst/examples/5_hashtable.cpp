#include <iostream>
using namespace std;

const int Size = 5;

struct Node
{
	int data;
	Node *pNext;
};

Node *initNode(int value)
{
	Node *p = new Node();
	p->data = value;
	p->pNext = nullptr;
	return p;
};

/**
 * tuong duong voi single linked list
 */
struct Bucket
{
	Node *pHead;
	Node *pTail;
};

void initBucket(Bucket &bk)
{
	bk.pHead = nullptr;
	bk.pTail = nullptr;
};

struct HashTable
{
	Bucket bucket[Size];
};

void initHashTable(HashTable &h)
{
	for (int i = 0; i < Size; i++)
	{
		initBucket(h.bucket[i]);
	}
};

int hashFunc(float value)
{
	return (int)(abs(value)) % Size; // lay gia tri tuyet doi de map voi key trong mang
};

void addHead(Bucket &bk, Node *p)
{
	if (bk.pHead == NULL)
	{
		bk.pHead = p;
		bk.pTail = p;
	}
	else
	{
		bk.pTail->pNext = p;
		bk.pTail = p;
	}
};

void add(HashTable &h, Node *p)
{
	int i = hashFunc(p->data);
	addHead(h.bucket[i], p);
};

void printHashTable(HashTable &h)
{
	for (int i = 0; i < Size; i++)
	{
		printf("Bucket[%d] = ", i);
		for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
		{
			cout << p->data << " ";
		}
		cout << endl;
	}
}

int main()
{
	HashTable h;
	initHashTable(h);
	add(h, initNode(50));
	add(h, initNode(73));
	add(h, initNode(35));
	add(h, initNode(36));
	add(h, initNode(64));
	add(h, initNode(28));
	add(h, initNode(90));
	add(h, initNode(21));
	add(h, initNode(53));
	add(h, initNode(13));
	printHashTable(h);
	return 0;
}
