#include "BST.h"

Node* insertNode(Node* root, int data, std::vector<Node*>& path) {
    if (!root) return new Node(data);
    path.push_back(root);
    if (data < root->data) root->left = insertNode(root->left, data, path);
    else root->right = insertNode(root->right, data, path);
    return root;
}

Node* deleteNode(Node* root, int data, std::vector<Node*>& path) {
    if (!root) return nullptr;
    path.push_back(root);
    if (data < root->data) root->left = deleteNode(root->left, data, path);
    else if (data > root->data) root->right = deleteNode(root->right, data, path);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, path);
    }
    return root;
}

Node* searchNode(Node* root, int data, std::vector<Node*>& path) {
    if (!root || root->data == data) return root;
    path.push_back(root);
    if (data < root->data) return searchNode(root->left, data, path);
    else return searchNode(root->right, data, path);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
