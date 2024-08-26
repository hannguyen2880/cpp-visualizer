#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>
#include <string>
#include "raylib.h"
#include <thread>
#include <chrono>

struct AVLStep;
class AVLState;

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

public:
    AVLTree();
    ~AVLTree();
    AVLNode* getRoot();
    void insert(int key);
    void deleteNode(int key);
    AVLNode* searchAVLNode(int key);
    void searchWithSteps(int value, AVLState& state);
    void deleteAVLTree();
    void drawTree(int startX, int endX, int startY, int endY, bool isDarkMode);
    void drawAVLTreeStepByStep(int startX, int endX, int startY, int endY, bool isDarkMode, AVLState& state);
};

struct AVLStep {
    std::string description;
    AVLNode* highlightedNode;
};

class AVLState {
public:
    std::vector<AVLStep> steps;
    int currentStep;
    bool stepByStepMode;

    AVLState() : currentStep(0), stepByStepMode(false) {}

    void addStep(const std::string& description, AVLNode* highlightedNode) {
        steps.push_back({ description, highlightedNode });
    }

    void nextStep() {
        if (currentStep < steps.size() - 1) {
            currentStep++;
            //std::cout << "Step: " << currentStep << " - " << steps[currentStep].description << std::endl;
        }
    }

    void prevStep() {
        if (currentStep > 0) {
            currentStep--;
            //std::cout << "Step: " << currentStep << " - " << steps[currentStep].description << std::endl;
        }
    }

    AVLStep getCurrentStep() {
        return steps[currentStep];
    }
};

#endif