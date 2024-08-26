#ifndef TREE234_H
#define TREE234_H

#include <vector>
#include <raylib.h>
#include <algorithm>

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
    void deleteTree(Tree234Node* node);
    Tree234Node* search(Tree234Node* node, int key);
    void deleteKey(Tree234Node* node, int key);
    void deleteFromLeaf(Tree234Node* node, int index);
    void deleteFromNonLeaf(Tree234Node* node, int index);
    int getPredecessor(Tree234Node* node, int index);
    int getSuccessor(Tree234Node* node, int index);
    void fill(Tree234Node* node, int index);
    void borrowFromPrev(Tree234Node* node, int index);
    void borrowFromNext(Tree234Node* node, int index);
    void merge(Tree234Node* node, int index);

public:
    Tree234() : root(nullptr) {}
    ~Tree234() { deleteTree(root); }
    void insert(int key);
    Tree234Node* getRoot();
    void deleteTree();
    Tree234Node* search(int key);
    void deleteNode(int key);
    void drawTree234(int startX, int endX, int startY, int endY, bool isDarkMode);
};

#endif
