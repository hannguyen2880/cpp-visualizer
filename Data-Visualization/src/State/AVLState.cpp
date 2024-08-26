#include "AVLState.h"
bool showEmptyMess = false, showRandomMess = false, showFileMess = false;


void AVL_InitOption(bool& chosen, bool isDarkMode, AVLTree& tree) {
    if (!chosen) return;

    if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Tree", isDarkMode)) {
        tree.deleteAVLTree();
        showEmptyMess = true;
    }
    if (showEmptyMess) {
        DrawTextInArea("An empty AVL Tree has been created.", 30, 380, 420, isDarkMode);
        showRandomMess = false;
        showFileMess = false;
    }
    if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "A Random Tree", isDarkMode)) {
        tree.deleteAVLTree();
        int nNodes = GetRandomValue(10, 20);
        while (nNodes--) {
            int value = GetRandomValue(1, 50);
            tree.insert(value);
        }
        showRandomMess = true;
    }
    if (showRandomMess) {
        DrawTextInArea("A random AVL Tree has been created.", 30, 380, 420, isDarkMode);
        showEmptyMess = false;
        showFileMess = false;
    }
    if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
        const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
        if (fileName) {
            tree.deleteAVLTree();
            std::vector<int> path = readDataFromFile(fileName);
            for (auto x : path) tree.insert(x);
        }
        showFileMess = true;
    }

    if (showFileMess) {
        DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 420, isDarkMode);
        showEmptyMess = false;
        showRandomMess = false;
    }
}
char inputText[10] = "\0";
bool textBoxEditMode = false;

//static int stepIndex = 0;
//static bool stepByStepMode = false;

static int stepIndexInsertAVL = 0;
static bool stepbystepModeInsertAVL = false;

void AVL_InsertOption(bool& chosen, bool isDarkMode, AVLTree& tree) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to insert in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }

    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        tree.transformSteps.clear();
        tree.insertWithSteps(value);
        stepIndexInsertAVL = 0;
        stepbystepModeInsertAVL = true;
        inputText[0] = '\0';  // Reset input
    }

    if (stepbystepModeInsertAVL) {
        if (GuiButton(Rectangle{ 200, 300, 100, 30 }, "Next Step")) {
            if (stepIndexInsertAVL < tree.transformSteps.size() - 1) ++stepIndexInsertAVL;
        }
        if (GuiButton(Rectangle{ 200, 340, 100, 30 }, "Prev Step")) {
            if (stepIndexInsertAVL > 0) --stepIndexInsertAVL;
        }
        tree.transformSteps[stepIndexInsertAVL].Render(isDarkMode);
        DrawAVLAnimation(tree, stepIndexInsertAVL, 400, 1400, 150, 790, isDarkMode);
    }
    /*
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
    */
}


void AVL_DeleteOption(bool& chosen, bool isDarkMode, AVLTree& tree) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to delete in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }

    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        tree.deleteNode(value);
        inputText[0] = '\0';
    }
}

void AVL_SearchOption(bool& chosen, bool isDarkMode, AVLTree& tree) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to search in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 300, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }
    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        AVLNode* node = tree.searchAVLNode(value);
        inputText[0] = '\0';
    }
}