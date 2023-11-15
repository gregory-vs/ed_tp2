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
    size_t sizeColorsByte = sizeof(colors);
    size_t sizeColors = sizeColorsByte / sizeof(int);

    if(isCompleteGraph(nVertix, nEdges))
        return 1;

    for(int i = 0; i < N; ++i)
    {
        listnode* temp = adjList[i];
        int *neighbors = (int *)malloc(sizeof(int));

        int count = 0;
        while(temp != nullptr)
        {
            neighbors[count] = temp->label;
            ++count;
            temp = temp->next;
        }

        size_t sizeNeighborsByte = sizeof(neighbors);
        size_t sizeNeighbors = sizeNeighborsByte/sizeof(int);

        for(int j = 0; j < sizeColors; ++j)
        {
            for(int k = 0; k < sizeNeighbors; ++k)
            {
                if(colors[j] == colors[neighbors[k]] && j != neighbors[k])
                    return 0;
            }

        }
        free(neighbors);
    }

    return 1;
}

bool Graph::isCompleteGraph(int nVertix, int nEdges)
{
    int formuleGraphs = (nVertix*(nVertix-1))/2;

    if(formuleGraphs/2 == nEdges)
        return true;

    return false;
}

int Graph::getColorPosition(int colors[], int posVertix)
{
    return colors[posVertix];
}
