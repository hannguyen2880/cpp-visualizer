#include "Tree234.h"

void Tree234::split(Tree234Node* node) {
    int midKey = node->keys[1];
    Tree234Node* newChild = new Tree234Node();
    newChild->keys[0] = node->keys[2];

    if (!node->isLeaf()) {
        newChild->children[0] = node->children[2];
        newChild->children[1] = node->children[3];
        if (newChild->children[0]) newChild->children[0]->parent = newChild;
        if (newChild->children[1]) newChild->children[1]->parent = newChild;
    }

    node->keys[1] = -1;
    node->keys[2] = -1;
    node->children[2] = nullptr;
    node->children[3] = nullptr;

    if (node->parent) {
        Tree234Node* parent = node->parent;
        int pos = 0;
        while (pos < 3 && parent->keys[pos] != -1 && parent->keys[pos] < midKey) pos++;
        for (int i = 2; i > pos; i--) {
            parent->keys[i] = parent->keys[i - 1];
            parent->children[i + 1] = parent->children[i];
        }
        parent->keys[pos] = midKey;
        parent->children[pos + 1] = newChild;
        newChild->parent = parent;
        if (parent->isFull()) split(parent);
    }
    else {
        Tree234Node* newRoot = new Tree234Node();
        newRoot->keys[0] = midKey;
        newRoot->children[0] = node;
        newRoot->children[1] = newChild;
        node->parent = newRoot;
        newChild->parent = newRoot;
        root = newRoot;
    }
}

void Tree234::insertNonFull(Tree234Node* node, int key) {
    int pos = 0;
    while (pos < 3 && node->keys[pos] != -1 && node->keys[pos] < key) pos++;
    if (node->isLeaf()) {
        for (int i = 2; i > pos; i--) node->keys[i] = node->keys[i - 1];
        node->keys[pos] = key;
        if (node->isFull()) split(node);
    }
    else {
        insertNonFull(node->children[pos], key);
    }
}
void Tree234::deleteTree(Tree234Node* node) {
    if (node != nullptr) {
        for (auto child : node->children) {
            deleteTree(child);
        }
        delete node;
    }
}
void Tree234::deleteTree() {
    deleteTree(root);
    root = nullptr;
}

Tree234Node* Tree234::search(Tree234Node* node, int key) {
    if (node == nullptr) return nullptr;
    for (int i = 0; i < 3; ++i) {
        if (node->keys[i] == key) return node;
        if (node->keys[i] > key || node->keys[i] == -1) {
            return search(node->children[i], key);
        }
    }
    return search(node->children[3], key);
}

Tree234Node* Tree234::search(int key) {
    return search(root, key);
}
void Tree234::insert(int key) {
    if (!root) {
        root = new Tree234Node();
        root->keys[0] = key;
    }
    else {
        insertNonFull(root, key);
    }
}

Tree234Node* Tree234::getRoot() {
    return root;
}

void Tree234::deleteKey(Tree234Node* node, int key) {
    int index = std::find(node->keys.begin(), node->keys.end(), key) - node->keys.begin();

    if (index < node->keys.size() && node->keys[index] == key) {
        if (node->isLeaf()) {
            deleteFromLeaf(node, index);
        }
        else {
            deleteFromNonLeaf(node, index);
        }
    }
    else {
        if (node->isLeaf()) {
            return; // Key không tồn tại trong cây
        }

        bool isLast = (index == node->keys.size());

        if (node->children[index]->keys.size() < 2) {
            fill(node, index);
        }

        if (isLast && index > node->keys.size()) {
            deleteKey(node->children[index - 1], key);
        }
        else {
            deleteKey(node->children[index], key);
        }
    }
}

