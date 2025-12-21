#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0
#define QUEUE_OVERFLOW 1
#define INVALID_INDEX 2

/*
A13.9 Define a logic to implement priority queue using 
2 dimensional arrays.

Problem Summary: define logic to implement priority queue using 2D array.
(Completed)
*/

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


int main()
{
    PriorityQueue p(5);
    try
    {
        p.insertWithPriority(3, 11);
        p.insertWithPriority(6, 8);
        p.insertWithPriority(9, 26);
        p.insertWithPriority(12, 11);
        p.insertWithPriority(15, 10);
    }
    catch(int e)
    {
        if(e == QUEUE_OVERFLOW)
            cout<<"Queue overflow! New insertion in queue is not possible now."<<endl;
        else if(e == INVALID_INDEX)
            cout<<"Error: Invalid index passed for insertion in queue."<<endl;
    }
    // p.displayElements();
    try
    {
        p.getHighestPriorityNumber();
        cout<<"Highest priority number in priority queue is "<<p.getHighestPriorityNumber()<<endl;
    }
    catch(int e)
    {
        cout<<"Cannot access the highest priority number because the priority queue is empty."<<endl;
    }
    return 0;
}