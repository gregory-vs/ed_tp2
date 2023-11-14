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

int Graph::countEdges() const
{
    int sum = 0;
    int countNeighbors;

    for(int i = 0; i < N; ++i) {
        countNeighbors = 0;
        for (listnode *itr = adjList[i]; itr != nullptr; itr = itr->next)
            ++countNeighbors;

        sum += countNeighbors;
    }
    return sum/2;
}

int Graph::isGreedy(int colors[], int nVertix, int nEdges)
{
    int isGreedy = 0;

    if(isCompleteGraph(nVertix, nEdges))
        return 1;

    for(int i = 0; i < N; ++i)
    {
        if(adjList[i] != nullptr)
        {
            for (listnode* itr = adjList[i]; itr != nullptr; itr = itr->next)
            {
                if(colors[i] == colors[adjList[i]->label])
                {
                    return 0;
                }
                if(colors[i] > 1 && adjList[i]->next != nullptr && adjList[i]->next->next == nullptr)
                {
                    isGreedy = 1;
                }
                if(colors[i] > 1 && adjList[i]->next != nullptr && colors[adjList[i]->next->label] != 1)
                {
                    isGreedy = 0;
                }
            }
        }
    }
}

bool Graph::isCompleteGraph(int nVertix, int nEdges)
{
    int formuleGraphs = (nVertix*(nVertix-1))/2;

    if(formuleGraphs == nEdges)
        return true;

    return false;
}


