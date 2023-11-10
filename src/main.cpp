#include <iostream>
#include <string>
#include "List.h"
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
    
    return 0;
}