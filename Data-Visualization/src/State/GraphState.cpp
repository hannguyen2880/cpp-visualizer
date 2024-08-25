#include "GraphState.h"
#include <set>
bool showEmptyMessGraph = false, showRandomMessGraph = false;
bool showFileMatrixMessGraph = false;

struct Edge {
	int u, v;
	bool operator<(const Edge& other) const {
		return std::tie(u, v) < std::tie(other.u, other.v);
	}
};

int nUpdate = 0;
void Graph_InitOption(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
	static bool initialized = false;

	// Empty graph (clear)
	if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Clear", isDarkMode)) {
		graph.deleteGraph();
		initialized = false;
		showEmptyMessGraph = true;
	}
	
	if (showEmptyMessGraph) {
		DrawTextInArea("An empty graph has been created.", 30, 380, 600, isDarkMode);
		showRandomMessGraph = false;
		showFileMatrixMessGraph = false;
		nUpdate = 0;
	}
	
	// Init from file (from matrix)
	if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "File (from matrix)", isDarkMode)) {
		const char* fileName = tinyfd_openFileDialog("File (from matrix)", "", 0, NULL, NULL, 0);
		if (fileName) {
			graph.deleteGraph();
			readGraphFromMatrixFile(fileName, graph);
		}
		showFileMatrixMessGraph = true;
		initialized = true;
	}
	if (showFileMatrixMessGraph) {
		DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 600, isDarkMode);
		showRandomMessGraph = false;
		showEmptyMessGraph = false;
	}
	
	// Randomized Graph
	if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Random Graph", isDarkMode)) {
		graph.deleteGraph();
		int nVertex = GetRandomValue(3, 8);
		for (int i = 1; i <= nVertex; ++i) graph.vertices.insert(i);
		std::set<Edge> existingEdges;

		
		for (int i = 1; i <= nVertex; ++i) {
			int n = GetRandomValue(1, nVertex);
			for (int j = 1; j <= n; ++j) {
				int toVertex = GetRandomValue(1, nVertex);
				if (toVertex != i) { 
					Edge edge = { std::min(i, toVertex), std::max(i, toVertex) };

					if (existingEdges.find(edge) == existingEdges.end()) {
						int weight = GetRandomValue(1, 50); 		
						graph.addEdge(i, toVertex, weight); 

						existingEdges.insert(edge);
					}
				}
			}
		}
		showRandomMessGraph = true;
		initialized = true;
	}
	if (showRandomMessGraph) {
		DrawTextInArea("A random graph has been created.", 30, 380, 600, isDarkMode);
		showEmptyMessGraph = false;
		showFileMatrixMessGraph = false;
	}
	
	if (initialized) {
		std::cout << "Initializing positions..." << std::endl;
		graph.initializePositions(400, 1400, 150, 700);
		initialized = false;
	}


	static int nUpdate = 0;
	//std::cout << "Drawing graph..." << std::endl;
	graph.drawGraph(400, 1400, 150, 700, isDarkMode, nUpdate);
}

void ConnectedComponent_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
	std::vector<std::vector<int>> components = graph.connectedComponents();
	
	graph.drawGraphComponents(components, 400, 1400, 150, 700, isDarkMode);
}

void MST_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
	std::vector<std::pair<int, int>> mstEdges = graph.mst();
	graph.drawGraphMST(mstEdges, 400, 1400, 150, 700, isDarkMode);
	//....
	int total = 0;
	for (auto pair : mstEdges) {
		for (int i = 0; i < graph.adjList[pair.first].size(); ++i) {
			int v = graph.adjList[pair.first][i].second;
			if (v == pair.second) {
				total += graph.adjList[pair.first][i].first;
				break;
			}
		}
	}
	std::string msg = "The minimum cost is " + std::to_string(total);
	DrawTextInArea(msg.c_str(), 30, 380, 600, isDarkMode);
}