#include "Graph.h"

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);  // For undirected graph
}

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
}
