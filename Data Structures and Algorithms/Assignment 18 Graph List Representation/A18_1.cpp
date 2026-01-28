#include<iostream>
using namespace std;

/*
A18.1 Define a class Graph to implement linked list representation
of graph. Define needful structure for node and class for AdjList.

Problem Summary: define class Graph to implement list representation
of graph. Define node and class AdjList.
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
};
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
