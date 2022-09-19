#pragma once
#include<iostream>
using namespace std;
struct nodeq
{
	int item;
	nodeq* next;
};
class queueForStack
{
	nodeq* front;
	nodeq* rear;
public:
	queueForStack() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int);
	int dequeue();
	bool isempty();
};

bool queueForStack::isempty()
{
	return (rear == NULL);
}
void queueForStack::enqueue(int val)
{
	nodeq* newnode = new nodeq;
	newnode->item = val;
	newnode->next = NULL;
	if (isempty())
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}
int queueForStack::dequeue()
{
	int carry;
	if (isempty())
	{
		cout << "queue is empty";
	}
	else
	{
		if (front->next == NULL)
		{
			carry = front->item;
			front = rear = NULL;
		}
		else
		{
			nodeq* temp = front;
			front = front->next;
			carry = temp->item;
			temp->next = NULL;
			delete temp;
			temp = NULL;
		}
		return carry;
	}
}
class stack1
{
	queueForStack q1, q2;
public:
	void push_using_queue(int);
	int pop_using_queue();
};
void stack1::push_using_queue(int ele)
{
	q2.enqueue(ele);
	while (!q1.isempty())
	{
		q2.enqueue(q1.dequeue());
	}
	while (!q2.isempty())
	{
		q1.enqueue(q2.dequeue());
	}
}
int stack1::pop_using_queue()
{
	int value = 0;
	value = q1.dequeue();
	return value;
}



void Option1()
{

	stack1 s;
	int n;
	int e;
	cout << "\t\t\t\t\t\t *Stack Option* \t\t\t\t\n\n\n\n";
	cout << " Please, Enter the number of items you want to add : ";
		cin >> n;
		cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << " Please, Enter the value of item " << i << ":  ";
		cin >> e;
		s.push_using_queue(e);
	}

	cout << "\n You have entered (" << n << ") element(s).\n\n\n";
	cout << " The Stack values are : [ ";
	for (int i = 0; i < n; i++)
	{
		cout << s.pop_using_queue() << " ";
	}
	cout << "]\n\n";
	cout << " Hit Enter To return\n";






}
