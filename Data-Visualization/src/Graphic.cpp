#include "Graphic.h"

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