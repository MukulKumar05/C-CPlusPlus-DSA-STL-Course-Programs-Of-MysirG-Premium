#include<iostream>
using namespace std;

/*
A4.3 In question 1, define a method to insert a data into the list at the
beginning.

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
};

int main()
{
    SLL mylist;
    mylist.insertAtBeginning(3);
    mylist.insertAtBeginning(6);
    mylist.insertAtBeginning(9);
    mylist.displayElements();
    return 0;
}