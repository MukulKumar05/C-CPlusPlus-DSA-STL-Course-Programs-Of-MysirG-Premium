#include<iostream>
using namespace std;
#define DUPLICATE_VALUE 5
#define ELEMENT_NOT_FOUND 0

/*
A14.8 In question 1, define a method to delete an element
from BST.

Problem Summary: define deleteElement(int data)
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
        void traverseBSTViaPreorder(node*);
        void traverseBSTViaPostorder(node*);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        ~BST();
        void inOrderTraversal();
        void preOrderTraversal();
        void postOrderTraversal();
        void deleteElement(int);
        node* searchNodewithItem(int);
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
void BST::traverseBSTViaPreorder(node *root)
{
    if(root) // BST has >= 1 elements
    {
        cout<<root->item<<" ";
        if(root->left) // if left subtree exists
            traverseBSTViaPreorder(root->left);
        if(root->right) // if right subtree exists
            traverseBSTViaPreorder(root->right);
    }
}
void BST::preOrderTraversal()
{
    if(root) // BST has >= 1 elements
        traverseBSTViaPreorder(root);
    else // BST is empty.
        cout<<"BST is empty."<<endl;
}
void BST::traverseBSTViaPostorder(node *root)
{
    if(root) // BST has >= 1 elements
    {
        if(root->left) // if left subtree exists
            traverseBSTViaPostorder(root->left);
        if(root->right) // if right subtree exists
            traverseBSTViaPostorder(root->right);
        cout<<root->item<<" ";
    }
}
void BST::postOrderTraversal()
{
    if(root) // BST has >= 1 elements
        traverseBSTViaPostorder(root);
    else // BST is empty.
        cout<<"BST is empty."<<endl;
}
node* BST::searchNodewithItem(int data)
{
    if(root) // if BST has >= 1 elements
    {
        node *ptr = root;
        while(ptr) // if BST has >= 1 elements
        {
            if(data == ptr->item)
                return ptr; // node found
            else if(data > ptr->item)
            {
                ptr = ptr->right;
            }
            else if(data < ptr->item)
            {
                ptr = ptr->left;
            }
        }
        return nullptr; // element not found in BST
    }
    else // if BST is empty
        return nullptr; // element not found in BST
}
void BST::deleteElement(int data)
{
    if(root) // if BST has >= 1 elements
    {
        node *ptr = root;
        node *parPtr = root;
        node *toBeDeleted = nullptr;
        while(ptr) // if BST has >= 1 elements
        {
            if(data == ptr->item) // node found which is to be deleted
                break;
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
        if(ptr == nullptr)
            throw ELEMENT_NOT_FOUND; // element not found in BST
        else if(data == ptr->item) // node found which is to be deleted
        {
            if(ptr->left && ptr->right) // node ptr has 2 childs
            {
                toBeDeleted = ptr;
                parPtr = ptr;
                ptr = ptr->left;
                while(ptr->right)
                {
                    parPtr = ptr;
                    ptr = ptr->right;
                }
                toBeDeleted->item = ptr->item;
                if(ptr->left) // node ptr has left child only
                {
                    if(parPtr->left == ptr)
                        parPtr->left = ptr->left;
                    else
                        parPtr->right = ptr->left;
                    delete ptr;
                }
                else // node ptr has no child
                {
                    if(parPtr->left == ptr)
                        parPtr->left = nullptr;
                    else
                        parPtr->right = nullptr;
                    delete ptr;
                }
            }
            else if(ptr->left) // node ptr has left child only
            {
                if(parPtr->left == ptr)
                    parPtr->left = ptr->left;
                else
                    parPtr->right = ptr->left;
                delete ptr;
            }
            else if(ptr->right) // node ptr has right child only
            {
                if(parPtr->left == ptr)
                    parPtr->left = ptr->right;
                else
                    parPtr->right = ptr->right;
                delete ptr;
            }
            else // node ptr has no child
            {
                if(parPtr->left == ptr)
                    parPtr->left = nullptr;
                else
                    parPtr->right = nullptr;
                delete ptr;
            }
        }
    }
    else // if BST is empty
        throw ELEMENT_NOT_FOUND; // element not found in BST
}



int main()
{
    BST b1;
    b1.insert(50);
    b1.insert(30);
    b1.insert(80);
    b1.insert(10);
    b1.insert(40);
    b1.insert(60);
    b1.insert(100);
    b1.insert(5);
    b1.insert(20);
    b1.insert(55);
    b1.insert(15);
    b1.insert(25);
    b1.insert(22);
    b1.insert(18);
    b1.deleteElement(100);
    b1.deleteElement(80);
    b1.deleteElement(30);
    b1.deleteElement(15);
    b1.inOrderTraversal();
    return 0;
}