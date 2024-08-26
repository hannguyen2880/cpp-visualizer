#include "Graphic.h"
#include <vector>
#include <string>

void DrawTextRectangle(const char* txt, Rectangle rect, int fontSize, bool isDarkMode, Color dark, Color bright) {
    int textWidth = MeasureText(txt, fontSize);
    int textHeight = fontSize;

    int textX = rect.x + (rect.width - textWidth) / 2;
    int textY = rect.y + (rect.height - textHeight) / 2;

    Color color = isDarkMode ? dark : bright;
    DrawText(txt, textX, textY, fontSize, color);
}

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

std::vector<std::string> SplitTextIntoLines(const char* text, int maxWidth, int fontSize, Font font) {
    std::vector<std::string> lines;
    std::istringstream words(text);
    std::string word;
    std::string line;

    while (words >> word) {
        if (MeasureTextEx(font, (line + word).c_str(), fontSize, 1).x > maxWidth) {
            lines.push_back(line);
            line = word + " ";
        }
        else {
            line += word + " ";
        }
    }
    if (!line.empty()) {
        lines.push_back(line);
    }
    return lines;
}

void DrawTextInArea2(const char* text, int startX, int endX, int startY, bool isDarkMode, Font font) {
    int maxWidth = endX - startX;
    int fontSize = 20;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color rectColor = isDarkMode ? DARKGRAY : LIGHTGRAY;
    std::vector<std::string> lines = SplitTextIntoLines(text, maxWidth, fontSize, font);

    int y = startY;
    for (const std::string& line : lines) {
        Vector2 textSize = MeasureTextEx(font, line.c_str(), fontSize, 1);
        DrawRectangle(startX - 5, y - 5, textSize.x + 10, fontSize + 10, rectColor);
        Vector2 position = { startX, y };
        DrawTextEx(font, line.c_str(), position, fontSize, 1, textColor);
        // DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
        y += fontSize + 15;
    }
}

void DrawTextInArea3(const char* text, int startX, int endX, int startY, bool isDarkMode) {
    int maxWidth = endX - startX;
    int fontSize = 20;
    Color textColor = isDarkMode ? RED : DARKBLUE;
    std::vector<std::string> lines = SplitTextIntoLines(text, maxWidth, fontSize);

    int y = startY;
    for (const std::string& line : lines) {
        DrawText(line.c_str(), startX, y, fontSize, textColor);
        y += fontSize + 5;
    }
}