#include<iostream>
using namespace std;

/*
A5.9 In question 1, define a method to delete a specific node.

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
        node* searchNode(int);
        void insertAfterNode(node*, int);
        void deleteLast();
        void deleteSpecificNode(node*);
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
node* DLL::searchNode(int itemToSearch)
{
    if(start) // there is atleast 1 element in the list
    {
        node *ptr = start;
        while(ptr)
        {
            if(ptr->item == itemToSearch)
                return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }
    else // linked list is empty
        return nullptr;
}
void DLL::insertAfterNode(node *temp, int data)
{
    if(temp)
    {
        if(searchNode(temp->item)) // if afternode found in the linked list
        {
            node *newPtr = new node;
            newPtr->prev = temp;
            newPtr->item = data;
            newPtr->next = temp->next;
            temp->next = newPtr;
            if(newPtr->next) // if new node is getting inserted between two nodes
                newPtr->next->prev = newPtr;
        }
    }
    else
        cout<<"Insertion not possible because the specified node is not found in the list."<<endl;
}
void DLL::deleteLast()
{
    if(start) // list has atleast 1 element
    {
        if(start->next) // there are > 1 elements in the list
        {
            node *ptr = start;
            while(ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = nullptr;
            delete ptr;
        }
        else // there is only 1 element in the list
        {
            delete start;
            start = nullptr;
        }
    }
    else // if list is empty
    {
        cout<<"Deletion not possible because linked list is already empty."<<endl;
    }
}
void DLL::deleteSpecificNode(node *temp)
{
    if(temp) // if temp is not NULL
    {
        if(searchNode(temp->item)) // if node passed is found in the linked list 
        {
            if(temp == start) // if specified node is the first node in the list
                deleteFirst();
            else // if specified node is not the first node in the list
            {
                temp->prev->next = temp->next;
                if(temp->next) // specified node is not the last node in the list
                    temp->next->prev = temp->prev;
                delete temp;
            }
        }
        else
            cout<<"Deletion not possible because either the linked list is empty or the node passed is not found in the list"<<endl;
    }
    else
        cout<<"Deletion not possible because the node passed is invalid"<<endl;
}


int main()
{
    DLL mylist;
    mylist.insertAtLast(10);
    mylist.insertAtLast(20);
    mylist.insertAtLast(30);
    mylist.insertAtLast(40);
    mylist.deleteSpecificNode(mylist.searchNode(20));
    mylist.deleteSpecificNode(mylist.searchNode(30));
    mylist.deleteSpecificNode(mylist.searchNode(40));
    mylist.deleteSpecificNode(mylist.searchNode(10));
    mylist.deleteSpecificNode(mylist.searchNode(40));
    mylist.displayDLL();
    return 0;
}