#include "AVLTree.h"
#include "../../Graphic.h"

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(AVLNode* N) {
    if (N == nullptr) return 0;
    return N->height;
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int AVLTree::getBalance(AVLNode* N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (node == nullptr) return new AVLNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

void AVLTree::deleteTree(AVLNode*& root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

AVLNode* AVLTree::deleteNode(AVLNode* root, int key) {
    if (root == nullptr) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else *root = *temp;
            delete temp;
        }
        else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == nullptr) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

AVLNode* AVLTree::searchNode(AVLNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key == root->key) return root;
    if (key < root->key) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::deleteNode(int key) {
    root = deleteNode(root, key);
}

AVLNode* AVLTree::searchAVLNode(int key) {
    return searchNode(root, key);
}
AVLTree::~AVLTree() {
    deleteTree(root);
}
AVLNode* AVLTree::getRoot() {
    return root;
}
void AVLTree::deleteAVLTree() {
    deleteTree(root);
}
void countNodesAndHeight(AVLNode* node, int depth, int& nodeCount, int& maxDepth) {
    if (node == nullptr) return;
    ++nodeCount;
    maxDepth = std::max(maxDepth, depth);
    countNodesAndHeight(node->left, depth + 1, nodeCount, maxDepth);
    countNodesAndHeight(node->right, depth + 1, nodeCount, maxDepth);
}

//---------------DRAW---------------

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

void AVLTree::drawTree(int startX, int endX, int startY, int endY, bool isDarkMode) {
    int initialX = (startX + endX) / 2;
    DrawAVLTreeRec(root, initialX, startY, startX, endX, startY, endY, isDarkMode);
}
//---------------SEARCHING STEP BY STEP---------------

void AVLTree::searchWithSteps(int value, AVLState& state) {
    AVLNode* currentNode = root;
    state.steps.clear();
    state.currentStep = 0;
    state.stepByStepMode = true;
    state.addStep("We're searching for node with value: " + std::to_string(value), currentNode);

    while (currentNode != nullptr) {
        state.addStep("Visiting node with value: " + std::to_string(currentNode->key), currentNode);
        if (currentNode->key == value) {
            state.addStep("Found the value: " + std::to_string(value), currentNode);
            return;
        }
        else if (currentNode->key < value) {
            std::string msg = "Because " + std::to_string(currentNode->key) + " < " + std::to_string(value)
                + ", we need to going right from this node!";
            state.addStep(msg, currentNode);
            currentNode = currentNode->right;
        }
        else {
            std::string msg = "Because " + std::to_string(currentNode->key) + " > " + std::to_string(value)
                + ", we need to going left from this node!";
            state.addStep(msg, currentNode);
            currentNode = currentNode->left;
        }
    }

    state.addStep("Value " + std::to_string(value) + " not found in AVL Tree.", nullptr);
}

void drawAVLNodeHighlighted(AVLNode* node, int x, int y, int startX, int endX, int startY, int endY, bool isDarkMode, AVLNode* highlightedNode) {
    if (node == nullptr) return;
    float nodeRadius = 20;
    Color nodeColor = (node == highlightedNode) ? (isDarkMode ? BEIGE : SKYBLUE) : (isDarkMode ? SKYBLUE : RED);
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;
    int childXLeft = (startX + x) / 2;
    int childXRight = (endX + x) / 2;
    int childY = y + (endY - startY) / 8;

    if (node->left != nullptr) {
        DrawLine(x, y, childXLeft, childY, lineColor);
        drawAVLNodeHighlighted(node->left, childXLeft, childY, startX, x, startY, endY, isDarkMode, highlightedNode);
    }

    if (node->right != nullptr) {
        DrawLine(x, y, childXRight, childY, lineColor);
        drawAVLNodeHighlighted(node->right, childXRight, childY, x, endX, startY, endY, isDarkMode, highlightedNode);
    }

    DrawCircle(x, y, nodeRadius, nodeColor);
    DrawText(TextFormat("%d", node->key), x - MeasureText(TextFormat("%d", node->key), 20) / 2, y - 10, 20, textColor);
}

void AVLTree::drawAVLTreeStepByStep(int startX, int endX, int startY, int endY, bool isDarkMode, AVLState& state) {
    int initialX = (startX + endX) / 2;
    AVLStep currentStep = state.getCurrentStep();
    drawAVLNodeHighlighted(root, initialX, startY, startX, endX, startY, endY, isDarkMode, currentStep.highlightedNode);
}
//------------INSERT STEP-BY-STEP

AVLStepType AVLTree::determineRotationType(AVLNode* node, int key) {
    int balance = getBalance(node);

    if (balance > 1) {
        if (key < node->left->key) return ROTATE_RIGHT;
        else return ROTATE_LEFT_RIGHT;
    }

    if (balance < -1) {
        if (key > node->right->key) return ROTATE_LEFT;
        else return ROTATE_RIGHT_LEFT;
    }

    return NO_ROTATION;
}

std::string getRotationDescription(AVLStepType rotationType, AVLNode* node) {
    switch (rotationType) {
    case ROTATE_LEFT:
        return "Perform left rotation at node " + std::to_string(node->key);
    case ROTATE_RIGHT:
        return "Perform right rotation at node " + std::to_string(node->key);
    case ROTATE_LEFT_RIGHT:
        return "Perform left-right rotation at node " + std::to_string(node->key);
    case ROTATE_RIGHT_LEFT:
        return "Perform right-left rotation at node " + std::to_string(node->key);
    default:
        return "No rotation required";
    }
}

AVLNode* AVLTree::insertWithStepsRec(AVLNode* node, int key, AVLNode* parent, AVLStateInsert& state) {
    if (node == nullptr) {
        state.addStep("Inserting node " + std::to_string(key), INSERT, nullptr);
        return new AVLNode(key);
    }

    if (key < node->key) {
        state.addStep("Going left from node " + std::to_string(node->key), INSERT, node);
        node->left = insertWithStepsRec(node->left, key, node, state);
    }
    else if (key > node->key) {
        state.addStep("Going right from node " + std::to_string(node->key), INSERT, node);
        node->right = insertWithStepsRec(node->right, key, node, state);
    }
    else {
        state.addStep("Key already exists: " + std::to_string(key), INSERT, node);
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));
    state.addStep("Updated height for node " + std::to_string(node->key) + " to " + std::to_string(node->height), UPDATE_HEIGHT, node);

    int balance = getBalance(node);

    if (balance > 1 || balance < -1) {
        AVLStepType rotationType = determineRotationType(node, key);
        if (!state.getCurrentStep().rotationAnnounced) {
            std::string rotationDesc = getRotationDescription(rotationType, node);
            rotationDesc = "Tree is not balanced now. " + rotationDesc;
            state.addStep(rotationDesc, rotationType, node);
            state.getCurrentStep().rotationAnnounced = true;
            return node;
        }

        if (state.rotationInProgress) {
            switch (rotationType) {
            case ROTATE_LEFT:
                node = leftRotate(node);
                break;
            case ROTATE_RIGHT:
                node = rightRotate(node);
                break;
            case ROTATE_LEFT_RIGHT:
                node->left = leftRotate(node->left);
                node = rightRotate(node);
                break;
            case ROTATE_RIGHT_LEFT:
                node->right = rightRotate(node->right);
                node = leftRotate(node);
                break;
            }
            state.rotationInProgress = false;
        }
    }
    return node;
}


void AVLTree::insertWithSteps(int key, AVLStateInsert& state) {
    state.steps.clear();
    state.currentStep = 0;
    root = insertWithStepsRec(root, key, nullptr, state);
}

void DrawAVLTreeRecHighlighted(AVLNode* node, int x, int y, int startX, int endX, int startY, int endY, bool isDarkMode, AVLNode* highlightedNode) {
    if (!node) return;

    float nodeRadius = 20;
    Color nodeColor = (node == highlightedNode) ? (isDarkMode ? BEIGE : SKYBLUE) : (isDarkMode ? SKYBLUE : RED);
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;
    int childXLeft = (startX + x) / 2;
    int childXRight = (endX + x) / 2;
    int childY = y + (endY - startY) / 8;

    if (node->left) {
        DrawLine(x, y, childXLeft, childY, lineColor);
        DrawAVLTreeRecHighlighted(node->left, childXLeft, childY, startX, x, startY, endY, isDarkMode, highlightedNode);
    }

    if (node->right) {
        DrawLine(x, y, childXRight, childY, lineColor);
        DrawAVLTreeRecHighlighted(node->right, childXRight, childY, x, endX, startY, endY, isDarkMode, highlightedNode);
    }

    DrawCircle(x, y, nodeRadius, nodeColor);
    DrawText(TextFormat("%d", node->key), x - MeasureText(TextFormat("%d", node->key), 20) / 2, y - 10, 20, textColor);
}

void AVLTree::drawTreeHighlighted(int startX, int endX, int startY, int endY, bool isDarkMode, AVLNode* highlightedNode) {
    int initialX = (startX + endX) / 2;
    DrawAVLTreeRecHighlighted(root, initialX, startY, startX, endX, startY, endY, isDarkMode, highlightedNode);
}

void AVLTree::drawAVLTreeStepByStepInsert(int startX, int endX, int startY, int endY, bool isDarkMode, AVLStateInsert& state) {
    AVLStepInsert& currentStep = state.getCurrentStep();
    drawTreeHighlighted(startX, endX, startY, endY, isDarkMode, currentStep.highlightedNode);
}

void AVLTree::executeRotation(AVLStepInsert& step) {
    if (step.isRotationStep && step.rotationAnnounced) {
        switch (step.rotationType) {
        case ROTATE_LEFT:
            step.highlightedNode = leftRotate(step.highlightedNode);
            break;
        case ROTATE_RIGHT:
            step.highlightedNode = rightRotate(step.highlightedNode);
            break;
        case ROTATE_LEFT_RIGHT:
            step.highlightedNode->left = leftRotate(step.highlightedNode->left);
            step.highlightedNode = rightRotate(step.highlightedNode);
            break;
        case ROTATE_RIGHT_LEFT:
            step.highlightedNode->right = rightRotate(step.highlightedNode->right);
            step.highlightedNode = leftRotate(step.highlightedNode);
            break;
        }
    }
}
//----------------------
AVLStepTypeDelete AVLTree::determineRotationTypeDelete(AVLNode* node) {
    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) >= 0) {
            return ROTATE_RIGHT_DELETE;
        }
        else {
            return ROTATE_LEFT_RIGHT_DELETE;
        }
    }
    else if (balance < -1) { 
        if (getBalance(node->right) <= 0) {
            return ROTATE_LEFT_DELETE;
        }
        else {
            return ROTATE_RIGHT_LEFT_DELETE;
        }
    }
    return DELETE;
}
std::string getRotationDescriptionDelete(AVLStepTypeDelete rotationType, AVLNode* node) {
    switch (rotationType) {
    case ROTATE_LEFT:
        return "Perform left rotation at node " + std::to_string(node->key);
    case ROTATE_RIGHT:
        return "Perform right rotation at node " + std::to_string(node->key);
    case ROTATE_LEFT_RIGHT:
        return "Perform left-right rotation at node " + std::to_string(node->key);
    case ROTATE_RIGHT_LEFT:
        return "Perform right-left rotation at node " + std::to_string(node->key);
    default:
        return "No rotation required";
    }
}
AVLNode* AVLTree::deleteWithStepsRec(AVLNode* node, int key, AVLStateDelete& state) {
    if (node == nullptr) {
        state.addStep("Key not found: " + std::to_string(key), DELETE, nullptr);
        return node;
    }

    if (key < node->key) {
        state.addStep("Traversing left from node " + std::to_string(node->key), DELETE, node);
        node->left = deleteWithStepsRec(node->left, key, state);
    }
    else if (key > node->key) {
        state.addStep("Traversing right from node " + std::to_string(node->key), DELETE, node);
        node->right = deleteWithStepsRec(node->right, key, state);
    }
    else {
        state.addStep("Deleting node " + std::to_string(key), DELETE, node);

        if ((node->left == nullptr) || (node->right == nullptr)) {
            AVLNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }
            delete temp;
            state.getCurrentStep().nodeDeleted = true;
        }
        else {
            AVLNode* temp = minValueNode(node->right);
            node->key = temp->key;
            state.addStep("Replacing with smallest node from right subtree: " + std::to_string(temp->key), DELETE, node);
            node->right = deleteWithStepsRec(node->right, temp->key, state);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    state.addStep("Updated height for node " + std::to_string(node->key) + " to " + std::to_string(node->height), UPDATE_HEIGHT_DELETE, node);

    int balance = getBalance(node);

    if (balance > 1 || balance < -1) {
        AVLStepTypeDelete rotationType = determineRotationTypeDelete(node);
        if (!state.getCurrentStep().rotationAnnounced) {
            std::string rotationDesc = getRotationDescriptionDelete(rotationType, node);
            state.addStep(rotationDesc, ROTATION_DELETE, node);
            state.getCurrentStep().rotationAnnounced = true;
            return node;
        }

        if (state.rotationInProgress) {
            switch (rotationType) {
            case ROTATE_LEFT_DELETE:
                node = leftRotate(node);
                break;
            case ROTATE_RIGHT_DELETE:
                node = rightRotate(node);
                break;
            case ROTATE_LEFT_RIGHT_DELETE:
                node->left = leftRotate(node->left);
                node = rightRotate(node);
                break;
            case ROTATE_RIGHT_LEFT_DELETE:
                node->right = rightRotate(node->right);
                node = leftRotate(node);
                break;
            }
            state.rotationInProgress = false;
        }
    }

    return node;
}

void AVLTree::deleteWithSteps(int key, AVLStateDelete& state) {
    state.steps.clear();
    state.currentStep = 0;
    root = deleteWithStepsRec(root, key, state);
}

void AVLTree::drawAVLTreeStepByStepDelete(int startX, int endX, int startY, int endY, bool isDarkMode, AVLStateDelete& state) {
    AVLStepDelete& currentStep = state.getCurrentStep();
    drawTreeHighlighted(startX, endX, startY, endY, isDarkMode, currentStep.node);

    if (currentStep.isRotationStep() && currentStep.rotationInProgress) {
        std::string rotationMsg = "Performing rotation: " + currentStep.description;
        DrawTextInArea3(rotationMsg.c_str(), 30, 380, 500, isDarkMode);
        currentStep.rotationInProgress = false;
    }
}
