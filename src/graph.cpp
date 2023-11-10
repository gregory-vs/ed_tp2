#include <iostream>
#include "graph.h"

Graph::Graph(int v)
{
    this->vertix = v;
    list = new List[v];
}

Graph::~Graph()
{

}

void Graph::addEdge(int v, int nextVertix)
{
    list[v].push(list[v],nextVertix);
    list[nextVertix].push(list[nextVertix], v);
}
