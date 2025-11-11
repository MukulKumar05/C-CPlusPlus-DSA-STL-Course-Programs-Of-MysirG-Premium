#include<iostream>
using namespace std;
#define STACK_UNDERFLOW -1

/*
A9.7 Define a method to reverse a stack.

Problem Summary: reverseStack()
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
        bool isEmpty();
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
bool Stack::isEmpty()
{
    if(top)
        return false;
    return true;
}
void moveElementsinReverseOrderFrom(Stack &s1, Stack &s2)
{
    while(!s1.isEmpty())
    {
        s2.push(s1.peekTopElement());
        s1.pop();
    }
}
void reverseStack(Stack &s)
{
    Stack s1;
    moveElementsinReverseOrderFrom(s, s1);
    Stack s2;
    moveElementsinReverseOrderFrom(s1, s2);
    moveElementsinReverseOrderFrom(s2, s);
}
int main()
{
    Stack s1;
    s1.push(3);
    s1.push(6);
    s1.push(9);
    s1.push(12);
    s1.push(15);
    reverseStack(s1);
    s1.displayElements();
    return 0;
}