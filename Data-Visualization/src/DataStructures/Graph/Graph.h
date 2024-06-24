#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;

public:
    void addEdge(int u, int v);
    void BFS(int start);
};

#endif
