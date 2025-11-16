#include<iostream>
using namespace std;

/*
A10.2 In question 1, define a parameterized constructor to initialise member 
variables.

Problem Summary: Queue(int cap)
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