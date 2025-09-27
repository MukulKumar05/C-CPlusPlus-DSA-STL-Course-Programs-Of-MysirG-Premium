#include<iostream>
using namespace std;

/*
A5.2 In question 1, define a constructor to initialise start pointer with NULL.

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
    public:
        DLL();
};
DLL::DLL()
{
    start = nullptr;
}

int main()
{
    DLL mylist;
    return 0;
}