#include "raylib_conf.h"

Vector2 Vector2Subtract(Vector2 v1, Vector2 v2) {
    return Vector2 { v1.x - v2.x, v1.y - v2.y };
}

float Vector2Length(Vector2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vector2 Vector2Normalize(Vector2 v) {
    float length = Vector2Length(v);
    if (length != 0) {
        return Vector2 { v.x / length, v.y / length };
    }
    return v;
}

Vector2 Vector2Scale(Vector2 v, float scale) {
    return Vector2 { v.x* scale, v.y* scale };
}

Vector2 Vector2Add(Vector2 v1, Vector2 v2) {
    return Vector2 { v1.x + v2.x, v1.y + v2.y };
}