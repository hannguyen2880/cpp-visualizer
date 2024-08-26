#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include "raylib.h"

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
    void deleteWord(const std::string& word);
    TrieNode* getRoot() { return root; }
    void deleteTrie();
    void drawTrie(int startX, int endX, int startY, int endY, bool isDarkMode);
};

#endif
