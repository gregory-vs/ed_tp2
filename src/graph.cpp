#include <iostream>
#include "graph.h"

using namespace std;

GraphNode* Graph::getAdjListNode(int dest, GraphNode* head)
{
    auto* newNode = new GraphNode;
    newNode->val = dest;

    // point new node to the current head
    newNode->next = head;

    return newNode;
}

Graph::Graph(Edge edges[], int n, int N)
{
    // allocate memory
    head = new GraphNode*[N]();
    this->N = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
        head[i] = nullptr;
    }

    // add edges to the directed graph
    for (unsigned i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        // insert at the beginning
        GraphNode* newNode = getAdjListNode(dest, head[src]);

        // point head pointer to the new node
        head[src] = newNode;

    }
}

Graph::~Graph() {
    for (int i = 0; i < N; i++) {
        delete[] head[i];
    }

    delete[] head;
}

void Graph::colorTheGraph(GraphNode* ptr, int color)
{
    while (ptr != nullptr)
    {
        ptr->val = color;
        ptr = ptr->next;
    }
}