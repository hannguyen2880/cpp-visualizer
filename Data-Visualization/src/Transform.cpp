#include "Transform.h"
#include "Graphic.h"

Vector2 Vector2Lerp(Vector2 start, Vector2 end, float t) {
    return Vector2{ start.x + t * (end.x - start.x), start.y + t * (end.y - start.y) };
}

Color ColorLerp(Color start, Color end, float t) {
    return Color {
        (unsigned char)(start.r + t * (end.r - start.r)),
        (unsigned char)(start.g + t * (end.g - start.g)),
        (unsigned char)(start.b + t * (end.b - start.b)),
        (unsigned char)(start.a + t * (end.a - start.a))
    };
}

float Lerp(float start, float end, float t) {
    return start + t * (end - start);
}

void TransformerAVL::Render(bool isDarkMode) {
    DrawTextInArea(message.c_str(), 30, 380, startY, isDarkMode);
    DrawCircle(posNode.x, posNode.y, 20, nodeColor);
    DrawText(TextFormat("%d", key), posNode.x - MeasureText(TextFormat("%d", key), 20) / 2, posNode.y - 10, 20, textColor);
}