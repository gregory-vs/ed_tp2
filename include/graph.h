#include "List.h"

#ifndef ED_TP2_GRAPH_H
#define ED_TP2_GRAPH_H
struct GraphNode
{
    int val;
    GraphNode* next;
};

struct Edge {
    int src, dest;
};

class Graph
{
    // Function to allocate a new node for the adjacency list
    static GraphNode* getAdjListNode(int dest, GraphNode* head);
    int N;    // total number of nodes in the graph

public:
    // An array of pointers to Node to represent the adjacency list
    GraphNode **head;
    // Constructor
    Graph(Edge edges[], int n, int N);
    // Destructor
    ~Graph();
    // Function to print all neighboring vertices of a given vertex
    static void printList(GraphNode* ptr);
};

#endif //ED_TP2_GRAPH_H
