#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
typedef std::pair<int, int> pii; // first: weight, second: vertex

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>


class Graph {
private:
    int nVertex, nEdge;
    std::unordered_map<int, std::list<pii>> adjList;
    //void connected_Components();
    //void MST();

public:
    void addEdge(int u, int v, int w);
    int getVertex();
    int getEdge();
    //void BFS(int start);
    void deleteGraph();
    //void connectedComponents();
    //void mst();
};

#endif
