#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    AVLNode* insert(AVLNode* node, int key);
    AVLNode* deleteNode(AVLNode* root, int key);
    AVLNode* minValueNode(AVLNode* node);
    int height(AVLNode* N);
    int max(int a, int b);
    int getBalance(AVLNode* N);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);

public:
    AVLTree();
    void insert(int key);
    void deleteNode(int key);
};

#endif
