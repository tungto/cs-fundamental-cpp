#include <iostream>
using namespace std;

/**
 * stack - LIFO -  last in first out
 * using linked list to create stack
 * API: pop, push, print, sum
 * Node: data, pNext
 * Stack: pTop
 */

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

struct Stack
{
	Node *pTop;
};

void initStack(Stack &s)
{
	s.pTop = nullptr;
};

void push(Stack &s, Node *p)
{
	if (p == nullptr)
		return; // Do nothing if the node is null

	if (s.pTop == nullptr)
	{
		s.pTop = p;
	}
	else
	{
		// update pNext of current pTop of stack to p
		// set pTop to p
		p->pNext = s.pTop;
		s.pTop = p;
	}
};

/**
 * remove from the top
 * input: stack
 * output:
 * - if empty stack => return;
 * - else: set pTop to current pTop-> pNext; unlink current pTop -> pNext to null; delete current pTop; return current pTop's value
 */
void pop(Stack &s, int &value)
{
	if (s.pTop == NULL)
		return;

	Node *p = s.pTop;
	value = p->data;
	s.pTop = s.pTop->pNext;
	p->pNext = nullptr;
	delete p;
}

/**
 * print stack
 * loop from pTop to the last node (node != nullptr)
 */
void printStack(Stack &s)
{
	Node *p = s.pTop;
	cout << "Stack elements (top to bottom): ";
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

int main()
{
	Stack s;
	initStack(s);
	Node *p1 = initNode(10);
	push(s, p1);
	push(s, initNode(79));
	push(s, initNode(39));
	printStack(s);
	int value;
	pop(s, value);
	cout << "Pop => " << value << endl;
	printStack(s);
	return 0;
}
