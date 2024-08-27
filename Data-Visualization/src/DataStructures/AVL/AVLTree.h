#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>
#include <string>
#include "raylib.h"
#include <thread>
#include <chrono>
#include <iostream>
enum AVLStepType {
    INSERT, UPDATE_HEIGHT, CHECK_BALANCE, ROTATE_LEFT, ROTATE_RIGHT, ROTATE_LEFT_RIGHT, ROTATE_RIGHT_LEFT, NO_ROTATION
};
enum AVLStepTypeDelete {
    DELETE,
    UPDATE_HEIGHT_DELETE,
    ROTATION_DELETE,
    ROTATE_LEFT_DELETE,
    ROTATE_RIGHT_DELETE,
    ROTATE_LEFT_RIGHT_DELETE,
    ROTATE_RIGHT_LEFT_DELETE
};
struct AVLStep;
class AVLState;
class AVLStepInsert;
class AVLStateInsert;
struct AVLStepDelete;
class AVLStateDelete;

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
    AVLNode* deleteWithStepsRec(AVLNode* node, int key, AVLStateDelete& state);
    AVLNode* searchNode(AVLNode* root, int key);
    AVLNode* minValueNode(AVLNode* node);
    void deleteTree(AVLNode*& root);
    int height(AVLNode* N);
    int max(int a, int b);
    int getBalance(AVLNode* N);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertWithStepsRec(AVLNode* node, int key, AVLNode* parent, AVLStateInsert& state);
    AVLStepType determineRotationType(AVLNode* node, int key);
    void drawTreeHighlighted(int startX, int endX, int startY, int endY, bool isDarkMode, AVLNode* highlightedNode);

public:
    AVLTree();
    ~AVLTree();
    AVLStepTypeDelete determineRotationTypeDelete(AVLNode* node);
    AVLNode* getRoot();
    void insert(int key);
    void deleteNode(int key);
    AVLNode* searchAVLNode(int key);
    void searchWithSteps(int value, AVLState& state);
    void executeRotation(AVLStepInsert& step);
    void deleteAVLTree();
    void drawTree(int startX, int endX, int startY, int endY, bool isDarkMode);
    void drawAVLTreeStepByStep(int startX, int endX, int startY, int endY, bool isDarkMode, AVLState& state);
    void insertWithSteps(int key, AVLStateInsert& state);
    void deleteWithSteps(int key, AVLStateDelete& state);
    void drawAVLTreeStepByStepInsert(int startX, int endX, int startY, int endY, bool isDarkMode, AVLStateInsert& state);
    void drawAVLTreeStepByStepDelete(int startX, int endX, int startY, int endY, bool isDarkMode, AVLStateDelete& state);
};

struct AVLStep {
    std::string description;
    AVLNode* highlightedNode;
};

class AVLState {
public:
    std::vector<AVLStep> steps;
    int currentStep = 0;
    bool stepByStepMode;

    AVLState() : currentStep(0), stepByStepMode(false) {}

    void addStep(const std::string& description, AVLNode* highlightedNode) {
        steps.push_back({ description, highlightedNode });
    }

    void nextStep() {
        if (currentStep < steps.size() - 1) ++currentStep;
    }

    void prevStep() {
        if (currentStep > 0) --currentStep;
    }

    AVLStep getCurrentStep() {
        return steps[currentStep];
    }
};
//---------------------------------------

class AVLStepInsert {
public:
    std::string description;
    AVLNode* highlightedNode;
    bool nodeInserted;
    bool rotationAnnounced;
    bool isRotationStep;
    AVLStepType rotationType;
};

class AVLStateInsert {
public:
    std::vector<AVLStepInsert> steps;
    int currentStep;
    bool stepByStepMode;
    bool rotationInProgress;

    AVLStateInsert() : currentStep(0), stepByStepMode(false), rotationInProgress(false) {}

    AVLStepInsert& getCurrentStep() {
        if (currentStep >= 0 && currentStep < steps.size()) {
            return steps[currentStep];
        }
    }

    bool hasNextStep() {
        return currentStep < steps.size() - 1;
    }

    void nextStep() {
        if (hasNextStep()) currentStep++;
    }

    void prevStep() {
        if (currentStep > 0) currentStep--;
    }

    void addStep(const std::string& desc, AVLStepType stepType, AVLNode* node) {
        AVLStepInsert step;
        step.description = desc;
        step.highlightedNode = node;
        step.nodeInserted = (stepType == INSERT);
        step.rotationAnnounced = false;
        step.isRotationStep = (stepType == ROTATE_LEFT || stepType == ROTATE_RIGHT || stepType == ROTATE_LEFT_RIGHT || stepType == ROTATE_RIGHT_LEFT);
        step.rotationType = stepType;
        steps.push_back(step);
    }
};
//-----------------delete step-by-step

struct AVLStepDelete {
    std::string description;
    AVLStepTypeDelete stepType;
    AVLNode* node;
    bool rotationAnnounced = false;
    bool nodeDeleted = false;
    bool rotationInProgress = false;

    AVLStepDelete(const std::string& desc, AVLStepTypeDelete type, AVLNode* n)
        : description(desc), stepType(type), node(n), rotationAnnounced(false), nodeDeleted(false), rotationInProgress(false) {}

    bool isRotationStep() const {
        return stepType == ROTATE_LEFT_DELETE || stepType == ROTATE_RIGHT_DELETE ||
            stepType == ROTATE_LEFT_RIGHT_DELETE || stepType == ROTATE_RIGHT_LEFT_DELETE;
    }
};

class AVLStateDelete {
public:
    std::vector<AVLStepDelete> steps;
    int currentStep;
    bool stepByStepMode;
    bool rotationInProgress;

    AVLStateDelete() : currentStep(0), stepByStepMode(false), rotationInProgress(false) {}

    void addStep(const std::string& description, AVLStepTypeDelete stepType, AVLNode* node) {
        steps.emplace_back(description, stepType, node);
    }

    AVLStepDelete& getCurrentStep() {
        return steps[currentStep];
    }

    bool hasNextStep() {
        return currentStep < steps.size() - 1;
    }

    void nextStep() {
        if (hasNextStep()) currentStep++;
    }

    bool hasPrevStep() {
        return currentStep > 0;
    }

    void prevStep() {
        if (hasPrevStep()) currentStep--;
    }

    bool isRotationStep() {
        return getCurrentStep().stepType == ROTATION_DELETE;
    }
};
#endif