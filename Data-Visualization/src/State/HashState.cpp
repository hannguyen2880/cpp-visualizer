#include "HashState.h"

bool showEmptyMessHash = false, showRandomMessHash = false, showFileMessHash = false;

void Hash_InitOption(bool& chosen, bool isDarkMode, HashTable& hash, std::vector<TransformerHash>& transformsHash) {
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
            hash.insertItem(value, transformsHash);
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
            for (auto x : path) {
                hash.insertItem(x, transformsHash);
                //std::cout << x << std::endl;
            }
        }
        showFileMessHash = true;
    }

    if (showFileMessHash) {
        DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 420, isDarkMode);
        showEmptyMessHash = false;
        showRandomMessHash = false;
    }	
}
char inputTextHash[10] = "\0";
bool textBoxEditModeHash = false;
static int stepIndexInsertHash = 0;
static bool stepbystepModeInsertHash = false;

void Hash_InsertOption(bool& chosen, bool isDarkMode, HashTable& hash, std::vector<TransformerHash>& transformsHash) {
    if (!chosen) return;
    showEmptyMessHash = false;
    showFileMessHash = false;
    showRandomMessHash = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to insert in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputTextHash, 200, textBoxEditModeHash)) {
        textBoxEditModeHash = 1 - textBoxEditModeHash;
    }

    if (!textBoxEditModeHash && inputTextHash[0] != '\0') {
        int value = atoi(inputTextHash);
        transformsHash.clear();
        hash.insertItem(value, transformsHash);
        stepIndexInsertHash = 0;
        stepbystepModeInsertHash = true;
        inputTextHash[0] = '\0';
    }

    if (stepbystepModeInsertHash) {
        if (GuiButton(Rectangle{ 200, 240, 100, 30 }, "Next Step")) {
            if (stepIndexInsertHash < transformsHash.size() - 1) ++stepIndexInsertHash;
        }
        if (GuiButton(Rectangle{ 200, 280, 100, 30 }, "Prev Step")) {
            if (stepIndexInsertHash > 0) --stepIndexInsertHash;
        }
        // Render
        DrawText(transformsHash[stepIndexInsertHash].message.c_str(), 200, 320, 20, isDarkMode ? WHITE : BLACK);
        std::vector<int> indexs;
        indexs.push_back(transformsHash[stepIndexInsertHash].index);
        if (stepIndexInsertHash > 0) hash.FillTableMode(isDarkMode, indexs);
        else hash.FillTable(isDarkMode);
    }
    else hash.FillTable(isDarkMode);
}
int idx = -1;
static int stepIndexDeleteHash = 0;
static bool stepbystepModeDeleteHash = false;

void Hash_DeleteOption(bool& chosen, bool isDarkMode, HashTable& hash, std::vector<TransformerHash>& transformsHash) {
    if (!chosen) return;
    showEmptyMessHash = false;
    showFileMessHash = false;
    showRandomMessHash = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to delete in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputTextHash, 200, textBoxEditModeHash)) {
        textBoxEditModeHash = 1 - textBoxEditModeHash;
    }
        
    if (!textBoxEditModeHash && inputTextHash[0] != '\0') {
        int value = atoi(inputTextHash);
        transformsHash.clear();
        stepIndexDeleteHash = 0;
        stepbystepModeDeleteHash = true;
        hash.deleteItem(value, transformsHash, idx);
        inputTextHash[0] = '\0';
    }    

    if (stepbystepModeDeleteHash) {
        if (GuiButton(Rectangle{ 200, 300, 100, 30 }, "Next Step")) {
            if (stepIndexDeleteHash < transformsHash.size() - 1) ++stepIndexDeleteHash;
        }
        if (GuiButton(Rectangle{ 200, 340, 100, 30 }, "Prev Step")) {
            if (stepIndexDeleteHash > 0) --stepIndexDeleteHash;
        }
        // Render
        DrawTextInArea(transformsHash[stepIndexDeleteHash].message.c_str(), 30, 380, 600, isDarkMode);
        std::vector<int> indexs;
        indexs.push_back(transformsHash[stepIndexDeleteHash].index);
        indexs.push_back(idx);
        if (stepIndexDeleteHash > 0) hash.FillTableMode(isDarkMode, indexs);
        else hash.FillTable(isDarkMode);
    }
    else hash.FillTable(isDarkMode);
}

static int stepIndexSearchHash = 0;
static bool stepbystepModeSearchHash = false;

void Hash_SearchOption(bool& chosen, bool isDarkMode, HashTable& hash, std::vector<TransformerHash>& transformsHash) {
	if (!chosen) return;

    showEmptyMessHash = false;
    showFileMessHash = false;
    showRandomMessHash = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to search in the box.", 30, 380, 480, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 300, 100, 50 }, inputTextHash, 200, textBoxEditModeHash)) {
        textBoxEditModeHash = 1 - textBoxEditModeHash;
    }

    if (!textBoxEditModeHash && inputTextHash[0] != '\0') {
        int value = atoi(inputTextHash);
        transformsHash.clear();
        int idx = -1;
        hash.searchItem(value, transformsHash, idx);
        stepIndexSearchHash = 0;
        stepbystepModeSearchHash = true;
        inputTextHash[0] = '\0';
    }
    if (stepbystepModeSearchHash) {
        if (GuiButton(Rectangle{ 200, 360, 100, 30 }, "Next Step")) {
            if (stepIndexSearchHash < transformsHash.size() - 1) ++stepIndexSearchHash;
        }
        if (GuiButton(Rectangle{ 200, 400, 100, 30 }, "Prev Step")) {
            if (stepIndexSearchHash > 0) --stepIndexSearchHash;
        }
        // Render
        DrawTextInArea(transformsHash[stepIndexSearchHash].message.c_str(), 30, 380, 600, isDarkMode);
        std::vector<int> indexs;
        indexs.push_back(transformsHash[stepIndexSearchHash].index);
        if (stepIndexSearchHash > 0) hash.FillTableMode(isDarkMode, indexs);
        else hash.FillTable(isDarkMode);
    }
    else hash.FillTable(isDarkMode);

}