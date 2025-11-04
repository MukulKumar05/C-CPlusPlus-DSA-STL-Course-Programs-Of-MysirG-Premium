#include<iostream>
using namespace std;
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW -1

/*
A8.10 Define a solution to keep track of minimum value element in the
stack.

Problem Summary: solution to keep track of minimum value element
(Completed)
*/
void swapArrayElementsAtIndices(int arr[], int i1, int i2)
{
    arr[i1]=arr[i1]+arr[i2];
    arr[i2]=arr[i1]-arr[i2];
    arr[i1]=arr[i1]-arr[i2];
}
int smallerNumber(int num1, int num2)
{
    if(num1 < num2)
        return num1;
    return num2;
}

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
        bool isStackUnderflow();
        void reverseStack();
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
bool Stack::isStackUnderflow()
{
    return isEmpty();
}
void Stack::reverseStack()
{
    if(top > 0) // stack has > 1 elements
    {
        int i, stackLength, rightIndex;
        stackLength = top + 1;
        for(i = 0, rightIndex = stackLength - 1; i < stackLength / 2; i++, rightIndex--)
        {
            // in this loop block, 2 elements of stack are swapped in every iteration
            // using swapping without using 3rd variable
            // ptr[i] = ptr[i] + ptr[rightIndex];
            // ptr[rightIndex] = ptr[i] - ptr[rightIndex];
            // ptr[i] = ptr[i] - ptr[rightIndex];
            swapArrayElementsAtIndices(ptr, i, rightIndex);
        }
    }
}
class keepMinStack
{
    private:
        Stack s;
        Stack minS;
    public:
        keepMinStack(int);
        void push(int);
        int pop();
        int getMinElement();
};
keepMinStack::keepMinStack(int cap) : s(cap), minS(cap) { }
void keepMinStack::push(int data)
{
    if(s.isFull())
        throw STACK_OVERFLOW;
    s.push(data);
    if(minS.isEmpty())
        minS.push(data);
    else
        minS.push(smallerNumber(s.peekTopElement(), minS.peekTopElement()));
}
int keepMinStack::getMinElement()
{
    return minS.peekTopElement();
}
int keepMinStack::pop()
{
    minS.pop();
    return s.pop();
}
int main()
{
    keepMinStack s1(10);
    s1.push(51);
    s1.push(23);
    s1.push(45);
    s1.push(91);
    s1.push(20);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.getMinElement()<<endl;
    return 0;
}