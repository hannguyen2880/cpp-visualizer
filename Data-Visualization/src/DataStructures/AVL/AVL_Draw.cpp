#include "AVL_Draw.h"

void DrawAVLTreeRec(AVLNode* node, int x, int y, int startX, int endX, int startY, int endY, bool isDarkMode) {
    if (!node) return;

    float nodeRadius = 20;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;
    int childXLeft = (startX + x) / 2;
    int childXRight = (endX + x) / 2;
    int childY = y + (endY - startY) / 8;

    if (node->left) {
        DrawLine(x, y, childXLeft, childY, lineColor);
        DrawAVLTreeRec(node->left, childXLeft, childY, startX, x, startY, endY, isDarkMode);
    }

    if (node->right) {
        DrawLine(x, y, childXRight, childY, lineColor);
        DrawAVLTreeRec(node->right, childXRight, childY, x, endX, startY, endY, isDarkMode);
    }

    DrawCircle(x, y, nodeRadius, nodeColor);
    DrawText(TextFormat("%d", node->key), x - MeasureText(TextFormat("%d", node->key), 20) / 2, y - 10, 20, textColor);
}

void DrawAVLTree(AVLNode* root, int startX, int endX, int startY, int endY, bool isDarkMode) {
    int initialX = (startX + endX) / 2;
    DrawAVLTreeRec(root, initialX, startY, startX, endX, startY, endY, isDarkMode);
}
