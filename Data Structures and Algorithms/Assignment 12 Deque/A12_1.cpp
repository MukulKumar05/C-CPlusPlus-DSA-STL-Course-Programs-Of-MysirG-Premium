#include<iostream>
using namespace std;

/*
A12.1 Define a class Deque with node type pointers front and rear
as member variables. Implement queue using doubly linked list.

Problem Summary: define class Deque with necessary member variables.
Implement queue using DLL.
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
