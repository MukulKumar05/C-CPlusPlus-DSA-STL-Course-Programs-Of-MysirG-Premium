#include<iostream>
using namespace std;

/*
A12.2 In question 1, define a constructor to initialise
member variables.

Problem Summary: define Deque()
(Completed)
*/

struct node
{
    node *prev;
    int item;
    node *next;
};

class Deque
{
    private:
        node *front;
        node *rear;
    public:
        Deque();
};
Deque::Deque()
{
    front = nullptr;
    rear = nullptr;
}

int main()
{
    Deque d1;
    return 0;
}