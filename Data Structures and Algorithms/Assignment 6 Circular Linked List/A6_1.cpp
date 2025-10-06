#include<iostream>
using namespace std;

/*
A6.1 Define a class CLL to implement Circular linked list data structure with
member variable last pointer of type node.

(Completed)
*/
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
};

int main()
{
    return 0;
}
