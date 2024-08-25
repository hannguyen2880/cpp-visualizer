// Graphic.h
#pragma once
#include <raylib.h>
#include "raygui.h"
#include "tinyfiledialogs.h"
#include <fstream>
#include <vector>
#include <sstream>

void DrawTextRectangle(const char* txt, Rectangle rect, int fontSize, bool isDarkMode, Color dark, Color bright);
bool DrawCustomButton(Rectangle rect, const char* text, bool isDarkMode);
bool DrawCustomButton2(Rectangle rect, const char* text, bool isDarkMode);
void DrawTextInArea(const char* text, int startX, int endX, int startY, bool isDarkMode);
std::vector<std::string> SplitTextIntoLines(const char* text, int maxWidth, int fontSize, Font font);
void DrawTextInArea2(const char* text, int startX, int endX, int startY, bool isDarkMode, Font font);
