#include <iostream>
#include <string>
#include "List.h"
#include "graph.h"

using namespace std;

int main(int argc,char *argv[])
{
    string sort, vertix = "5", qtNeighbour, nextNeighbour;
    int vertixInt = stoi(vertix);
    int counter = 1;
    int counterNeighbour;
    int posVertix = 0;

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
        }

        ++posVertix;
        ++counter;
    }

    return 0;
}