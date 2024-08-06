#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>
#include <string>
#include "raylib.h"
#include <thread>
#include <chrono>

struct AVLNode {
    int key, height;
    AVLNode* left, * right;
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root = nullptr;
    AVLNode* insert(AVLNode* node, int key);
    AVLNode* deleteNode(AVLNode* root, int key);
    AVLNode* searchNode(AVLNode* root, int key);
    AVLNode* minValueNode(AVLNode* node);
    void deleteTree(AVLNode*& root);
    int height(AVLNode* N);
    int max(int a, int b);
    int getBalance(AVLNode* N);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert_steps(AVLNode* node, int key);

public:
    std::vector<std::string> steps;
    AVLTree();
    ~AVLTree();
    AVLNode* getRoot();
    void insert(int key);
    void deleteNode(int key);
    AVLNode* searchAVLNode(int key);
    void deleteAVLTree();
    void insertWithSteps(int key);
};
void DrawAVLTree(AVLNode* root, int startX, int endX, int startY, int endY, bool isDarkMode);
void DrawAVLTreeWithHighlight(AVLNode* node, int startX, int endX, int startY, int endY, Color nodeColor, Color highlightColor, const std::string& currentStep, bool isDarkMode);
void DrawAVLAnimation(AVLTree& tree, int stepIndex, int startX, int endX, int startY, int endY, bool isDarkMode);
#endif
