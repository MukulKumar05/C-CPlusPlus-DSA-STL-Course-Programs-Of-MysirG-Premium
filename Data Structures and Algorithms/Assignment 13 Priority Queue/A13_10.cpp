#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0
#define QUEUE_OVERFLOW 1
#define INVALID_INDEX 2

/*
A13.10 Define a logic to implement min priority queue and max priority
queue in the same data structure.

Problem Summary: define logic to implement:
i. min priority queue (Completed)
ii. max priority queue (Completed)
in the priority queue data structure using array.
(Completed)
*/

// Logic of Max Priority Queue
class PriorityQueue
{
    private:
        int capacity;
        int lastIndex;
        int **ptr;
    protected:
        void insertAtIndex(int,int,int);
    public:
        PriorityQueue(int);
        ~PriorityQueue();
        void insertWithPriority(int, int);
        bool isFull();
        void displayElements();
        void deleteFirst();
        bool isEmpty();
        int getHighestPriorityElement();
        int getHighestPriorityNumber();
};
PriorityQueue::PriorityQueue(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    lastIndex=-1;
    ptr=new int*[capacity];
    for(int i = 0; i < capacity; i++)
        ptr[i] = new int[2];
}
PriorityQueue::~PriorityQueue()
{
    int i;
    for(i = 0; i < capacity; i++)
    {
        delete []ptr[i];
    }
    delete []ptr;
}
bool PriorityQueue::isFull()
{
    return capacity-1==lastIndex;
}
void PriorityQueue::insertAtIndex(int data, int index, int priority)
{
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        throw QUEUE_OVERFLOW;
    int i;
    for(i=lastIndex;i>=index;i--)
    {
        ptr[i+1][0] = ptr[i][0];
        ptr[i+1][1] = ptr[i][1];
    }
    ptr[index][0]=data;
    ptr[index][1]=priority;
    lastIndex++;
}
void PriorityQueue::insertWithPriority(int data, int priority)
{
    int i;
    for(i = 0; i <= lastIndex; i++)
    {
        if(priority > ptr[i][1])
            break;
    }
    insertAtIndex(data, i, priority);
}
void PriorityQueue::displayElements()
{
    int i;
    for(i = 0; i <= lastIndex; i++)
        cout<<ptr[i][0]<<" ";
}
void PriorityQueue::deleteFirst()
{
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    int i;
    for(i=0;i<lastIndex;i++)
    {
        ptr[i][0]=ptr[i+1][0];
        ptr[i][1]=ptr[i+1][1];
    }
    lastIndex--;
}
bool PriorityQueue::isEmpty()
{
    return lastIndex==-1;
}
int PriorityQueue::getHighestPriorityElement()
{
    if(isEmpty())
        throw EMPTY_QUEUE;
    return ptr[0][0];
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(isEmpty())
        throw EMPTY_QUEUE;
    return ptr[0][1];
}

class MinPriorityQueue
{
    private:
        int capacity;
        int lastIndex;
        int **ptr;
    protected:
        void insertAtIndex(int,int,int);
    public:
        MinPriorityQueue(int);
        ~MinPriorityQueue();
        void insertWithPriority(int, int);
        bool isFull();
        void displayElements();
        void deleteFirst();
        bool isEmpty();
        int getLowestPriorityElement();
        int getLowestPriorityNumber();
};
MinPriorityQueue::MinPriorityQueue(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    lastIndex=-1;
    ptr=new int*[capacity];
    for(int i = 0; i < capacity; i++)
        ptr[i] = new int[2];
}
MinPriorityQueue::~MinPriorityQueue()
{
    int i;
    for(i = 0; i < capacity; i++)
    {
        delete []ptr[i];
    }
    delete []ptr;
}
void MinPriorityQueue::insertAtIndex(int data, int index, int priority)
{
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        throw QUEUE_OVERFLOW;
    int i;
    for(i=lastIndex;i>=index;i--)
    {
        ptr[i+1][0] = ptr[i][0];
        ptr[i+1][1] = ptr[i][1];
    }
    ptr[index][0]=data;
    ptr[index][1]=priority;
    lastIndex++;
}
void MinPriorityQueue::insertWithPriority(int data, int priority)
{
    int i;
    for(i = 0; i <= lastIndex; i++)
    {
        if(priority < ptr[i][1])
            break;
    }
    insertAtIndex(data, i, priority);
}
bool MinPriorityQueue::isFull()
{
    return capacity-1==lastIndex;
}
void MinPriorityQueue::displayElements()
{
    int i;
    for(i = 0; i <= lastIndex; i++)
        cout<<ptr[i][0]<<" ";
}
bool MinPriorityQueue::isEmpty()
{
    return lastIndex==-1;
}
void MinPriorityQueue::deleteFirst()
{
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    int i;
    for(i=0;i<lastIndex;i++)
    {
        ptr[i][0]=ptr[i+1][0];
        ptr[i][1]=ptr[i+1][1];
    }
    lastIndex--;
}
int MinPriorityQueue::getLowestPriorityElement()
{
    if(isEmpty())
        throw EMPTY_QUEUE;
    return ptr[0][0];
}
int MinPriorityQueue::getLowestPriorityNumber()
{
    if(isEmpty())
        throw EMPTY_QUEUE;
    return ptr[0][1];
}

int main()
{
    MinPriorityQueue m1(5);
    m1.insertWithPriority(3, 11);
    m1.insertWithPriority(6, 15);
    m1.insertWithPriority(9, 10);
    m1.insertWithPriority(12, 14);
    m1.insertWithPriority(15, 14);
    m1.displayElements();
    try
    {
        m1.getLowestPriorityNumber();
        cout<<"Lowest priority number in the priority queue is "<<m1.getLowestPriorityNumber()<<endl;
    }
    catch(int e)
    {
        cout<<"Cannot access the lowest priority number because the priority queue is empty."<<endl;
    }
    return 0;
}