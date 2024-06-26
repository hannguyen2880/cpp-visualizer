#include "Tree234_Draw.h"

void DrawTree234Node(Tree234Node* node, int x, int y, int startX, int endX, int startY, int endY, bool isDarkMode) {
    if (node == nullptr) return;

    float nodeWidth = 60;
    float nodeHeight = 40;
    float spaceBetweenNodes = 20;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;

    // Draw the keys of the node
    for (int i = 0; i < 3; i++) {
        if (node->keys[i] != -1) {
            DrawRectangle(x + i * (nodeWidth + spaceBetweenNodes), y, nodeWidth, nodeHeight, nodeColor);
            DrawText(TextFormat("%d", node->keys[i]), x + i * (nodeWidth + spaceBetweenNodes) + 10, y + 10, 20, textColor);
        }
    }

    // Draw the children of the node
    int childY = y + nodeHeight + spaceBetweenNodes;
    for (int i = 0; i < 4; i++) {
        if (node->children[i] != nullptr) {
            int childX = startX + (endX - startX) / 4 * i + (endX - startX) / 8;
            DrawLine(x + i * (nodeWidth + spaceBetweenNodes), y + nodeHeight, childX, childY, lineColor);
            DrawTree234Node(node->children[i], childX, childY, startX + (endX - startX) / 4 * i, startX + (endX - startX) / 4 * (i + 1), startY, endY, isDarkMode);
        }
    }
}

void DrawTree234(Tree234Node* root, int startX, int endX, int startY, int endY, bool isDarkMode) {
    if (root == nullptr) return;

    int initialX = (startX + endX) / 2;
    int initialY = startY;
    DrawTree234Node(root, initialX, initialY, startX, endX, startY, endY, isDarkMode);
}