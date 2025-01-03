
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *pNext;
};

/**
 * init node get data, return pointer
 */

Node *initNode(int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->pNext = nullptr;

	return newNode;
}

/**
 * List: pHead and pTail
 */
struct List
{
	Node *pHead;
	Node *pTail;
};

/**
 * con tro: bien luu dia chi
 * &l : dia chi tham chieu
 */

void initList(List &l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
};

/**
 * if empty list: head and tail = new node
 * else: p.next = l.pHead, l.pHead = p
 */
void addHead(List &l, Node *p)
{
	if (l.pHead == nullptr)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(List &l, Node *p)
{
	if (l.pHead == nullptr)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

/**
 * in ra danh sach
 * su dung p  != null
 */

void print(List l)
{
	Node *p = l.pHead; // pointer: a->x
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->pNext;
	}
}

/**
 * Tim node ke cuoi - next to last node
 * node ke cuoi la node co p.next value cuoi cung
 * input: list
 * output: Node / bool
 */

Node *findLastNode(List l)
{
	Node *p = l.pHead;

	if (p == NULL)
		return NULL;

	while (p->pNext != nullptr)
	{
		p = p->pNext;
	}
	return p;
}

/**
 * Viet ham tim kiem 1 gia tri co trong list hay k
 * input: gia tri, list
 * output: boolean or &
 *
 */
bool findValue(List l, int value)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		if (p->data == value)
			return true;
		p = p->pNext;
	}
	return false;
}

/**
 * Count Even numbers
 * input: list
 * output: number
 */
int countEvenNumbers(List l)
{
	int count = 0;
	Node *p = l.pHead;
	while (p != NULL)
	{
		if (p->data % 2 == 0)
			count++;
		p = p->pNext;
	}
	return count;
}

/**
 * find max
 * input: list
 * output: value / null (empty list)
 */

int findMax(List l)
{
	Node *p = l.pHead;

	Node *pMax = p;
	while (p != NULL)
	{
		if (p->data > pMax->data)
			pMax = p;
		p = p->pNext;
	}

	return pMax->data;
}

/**
 * xoa node tai vi tri dau
 * input list
 * output: list data xoa, node data xoa, ket qua xoa
 */
int removeHead(List &list)
{
	if (list.pHead == nullptr)
		return -1;

	Node *p = list.pHead;
	if (list.pHead == list.pTail)
	{
		list.pHead = nullptr;
		list.pTail = nullptr;
	}
	else
	{
		list.pHead = p->pNext; // set head to next node of removing head
		p->pNext = NULL;	   // set next node of removing head to nullptr
	}
	delete p; // free memory for removed node
	return p->data;
}
/**
 * remove tail
 * input: list
 * output: list data xoa, gia tri node data xoa
 */

int removeTail(List &list)
{
	if (list.pHead == NULL)
		return -1;

	Node *current = list.pHead;
	int removeValue = current->data;

	if (list.pHead == list.pTail)
	{
		list.pHead = nullptr;
		list.pTail = nullptr;
	}
	else
	{
		while (current->pNext != list.pTail)
		{
			current = current->pNext;
		}
		removeValue = list.pTail->data;
		delete list.pTail;
		list.pTail = current;
		current->pNext = nullptr;
	}

	return removeValue;
}

int main()
{
	// init list
	List l;
	initList(l);

	// init node
	Node *p1 = initNode(10);
	Node *p2 = initNode(18);

	addHead(l, p1);
	addHead(l, p2);
	addHead(l, initNode(30));
	addTail(l, initNode(1));

	// print list
	cout << "In ra danh sach: " << endl;
	print(l);

	// tim gia tri
	// int searchValue;
	// cout << "Nhap gia tri can tim kiem" << endl;
	// cin >> searchValue;
	// bool isFound = findValue(l, searchValue);
	// cout << "Gia tri " << searchValue << " co trong danh sach: " << (isFound ? "Yes" : "No") << endl;

	// count even numbers
	int eventAmount = countEvenNumbers(l);
	cout << "So luong so chan trong danh sach: " << eventAmount << endl;

	// find max
	int maxValue = findMax(l);
	cout << "Gia tri lon nhat trong danh sach: " << maxValue << endl;

	return 0;
};