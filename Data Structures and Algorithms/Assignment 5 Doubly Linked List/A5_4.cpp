#include<iostream>
using namespace std;

/*
A5.4 In question 1, define a method to insert a data into the list
at the end.

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
        void insertAtLast(int);
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
void DLL::insertAtLast(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    newPtr->next = nullptr;
    if(start) // there is atleast 1 element in the list
    {
        node *ptr = start;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        newPtr->prev = ptr;
        ptr->next = newPtr;
    }
    else // if list is empty
    {
        newPtr->prev = nullptr;
        start = newPtr;
    }
}


int main()
{
    DLL mylist;
    mylist.insertAtLast(10);
    mylist.insertAtLast(20);
    mylist.insertAtLast(30);
    mylist.insertAtLast(40);
    mylist.displayDLL();
    return 0;
}