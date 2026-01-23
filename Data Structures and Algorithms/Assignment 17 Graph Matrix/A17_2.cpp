#include<iostream>
using namespace std;
#define INVALID_VERTICES_COUNT 0
#define INVALID_EDGES_COUNT 1

/*
A17.2 In question 1, define a method createGraph() to create and store
adjacent node information.

Problem Summary:
define createGraph() to create and store adjacent node information.
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
    // for(int i = 0; i < v_count; i++)
    // {
    //     for(int j = 0; j < v_count; j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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
    return 0;
}