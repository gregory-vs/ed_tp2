#include <iostream>
#include "List.h"

#ifndef ED_TP2_GRAPH_H
#define ED_TP2_GRAPH_H
class Graph {

    int vertix;
    List *list;

public:
    explicit Graph(int v); // constructor
    ~Graph(); // destructor
    void addEdge(int v, int nextVertix);
};


#endif //ED_TP2_GRAPH_H
