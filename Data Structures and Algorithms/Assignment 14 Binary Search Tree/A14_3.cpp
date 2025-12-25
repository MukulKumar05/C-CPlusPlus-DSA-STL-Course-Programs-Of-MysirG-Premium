#include<iostream>
using namespace std;

/*
A14.3 In question 1, define a method to check if the tree
is empty.

Problem Summary: define isEmpty()
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
        bool isEmpty();
};
BST::BST()
{
    root = nullptr;
}
bool BST::isEmpty()
{
    return root == nullptr;
}


int main()
{
    BST b1;
    if(b1.isEmpty())
        cout<<"Binary Search tree is empty."<<endl;
    else
        cout<<"Binary Search tree is not empty."<<endl;
    return 0;
}