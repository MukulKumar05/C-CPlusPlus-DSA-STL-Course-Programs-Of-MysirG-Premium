#include<iostream>
using namespace std;

/*
A14.2 In question 1, define a constructor to initialise root
pointer with NULL.

Problem Summary: define BST()
(Completed)
*/
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
        node *root;
    public:
        BST();
};
BST::BST()
{
    root = nullptr;
}


int main()
{
    BST b1;
    return 0;
}