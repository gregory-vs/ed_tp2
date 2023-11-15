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
        listnode* temp2 = adjList[i];
        int numNeighbors = 0;
        while(temp != nullptr)
        {
            ++numNeighbors;
            temp = temp->next;
        }

        int neighbors[numNeighbors];
        int count = 0;
        while(temp2 != nullptr)
        {
            neighbors[count] = temp2->label;
            ++count;
            temp2 = temp2->next;
        }

        for(int k = 0; k < numNeighbors; ++k)
        {
            if(colors[i] == colors[neighbors[k]] && i != neighbors[k])
                return 0;
        }

        int colorsNeighbors[numNeighbors];
        for(int k = 0; k < numNeighbors; ++k)
            colorsNeighbors[k] = colors[neighbors[k]];

        for(int k = 0; k < numNeighbors; ++k)
        {
            int actualColor = colorsNeighbors[k];
            if(colors[i] == actualColor)
                return 0;

//            if(colors[i] != 1)
//                if(colors[i] < actualColor)
//                    return 0;
        }
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

int Graph::canBeLesser(int actualVertixColor, int colorsNeighbors[])
{

}
