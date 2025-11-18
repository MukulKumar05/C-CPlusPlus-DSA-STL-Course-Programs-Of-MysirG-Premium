#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define ARRAY_UNDERFLOW -1

/*
A10.4 In question 1, define a method to view rear element of the
queue.

Problem Summary: viewRearElement()
(Completed)
*/
class Queue
{
    private:
        int capacity, front, rear;
        int *ptr;
    public:
        Queue(int);
        void insertRear(int);
        bool isFull();
        void displayElements();
        ~Queue();
        int viewRearElement();
        bool isEmpty();
};
Queue::Queue(int cap){
    if(cap<=0)
        cap=10;
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}
bool Queue::isFull()
{
    return capacity-1==rear && front == 0;
}
void Queue::insertRear(int data)
{
    if(isFull())
        throw ARRAY_OVERFLOW;
    ptr[rear+1]=data;
    rear++;
}
void Queue::displayElements()
{
    int i;
    for(i = 0; i <= rear; i++)
        cout<<ptr[i]<<" ";
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::viewRearElement()
{
    if(isEmpty())
        throw ARRAY_UNDERFLOW;
    return ptr[rear];
}
bool Queue::isEmpty()
{
    return rear==-1 && front == -1;
}

int main()
{
    Queue q1(5);
    q1.insertRear(10);
    q1.insertRear(20);
    q1.insertRear(30);
    q1.insertRear(40);
    q1.insertRear(50);
    // q1.displayElements();
    cout<<q1.viewRearElement()<<endl;
    return 0;
}