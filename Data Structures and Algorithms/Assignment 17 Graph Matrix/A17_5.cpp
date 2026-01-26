#include<iostream>
using namespace std;
#define INVALID_VERTICES_COUNT 0
#define INVALID_EDGES_COUNT 1
#define INVALID_NODE_INDEX

/*
A17.5 In question 1, define a method to check if a given node
is isolated node.

Problem Summary: define isIsolatedNode(int nodeIndex)
(Completed)
*/
class Graph
{
    private:
        int v_count, e_count, **adj;
    public:
        Graph();
        void createGraph(int, int, int**);
        ~Graph();
        void printGraphMatrix();
        void printAllAdjacentNodesOfNode(int);
        bool isIsolatedNode(int);
};
Graph::Graph()
{
    v_count = 0;
    e_count = 0;
    adj = nullptr;
}
void Graph::createGraph(int verticesCount, int edgesCount, int **a)
{
    if(verticesCount <= 0)
        throw INVALID_VERTICES_COUNT;
    if(edgesCount < 0)
        throw INVALID_EDGES_COUNT;
    v_count = verticesCount;
    e_count = edgesCount;
    adj = new int*[v_count];
    for(int i = 0; i < v_count; i++)
    {
        adj[i] = new int[v_count];
    }
    for(int i = 0; i < v_count; i++)
    {
        for(int j = 0; j < v_count; j++)
        {
            adj[i][j] = a[i][j];
        }
    }
}
Graph::~Graph()
{
    int i;
    for(i = 0; i < v_count; i++)
    {
        delete []adj[i];
    }
    delete []adj;
}
void Graph::printGraphMatrix()
{
    for(int i = 0; i < v_count; i++)
    {
        for(int j = 0; j < v_count; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::printAllAdjacentNodesOfNode(int nodeIndex)
{
    if(nodeIndex < 0 || nodeIndex >= v_count)
        throw INVALID_NODE_INDEX;
    cout<<"All adjacent nodes of node "<<nodeIndex<<" are: ";
    for(int i = 0; i < v_count; i++)
    {
        if(adj[nodeIndex][i] == 1)
        {
            cout<<i<<", ";
        }
    }
    cout<<"\b\b  ";
    cout<<endl;
}
bool Graph::isIsolatedNode(int nodeIndex)
{
    if(nodeIndex < 0 || nodeIndex >= v_count)
        throw INVALID_NODE_INDEX;
    for(int i = 0; i < v_count; i++)
    {
        if(adj[nodeIndex][i] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Graph g1;
    int arr[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 1, 1, 1, 0}};
    int **a = new int*[5];
    for(int i = 0; i < 5; i++)
    {
        a[i] = new int[5];
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a[i][j] = arr[i][j];
        }
    }
    g1.createGraph(5, 6, a);
    for(int i = 0; i < 5; i++)
    {
        delete []a[i];
    }
    delete []a;
    if(g1.isIsolatedNode(3))
        cout<<"This node is an isolated node."<<endl;
    else
        cout<<"This node is not an isolated node."<<endl;
    return 0;
}