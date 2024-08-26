#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include "raylib.h"
#include <string>
#include "../../Graphic.h"

struct TrieStep;
class TrieState;

class TrieNode {
public:
    bool isEndOfWord;
    std::unordered_map<char, TrieNode*> children;
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}
    void insert(const std::string &word);
    bool search(const std::string &word);
    void searchWithSteps(const std::string& word, TrieState& state);
    void drawTrieStepByStep(int startX, int endX, int startY, int endY, bool isDarkMode, TrieState& state);
    bool deleteWord(const std::string& word);
    TrieNode* getRoot() { return root; }
    void deleteTrie();
    void drawTrie(int startX, int endX, int startY, int endY, bool isDarkMode);
    void drawTrieHighlighted(int startX, int endX, int startY, int endY, bool isDarkMode, const std::string& insertedString);
};

struct TrieStep {
    std::string description;
    TrieNode* highlightedNode;
    char currentChar;
};

class TrieState {
public:
    std::vector<TrieStep> steps;
    int currentStep = 0;
    bool stepByStepMode;
    TrieState() : currentStep(0), stepByStepMode(false) {}
    void addStep(const std::string& description, TrieNode* highlightedNode, char currentChar) {
        steps.push_back({ description, highlightedNode, currentChar });
    }
    void nextStep() {
        if (currentStep < steps.size() - 1) ++currentStep;
    }
    void prevStep() {
        if (currentStep > 0) --currentStep;
    }
    TrieStep getCurrentStep() {
        return steps[currentStep];
    }
};
#endif
