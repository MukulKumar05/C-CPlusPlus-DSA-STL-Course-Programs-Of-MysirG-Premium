#include<iostream>
using namespace std;

/*
A9.1 Define a class Stack with node type pointer top as member variable.
Implement stack using linked list.

Problem Summary: Define class Stack with node *top as member variable. Implement
stack using SLL.
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
};
Stack::Stack()
{
    top = nullptr;
}

int main()
{
    Stack s1;
    return 0;
}
