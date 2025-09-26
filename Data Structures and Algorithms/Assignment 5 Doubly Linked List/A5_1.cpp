#include<iostream>
using namespace std;

/*
A5.1 Define a class DLL to implement doubly linked list data structure
with member variable start pointer of type node.

(Completed)
*/

struct node
{
    int item;
    node *next;
    node *prev;
};

class DLL
{
    private:
        node *start;
};

int main()
{
    
    return 0;
}
