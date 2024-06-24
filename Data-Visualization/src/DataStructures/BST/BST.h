#ifndef BST_H
#define BST_H

#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int data, std::vector<Node*>& path);
Node* deleteNode(Node* root, int data, std::vector<Node*>& path);
Node* searchNode(Node* root, int data, std::vector<Node*>& path);
void deleteTree(Node* root);

#endif
