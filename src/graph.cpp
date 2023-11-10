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

void Graph::greedyColoring(int colors[])
{
    bool avaliable[N];
    for (int cr = 0; cr < N; ++cr)
        avaliable[cr] = false;

    for (int u = 1; u < N; ++u)
    {
        for (listnode *itr = adjList[u]; itr != nullptr; itr = itr->next)
            if(colors[itr->label] != -1)
                avaliable[colors[itr->label]] = false;
    }

    for (int u = 0; u < N; ++u)
        cout << "Vertice: " << u << "---> Cor " << colors[u] << endl;

}


/*void Graph::colourVertix(int vertix, int colour[])
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
}*/

