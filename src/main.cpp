#include <iostream>
#include <string>
#include "graph.h"
#include "sorting.h"

using namespace std;

int main(int argc,char *argv[])
{
    string sort, vertix = "6", qtNeighbour, nextNeighbour;
    int vertixInt = stoi(vertix);
    int counter = 0;
    int counterNeighbour;
    int posVertix = 0;
    int counterArr = 0;
    int isGreedy;
    int permuttedArray[vertixInt];
    int printedArray[vertixInt];

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

    int edges = g.countEdges();

    int arrayColors[vertixInt];

    for(int i = 0; i < vertixInt; ++i)
    {
        cin >> arrayColors[i];
    }

    isGreedy = Graph::isGreedy(arrayColors, vertixInt, edges);

    for(int i = 0; i  < vertixInt; ++i)
    {
        permuttedArray[i] = arrayColors[i];
    }

    if(isGreedy == 0)
        cout << 0;
    else
    {
        if(sort == "b")
        {
            Sorting::bubbleSort(permuttedArray, vertixInt);
        }
        else if(sort == "s")
        {
            Sorting::selectionSort(permuttedArray, vertixInt);
        }
        else if(sort == "i")
        {
            Sorting::insertionSort(permuttedArray, vertixInt);
        }
        else if(sort == "q")
        {
            Sorting::quickSort(permuttedArray, 0, vertixInt-1);
        }
        else if(sort == "m")
        {
            Sorting::mergeSort(permuttedArray, 0, vertixInt-1);
        }
        else if(sort == "p")
        {
            Sorting::heapSort(permuttedArray, vertixInt);
        }
        else if(sort == "y")
        {

        }

        for(int i = 0; i < vertixInt; ++i)
        {
            for(int j = 0; j < vertixInt; ++j)
            {
                if(arrayColors[i] == permuttedArray[j])
                {
                    printedArray[i] = j;
                }
            }

        }

        cout << "1";

        for(int i = 0; i < vertixInt; ++i)
        {
            cout << " " << printedArray << endl;
        }

    }

    return 0;
}