#include<iostream>
using namespace std;

/*
A4.2 In question 1, define a constructor to initialise start pointer with NULL.

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