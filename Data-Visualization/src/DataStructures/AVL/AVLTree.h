#ifndef AVLTREE_H
#define AVLTREE_H

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
    void deleteAVLTree();
};

#endif
