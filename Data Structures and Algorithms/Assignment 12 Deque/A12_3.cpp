#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1

/*
A12.3 In question 1, define a method to insert a new element
at the front.

Problem Summary: insertFront(int data)
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

int main()
{
    Deque d1;
    d1.insertFront(3);
    d1.insertFront(6);
    d1.insertFront(9);
    d1.display();
    return 0;
}