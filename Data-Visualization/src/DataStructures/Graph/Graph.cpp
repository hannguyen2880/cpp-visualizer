#include "Graph.h"

void Graph::addEdge(int u, int v, int w) {
    adjList[u].push_back({w, v});
    adjList[v].push_back({w, u});  // For undirected graph
}

int Graph::getVertex() {
    return nVertex;
}
int Graph::getEdge() {
    return nEdge;
}
/*
void Graph::BFS(int start) {
    std::unordered_map<int, bool> visited;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        std::cout << node << " ";
        q.pop();

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}*/

void Graph::deleteGraph() {
    adjList.clear();
}
