#include "AVLState.h"

void AVL_InitOption(bool& chosen, bool isDarkMode) {
	if (!chosen) return;
    if (DrawCustomButton2(Rectangle{ 160, 120, 150, 50 }, "Empty Tree", isDarkMode)) {
        // Logic cho An empty
    }
    if (DrawCustomButton2(Rectangle{ 160, 180, 150, 50 }, "Random", isDarkMode)) {
        // Logic cho Random
    }
    if (DrawCustomButton2(Rectangle{ 160, 240, 150, 50 }, "Open File", isDarkMode)) {
        const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
        if (fileName) {
            // readDatafromFile;
        }
    }
}

void AVL_InsertOption(bool& chosen, bool isDarkMode) {
    if (!chosen) return;
    
}