#include<iostream>
using namespace std;

/*
A18.2 Define appropriate constructors in the classes AdjList
and Graph.

Problem Summary: define AdjList() and Graph()
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
};
AdjList::AdjList()
{
    start = nullptr;
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