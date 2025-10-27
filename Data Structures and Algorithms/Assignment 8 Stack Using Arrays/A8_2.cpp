#include<iostream>
using namespace std;

/*
A8.2 In question 1, define a parameterized constructor to initialise
member variables.

(Completed)
*/
class Stack
{
    private:
        int capacity, top;
        int *ptr;
    public:
        Stack(int);
        ~Stack();
};
Stack::Stack(int cap)
{
    if(cap<=0)
        cap=10;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
Stack::~Stack()
{
    delete []ptr;
}

int main()
{
    Stack s1(5);
    return 0;
}