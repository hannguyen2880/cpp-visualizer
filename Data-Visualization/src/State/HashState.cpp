#include "HashState.h"

bool showEmptyMessHash = false, showRandomMessHash = false, showFileMessHash = false;

void Hash_InitOption(bool& chosen, bool isDarkMode, HashTable& hash) {
    if (!chosen) return;
    if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Table", isDarkMode)) {
        hash.deleteTable();
        showEmptyMessHash = true;
    }
    if (showEmptyMessHash) {
        DrawTextInArea("An empty table has been created.", 30, 380, 420, isDarkMode);
        showRandomMessHash = false;
        showFileMessHash = false;
    }

    if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "A Random Table", isDarkMode)) {
        hash.deleteTable();
        int nNodes = GetRandomValue(10, 20);
        while (nNodes--) {
            int value = GetRandomValue(1, 50);
            hash.insertItem(value);
        }
        showRandomMessHash = true;
    }
    if (showRandomMessHash) {
        DrawTextInArea("A random Table has been created.", 30, 380, 420, isDarkMode);
        showEmptyMessHash = false;
        showFileMessHash = false;
    }

    if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
        const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
        if (fileName) {
            hash.deleteTable();
            std::vector<int> path = readDataFromFile(fileName);
            for (auto x : path) hash.insertItem(x);
        }
        showFileMessHash = true;
    }

    if (showFileMessHash) {
        DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 420, isDarkMode);
        showEmptyMessHash = false;
        showRandomMessHash = false;
    }	
}

void Hash_InsertOption(bool& chosen, bool isDarkMode, HashTable& hash) {
	if (!chosen) return;
}

void Hash_DeleteOption(bool& chosen, bool isDarkMode, HashTable& hash) {
	if (!chosen) return;
}
void Hash_SearchOption(bool& chosen, bool isDarkMode, HashTable& hash) {
	if (!chosen) return;
}