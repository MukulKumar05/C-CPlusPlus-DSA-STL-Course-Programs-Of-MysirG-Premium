#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0

/*
A11.8 In question 1, define a method to count number of elements
present in the queue.

Problem Summary: elementsCount()
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
        int elementsCount();
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
void Queue::deleteFromFront()
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
int Queue::elementsCount()
{
    int count = 0;
    node *ptr = front;
    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
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
    cout<<"Elements count in queue is "<<q1.elementsCount()<<endl;
    return 0;
}