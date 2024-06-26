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
            parent->keys[i] = parent->keys[i-1];
            parent->children[i+1] = parent->children[i];
        }
        parent->keys[pos] = midKey;
        parent->children[pos+1] = newChild;
        newChild->parent = parent;
        if (parent->isFull()) split(parent);
    } else {
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
        for (int i = 2; i > pos; i--) node->keys[i] = node->keys[i-1];
        node->keys[pos] = key;
        if (node->isFull()) split(node);
    } else {
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
    } else {
        insertNonFull(root, key);
    }
}

Tree234Node* Tree234::getRoot() {
    return root;
}
