#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *pNext;
};

Node *initNode(int value)
{
	Node *p = new Node();
	p->data = value;
	p->pNext = NULL;

	return p;
};

/**
 * QUEUE - FIFO - first in first out
 * pFront, pRear
 * API: enqueue, dequeue, print
 */
struct Queue
{
	Node *pFront;
	Node *pRear;
	/* data */
};

void initQueue(Queue &queue)
{
	queue.pFront = nullptr;
	queue.pRear = nullptr;
};

/**
 * empty queue: set fornt, rear to node
 * other: rear-> next = node, queue.rear = node
 */
void enQueue(Queue &queue, Node *p)
{
	if (queue.pRear == nullptr)
	{
		queue.pFront = p;
		queue.pRear = p;
	}
	else
	{
		queue.pRear->pNext = p;
		queue.pRear = p;
	}
};

int deQueue(Queue &queue)
{
	if (queue.pFront == nullptr)
		return 0;

	Node *removeFront = queue.pFront;
	int value = removeFront->data;
	if (queue.pFront == queue.pRear)
	{
		queue.pFront = nullptr;
		queue.pRear = nullptr;
	}
	else
	{
		queue.pFront = queue.pFront->pNext;
		removeFront->pNext = nullptr;

		delete removeFront;
	}
	return value;
}

/**
 * print queue
 * loop from front to rear
 *
 */

void printQueueWhile(Queue &q)
{
	Node *p = q.pFront;
	cout << "Print Queue While " << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << ">Rear" << endl;
}

void printQueue(Queue &q)
{

	cout << "print queue for:" << endl;
	for (Node *p = q.pFront; p != NULL; p = p->pNext)
	{

		cout << p->data << " ";
	}

	cout << ">Rear" << endl;
}

int main()
{
	Queue q;
	initQueue(q);
	enQueue(q, initNode(10));
	enQueue(q, initNode(79));
	enQueue(q, initNode(39));
	printQueue(q);
	int value = deQueue(q);
	printQueueWhile(q);
	return 0;
}
