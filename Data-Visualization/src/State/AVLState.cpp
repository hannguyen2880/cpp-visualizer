#include "AVLState.h"
#include <iostream>
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
    tree.drawTree(400, 1400, 150, 790, isDarkMode);
}
char inputText[10] = "\0";
bool textBoxEditMode = false;

void AVL_InsertOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLStateInsert& state) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value you want to insert in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }

    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        tree.insertWithSteps(value, state);
        state.stepByStepMode = true;
        inputText[0] = '\0';
    }
    if (state.stepByStepMode) {
        tree.drawAVLTreeStepByStepInsert(400, 1400, 150, 790, isDarkMode, state);
        std::string msg = "Step: " + std::to_string(state.currentStep + 1) + ": " + state.steps[state.currentStep].description;
        DrawTextInArea3(msg.c_str(), 30, 380, 500, isDarkMode);
    }
    else tree.drawTree(400, 1400, 150, 790, isDarkMode);

    if (DrawCustomButton2(Rectangle{ 170, 250, 80, 30 }, "Next", isDarkMode)) {
        if (state.hasNextStep()) {
            state.nextStep();
            if (state.getCurrentStep().isRotationStep) {
                state.rotationInProgress = true;
            }
        }
        if (state.rotationInProgress && state.getCurrentStep().rotationAnnounced) {
            tree.executeRotation(state.getCurrentStep());
            state.rotationInProgress = false;
        }
    }

    if (DrawCustomButton2(Rectangle{ 270, 250, 80, 30 }, "Prev", isDarkMode)) {
        state.prevStep();
    }

    if (state.rotationInProgress && state.getCurrentStep().rotationAnnounced) {
        tree.executeRotation(state.getCurrentStep());
        state.rotationInProgress = false;
    }
}


void AVL_DeleteOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLStateDelete& state) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value you want to delete in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }

    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        tree.deleteWithSteps(value, state);
        state.stepByStepMode = true;
        inputText[0] = '\0';
    }

    if (state.stepByStepMode) {
        tree.drawAVLTreeStepByStepDelete(400, 1400, 150, 790, isDarkMode, state);
        std::string msg = "Step: " + std::to_string(state.currentStep + 1) + ": " + state.getCurrentStep().description;
        DrawTextInArea3(msg.c_str(), 30, 380, 500, isDarkMode);
    }
    else tree.drawTree(400, 1400, 150, 790, isDarkMode);

    if (DrawCustomButton2(Rectangle{ 170, 310, 80, 30 }, "Next", isDarkMode)) {
        if (state.hasNextStep()) {
            state.nextStep();
            if (state.getCurrentStep().isRotationStep()) {
                state.getCurrentStep().rotationInProgress = true;
            }
        }
    }

    if (DrawCustomButton2(Rectangle{ 270, 310, 80, 30 }, "Prev", isDarkMode)) {
        state.prevStep();
    }
}

void AVL_SearchOption(bool& chosen, bool isDarkMode, AVLTree& tree, AVLState& state) {
    if (!chosen) return;
    showEmptyMess = false;
    showFileMess = false;
    showRandomMess = false;
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
    DrawTextInArea("Input the value you want to search in the box.", 30, 380, 420, isDarkMode);

    if (GuiTextBox(Rectangle{ 200, 300, 100, 50 }, inputText, 200, textBoxEditMode)) {
        textBoxEditMode = 1 - textBoxEditMode;
    }
    if (!textBoxEditMode && inputText[0] != '\0') {
        int value = atoi(inputText);
        state.stepByStepMode = true;
        tree.searchWithSteps(value, state);
        inputText[0] = '\0';
    }
    if (state.stepByStepMode) {
        tree.drawAVLTreeStepByStep(400, 1400, 150, 790, isDarkMode, state);
        std::string msg = "Step: " + std::to_string(state.currentStep + 1) + ": " + state.steps[state.currentStep].description;
        DrawTextInArea3(msg.c_str(), 30, 380, 500, isDarkMode);
    }
    else tree.drawTree(400, 1400, 150, 790, isDarkMode);

    if (DrawCustomButton2(Rectangle{ 170, 370, 80, 30 }, "Next", isDarkMode)) state.nextStep();
    if (DrawCustomButton2(Rectangle{ 270, 370, 80, 30 }, "Prev", isDarkMode)) state.prevStep();
}