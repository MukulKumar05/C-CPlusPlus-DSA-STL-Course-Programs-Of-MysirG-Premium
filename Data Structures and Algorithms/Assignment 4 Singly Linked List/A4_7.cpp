#include<iostream>
using namespace std;

/*
A4.7 In question 1, define a method to delete first node from the list.

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
        bool isItemFoundInList(int itemToSearch)
        {
            if(start == nullptr)
                return false;
            else
            {
                node *ptr = start;
                while(ptr)
                {
                    if(ptr->item == itemToSearch)
                    {
                        return true;
                        break;
                    }
                    ptr = ptr->next;
                }
                if(ptr == nullptr)
                    return false;
            }
        }
        void insertAfterListItem(int listItem, int data)
        {
            if(isItemFoundInList(listItem))
            {
                node *ptr = start;
                while(ptr)
                {
                    if(ptr->item == listItem)
                    {
                        node *newPtr = new node;
                        newPtr->next = ptr->next;
                        ptr->next = newPtr;
                        newPtr->item = data;
                        break;
                    }
                    ptr = ptr->next;
                }
            }
            else
            {
                cout<<"Cannot do insertion because item "<<listItem<<" not found in list."<<endl;
            }
        }
        void deleteFirstNode()
        {
            if(start)
            {
                node *ptr = start;
                start = start->next;
                delete ptr;
            }
            else
                cout<<"Deletion not possible because linked list is already empty."<<endl;
        }
};

int main()
{
    SLL mylist;
    mylist.insertAtEnd(3);
    mylist.insertAfterListItem(3, 8);
    mylist.insertAfterListItem(3, 7);
    mylist.insertAfterListItem(8, 11);
    mylist.insertAfterListItem(3, 92);
    mylist.deleteFirstNode();
    mylist.deleteFirstNode();
    mylist.deleteFirstNode();
    mylist.deleteFirstNode();
    mylist.deleteFirstNode();
    mylist.deleteFirstNode();
    mylist.displayElements();
    return 0;
}