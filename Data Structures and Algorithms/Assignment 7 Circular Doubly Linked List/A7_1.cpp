#include<iostream>
using namespace std;

/*
A7.1 Define a class CDLL to implement Circular Doubly linked list data
structure with member variable start pointer of type node.

(Completed)
*/

struct node
{
    node *prev;
    int item;
    node *next;
};

class CDLL
{
    private:
        node *start;
};

int main()
{
    return 0;
}
