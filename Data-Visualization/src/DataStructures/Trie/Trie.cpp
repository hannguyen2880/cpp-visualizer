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
void CountNodesAndHeight(TrieNode* node, int depth, int& nodeCount, int& maxDepth) {
    if (!node) return;
    nodeCount++;
    maxDepth = std::max(maxDepth, depth);
    for (auto& child : node->children) {
        CountNodesAndHeight(child.second, depth + 1, nodeCount, maxDepth);
    }
}

void DrawTrieNode(TrieNode* node, int x, int y, int horizontalSpacing, int verticalSpacing, char currentChar, bool isDarkMode) {
    if (!node) return;

    float nodeRadius = 20;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;

    int numChildren = node->children.size();
    int childX = x - horizontalSpacing * (numChildren - 1) / 2;

    DrawCircle(x, y, nodeRadius, nodeColor);
    if (currentChar != ' ') {
        DrawText(TextFormat("%c", currentChar), x - 5, y - 5, 20, textColor);
    }
    for (auto& child : node->children) {
        int nextX = childX;
        int nextY = y + verticalSpacing;
        DrawLine(x, y + nodeRadius, nextX, nextY - nodeRadius, lineColor);
        DrawTrieNode(child.second, nextX, nextY, horizontalSpacing / 2, verticalSpacing, child.first, isDarkMode);
        childX += horizontalSpacing;
    }
}

void Trie::drawTrie(int startX, int endX, int startY, int endY, bool isDarkMode) {
    int initialX = (startX + endX) / 2;
    int initialY = startY + 50;

    int nodeCount = 0, maxDepth = 0;
    CountNodesAndHeight(root, 0, nodeCount, maxDepth);

    int horizontalSpacing = (endX - startX) / (root->children.size() + 1);
    int verticalSpacing = (endY - startY) / (maxDepth + 1);

    DrawTrieNode(root, initialX, initialY, horizontalSpacing, verticalSpacing, ' ', isDarkMode);
}

