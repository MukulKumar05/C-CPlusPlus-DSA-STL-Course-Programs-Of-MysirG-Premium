#include<iostream>
using namespace std;

/*
A4.5 In question 1, define a method to search a node with the
given item.

(Completed)
*/

struct node
{
    int item;
    node *next;
};

class SLL
{
    private:
        node *start;
    protected:
        void deallocateNodeByNodeFromAddress(node *st)
        {
            if(st)
            {
                deallocateNodeByNodeFromAddress(st->next);
            }
            delete st;
        }
    public:
        SLL()
        {
            start = nullptr;
        }
        void insertAtBeginning(int data)
        {
            if(start)
            {
                node *newPtr = new node;
                newPtr->next = start;
                start = newPtr;
                start->item = data;
            }
            else
            {
                start = new node;
                start->next = nullptr;
                start->item = data;
            }
        }
        void insertAtEnd(int data)
        {
            if(start)
            {
                node *ptr = start;
                while(ptr->next)
                {
                    ptr = ptr->next;
                }
                ptr->next = new node;
                ptr->next->next = nullptr;
                ptr->next->item = data;
            }
            else
            {
                start = new node;
                start->next = nullptr;
                start->item = data;
            }
        }
        ~SLL()
        {
            deallocateNodeByNodeFromAddress(start);
        }
        void displayElements()
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
        void searchItemInList(int itemToSearch)
        {
            if(start == nullptr)
                cout<<itemToSearch<<" not found in linked list."<<endl;
            else
            {
                node *ptr = start;
                while(ptr)
                {
                    if(ptr->item == itemToSearch)
                    {
                        cout<<itemToSearch<<" found in linked list."<<endl;
                        break;
                    }
                    ptr = ptr->next;
                }
                if(ptr == nullptr)
                    cout<<itemToSearch<<" not found in linked list."<<endl;
            }
        }
};

int main()
{
    SLL mylist;
    mylist.insertAtEnd(3);
    mylist.insertAtEnd(6);
    mylist.insertAtEnd(9);
    mylist.displayElements();
    cout<<endl;
    mylist.searchItemInList(9);
    return 0;
}