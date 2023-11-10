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

    Graph g(vertixInt);

    while(counter < vertixInt)
    {
        cin >> qtNeighbour;
        counterNeighbour = 0;

        while(counterNeighbour < stoi(qtNeighbour))
        {
            cin >> nextNeighbour;
            g.addEdge(posVertix, stoi(nextNeighbour));
            ++counterNeighbour;
            ++counterArr;
        }

        ++posVertix;
        ++counter;
    }

    g.showGraph();

    return 0;
}