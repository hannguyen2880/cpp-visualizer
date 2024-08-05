// Graphic.h
#pragma once
#include <raylib.h>
#include "raygui.h"
#include "tinyfiledialogs.h"
#include "DataStructures/AVL/AVLTree.h"

bool DrawCustomButton(Rectangle rect, const char* text, bool isDarkMode);
bool DrawCustomButton2(Rectangle rect, const char* text, bool isDarkMode);
void DrawTextInArea(const char* text, int startX, int endX, int startY, bool isDarkMode);
