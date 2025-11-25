#include<iostream>
using namespace std;

/*
A11.1 Define a class Queue with node type pointers front and rear
as member variables. Implement queue using Singly linked list.

Problem Summary: define class Queue with necessary member variables.
Implement queue using SLL.

(Completed)
*/

struct node
{
    int item;
    node *next;
};

class Queue
{
    private:
        node *front;
        node *rear;
    public:
        Queue();
};
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

int main()
{
    Queue q1;
    return 0;
}
