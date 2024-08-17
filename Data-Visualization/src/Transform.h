#pragma once
#include <raylib.h>
#include <string>

Vector2 Vector2Lerp(Vector2 start, Vector2 end, float t);
Color ColorLerp(Color start, Color end, float t);
float Lerp(float start, float end, float t);


class TransformerHash {
public:
    int index;
    std::string message;

    TransformerHash(int index, const std::string& msg = "")
        : index(index), message(msg) {}

    std::string GetMessage() {
        return message;
    }
};