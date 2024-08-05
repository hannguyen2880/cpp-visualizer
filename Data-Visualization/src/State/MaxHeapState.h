#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/Heap/MaxHeap.h"

void MaxHeap_InitOption(bool& chosen, bool isDarkMode, AVLTree& tree);
void MaxHeap_InsertOption(bool& chosen, bool isDarkMode, AVLTree& tree);
void MaxHeap_DeleteOption(bool& chosen, bool isDarkMode, AVLTree& tree);
void MaxHeap_SearchOption(bool& chosen, bool isDarkMode, AVLTree& tree);
