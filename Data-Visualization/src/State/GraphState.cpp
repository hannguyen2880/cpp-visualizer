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
		DrawTextInArea("An empty graph has been created.", 30, 380, 600, isDarkMode);
		showRandomMessGraph = false;
		showFileMatrixMessGraph = false;
		showFileAdjMessGraph = false;
	}
	
	// Init from file (from matrix)
	if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "File (from matrix)", isDarkMode)) {
		//graph.deleteGraph();...........
		showFileMatrixMessGraph = true;
	}
	if (showFileMatrixMessGraph) {
		DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 600, isDarkMode);
		showRandomMessGraph = false;
		showEmptyMessGraph = false;
		showFileAdjMessGraph = false;
	}
	// Init from file (from adjective list)
	if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "File (from list)", isDarkMode)) {
		//graph.deleteGraph();.............
		showFileAdjMessGraph = true;
	}
	if (showFileAdjMessGraph) {
		DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 600, isDarkMode);
		showRandomMessGraph = false;
		showEmptyMessGraph = false;
		showFileMatrixMessGraph = false;
	}
	// Randomized Graph
	if (DrawCustomButton2(Rectangle{ 180, 300, 180, 50 }, "Random Graph", isDarkMode)) {
		//graph.deleteGraph();............
		showRandomMessGraph = true;
	}
	if (showRandomMessGraph) {
		DrawTextInArea("A random graph has been created.", 30, 380, 600, isDarkMode);
		showFileAdjMessGraph = false;
		showEmptyMessGraph = false;
		showFileMatrixMessGraph = false;
	}
}
void ConnectedComponent_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
}
void MST_Option(bool& chosen, bool isDarkMode, Graph& graph) {
	if (!chosen) return;
}