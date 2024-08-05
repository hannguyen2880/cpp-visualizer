#include "Graphic.h"
#include <vector>
#include <string>

bool DrawCustomButton(Rectangle rect, const char* text, bool isDarkMode) {
    Vector2 mousePoint = GetMousePosition();
    bool hover = CheckCollisionPointRec(mousePoint, rect);
    bool clicked = hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    Color buttonColor, textColor;
    if (!isDarkMode) {
        buttonColor = hover ? ORANGE : PINK;
        textColor = hover ? WHITE : BLACK;
    }
    else {
        buttonColor = hover ? BLUE : PURPLE;
        textColor = hover ? WHITE : DARKBROWN;
    }
    DrawRectangleRec(rect, buttonColor);
    DrawText(text, rect.x + rect.width / 2 - MeasureText(text, 20) / 2, rect.y + rect.height / 2 - 10, 20, textColor);

    return clicked;
}

bool DrawCustomButton2(Rectangle rect, const char* text, bool isDarkMode) {
    Vector2 mousePoint = GetMousePosition();
    bool hover = CheckCollisionPointRec(mousePoint, rect);
    bool clicked = hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    Color buttonColor, textColor;
    if (!isDarkMode) {
        buttonColor = hover ? SKYBLUE : ORANGE;
        textColor = hover ? WHITE : BLACK;
    }
    else {
        buttonColor = hover ? BLUE : SKYBLUE;
        textColor = hover ? WHITE : DARKBROWN;
    }
    DrawRectangleRec(rect, buttonColor);
    DrawText(text, rect.x + rect.width / 2 - MeasureText(text, 20) / 2, rect.y + rect.height / 2 - 10, 20, textColor);
    return clicked;
}
std::vector<std::string> SplitTextIntoLines(const char* text, int maxWidth, int fontSize) {
    std::vector<std::string> lines;
    std::string currentLine;
    std::string word;
    int wordWidth = 0;
    for (const char* p = text; *p != '\0'; ++p) {
        if (*p == ' ' || *p == '\n') {
            if (!word.empty()) {
                if (MeasureText((currentLine + word).c_str(), fontSize) > maxWidth) {
                    lines.push_back(currentLine);
                    currentLine = word + " ";
                }
                else currentLine += word + " ";
                word.clear();
            }
            if (*p == '\n') {
                lines.push_back(currentLine);
                currentLine.clear();
            }
        }
        else word += *p;
    }
    if (!word.empty()) {
        if (MeasureText((currentLine + word).c_str(), fontSize) > maxWidth) {
            lines.push_back(currentLine);
            currentLine = word;
        }
        else currentLine += word;
    }
    if (!currentLine.empty()) lines.push_back(currentLine);
    return lines;
}
void DrawTextInArea(const char* text, int startX, int endX, int startY, bool isDarkMode) {
    int maxWidth = endX - startX;
    int fontSize = 20;
    Color textColor = isDarkMode ? WHITE : BLACK;
    std::vector<std::string> lines = SplitTextIntoLines(text, maxWidth, fontSize);

    int y = startY;
    for (const std::string& line : lines) {
        DrawText(line.c_str(), startX, y, fontSize, textColor);
        y += fontSize + 5;
    }
}
/*void DrawAVLAnimation(AVLTree& tree, int stepIndex, int startX, int endX, int startY, int endY, bool isDarkMode) {
    if (isDarkMode) {
        ClearBackground(DARKGRAY);
    }
    else {
        ClearBackground(RAYWHITE);
    }

    // Display step-by-step information
    DrawText("Step-by-step Insertion Mode", 10, 10, 20, isDarkMode ? LIGHTGRAY : DARKGRAY);
    if (stepIndex < tree.steps.size()) {
        DrawText(("Current Step: " + tree.steps[stepIndex]).c_str(), 30, 480, 20, isDarkMode ? LIGHTGRAY : DARKGRAY);
    }

    // Draw buttons 30 380 420
    if (GuiButton(Rectangle{ 10, 70, 120, 30 }, "Next Step")) {
        if (stepIndex < tree.steps.size() - 1) stepIndex++;
    }
    if (GuiButton(Rectangle{140, 70, 120, 30 }, "Previous Step")) {
        if (stepIndex > 0) stepIndex--;
    }
    if (GuiButton(Rectangle{270, 70, 120, 30 }, "Run to End")) {
        stepIndex = tree.steps.size() - 1;
    }

    // Display the tree with custom parameters
    DrawAVLTree(tree.getRoot(), startX, endX, startY, endY, isDarkMode);
}*/