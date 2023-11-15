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
    int isGreedy(int colors[], int nVertix, int nEdges);
    static bool isCompleteGraph(int nVertix, int nEdges);
    int countEdges() const;

private:
    static int getColorPosition(int colors[], int posVertix);
};

#endif //ED_TP2_GRAPH_H
