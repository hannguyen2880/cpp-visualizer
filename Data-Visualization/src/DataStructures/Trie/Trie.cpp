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
