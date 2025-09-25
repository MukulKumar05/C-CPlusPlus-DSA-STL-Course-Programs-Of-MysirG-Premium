#include<iostream>
using namespace std;

/*
A4.10 In question 1, define a destructor to deallocates memory for all
the nodes in the linked list.

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
        void deleteLastNode()
        {
            if(start)
            {
                if(start->next)
                {
                    node *ptr = start;
                    node *prevPtr = start;
                    while(ptr->next)
                    {
                        prevPtr = ptr;
                        ptr = ptr->next;
                    }
                    prevPtr->next = nullptr;
                    delete ptr;
                }
                else
                {
                    node *ptr = start;
                    start = nullptr;
                    delete ptr;
                }
            }
            else
                cout<<"Deletion not possible because linked list is already empty."<<endl;
        }
        void deleteNodewithItem(int listItem)
        {
            if(isItemFoundInList(listItem))
            {
                if(start->item == listItem)
                {
                    node *ptr = start;
                    start = start->next;
                    delete ptr;
                }
                else
                {
                    node *ptr = start;
                    node *prevPtr = start;
                    while(ptr)
                    {
                        if(ptr->item == listItem)
                        {
                            // coding to do when specific node found
                            prevPtr->next = ptr->next;
                            delete ptr;
                            break;
                        }
                        prevPtr = ptr;
                        ptr = ptr->next;
                    }
                }
            }
            else
            {
                cout<<"Cannot do deletion because item "<<listItem<<" not found in list."<<endl;
            }
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
    mylist.displayElements();
    return 0;
}