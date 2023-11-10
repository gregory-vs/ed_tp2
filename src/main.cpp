#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main(int argc,char *argv[])
{
    string sort, vertix = "6", qtNeighbour, nextNeighbour;
    int vertixInt = stoi(vertix);
    int counter = 0;
    int counterNeighbour;
    int posVertix = 0;
    int counterArr = 0;
    int qtEdges = (vertixInt*(vertixInt-1))/2;

    Edge *edges = new Edge[qtEdges];

    while(counter < vertixInt)
    {
        cin >> qtNeighbour;
        counterNeighbour = 0;

        while(counterNeighbour < stoi(qtNeighbour))
        {
            cin >> nextNeighbour;
            edges[counterArr].src = posVertix;
            edges[counterArr].dest = stoi(nextNeighbour);
            ++counterNeighbour;
            ++counterArr;
        }

        ++posVertix;
        ++counter;
    }

    int j = 0;
    int k = 0;
    while(j < qtEdges)
    {
        if(edges[j].src == edges[j].dest)
        {
            ++k;
        }
        ++j;
    }

    int correctedQtEdges = qtEdges - k;

    Graph graph(edges, correctedQtEdges, vertixInt);

    int arrayColors[vertixInt];

    for(int i = 0; i < vertixInt; ++i)
    {
        cin >> arrayColors[i];
    }

    for (int i = 0; i < vertixInt; i++)
    {
        graph.head[i]->color = arrayColors[i];
    }

    for (int i = 0; i < vertixInt; i++)
    {
        // print given vertex
        cout << "vertice: " << i << " cor: " << graph.head[i]->color << endl;
    }

    return 0;
}