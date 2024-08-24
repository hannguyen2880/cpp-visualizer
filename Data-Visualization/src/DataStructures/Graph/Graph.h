#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "raylib.h"
#include "../../raylib_conf.h"

typedef std::pair<int, int> pii;

class Graph {
private:
    std::unordered_map<int, std::vector<pii>> adjList;
    std::unordered_map<int, Vector2> positions;
    std::unordered_map<int, Vector2> velocities;
    std::unordered_map<int, Vector2> forces;
    std::unordered_set<int> vertices;
    void dfs(int v, std::unordered_map<int, bool>& visited, std::vector<int>& component);

public:
    Graph() {};
    void addEdge(int u, int v, int w);
    void drawGraph(int startX, int endX, int startY, int endY, bool isDarkMode);
    void initializePositions(int startX, int endX, int startY, int endY);
    void updatePositions();
    int getVertexCount();
    std::vector<std::vector<int>> connectedComponents();
    std::vector<pii> mst();
    void deleteGraph();
};
#endif
