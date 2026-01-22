#include<iostream>
using namespace std;

/*
A17.1 Define a class Graph using matrix representation with
v_count, e_count and adj pointer as instance members.

Problem Summary:
define class Graph using matrix method with 
v_count, e_count and adj pointer as instance members.
(Completed)
*/
class Graph
{
    private:
        int v_count, e_count, **adj;
    public:
        Graph();
};
Graph::Graph()
{
    v_count = 0;
    e_count = 0;
    adj = nullptr;
}

int main()
{
    Graph g1;
    return 0;
}
