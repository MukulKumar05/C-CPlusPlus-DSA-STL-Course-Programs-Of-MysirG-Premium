#include<iostream>
using namespace std;

/*
A13.2 In question 1, define a constructor to initialise member variable.

Problem Summary: define PriorityQueue()
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
};
PriorityQueue::PriorityQueue()
{
    start = nullptr;
}


int main()
{
    PriorityQueue p1;
    return 0;
}