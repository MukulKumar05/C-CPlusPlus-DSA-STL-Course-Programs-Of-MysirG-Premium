#include<iostream>
using namespace std;
#define STACK_UNDERFLOW -1

/*
A9.5 In question 1, define a method to pop the top element
of the stack.

Problem Summary: pop() top element
(Completed)
*/
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        void push(int);
        void displayElements();
        void pop();
        ~Stack();
        int peekTopElement();
};
Stack::Stack()
{
    top = nullptr;
}
void Stack::push(int data)
{
    if(top)
    {
        node *newPtr = new node;
        newPtr->next = top;
        top = newPtr;
        top->item = data;
    }
    else
    {
        top = new node;
        top->next = nullptr;
        top->item = data;
    }
}
void Stack::displayElements()
{
    if(top == nullptr)
        cout<<"Stack is empty."<<endl;
    else
    {
        node *ptr = top;
        while(ptr)
        {
            cout<<ptr->item<<" ";
            ptr = ptr->next;
        }
    }
}
void Stack::pop()
{
    if(top)
    {
        node *ptr = top;
        top = top->next;
        delete ptr;
    }
    else
        cout<<"Deletion not possible because stack is already empty."<<endl;
}
Stack::~Stack()
{
    while(top)
        pop();
}
int Stack::peekTopElement()
{
    if(top)
        return top->item;
    throw STACK_UNDERFLOW;
}
int main()
{
    Stack s1;
    s1.push(3);
    s1.push(6);
    s1.push(9);
    s1.push(12);
    s1.push(15);
    cout<<s1.peekTopElement();
    return 0;
}