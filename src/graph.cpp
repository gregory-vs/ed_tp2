#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(int numV)
{
    N = numV;
    adjList = new listnode*[N];
    for (int i = 0; i < N; i++)
        adjList[i] = nullptr;
}
void Graph::addEdge(int from, int to)
{
    adjList[from] = new listnode(to, adjList[from]);
}

void Graph::showGraph()
{
    for (int i = 0; i < N; i++)
    {
        if (adjList[i] != nullptr)
        {
            cout<<i<<": ";
            for (listnode* itr = adjList[i]; itr != nullptr; itr = itr->next)
            {
                cout<<itr->label<<" ";
            }
            cout<<endl;
        }
    }
}

void Graph::colourVertix(int vertix, int colour)
{

}