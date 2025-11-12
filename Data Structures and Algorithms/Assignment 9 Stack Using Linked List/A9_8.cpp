#include<iostream>
using namespace std;
#define STACK_UNDERFLOW -1

/*
A9.8 Define a method to check whether a given number is a palindrome
or not using stack.

Problem Summary: bool isPalindrome(int number) using stack.
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
        Stack(Stack&);
        Stack& operator=(Stack&);
};
Stack& Stack::operator=(Stack &s)
{
    this->~Stack();
    top = nullptr;
    if(s.top) // if stack s has >= 1 elements
    {
        if(s.top->next) // stack has > 1 elements
        {
            top = nullptr;
            node *ptr = s.top;
            while(ptr->next)
                ptr = ptr->next;
            push(ptr->item);
            while(ptr != s.top)
            {
                node *ptr2 = s.top;
                while(ptr2->next != ptr)
                    ptr2 = ptr2->next;
                push(ptr2->item);
                ptr = ptr2; 
            }
        }
        else // stack has only 1 element
        {
            top = nullptr;
            push(s.top->item);
        }
        
    }
    else // stack is empty
        top = nullptr;
    return *this;
}
Stack::Stack(Stack &s)
{
    if(s.top) // if stack s has >= 1 elements
    {
        if(s.top->next) // stack has > 1 elements
        {
            top = nullptr;
            node *ptr = s.top;
            while(ptr->next)
                ptr = ptr->next;
            push(ptr->item);
            while(ptr != s.top)
            {
                node *ptr2 = s.top;
                while(ptr2->next != ptr)
                    ptr2 = ptr2->next;
                push(ptr2->item);
                ptr = ptr2; 
            }
        }
        else // stack has only 1 element
        {
            top = nullptr;
            push(s.top->item);
        }
        
    }
    else // stack is empty
        top = nullptr;
}
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
bool isPalindrome(int number)
{
    int x = number;
    Stack s;
    while(number)
    {
        s.push(number % 10);
        number /= 10;
    }
    while(x)
    {
        if(x % 10 != s.peekTopElement())
            return false;
        s.pop();
        x /= 10;
    }
    return true;
}
int main()
{
    // Stack s1;
    // s1.push(3);
    // s1.push(6);
    // s1.push(9);
    // s1.push(12);
    // s1.push(15);
    // reverseStack(s1);
    // s1.displayElements();
    int number = 13531;
    if(isPalindrome(number))
        cout<<number<<" is a palindrome number."<<endl;
    else
        cout<<number<<" is not a palindrome number."<<endl;
    return 0;
}