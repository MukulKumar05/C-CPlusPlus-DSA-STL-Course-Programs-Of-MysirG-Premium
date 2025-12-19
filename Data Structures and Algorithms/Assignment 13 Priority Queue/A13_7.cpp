#include<iostream>
using namespace std;
#define QUEUE_UNDERFLOW -1
#define EMPTY_QUEUE 0

/*
A13.7 In question 1, define a destructor to deallocate the memory.

Problem Summary: define ~PriorityQueue()
(Completed)
*/
struct node
{
    int item;
    int priorityNum;
    node *next;
};

class PriorityQueue
{
    private:
        node *start;
    public:
        PriorityQueue();
        void insert(int, int);
        void display();
        void deleteFirst();
        ~PriorityQueue();
        int getHighestPriorityElement();
        int getHighestPriorityNumber();
};
PriorityQueue::PriorityQueue()
{
    start = nullptr;
}
void PriorityQueue::insert(int data, int priority)
{
    if(start) // queue has >= 1 elements
    {
        node *newPtr = new node;
        newPtr->item = data;
        newPtr->priorityNum = priority;
        node *ptr = start;
        node *prevPtr = start;
        while(ptr->next)
        {
            if(newPtr->priorityNum > ptr->priorityNum)
                break;
            prevPtr = ptr;
            ptr = ptr->next;
        }
        if(ptr->next == nullptr) // pointer ptr is pointing to the last node
        {
            if(newPtr->priorityNum > ptr->priorityNum) // if new node has higher priority than the last node
            {
                if(start == ptr)
                {
                    newPtr->next = ptr;
                    start = newPtr;              
                }
                else
                {
                    newPtr->next = ptr;
                    prevPtr->next = newPtr;
                }
            }
            else
            {
                newPtr->next = nullptr;
                ptr->next = newPtr;
            }
        }
        else // if new node has higher priority than the current node ptr
        {
            if(start == ptr)
            {
                newPtr->next = ptr;
                start = newPtr;
            }
            else
            {
                newPtr->next = ptr;
                prevPtr->next = newPtr;
            }
        }
    }
    else // queue is empty
    {
        node *newPtr = new node;
        newPtr->item = data;
        newPtr->priorityNum = priority;
        newPtr->next = nullptr;
        start = newPtr;
    }
}
void PriorityQueue::display()
{
    if(start == nullptr)
        cout<<"Linked list is empty."<<endl;
    else
    {
        node *ptr = start;
        while(ptr)
        {
            cout<<ptr->item<<" ";
            ptr = ptr->next;
        }
    }
}
void PriorityQueue::deleteFirst()
{
    if(start)
    {
        node *ptr = start;
        start = start->next;
        delete ptr;
    }
    else
        throw QUEUE_UNDERFLOW;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        deleteFirst();
}
int PriorityQueue::getHighestPriorityElement()
{
    if(start)
        return start->item;
    throw EMPTY_QUEUE;
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(start)
        return start->priorityNum;
    throw EMPTY_QUEUE;
}


int main()
{
    PriorityQueue p1;
    p1.insert(3, 63);
    p1.insert(6, 58);
    p1.insert(9, 53);
    p1.insert(12, 49);
    p1.insert(15, 45);
    p1.insert(18, 47);
    p1.insert(21, 51);
    p1.insert(24, 76);
    p1.insert(27, 76);
    try
    {
        p1.getHighestPriorityNumber();
        cout<<"Highest priority number in queue is "<<p1.getHighestPriorityNumber()<<endl;
    }
    catch(int e)
    {
        cout<<"Queue is empty."<<endl;
    }
    return 0;
}