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

AVLNode* AVLTree::insert_steps(AVLNode* node, int key) {
    if (node == nullptr) {
        steps.push_back("Inserting node " + std::to_string(key));
        return new AVLNode(key);
    }
    if (key < node->key) {
        steps.push_back("Going left from node " + std::to_string(node->key));
        node->left = insert_steps(node->left, key);
    }
    else if (key > node->key) {
        steps.push_back("Going right from node " + std::to_string(node->key));
        node->right = insert_steps(node->right, key);
    }
    else {
        steps.push_back("Node " + std::to_string(key) + " already exists");
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        steps.push_back("Performing right rotation at node " + std::to_string(node->key));
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        steps.push_back("Performing left rotation at node " + std::to_string(node->key));
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        steps.push_back("Performing left rotation at node " + std::to_string(node->left->key));
        node->left = leftRotate(node->left);
        steps.push_back("Performing right rotation at node " + std::to_string(node->key));
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        steps.push_back("Performing right rotation at node " + std::to_string(node->right->key));
        node->right = rightRotate(node->right);
        steps.push_back("Performing left rotation at node " + std::to_string(node->key));
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insertWithSteps(int key) {
    steps.clear();
    root = insert_steps(root, key);
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

void DrawAVLTree(AVLNode* root, int startX, int endX, int startY, int endY, bool isDarkMode) {
    int initialX = (startX + endX) / 2;
    DrawAVLTreeRec(root, initialX, startY, startX, endX, startY, endY, isDarkMode);
}
void DrawAVLTreeWithHighlight(AVLNode* node, int startX, int endX, int startY, int endY, Color nodeColor, Color highlightColor, const std::string& currentStep, bool isDarkMode) {
    if (!node) return;

    float nodeRadius = 20;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;
    int x = (startX + endX) / 2;
    int y = startY + (endY - startY) / 8;
    int childXLeft = (startX + x) / 2;
    int childXRight = (endX + x) / 2;
    int childY = y + (endY - startY) / 8;

    if (currentStep.find("Inserting node " + std::to_string(node->key)) != std::string::npos) {
        nodeColor = highlightColor;
    }

    if (node->left) {
        DrawLine(x, y, childXLeft, childY, lineColor);
        DrawAVLTreeWithHighlight(node->left, startX, x, startY, endY, nodeColor, highlightColor, currentStep, isDarkMode);
    }

    if (node->right) {
        DrawLine(x, y, childXRight, childY, lineColor);
        DrawAVLTreeWithHighlight(node->right, x, endX, startY, endY, nodeColor, highlightColor, currentStep, isDarkMode);
    }

    DrawCircle(x, y, nodeRadius, nodeColor);
    DrawText(TextFormat("%d", node->key), x - MeasureText(TextFormat("%d", node->key), 20) / 2, y - 10, 20, textColor);
}

void DrawAVLAnimation(AVLTree& tree, int stepIndex, int startX, int endX, int startY, int endY, bool isDarkMode) {
    AVLTree tempTree;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color highlightColor = isDarkMode ? YELLOW : GREEN;
    std::string currentStep = stepIndex < tree.steps.size() ? tree.steps[stepIndex] : "";
    //
    // 
    // Create temporary AVL tree up to the current step
    for (int i = 0; i <= stepIndex && i < tree.steps.size(); ++i) {
        std::string step = tree.steps[i];
        if (step.find("Inserting node") != std::string::npos) {
            int value = std::stoi(step.substr(14));
            tempTree.insert(value);
        }
        else if (step.find("Going") != std::string::npos) {
            // Navigate, no action needed for visualization here
        }
        else if (step.find("Performing") != std::string::npos) {
            // Highlight rotations or cases
            DrawText(step.c_str(), 200, 360, 20, isDarkMode ? WHITE : BLACK);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    // Draw the tree
    DrawAVLTreeWithHighlight(tempTree.getRoot(), startX, endX, startY, endY, nodeColor, highlightColor, currentStep, isDarkMode);
}