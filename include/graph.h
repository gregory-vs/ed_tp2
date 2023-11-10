#ifndef ED_TP2_GRAPH_H
#define ED_TP2_GRAPH_H
struct listnode {
    int label;
    listnode* next;
    listnode(int l, listnode* n)
    {
        label = l;
        next = n;
    }
    listnode()
    {
        label = 0;
        next = nullptr;
    }
};
class Graph {
public:
    int N;
    listnode **adjList;
    Graph(int numV);
    void addEdge(int from, int to);
    void showGraph();
    void greedyColoring(int colors[]);
};

#endif //ED_TP2_GRAPH_H
