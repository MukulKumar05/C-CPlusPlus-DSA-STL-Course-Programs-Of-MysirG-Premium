#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0

/*
A12.10 In question 1, define a method to check if deque is empty.

Problem Summary: isEmpty()
(Completed)
*/

struct node
{
    node *prev;
    int item;
    node *next;
};

class Deque
{
    private:
        node *front;
        node *rear;
    public:
        Deque();
        void insertFront(int);
        void deleteFront();
        void display();
        ~Deque();
        void insertRear(int);
        void deleteRear();
        int getFrontElement();
        int getRearElement();
        bool isEmpty();
};
Deque::Deque()
{
    front = nullptr;
    rear = nullptr;
}
void Deque::insertFront(int data)
{
    node *newPtr = new node;
    newPtr->prev = nullptr;
    newPtr->item = data;
    newPtr->next = front;
    if(front) // queue has >= 1 elements
    {
        front->prev = newPtr;
    }
    else // queue is empty
    {
        rear = newPtr;
    }
    front = newPtr;
}
void Deque::display()
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
void Deque::deleteFront()
{
    if(front) // if queue has >= 1 elements.
    {
        if(front->next)  // > 1 elements in queue
        {
            node *ptr = front;
            front->next->prev = nullptr;
            front = front->next;
            delete ptr;
        }
        else // only 1 element is present in queue
        {
            rear = nullptr;
            delete front;
            front = nullptr;
        }
    }
    else // queue is empty
        throw QUEUE_UNDERFLOW;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
void Deque::insertRear(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    newPtr->next = nullptr;
    if(front) // if there are >= 1 elements in the queue
    {
        newPtr->prev = rear;
        rear->next = newPtr;
        rear = newPtr;
    }
    else // if queue is empty
    {
        newPtr->prev = nullptr;
        front = newPtr;
        rear = newPtr;
    }
}
void Deque::deleteRear()
{
    if(front) // if queue has >= 1 elements
    {
        if(front->next) // there are > 1 elements in the queue
        {
            node *ptr = rear;
            ptr->prev->next = nullptr;
            rear = rear->prev;
            delete ptr;
        }
        else // there is only 1 element in the queue
        {
            rear = nullptr;
            delete front;
            front = nullptr;
        }
    }
    else // if queue is empty
        throw QUEUE_UNDERFLOW;
}
int Deque::getFrontElement()
{
    if(front)
        return front->item;
    throw EMPTY_QUEUE;
}
int Deque::getRearElement()
{
    if(rear)
        return rear->item;
    throw EMPTY_QUEUE;
}
bool Deque::isEmpty()
{
    return front == nullptr;
}

int main()
{
    Deque d1;
    d1.insertRear(3);
    d1.insertRear(6);
    d1.insertRear(9);
    d1.insertRear(12);
    if(d1.isEmpty())
        cout<<"Queue is empty."<<endl;
    else
        cout<<"Queue is not empty."<<endl;
    return 0;
}