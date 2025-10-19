#include<iostream>
using namespace std;

/*
A7.4 In question 1, define a method to insert a data into the list
at the end.

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
        void insertAtBeginning(int);
        void displayList();
        void deleteFromBeginning();
        ~CDLL();
        void insertAtEnd(int);
};
CDLL::CDLL()
{
    start = nullptr;
}
void CDLL::insertAtBeginning(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    if(start) // list has >=1 elements
    {
        newPtr->prev = start->prev;
        newPtr->next = start;
        start->prev = newPtr;
        newPtr->prev->next = newPtr;
        start = newPtr;
    }
    else // list is empty
    {
        newPtr->prev = newPtr;
        newPtr->next = newPtr;
        start = newPtr;
    }
}
void CDLL::displayList()
{
    if(start) // list has >= 1 elements.
    {
        cout<<start->item<<" ";
        if(start->next != start) // if list > 1 elements
        {
            node *ptr = start->next;
            while(ptr != start)
            {
                cout<<ptr->item<<" ";
                ptr = ptr->next;
            }
        }
    }
    else // list is empty
        cout<<"Linked List is empty."<<endl;
}
void CDLL::deleteFromBeginning()
{
    if(start) // list has >= 1 elements
    {
        if(start->next == start) // CDLL has only 1 element
        {
            delete start;
            start = nullptr;
        }
        else // CDLL has > 1 elements
        {
            node *ptr = start;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            start = ptr->next;
            delete ptr;
        }
    }
    else // list is empty
        cout<<"Deletion is not possible because linked list is already empty."<<endl;
}
CDLL::~CDLL()
{
    while(start)
        deleteFromBeginning();
}
void CDLL::insertAtEnd(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    if(start) // CDLL has >= 1 elements
    {
        newPtr->prev = start->prev;
        newPtr->next = start;
        start->prev->next = newPtr;
        start->prev = newPtr;
    }
    else // if list is empty
    {
        newPtr->prev = newPtr;
        newPtr->next = newPtr;
        start = newPtr;
    }
}
int main()
{
    CDLL mylist;
    mylist.insertAtEnd(3);
    mylist.insertAtEnd(6);
    mylist.insertAtEnd(9);
    mylist.insertAtEnd(12);
    mylist.insertAtEnd(15);
    mylist.displayList();
    return 0;
}