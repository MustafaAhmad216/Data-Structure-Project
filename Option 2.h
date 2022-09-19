#pragma once
# include<iostream>
using namespace std;

const int max_size = 100;

// implementing the stack class
class Stack
{
private:
    int top;
    int item[max_size];

public:
    Stack() {
        top = -1;
    }

    // declaring all functions we will use
    bool isEmpty();
    void push(int x);
    int pop();
};

// function to check if stack is empty
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

// function to insert data into stack
void Stack::push(int x)
{
    if (top >= max_size - 1)
    {
        cout << "Stack Overflow \n";
    }
    else
    {
        top++;
        item[top] = x;
        //cout << "Element "<<x<<" Inserted into Stack\n";
    }
}

// function to remove data from the top of the stack
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow \n";
        return 0;
    }
    else
    {
        int g = item[top--];
        return g;
    }
}

// implementing the queue class
class Queue{
public:
    Stack S1, S2;

    //declaring enqueue and dequeue functions
    void Enqueue(int x);
    void Dequeue();
};

// enqueue function
void Queue::Enqueue(int x)
{
    S1.push(x);
    //cout << "Element "<<x<<" Inserted into Queue\n";
}

// dequeue function
void Queue::Dequeue()
{
    int x{ 0 }, y{ 0 };
    while (!S1.isEmpty())
    {
        // take an element out of first stack
        x = S1.pop();
        // insert it into the second stack
        S2.push(x);
    }

    // removing the element we wanted to remove
    y = S2.pop();

    // moving back the elements to the first stack
    while (!S2.isEmpty())
    {
        x = S2.pop();
        S1.push(x);
    }
    cout << y;
}

void Option2() {
    Queue m;
    int num_of_elements;
    int element;

    cout << "\t\t\t\t\t\t *Queue Option* \t\t\t\t\n\n\n\n";
    cout << " Please, Enter the number of values you want to add to the queue : ";
    cin >> num_of_elements;
    cout << endl;
    for (int i = 1; i <= num_of_elements; i++) {
        cout << " Please, Enter the value of element " << i <<":  ";
        cin >> element;
        m.Enqueue(element);
    }

    cout <<"\n You have entered (" << num_of_elements << ") element(s).\n\n\n";

    cout << " The Queue Values are : [ ";
    for (int i = 1; i <= num_of_elements; i++) {
        m.Dequeue();
        cout << "  ";
    }
    cout << "]\n\n";
    cout << " Hit Enter To return\n";
}


