#include<iostream>
using namespace std;
#define DUPLICATE_VALUE 5

/*
A14.4 In question 1, define a method to insert a new element
in the BST.

Problem Summary: define insert(int data)
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
    protected:
        void deleteTree(node*);
        void traverseBSTViaInorder(node*);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        ~BST();
        void inOrderTraversal();
};
BST::BST()
{
    root = nullptr;
}
bool BST::isEmpty()
{
    return root == nullptr;
}
void BST::insert(int data) // to test
{
    node *newPtr = new node;
    newPtr->left = nullptr;
    newPtr->item = data;
    newPtr->right = nullptr;
    node *ptr = root;
    node *parPtr = root;
    while(ptr) // if BST has >= 1 elements
    {
        if(data == ptr->item)
            throw DUPLICATE_VALUE;
        else if(data > ptr->item)
        {
            parPtr = ptr;
            ptr = ptr->right;
        }
        else if(data < ptr->item)
        {
            parPtr = ptr;
            ptr = ptr->left;
        }
    }
    if(root == nullptr) // if BST is empty
    {
        root = newPtr;
    }
    else if(data > parPtr->item)
    {
        parPtr->right = newPtr;
    }
    else if(data < parPtr->item)
    {
        parPtr->left = newPtr;
    }
}
void BST::deleteTree(node *ptr)
{
    if(ptr) // if BST has >= 1 elements
    {
        if(ptr->left)
        {
            deleteTree(ptr->left);
            ptr->left = nullptr;
        }
        if(ptr->right)
        {
            deleteTree(ptr->right);
            ptr->right = nullptr;
        }
        delete ptr;
    }
}
BST::~BST()
{
    deleteTree(root);
}
void BST::traverseBSTViaInorder(node *root) 
{
    if(root) // BST has >= 1 elements
    {
        if(root->left) // if left subtree exists
            traverseBSTViaInorder(root->left);
        cout<<root->item<<" ";
        if(root->right) // if right subtree exists
            traverseBSTViaInorder(root->right);
    }
}
void BST::inOrderTraversal()
{
    if(root) // BST has >= 1 elements
        traverseBSTViaInorder(root);
    else // BST is empty.
        cout<<"BST is empty."<<endl;
}


int main()
{
    BST b1;
    b1.insert(50);
    b1.insert(30);
    b1.insert(80);
    b1.insert(10);
    b1.insert(40);
    b1.insert(70);
    b1.insert(100);
    cout<<"Inorder Traversal of BST is "<<endl;
    b1.inOrderTraversal();
    return 0;
}