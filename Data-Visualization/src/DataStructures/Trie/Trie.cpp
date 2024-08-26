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
        if (currentNode->children.find(ch) == currentNode->children.end()) return false;
        currentNode = currentNode->children[ch];
    }
    return currentNode->isEndOfWord;
}

bool deleteHelper(TrieNode* currentNode, const std::string& word, int index) {
    if (index == word.length()) {
        if (!currentNode->isEndOfWord) return false;
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

bool Trie::deleteWord(const std::string& word) {
    if (search(word)) {
        deleteHelper(root, word, 0);
        return true;
    }
    return false;
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
int CountWords(TrieNode* node) {
    if (!node) return 0;
    int count = node->isEndOfWord ? 1 : 0;
    for (auto& child : node->children) {
        count += CountWords(child.second);
    }
    return count;
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
    int wordCount = CountWords(node);
    DrawText(TextFormat("%d", wordCount), x + nodeRadius + 5, y - 5, 20, textColor);

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

//----------------------------------

void FindNodesForHighlight(TrieNode* node, const std::string& str, int index, std::vector<TrieNode*>& highlightNodes, std::vector<char>& highlightChars) {
    if (!node) return;
    if (index < str.size()) {
        char currentChar = str[index];
        auto it = node->children.find(currentChar);
        if (it != node->children.end()) {
            highlightNodes.push_back(it->second);
            highlightChars.push_back(currentChar);
            FindNodesForHighlight(it->second, str, index + 1, highlightNodes, highlightChars);
        }
    }
    if (index == str.size()) {
        highlightNodes.push_back(node);
    }
}

void DrawTrieNodeHighlighted(TrieNode* node, int x, int y, int horizontalSpacing, int verticalSpacing, char currentChar, bool isDarkMode, const std::vector<TrieNode*>& highlightNodes, const std::vector<char>& highlightChars) {
    if (!node) return;

    float nodeRadius = 20;
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;
    Color lineColor = isDarkMode ? GRAY : DARKGRAY;

    // Check if hightlight is essential
    bool highlight = false;
    for (size_t i = 0; i < highlightNodes.size(); ++i) {
        if (highlightNodes[i] == node) {
            highlight = true;
            nodeColor = isDarkMode ? BEIGE : SKYBLUE;
            textColor = BLACK;
            //std::cout << "Highlighting character: " << highlightChars[i] << " at position (" << x << ", " << y << ")" << std::endl;
            break;
        }
    }
    int wordCount = CountWords(node);
    DrawText(TextFormat("%d", wordCount), x + nodeRadius + 5, y - 5, 20, isDarkMode ? WHITE : BLACK);

    DrawCircle(x, y, nodeRadius, nodeColor);
    if (currentChar != ' ') {
        DrawText(TextFormat("%c", currentChar), x - 5, y - 5, 20, textColor);
    }

    int childX = x - horizontalSpacing * (node->children.size() - 1) / 2;
    for (auto& child : node->children) {
        int nextX = childX;
        int nextY = y + verticalSpacing;
        DrawLine(x, y + nodeRadius, nextX, nextY - nodeRadius, lineColor);
        DrawTrieNodeHighlighted(child.second, nextX, nextY, horizontalSpacing / 2, verticalSpacing, child.first, isDarkMode, highlightNodes, highlightChars);
        childX += horizontalSpacing;
    }
    if (highlight) {
        DrawCircle(x, y, nodeRadius, nodeColor);
        DrawText(TextFormat("%c", currentChar), x - 5, y - 5, 20, textColor);
    }
}

void Trie::drawTrieHighlighted(int startX, int endX, int startY, int endY, bool isDarkMode, const std::string& insertedString) {
    int initialX = (startX + endX) / 2;
    int initialY = startY + 50;

    int nodeCount = 0, maxDepth = 0;
    CountNodesAndHeight(root, 0, nodeCount, maxDepth);

    int horizontalSpacing = (endX - startX) / (root->children.size() + 1);
    int verticalSpacing = (endY - startY) / (maxDepth + 1);

    std::vector<TrieNode*> highlightNodes;
    std::vector<char> highlightChars;
    FindNodesForHighlight(root, insertedString, 0, highlightNodes, highlightChars);

    DrawTrieNodeHighlighted(root, initialX, initialY, horizontalSpacing, verticalSpacing, ' ', isDarkMode, highlightNodes, highlightChars);
}

//------------------------------------

void Trie::searchWithSteps(const std::string& word, TrieState& state) {
    TrieNode* currentNode = root;
    state.steps.clear();
    state.currentStep = 0;
    state.stepByStepMode = true;
    state.addStep("Start finding the word: " + word, root, '\0');
    for (size_t i = 0; i < word.size(); ++i) {
        char currentChar = word[i];
        if (currentNode->children.find(currentChar) != currentNode->children.end()) {
            currentNode = currentNode->children[currentChar];
            state.addStep("Found character: " + std::string(1, currentChar), currentNode, currentChar);
        }
        else {
            state.addStep("Character not found: " + std::string(1, currentChar), nullptr, currentChar);
            state.addStep("Cannot find '" + word + "' in Trie.", currentNode, ' ');
            return;
        }
    }

    if (currentNode->isEndOfWord) {
        state.addStep("Word found in Trie.", currentNode, ' ');
    }
    else {
        state.addStep("Reached end of branch, word not fully found.", currentNode, ' ');
    }
}

void Trie::drawTrieStepByStep(int startX, int endX, int startY, int endY, bool isDarkMode, TrieState& state) {
    int initialX = (startX + endX) / 2;
    int initialY = startY + 50;

    int nodeCount = 0, maxDepth = 0;
    CountNodesAndHeight(root, 0, nodeCount, maxDepth);

    int horizontalSpacing = (endX - startX) / (root->children.size() + 1);
    int verticalSpacing = (endY - startY) / (maxDepth + 1);

    TrieStep currentStep = state.getCurrentStep();

    DrawTrieNodeHighlighted(root, initialX, initialY, horizontalSpacing, verticalSpacing, ' ', isDarkMode, { currentStep.highlightedNode }, { currentStep.currentChar });
}
