#include<iostream>
using namespace std;

/*
A10.1 Define a class Queue with capacity, front, rear and ptr pointer
as member variables. Implement queue using array.

Problem Summary: define class Queue with necessary member variables.
Implement queue using array.
(Completed)
*/
class Queue
{
    private:
        int capacity, front, rear;
        int *ptr;
    public:
        Queue(int);
};
Queue::Queue(int cap){
    if(cap<=0)
        cap=10;
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}
int main()
{
    Queue q1(10);
    return 0;
}
