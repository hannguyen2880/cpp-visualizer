#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/AVL/AVLTree.h"
#include "../DataStructures/AVL/AVL_Draw.h"

void AVL_InitOption(bool& chosen, bool isDarkMode, AVLTree& tree);
void AVL_InsertOption(bool& chosen, bool isDarkMode, AVLTree& tree);
