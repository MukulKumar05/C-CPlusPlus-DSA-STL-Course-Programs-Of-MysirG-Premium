#include<iostream>
using namespace std;

/*
A11.2 In question 1, define a constructor to initialise member variable.

Problem Summary: Queue()
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