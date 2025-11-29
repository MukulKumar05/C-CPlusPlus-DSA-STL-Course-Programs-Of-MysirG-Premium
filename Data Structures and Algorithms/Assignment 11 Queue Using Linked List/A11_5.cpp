#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0

/*
A11.5 In question 1, define a method to view front element
in the queue.

Problem Summary: viewFrontElement()
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
        void insertAtRear(int);
        void displayQueue();
        void deleteFromFront();
        ~Queue();
        int viewRearElement();
        int viewFrontElement();
};
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}
void Queue::insertAtRear(int data)
{
    if(front) // queue has >= 1 elements
    {
        rear->next = new node;
        rear->next->next = nullptr;
        rear->next->item = data;
        rear = rear->next;
    }
    else // queue is empty
    {
        front = new node;
        front->next = nullptr;
        front->item = data;
        rear = front;
    }
}
void Queue::deleteFromFront() // to do
{
    if(front) // queue has >=1 elements
    {
        node *ptr = front;
        front = front->next;
        if(front == nullptr)
            rear = nullptr;
        delete ptr;
    }
    else // queue is empty
        throw QUEUE_UNDERFLOW;
}
int Queue::viewRearElement()
{
    if(rear)
        return rear->item;
    throw EMPTY_QUEUE;
}
int Queue::viewFrontElement()
{
    if(front)
        return front->item;
    throw EMPTY_QUEUE;
}
Queue::~Queue()
{
    while(front)
        deleteFromFront();
}
void Queue::displayQueue()
{
    if(front == nullptr)
        cout<<"Queue is empty."<<endl;
    else
    {
        node *ptr = front;
        while(ptr)
        {
            cout<<ptr->item<<" ";
            ptr = ptr->next;
        }
    }
}

int main()
{
    Queue q1;
    q1.insertAtRear(3);
    q1.insertAtRear(6);
    q1.insertAtRear(9);
    try
    {
        q1.viewFrontElement(); // calling viewRearElement() to check for any exception
        cout<<"Front element of queue is "<<q1.viewFrontElement()<<endl;
    }
    catch(int e)
    {
        cout<<"Queue is empty."<<endl;
    }
    return 0;
}