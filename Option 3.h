#pragma once
#include<iostream>
using namespace std;
const int maxe_size = 100;
class stack
{
private:
	int item[maxe_size];
	int top;
public:
	stack()
	{
		top = -1;
	}
	void push(int x)
	{
		if (top >= maxe_size - 1)
		{
			cout << " the stack is overflow " << endl;
		}
		else
		{
			top++;
			item[top] = x;
		}
	}
	bool isempty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	void pop()
	{
		if (isempty())
		{
			cout << " The stack is e" << endl;
		}
		else
			top--;
	}

	void print()
	{
		cout << "[ ";
		for (int i = top;i >= 0;i--)
		{
			cout << item[i] << "  ";
		}
		cout << "]";
	}

};

struct node
{
	int data;
	node* next;
};
class linkedlist
{
private:

	node* first;
	node* last;
	int length;
public:
	node* get_first()
	{
		return first;
	}

	linkedlist()
	{

		first = last = NULL;
		length = 0;
	}
	void insertatlast(int x)
	{
		node* newnode = new node;
		newnode->data = x;
		if (length == 0)
		{
			first = last = newnode;
			newnode->next = NULL;
		}
		else
		{
			last->next = newnode;
			newnode->next = NULL;
			last = newnode;
		}
		length++;

	}

	void display()
	{
		node* ptr;
		ptr = first;
		cout << "[";
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout <<"]";
	}
};

void Option3()
{
	int number = 0;
	int count = 1;
	int iteam;
	linkedlist a ;
	cout << "\t\t\t\t\t\t *Linked list option* \t\t\t\t\n\n\n\n";
	cout << " Please, Enter number of items you want to add : ";
	cin >> number;
	cout << endl;
	while (number != 0) {
		cout << " Please, Enter the value item "<<count <<":  ";
		cin >> iteam;
		a.insertatlast(iteam);
		number--;
		count++;
	};
	cout << "\n You have entered " << "(" << count - 1 << ")" << " element(s). \n\n\n";
	cout << " Linked list values in reverse order are : ";

	stack b;
	node* ptr = a.get_first();
	while (ptr != NULL) {
		b.push(ptr->data);
		ptr = ptr->next;
	}
	b.print();

	cout << "\n\n";
	cout << " Hit Enter To return\n";
	
}
