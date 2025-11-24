#include<iostream>
using namespace std;
#define QUEUE_OVERFLOW 1
#define QUEUE_UNDERFLOW -1

/*
A10.10 In question 1, Define a method to count number of elements
present in the queue.

Problem Summary: countElements()
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
        int viewFrontElement();
        void deleteFrontElement();
        bool isQueueOverflow();
        bool isQueueUnderflow();
        int countElements();
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
        throw QUEUE_OVERFLOW;
    if(isEmpty())
        front++;
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
        throw QUEUE_UNDERFLOW;
    return ptr[rear];
}
bool Queue::isEmpty()
{
    return rear==-1 && front == -1;
}
int Queue::viewFrontElement()
{
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    return ptr[front];
}
void Queue::deleteFrontElement()
{
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    if(rear == 0)
        front--;
    int i;
    for(i=0;i<rear;i++)
    {
        ptr[i]=ptr[i+1];
    }
    rear--;
}
bool Queue::isQueueOverflow()
{
    return isFull();
}
bool Queue::isQueueUnderflow()
{
    return isEmpty();
}
int Queue::countElements()
{
    return rear+1;
}

int main()
{
    Queue q1(5);
    q1.insertRear(10);
    q1.insertRear(20);
    q1.insertRear(30);
    q1.insertRear(40);
    q1.insertRear(50);
    q1.deleteFrontElement();
    cout<<"Currently, number of elements in queue are "<<q1.countElements()<<endl;
    return 0;
}