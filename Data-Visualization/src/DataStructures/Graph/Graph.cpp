#include "Graph.h"
const int inf = 2e9;

void Graph::addEdge(int u, int v, int w) {
    adjList[u].push_back({ w, v });
    adjList[v].push_back({ w, u });
    vertices.insert(u);
    vertices.insert(v);
}
int Graph::getVertexCount() {
    return vertices.size();
}

void Graph::dfs(int v, std::unordered_map<int, bool>& visited, std::vector<int>& component) {
    visited[v] = true;
    component.push_back(v);

    for (const auto& neighbor : adjList[v]) {
        if (!visited[neighbor.second]) {
            dfs(neighbor.second, visited, component);
        }
    }
}

std::vector<std::vector<int>> Graph::connectedComponents() {
    std::unordered_map<int, bool> visited;
    std::vector<std::vector<int>> components;

    for (int vertex : vertices) visited[vertex] = false;

    for (int vertex : vertices) {
        if (!visited[vertex]) {
            std::vector<int> component;
            dfs(vertex, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

std::vector<pii> Graph::mst() {
    std::vector<pii> mstEdges;
    if (vertices.empty()) return mstEdges;

    std::unordered_map<int, int> key, parent, inMST;

    for (int vertex : vertices) {
        key[vertex] = inf;
        parent[vertex] = -1;
        inMST[vertex] = false;
    }

    int startVertex = *vertices.begin();
    key[startVertex] = 0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({ 0, startVertex });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (int i = 0; i < adjList[u].size(); ++i) {
            int weight = adjList[u][i].first;
            int v = adjList[u][i].second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({ key[v], v });
                parent[v] = u;
            }
        }
    }
    
    for (const auto& pair : parent) {
        int v = pair.first;
        int p = pair.second;
        if (p != -1) {
            mstEdges.push_back({ p, v });
        }
    }

    return mstEdges;
}

void Graph::deleteGraph() {
    adjList.clear();
    positions.clear();
    velocities.clear();
    forces.clear();
    vertices.clear();
}

void Graph::initializePositions(int startX, int endX, int startY, int endY) {
    int width = endX - startX;
    int height = endY - startY;

    for (int vertex : vertices) {
        float x = startX + std::rand() % width;
        float y = startY + std::rand() % height;
        positions[vertex] = Vector2{ x, y };
        velocities[vertex] = Vector2{ 0, 0 };
        forces[vertex] = Vector2{ 0, 0 };
    }
}

void Graph::updatePositions() {
    const float repulsion = 100.0f;
    const float attraction = 0.1f;
    const float damping = 0.85f;    // velocity decreasing

    for (auto& pair : forces) {
        int node = pair.first;
        Vector2 force = pair.second;
        force = Vector2{ 0, 0 };
    }
    

    // Calculate repulsion
    for (auto it1 = vertices.begin(); it1 != vertices.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != vertices.end(); ++it2) {
            Vector2 direction = Vector2Subtract(positions[*it1], positions[*it2]);
            float distance = Vector2Length(direction);
            if (distance == 0) distance = 0.1f; // Avoid dividing by 0
            Vector2 repulsiveForce = Vector2Scale(Vector2Normalize(direction), repulsion / (distance * distance));
            forces[*it1] = Vector2Add(forces[*it1], repulsiveForce);
            forces[*it2] = Vector2Subtract(forces[*it2], repulsiveForce);
        }
    }

    // Calculate attraction
    for (const auto& pair : adjList) {
        int u = pair.first;
        std::vector<pii> neighbors = pair.second;
        for (const auto& neighbor : neighbors) {
            int weight = neighbor.first;
            int v = neighbor.second;
            Vector2 direction = Vector2Subtract(positions[v], positions[u]);
            float distance = Vector2Length(direction);
            Vector2 attractiveForce = Vector2Scale(Vector2Normalize(direction), attraction * distance);
            forces[u] = Vector2Add(forces[u], attractiveForce);
            forces[v] = Vector2Subtract(forces[v], attractiveForce);
        }
    }

    // update velocity and position
    for (int vertex : vertices) {
        velocities[vertex] = Vector2Add(velocities[vertex], forces[vertex]);
        velocities[vertex] = Vector2Scale(velocities[vertex], damping);
        positions[vertex] = Vector2Add(positions[vertex], velocities[vertex]);
    }
}

void Graph::drawGraph(int startX, int endX, int startY, int endY, bool isDarkMode) {
    initializePositions(startX, endX, startY, endY);

    Color bgColor = isDarkMode ? DARKGRAY : RAYWHITE;
    Color nodeColor = isDarkMode ? LIGHTGRAY : DARKBLUE;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color edgeColor = GRAY;

    updatePositions();
    for (const auto& pair : adjList) {
        int u = pair.first;
        for (const auto& nei : pair.second) {
            int weight = nei.first;
            int v = nei.second;
            if (positions.count(u) && positions.count(v)) {
                DrawLineEx(positions[u], positions[v], 2.0f, edgeColor);
            }
        }
    }

    for (const auto& position : positions) {
        int vertex = position.first;
        Vector2 pos = position.second;
        if (pos.x >= startX && pos.x <= endX && pos.y >= startY && pos.y <= endY) {
            DrawCircleV(pos, 20, nodeColor);
            DrawText(TextFormat("%d", vertex), pos.x - 5, pos.y - 10, 10, textColor);
        }
    }
}
