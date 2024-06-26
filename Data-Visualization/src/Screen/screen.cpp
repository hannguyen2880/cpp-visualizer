#include "screen.h"

#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 800
Texture2D AVL_background;
Texture2D AVL_background_dark;
bool AVLInitOption = false;
bool AVLInsertOption = false, AVLDeleteOption = false, AVLSearchOption = false;
//
AVLTree AvlTree;
Tree234 tree234;
bool Tree234InitOption = false;
bool Tree234InsertOption = false, Tree234DeleteOption = false, Tree234SearchOption = false;

void AVLScreenInit() {
    AVL_background = LoadTexture("Resources/AVL_background.png");
    AVL_background_dark = LoadTexture("Resources/AVL_background_dark_mode.png");
}
void AVLScreenUnload() {
    UnloadTexture(AVL_background);
    UnloadTexture(AVL_background_dark);
}

void AVLScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    
    Texture2D currentBackground = isDarkMode ? AVL_background_dark : AVL_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);

    if (DrawCustomButton(Rectangle{ 0, 120, 150, 50 }, "Init", isDarkMode)) {
        AVLInitOption = 1 - AVLInitOption;
        if (AVLInitOption) {
            AVLInsertOption = false;
            AVLDeleteOption = false;
            AVLSearchOption = false;
        }
    }
    AVL_InitOption(AVLInitOption, isDarkMode, AvlTree);

    if (DrawCustomButton(Rectangle{ 0, 180, 150, 50 }, "Insert", isDarkMode)) {
        AVLInsertOption = 1 - AVLInsertOption;
        if (AVLInsertOption) {
            AVLInitOption = false;
            AVLDeleteOption = false;
            AVLSearchOption = false;
        }
    }
    AVL_InsertOption(AVLInsertOption, isDarkMode, AvlTree);

    if (DrawCustomButton(Rectangle{ 0, 240, 150, 50 }, "Delete", isDarkMode)) {
        AVLDeleteOption = 1 - AVLDeleteOption;
        if (AVLDeleteOption) {
            AVLInitOption = false;
            AVLInsertOption = false;
            AVLSearchOption = false;
        }
    }
    AVL_DeleteOption(AVLDeleteOption, isDarkMode, AvlTree);

    if (DrawCustomButton(Rectangle{ 0, 300, 150, 50 }, "Search", isDarkMode)) {
        AVLSearchOption = 1 - AVLSearchOption;
        if (AVLSearchOption) {
            AVLInitOption = false;
            AVLInsertOption = false;
            AVLDeleteOption = false;
        }
    }
    AVL_SearchOption(AVLSearchOption, isDarkMode, AvlTree);

    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        AVLInitOption = false;
        AVLInsertOption = false;
        AVLDeleteOption = false;
        AVLSearchOption = false;
        AvlTree.deleteAVLTree();
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
    DrawAVLTree(AvlTree.getRoot(), 400, 1400, 150, 790, isDarkMode);
}

// Tree234
Texture2D Tree234_background, Tree234_background_dark;

void Tree234_ScreenInit() {
    Tree234_background = LoadTexture("Resources/Tree234_background.png");
    Tree234_background_dark = LoadTexture("Resources/Tree234_background_dark.png");
}

void Tree234_ScreenUnload() {
    UnloadTexture(Tree234_background);
    UnloadTexture(Tree234_background_dark);
}

void Tree234_Screen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);

    Texture2D currentBackground = isDarkMode ? Tree234_background_dark : Tree234_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);

    if (DrawCustomButton(Rectangle{ 0, 120, 150, 50 }, "Init", isDarkMode)) {
        Tree234InitOption = 1 - Tree234InitOption;
        if (Tree234InitOption) {
            Tree234InsertOption = false;
            Tree234DeleteOption = false;
            Tree234SearchOption = false;
        }
    }
    Tree234_InitOption(Tree234InitOption, isDarkMode, tree234);

    if (DrawCustomButton(Rectangle{ 0, 180, 150, 50 }, "Insert", isDarkMode)) {
        // Insert logic
    }
    if (DrawCustomButton(Rectangle{ 0, 240, 150, 50 }, "Delete", isDarkMode)) {
        // Delete logic
    }
    if (DrawCustomButton(Rectangle{ 0, 300, 150, 50 }, "Search", isDarkMode)) {
        // Search logic
    }
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
    DrawTree234(tree234.getRoot(), 400, 1400, 150, 790, isDarkMode);
}

// Hash Table
Texture2D Hash_background, Hash_background_dark;
void HashScreenInit() {
    Hash_background = LoadTexture("Resources/Hash_background.png");
    Hash_background_dark = LoadTexture("Resources/Hash_background_dark.png");
}

void HashScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    Texture2D currentBackground = isDarkMode ? Hash_background_dark : Hash_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}

void HashScreenUnload() {
    UnloadTexture(Hash_background);
    UnloadTexture(Hash_background_dark);
}

// Graph
Texture2D Graph_background, Graph_background_dark;
void GraphScreenInit() {
    Graph_background = LoadTexture("Resources/graph_background.png");
    Graph_background_dark = LoadTexture("Resources/graph_background_dark.png");
}

void GraphScreenUnload() {
    UnloadTexture(Graph_background);
    UnloadTexture(Graph_background_dark);
}

void GraphScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    Texture2D currentBackground = isDarkMode ? Graph_background_dark : Graph_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}

// Trie
Texture2D Trie_background, Trie_background_dark;
void TrieScreenInit() {
    Trie_background = LoadTexture("Resources/Trie_background.png");
    Trie_background_dark = LoadTexture("Resources/Trie_background_dark.png");
}
void TrieScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    Texture2D currentBackground = isDarkMode ? Trie_background_dark : Trie_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}

void TrieScreenUnload() {
    UnloadTexture(Trie_background);
    UnloadTexture(Trie_background_dark);
}
// Min Heap
Texture2D minHeap_background, minHeap_background_dark;
void minHeapScreenInit() {
    minHeap_background = LoadTexture("Resources/minHeap_background.png");
    minHeap_background_dark = LoadTexture("Resources/minHeap_background_dark.png");
}
void minHeapScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    Texture2D currentBackground = isDarkMode ? minHeap_background_dark : minHeap_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}
void minHeapScreenUnload() {
    UnloadTexture(minHeap_background);
    UnloadTexture(minHeap_background_dark);
}
// MaxHeap
Texture2D maxHeap_background, maxHeap_background_dark;
void maxHeapScreenInit() {
    maxHeap_background = LoadTexture("Resources/maxHeap_background.png");
    maxHeap_background_dark = LoadTexture("Resources/maxHeap_background_dark.png");
}
void maxHeapScreen(Screen& currentScreen, bool& isDarkMode) {
    ClearBackground(isDarkMode ? DARKGRAY : LIGHTGRAY);
    Texture2D currentBackground = isDarkMode ? maxHeap_background_dark : maxHeap_background;
    Rectangle source = Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height };
    Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
    DrawTexturePro(currentBackground, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 100, 400, 680, isDarkMode ? GRAY : WHITE);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}
void maxHeapScreenUnload() {
    UnloadTexture(maxHeap_background);
    UnloadTexture(maxHeap_background_dark);
}

