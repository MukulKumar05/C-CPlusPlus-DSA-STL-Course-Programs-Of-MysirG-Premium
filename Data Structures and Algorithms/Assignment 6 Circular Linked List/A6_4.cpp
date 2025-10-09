#include<iostream>
using namespace std;

/*
A6.4 In question 1, define a method to insert a data into the list
at the end.

(Completed)
*/
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        void insertAtBeginning(int);
        void displayList();
        void deleteFromBeginning();
        ~CLL();
        void insertAtEnd(int);
};
CLL::CLL()
{
    last = nullptr;
}
void CLL::insertAtBeginning(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    if(last) // if list has >=1 elements
    {
        newPtr->next = last->next;
        last->next = newPtr;
    }
    else // if list is empty
    {
        newPtr->next = newPtr;
        last = newPtr;
    }
}
void CLL::displayList()
{
    if(last) // if list has >=1 elements
    {
        cout<<last->next->item<<" ";
        if(last->next != last) // > 1 elements present in list
        {
            node *ptr = last->next->next;
            while(ptr != last->next)
            {
                cout<<ptr->item<<" ";
                ptr = ptr->next;
            }
        }
    }
    else // if list is empty
        cout<<"Linked list is empty"<<endl;
}
void CLL::deleteFromBeginning()
{
    if(last) // CLL has >= 1 elements
    {
        if(last->next == last) // CLL has only 1 element
        {
            delete last;
            last = nullptr;
        }
        else // CLL has > 1 elements
        {
            node *ptr = last->next;
            last->next = ptr->next;
            delete ptr;
        }
    }
    else // CLL is empty
        cout<<"Deletion is not possible because linked list is already empty"<<endl;
}
CLL::~CLL()
{
    while(last)
        deleteFromBeginning();
}
void CLL::insertAtEnd(int data)
{
    node *newPtr = new node;
    newPtr->item = data;
    if(last) // list has >= 1 elements
    {
        newPtr->next = last->next;
        last->next = newPtr;
        last = newPtr;
    }
    else // if list is empty
    {
        newPtr->next = newPtr;
        last = newPtr;
    }
}

int main()
{
    CLL mylist;
    mylist.insertAtEnd(3);
    mylist.insertAtEnd(6);
    mylist.insertAtEnd(9);
    mylist.displayList();
    return 0;
}