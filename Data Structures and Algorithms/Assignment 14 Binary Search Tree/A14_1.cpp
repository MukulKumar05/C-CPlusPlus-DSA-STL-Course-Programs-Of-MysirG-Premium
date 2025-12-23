#include<iostream>
using namespace std;

/*
A14.1 Define a class BST (Binary Search Tree) with node type
pointer root as member variable. Implement Binary Search Tree
using linked representation.

Problem Summary: define class BST with node *root as member variable.
Implement BST using linked representation.
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
