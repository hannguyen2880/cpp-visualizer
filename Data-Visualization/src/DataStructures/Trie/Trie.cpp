#include "Trie.h"

void Trie::insert(const std::string &word) {
    TrieNode* currentNode = root;
    for (char ch : word) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            currentNode->children[ch] = new TrieNode();
        }
        currentNode = currentNode->children[ch];
    }
    currentNode->isEndOfWord = true;
}

bool Trie::search(const std::string &word) {
    TrieNode* currentNode = root;
    for (char ch : word) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[ch];
    }
    return currentNode->isEndOfWord;
}

bool deleteHelper(TrieNode* currentNode, const std::string& word, int index) {
    if (index == word.length()) {
        if (!currentNode->isEndOfWord) {
            return false;
        }
        currentNode->isEndOfWord = false;
        return currentNode->children.empty();
    }

    char ch = word[index];
    TrieNode* nextNode = currentNode->children[ch];
    if (nextNode == nullptr) return false;

    bool shouldDeleteCurrentNode = deleteHelper(nextNode, word, index + 1);

    if (shouldDeleteCurrentNode) {
        delete nextNode;
        currentNode->children.erase(ch);
        return currentNode->children.empty() && !currentNode->isEndOfWord;
    }

    return false;
}

void Trie::deleteWord(const std::string& word) {
    deleteHelper(root, word, 0);
}

void deleteTrieHelper(TrieNode* currentNode) {
    if (currentNode == nullptr) return;
    for (auto& child : currentNode->children) {
        deleteTrieHelper(child.second);
    }
    delete currentNode;
}

void Trie::deleteTrie() {
    deleteTrieHelper(root);
    root = new TrieNode();
}


//-----------------------------------------------------
void DrawTrieNode(TrieNode* node, int startX, int endX, int startY, int endY, int depth, bool isDarkMode) {
    if (!node) return;
    float nodeRadius = 20;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;


}
void DrawTrie(TrieNode* root, int startX, int endX, int startY, int endY, bool isDarkMode) {
    if (root) {
        DrawTrieNode(root, startX, endX, startY, endY, 0, isDarkMode);
    }
}

