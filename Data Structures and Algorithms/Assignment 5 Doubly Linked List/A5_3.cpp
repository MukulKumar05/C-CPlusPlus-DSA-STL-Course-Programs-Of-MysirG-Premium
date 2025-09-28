#include<iostream>
using namespace std;

/*
A5.3 In question 1, define a method to insert a data into the list
at the beginning. 

(Completed)
*/

struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL
{
    private:
        node *start;
    public:
        DLL();
        void insertAtBeginning(int);
        void displayDLL();
        void deleteFirst();
        ~DLL();
};
DLL::DLL()
{
    start = nullptr;
}
void DLL::insertAtBeginning(int data)
{
    node *newPtr = new node;
    newPtr->prev = nullptr;
    newPtr->item = data;
    newPtr->next = start;
    if(start)
    {
        start->prev = newPtr;
    }
    start = newPtr;
}
void DLL::displayDLL()
{
    if(start == nullptr)
        cout<<"Linked list is empty."<<endl;
    else
    {
        node *ptr = start;
        while(ptr)
        {
            cout<<ptr->item<<" ";
            ptr = ptr->next;
        }
    }
}
void DLL::deleteFirst()
{
    if(start) // if linked list is not empty.
    {
        if(start->next)  // > 1 elements in linked list
        {
            node *ptr = start;
            start->next->prev = nullptr;
            start = start->next;
            delete ptr;
        }
        else // only 1 element is present in linked list
        {
            delete start;
            start = nullptr;
        }
    }
}
DLL::~DLL()
{
    while(start)
    {
        deleteFirst();
    }
}


int main()
{
    DLL mylist;
    mylist.insertAtBeginning(3);
    mylist.insertAtBeginning(6);
    mylist.insertAtBeginning(9);
    mylist.displayDLL();
    return 0;
}