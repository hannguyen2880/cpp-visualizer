#include "AVLTree.h"

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