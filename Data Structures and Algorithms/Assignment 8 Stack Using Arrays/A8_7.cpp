#include<iostream>
using namespace std;
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW -1

/*
A8.7 In question 1, define a method to check stack overflow.

Problem Summary: isStackOverflow()

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
        bool isFull();
        void push(int);
        void displayStackElements();
        int peekTopElement();
        bool isEmpty();
        int pop();
        bool isStackOverFlow();
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
bool Stack::isFull()
{
    return capacity-1==top;
}
void Stack::push(int data)
{
    if(isFull())
        throw STACK_OVERFLOW;
    ptr[top+1]=data;
    top++;
}
void Stack::displayStackElements()
{
    int i;
    for(i = 0; i <= top; i++)
        cout<<ptr[i]<<" ";
}
bool Stack::isEmpty()
{
    return top==-1;
}
int Stack::peekTopElement()
{
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return ptr[top];
}
int Stack::pop()
{
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return ptr[top--];
}
bool Stack::isStackOverFlow()
{
    return isFull();
}
int main()
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    if(s1.isStackOverFlow())
        cout<<"Stack Overflow"<<endl;
    else
        cout<<"There is space to store data in stack."<<endl;
    return 0;
}