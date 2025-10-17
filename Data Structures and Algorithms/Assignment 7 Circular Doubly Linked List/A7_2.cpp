#include<iostream>
using namespace std;

/*
A7.2 In question 1, define a constructor to initialise start pointer
with NULL.

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
    public:
        CDLL();
};
CDLL::CDLL()
{
    start = nullptr;
}

int main()
{
    CDLL mylist;
    return 0;
}