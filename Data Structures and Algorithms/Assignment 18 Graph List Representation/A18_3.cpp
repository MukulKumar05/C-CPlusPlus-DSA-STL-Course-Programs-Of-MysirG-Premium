#include<iostream>
using namespace std;

/*
A18.3 Define appropriate methods to manage linked list
in AdjList.

Problem Summary: define methods to manage linked list in AdjList.
(Completed)
*/
struct node
{
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
    public:
        AdjList();
        void insertAtEnd(int);
        void deleteNodewithItem(int);
        bool isItemFoundInList(int);
        void displayElements();
        ~AdjList();
};
AdjList::AdjList()
{
    start = nullptr;
}
void AdjList::insertAtEnd(int data)
{
    if(start) // list has >= 1 elements
    {
        node *ptr = start;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = new node;
        ptr->next->next = nullptr;
        ptr->next->vertex = data;
    }
    else // list is empty
    {
        start = new node;
        start->next = nullptr;
        start->vertex = data;
    }
}
bool AdjList::isItemFoundInList(int itemToSearch)
{
    if(start == nullptr)
        return false;
    else
    {
        node *ptr = start;
        while(ptr)
        {
            if(ptr->vertex == itemToSearch)
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
void AdjList::deleteNodewithItem(int listItem)
{
    if(isItemFoundInList(listItem))
    {
        if(start->vertex == listItem)
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
                if(ptr->vertex == listItem)
                {
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
void AdjList::displayElements()
{
    if(start == nullptr)
        cout<<"Linked list is empty."<<endl;
    else
    {
        node *ptr = start;
        while(ptr)
        {
            cout<<ptr->vertex<<" ";
            ptr = ptr->next;
        }
    }
}
AdjList::~AdjList()
{
    while(start)
        deleteNodewithItem(start->vertex);
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
};
Graph::Graph()
{
    v_count = 0;
    arr = nullptr;
}

int main()
{
    Graph g1;
    return 0;
}