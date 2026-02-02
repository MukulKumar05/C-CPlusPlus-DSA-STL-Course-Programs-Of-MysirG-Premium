#include<iostream>
using namespace std;
#define INVALID_VERTICES_COUNT 0
#define INVALID_VERTEX 1

/*
A18.6 Define destructors in the classes AdjList and Graph.

Problem Summary: Define ~AdjList() and ~Graph()
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
        void createGraph(int);
        void addEdge(int, int);
        ~Graph();
        void printGraph();
};
Graph::Graph()
{
    v_count = 0;
    arr = nullptr;
}
void Graph::createGraph(int verticesCount)
{
    if(verticesCount <= 0)
        throw INVALID_VERTICES_COUNT;
    v_count = verticesCount;
    arr = new AdjList[v_count];
}
void Graph::addEdge(int node1Item, int node2Item)
{
    if(node1Item < 0 || node1Item >= v_count)
        throw INVALID_VERTEX;
    if(node2Item < 0 || node2Item >= v_count)
        throw INVALID_VERTEX;
    arr[node1Item].insertAtEnd(node2Item);
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::printGraph()
{
    if(arr) // if graph arr is pointing to the array of AdjList objects
    {
        int i;
        for(i = 0; i < v_count; i++)
        {
            cout<<"Vertex "<<i<<": ";
            arr[i].displayElements();
            cout<<endl;
        }
    }
    else
        cout<<"Graph is empty."<<endl;
}

int main()
{
    Graph g1;
    g1.createGraph(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(1, 4);
    g1.addEdge(2, 0);
    g1.addEdge(2, 1);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(3, 2);
    g1.addEdge(4, 1);
    g1.addEdge(4, 2);
    g1.printGraph();
    return 0;
}