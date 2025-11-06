#include<iostream>
using namespace std;

/*
A9.2 In question 1, define a constructor to initialise member
variable.

Problem Summary: define constructor
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