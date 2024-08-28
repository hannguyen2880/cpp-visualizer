#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/AVL/AVLTree.h"

void AVL_InitOption(bool& chosen, bool isDarkMode, AVLTree& tree);
void AVL_InsertOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLStateInsert& state);
void AVL_DeleteOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLStateDelete& state);
void AVL_SearchOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLState& state);