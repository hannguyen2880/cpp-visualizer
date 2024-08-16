#include "GraphState.h"
bool showEmptyMessGraph = false, showRandomMessGraph = false;
bool showFileMatrixMessGraph = false, showFileAdjMessGraph = false;

void Graph_InitOption(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;

	// Empty graph (clear)
	if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Clear", isDarkMode)) {
		graph.deleteGraph();
		showEmptyMessGraph = true;
	}
	
	if (showEmptyMessGraph) {
		DrawTextInArea("An empty graph has been created.", 30, 380, 420, isDarkMode);
		showRandomMessGraph = false;
		showFileMatrixMessGraph = false;
		showFileAdjMessGraph = false;
	}
	
	// Init from file (from matrix)
	
	// Init from file (from adjective array)
	
	// Randomized Graph

}
void ConnectedComponent_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
}
void MST_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
}