#ifndef TREE234_H
#define TREE234_H

#include <iostream>
#include <vector>

class Tree234Node {
public:
    std::vector<int> keys;
    std::vector<Tree234Node*> children;
    Tree234Node* parent;

    Tree234Node() : parent(nullptr) {
        keys.resize(3, -1);
        children.resize(4, nullptr);
    }

    bool isLeaf() {
        return children[0] == nullptr;
    }

    bool isFull() {
        return keys[2] != -1;
    }
};

class Tree234 {
private:
    Tree234Node* root;

    void split(Tree234Node* node);
    void insertNonFull(Tree234Node* node, int key);

public:
    Tree234() : root(nullptr) {}
    void insert(int key);
    Tree234Node* getRoot() { return root; }
};

#endif
