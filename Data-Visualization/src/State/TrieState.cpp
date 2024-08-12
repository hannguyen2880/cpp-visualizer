#include "TrieState.h"
bool showEmptyMessTrie = false, showRandomMessTrie = false, showFileMessTrie = false;

void Trie_InitOption(bool& chosen, bool isDarkMode, Trie& trie) {
    if (!chosen) return;

    if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Tree", isDarkMode)) {
        trie.deleteTrie();
        showEmptyMessTrie = true;
    }
    if (showEmptyMessTrie) {
        DrawTextInArea("An empty Trie has been created.", 30, 380, 420, isDarkMode);
        showRandomMessTrie = false;
        showFileMessTrie = false;
    }
	
    if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "Random Tree", isDarkMode)) {
        trie.deleteTrie();
        int nWords = GetRandomValue(5, 10);
        while (nWords--) {
            std::string word = getRandomString(5, 10);
            trie.insert(word);
            //std::cout << word << std::endl;
        }
        showRandomMessTrie = true;
    }

    if (showRandomMessTrie) {
        DrawTextInArea("A random Trie has been created.", 30, 380, 420, isDarkMode);
        showEmptyMessTrie = false;
        showFileMessTrie = false;
    }
    if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
        const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
        if (fileName) {
            trie.deleteTrie();
            std::vector<std::string> path = readDataStringFromFile(fileName);
            for (auto x : path) {
                trie.insert(x);
            }
        }
        showFileMessTrie = true;
    }

    if (showFileMessTrie) {
        DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 420, isDarkMode);
        showEmptyMessTrie = false;
        showRandomMessTrie = false;
    }
}
void Trie_InsertOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
}
void Trie_DeleteOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
}
void Trie_SearchOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
}