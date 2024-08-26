#include "Tree234State.h"

bool showEmptyMess234 = false, showRandomMess234 = false, showFileMess234 = false;

void Tree234_InitOption(bool& chosen, bool isDarkMode, Tree234& tree) {
    if (!chosen) return;

    if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Tree", isDarkMode)) {
        tree.deleteTree();
        showEmptyMess234 = true;
    }
    if (showEmptyMess234) {
        DrawTextInArea("An empty 2-3-4 Tree has been created.", 30, 380, 420, isDarkMode);
        showRandomMess234 = false;
        showFileMess234 = false;
    }
    if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "A Random Tree", isDarkMode)) {
        tree.deleteTree();
        int nNodes = GetRandomValue(10, 20);
        while (nNodes--) {
            int value = GetRandomValue(1, 50);
            tree.insert(value);
        }
        showRandomMess234 = true;
    }
    if (showRandomMess234) {
        DrawTextInArea("A random AVL Tree has been created.", 30, 380, 420, isDarkMode);
        showEmptyMess234 = false;
        showFileMess234 = false;
    }
    if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
        const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
        if (fileName) {
            tree.deleteTree();
            std::vector<int> path = readDataFromFile(fileName);
            for (auto x : path) tree.insert(x);
        }
        showFileMess234 = true;
    }

    if (showFileMess234) {
        DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 420, isDarkMode);
        showEmptyMess234 = false;
        showRandomMess234 = false;
    }
    tree.drawTree234(400, 1400, 150, 790, isDarkMode);
}
char inputText234[10] = "\0";
bool textBoxEditMode234 = false;

void Tree234_InsertOption(bool& chosen, bool isDarkMode, Tree234& tree) {
    if (!chosen) return;
    showEmptyMess234 = false; 
    showRandomMess234 = false; 
    showFileMess234 = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to insert in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputText234, 200, textBoxEditMode234)) {
        textBoxEditMode234 = 1 - textBoxEditMode234;
    }

    if (!textBoxEditMode234 && inputText234[0] != '\0') {
        int value = atoi(inputText234);
        inputText234[0] = '\0';
    }
}
void Tree234_DeleteOption(bool& chosen, bool isDarkMode, Tree234& tree) {
    if (!chosen) return;
    showEmptyMess234 = false;
    showRandomMess234 = false;
    showFileMess234 = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to delete in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputText234, 200, textBoxEditMode234)) {
        textBoxEditMode234 = 1 - textBoxEditMode234;
    }

    if (!textBoxEditMode234 && inputText234[0] != '\0') {
        int value = atoi(inputText234);
        inputText234[0] = '\0';
    }
}
void Tree234_SearchOption(bool& chosen, bool isDarkMode, Tree234& tree) {
    if (!chosen) return;
    showEmptyMess234 = false;
    showRandomMess234 = false;
    showFileMess234 = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value in want to search in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 300, 100, 50 }, inputText234, 200, textBoxEditMode234)) {
        textBoxEditMode234 = 1 - textBoxEditMode234;
    }

    if (!textBoxEditMode234 && inputText234[0] != '\0') {
        int value = atoi(inputText234);
        inputText234[0] = '\0';
    }
}