#include<iostream>
using namespace std;

/*
A6.2 In question 1, define a constructor to initialise last pointer
with NULL.

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
    public:
        CLL();
};
CLL::CLL()
{
    last = nullptr;
}

int main()
{
    CLL mylist;
    return 0;
}