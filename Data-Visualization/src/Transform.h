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
enum class StepTypeAVL {
    INSERT,
    ROTATE,
    DELETE,
    SEARCH
};
class TransformerAVL {
public:
    StepTypeAVL stepType;    
    std::string message; 
    Vector2 posNode;   
    int startY;      
    int key;
    Color nodeColor;
    Color textColor;

    TransformerAVL(StepTypeAVL type, int key, int startY, const std::string& msg = "",
        Color nodeClr = SKYBLUE, Color txtClr = WHITE)
        : stepType(type), key(key), startY(startY), message(msg), nodeColor(nodeClr), textColor(txtClr) {}

    void Render(bool isDarkMode);
};