void Tree234::deleteFromLeaf(Tree234Node* node, int index) {
    for (int i = index + 1; i < node->keys.size(); ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    node->keys[node->keys.size() - 1] = -1;
}

void Tree234::deleteFromNonLeaf(Tree234Node* node, int index) {
    int key = node->keys[index];

    if (node->children[index]->keys.size() >= 2) {
        int pred = getPredecessor(node, index);
        node->keys[index] = pred;
        deleteKey(node->children[index], pred);
    }
    else if (node->children[index + 1]->keys.size() >= 2) {
        int succ = getSuccessor(node, index);
        node->keys[index] = succ;
        deleteKey(node->children[index + 1], succ);
    }
    else {
        merge(node, index);
        deleteKey(node->children[index], key);
    }
}

int Tree234::getPredecessor(Tree234Node* node, int index) {
    Tree234Node* cur = node->children[index];
    while (!cur->isLeaf()) {
        cur = cur->children[cur->keys.size()];
    }
    return cur->keys[cur->keys.size() - 1];
}

int Tree234::getSuccessor(Tree234Node* node, int index) {
    Tree234Node* cur = node->children[index + 1];
    while (!cur->isLeaf()) {
        cur = cur->children[0];
    }
    return cur->keys[0];
}

void Tree234::fill(Tree234Node* node, int index) {
    if (index != 0 && node->children[index - 1]->keys.size() >= 2) {
        borrowFromPrev(node, index);
    }
    else if (index != node->keys.size() && node->children[index + 1]->keys.size() >= 2) {
        borrowFromNext(node, index);
    }
    else {
        if (index != node->keys.size()) {
            merge(node, index);
        }
        else {
            merge(node, index - 1);
        }
    }
}

void Tree234::borrowFromPrev(Tree234Node* node, int index) {
    Tree234Node* child = node->children[index];
    Tree234Node* sibling = node->children[index - 1];

    for (int i = child->keys.size() - 1; i >= 0; --i) {
        child->keys[i + 1] = child->keys[i];
    }

    if (!child->isLeaf()) {
        for (int i = child->children.size() - 1; i >= 0; --i) {
            child->children[i + 1] = child->children[i];
        }
    }

    child->keys[0] = node->keys[index - 1];

    if (!node->isLeaf()) {
        child->children[0] = sibling->children[sibling->keys.size()];
    }

    node->keys[index - 1] = sibling->keys[sibling->keys.size() - 1];

    sibling->keys[sibling->keys.size() - 1] = -1;
    sibling->children[sibling->keys.size()] = nullptr;
}

void Tree234::borrowFromNext(Tree234Node* node, int index) {
    Tree234Node* child = node->children[index];
    Tree234Node* sibling = node->children[index + 1];

    child->keys[child->keys.size()] = node->keys[index];

    if (!child->isLeaf()) {
        child->children[child->keys.size() + 1] = sibling->children[0];
    }

    node->keys[index] = sibling->keys[0];

    for (int i = 1; i < sibling->keys.size(); ++i) {
        sibling->keys[i - 1] = sibling->keys[i];
    }

    if (!sibling->isLeaf()) {
        for (int i = 1; i < sibling->children.size(); ++i) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    sibling->keys[sibling->keys.size() - 1] = -1;
    sibling->children[sibling->keys.size()] = nullptr;
}

void Tree234::merge(Tree234Node* node, int index) {
    Tree234Node* child = node->children[index];
    Tree234Node* sibling = node->children[index + 1];

    child->keys[1] = node->keys[index];

    for (int i = 0; i < sibling->keys.size(); ++i) {
        child->keys[i + 2] = sibling->keys[i];
    }

    if (!child->isLeaf()) {
        for (int i = 0; i <= sibling->keys.size(); ++i) {
            child->children[i + 2] = sibling->children[i];
        }
    }

    for (int i = index + 1; i < node->keys.size(); ++i) {
        node->keys[i - 1] = node->keys[i];
    }

    for (int i = index + 2; i <= node->keys.size(); ++i) {
        node->children[i - 1] = node->children[i];
    }

    child->keys.resize(child->keys.size() - sibling->keys.size() - 1);
    child->children.resize(child->children.size() - sibling->children.size());

    delete sibling;
}

void Tree234::deleteNode(int key) {
    if (!root) return;

    deleteKey(root, key);

    if (root->keys.size() == 0) {
        Tree234Node* tmp = root;
        if (root->isLeaf()) {
            root = nullptr;
        }
        else {
            root = root->children[0];
        }
        delete tmp;
    }
}