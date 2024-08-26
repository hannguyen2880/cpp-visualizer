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
    trie.drawTrie(400, 1400, 60, 720, isDarkMode);
}

char inputTextTrie[20] = "\0";
bool textBoxEditModeTrie = false;

void Trie_InsertOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
    showEmptyMessTrie = false;
    showRandomMessTrie = false;
    showFileMessTrie = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input string in want to insert in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputTextTrie, 200, textBoxEditModeTrie)) {
        textBoxEditModeTrie = 1 - textBoxEditModeTrie;
    }
    if (!textBoxEditModeTrie && inputTextTrie[0] != '\0') {
        trie.insert(inputTextTrie);
        inputTextTrie[0] = '\0';
    }
    trie.drawTrie(400, 1400, 60, 720, isDarkMode);
}
void Trie_DeleteOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
    showEmptyMessTrie = false; 
    showRandomMessTrie = false; 
    showFileMessTrie = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input string in want to delete in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputTextTrie, 200, textBoxEditModeTrie)) {
        textBoxEditModeTrie = 1 - textBoxEditModeTrie;
    }
    if (!textBoxEditModeTrie && inputTextTrie[0] != '\0') {
        trie.deleteWord(inputTextTrie);
        inputTextTrie[0] = '\0';
    }
    trie.drawTrie(400, 1400, 60, 720, isDarkMode);
    
}
void Trie_SearchOption(bool& chosen, bool isDarkMode, Trie& trie) {
	if (!chosen) return;
    showEmptyMessTrie = false;
    showRandomMessTrie = false;
    showFileMessTrie = false;
}