#include<iostream>
using namespace std;

/*
A13.1 Define a class PriorityQueue with node type pointer start as
member variable. Implement PriortyQueue using singly linked list.

Problem Summary: define class PriorityQueue with necessary member variables.
Implement PriortyQueue using SLL.
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
