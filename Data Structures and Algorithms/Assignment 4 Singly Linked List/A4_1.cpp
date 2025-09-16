#include<iostream>
using namespace std;

/*
A4.1 Define a class SLL to implement singly linked list data structure with
member variable start pointer of type node.

(Completed)
*/

struct node
{
    int item;
    node *next;
};

class SLL
{
    private:
        node *start;
    public:
        SLL()
        {
            start = nullptr;
        }
};

int main()
{
    SLL mylist;
    return 0;
}
