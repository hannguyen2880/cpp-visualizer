#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/Graph/Graph.h"
#include "../Graphic.h"

void Graph_InitOption(bool& chosen, bool isDarkMode, Graph& graph);
void ConnectedComponent_Option(bool& chosen, bool isDarkMode, Graph& graph);
void MST_Option(bool& chosen, bool isDarkMode, Graph& graph);
