#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1

/*
A12.4 In question 1, define a method to insert a new element
at the rear.

Problem Summary: insertRear(int data)
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

int main()
{
    Deque d1;
    d1.insertRear(3);
    d1.insertRear(6);
    d1.insertRear(9);
    d1.insertRear(12);
    d1.display();
    return 0;
}