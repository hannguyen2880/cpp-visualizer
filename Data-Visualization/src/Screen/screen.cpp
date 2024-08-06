#include "screen.h"

#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 800
Texture2D AVL_background;
Texture2D AVL_background_dark;

//---------------------------AVL TREE------------------------------
AVLTree AvlTree;
bool AVLInitOption = false;
bool AVLInsertOption = false, AVLDeleteOption = false, AVLSearchOption = false;

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
//------------------TREE234---------------------
// Tree234
Texture2D Tree234_background, Tree234_background_dark;
Tree234 tree234;
bool Tree234InitOption = false;
bool Tree234InsertOption = false, Tree234DeleteOption = false, Tree234SearchOption = false;

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
        Tree234InsertOption = 1 - Tree234InsertOption;
        if (Tree234InsertOption) {
            Tree234InitOption = false;
            Tree234DeleteOption = false;
            Tree234SearchOption = false;
        }
    }
    Tree234_InsertOption(Tree234InsertOption, isDarkMode, tree234);

    if (DrawCustomButton(Rectangle{ 0, 240, 150, 50 }, "Delete", isDarkMode)) {
        Tree234DeleteOption = 1 - Tree234DeleteOption;
        if (Tree234DeleteOption) {
            Tree234InitOption = false;
            Tree234InsertOption = false;
            Tree234SearchOption = false;
        }
    }
    Tree234_DeleteOption(Tree234DeleteOption, isDarkMode, tree234);

    if (DrawCustomButton(Rectangle{ 0, 300, 150, 50 }, "Search", isDarkMode)) {
        Tree234SearchOption = 1 - Tree234SearchOption;
        if (Tree234SearchOption) {
            Tree234InitOption = false;
            Tree234InsertOption = false;
            Tree234DeleteOption = false;
        }
    }
    Tree234_SearchOption(Tree234SearchOption, isDarkMode, tree234);

    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        Tree234InitOption = false;
        Tree234InsertOption = false;
        Tree234DeleteOption = false;
        Tree234SearchOption = false;
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
    DrawTree234(tree234.getRoot(), 400, 1400, 150, 790, isDarkMode);
}

// ------------------ HASH TABLE ----------------------
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

// ------------------GRAPH----------------------
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

    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
}
// ---------------TRIE----------------------

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


// ---------------MIN HEAP----------------------

Texture2D minHeap_background, minHeap_background_dark;
MinHeap minHeap;
bool minHeapInitOption = false, minHeapInsertOption = false, minHeapDeleteOption = false;
bool minHeapGetTopOption = false, minHeapGetSizeOption = false;

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
    if (DrawCustomButton(Rectangle{ 0, 120, 150, 50 }, "Init", isDarkMode)) {
        minHeapInitOption = 1 - minHeapInitOption;
        if (minHeapInitOption) {
            minHeapInsertOption = false;
            minHeapDeleteOption = false;
            minHeapGetTopOption = false;
            minHeapGetSizeOption = false;
        }
    }
    MinHeap_InitOption(minHeapInitOption, isDarkMode, minHeap);

    if (DrawCustomButton(Rectangle{ 0, 180, 150, 50 }, "Insert", isDarkMode)) {
        minHeapInsertOption = 1 - minHeapInsertOption;
        if (minHeapInsertOption) {
            minHeapInitOption = false;
            minHeapDeleteOption = false;
            minHeapGetTopOption = false;
            minHeapGetSizeOption = false;
        }
    }
    MinHeap_InsertOption(minHeapInsertOption, isDarkMode, minHeap);

    if (DrawCustomButton(Rectangle{ 0, 240, 150, 50 }, "Delete", isDarkMode)) {
        minHeapDeleteOption = 1 - minHeapDeleteOption;
        if (minHeapDeleteOption) {
            minHeapInitOption = false;
            minHeapInsertOption = false;
            minHeapGetTopOption = false;
            minHeapGetSizeOption = false;
        }
    }
    MinHeap_DeleteOption(minHeapDeleteOption, isDarkMode, minHeap);

    if (DrawCustomButton(Rectangle{ 0, 300, 150, 50 }, "Get Top", isDarkMode)) {
        minHeapGetTopOption = 1 - minHeapGetTopOption;
        if (minHeapGetTopOption) {
            minHeapInitOption = false;
            minHeapInsertOption = false;
            minHeapDeleteOption = false;
            minHeapGetSizeOption = false;
        }
    }
    MinHeap_GetTopOption(minHeapGetTopOption, isDarkMode, minHeap);

    if (DrawCustomButton(Rectangle{ 0, 360, 150, 50 }, "Get Size", isDarkMode)) {
        minHeapGetSizeOption = 1 - minHeapGetSizeOption;
        if (minHeapGetSizeOption) {
            minHeapInitOption = false;
            minHeapInsertOption = false;
            minHeapDeleteOption = false;
            minHeapGetTopOption = false;
        }
    }
    MinHeap_GetSizeOption(minHeapGetSizeOption, isDarkMode, minHeap);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        minHeapInitOption = false;
        minHeapInsertOption = false;
        minHeapDeleteOption = false;
        minHeapGetTopOption = false;
        minHeapGetSizeOption = false;
        minHeap.deleteHeap();
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
    // Draw Min Heap
    DrawMinHeap(&minHeap, 400, 1400, 150, 650, isDarkMode);
}
void minHeapScreenUnload() {
    UnloadTexture(minHeap_background);
    UnloadTexture(minHeap_background_dark);
}
// ---------------MAX HEAP----------------------
// MaxHeap
Texture2D maxHeap_background, maxHeap_background_dark;
MaxHeap maxHeap;
bool maxHeapInitOption = false, maxHeapInsertOption = false, maxHeapDeleteOption = false;
bool maxHeapGetTopOption = false, maxHeapGetSizeOption = false;


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
    if (DrawCustomButton(Rectangle{ 0, 120, 150, 50 }, "Init", isDarkMode)) {
        maxHeapInitOption = 1 - maxHeapInitOption;
        if (maxHeapInitOption) {
            maxHeapInsertOption = false;
            maxHeapDeleteOption = false;
            maxHeapGetTopOption = false;
            maxHeapGetSizeOption = false;
        }
    }
    MaxHeap_InitOption(maxHeapInitOption, isDarkMode, maxHeap);

    if (DrawCustomButton(Rectangle{ 0, 180, 150, 50 }, "Insert", isDarkMode)) {
        maxHeapInsertOption = 1 - maxHeapInsertOption;
        if (maxHeapInsertOption) {
            maxHeapInitOption = false;
            maxHeapDeleteOption = false;
            maxHeapGetTopOption = false;
            maxHeapGetSizeOption = false;
        }
    }
    MaxHeap_InsertOption(maxHeapInsertOption, isDarkMode, maxHeap);

    if (DrawCustomButton(Rectangle{ 0, 240, 150, 50 }, "Delete", isDarkMode)) {
        maxHeapDeleteOption = 1 - maxHeapDeleteOption;
        if (maxHeapDeleteOption) {
            maxHeapInitOption = false;
            maxHeapInsertOption = false;
            maxHeapGetTopOption = false;
            maxHeapGetSizeOption = false;
        }
    }
    MaxHeap_DeleteOption(maxHeapDeleteOption, isDarkMode, maxHeap);

    if (DrawCustomButton(Rectangle{ 0, 300, 150, 50 }, "Get Top", isDarkMode)) {
        maxHeapGetTopOption = 1 - maxHeapGetTopOption;
        if (maxHeapGetTopOption) {
            maxHeapInitOption = false;
            maxHeapInsertOption = false;
            maxHeapDeleteOption = false;
            maxHeapGetSizeOption = false;
        }
    }
    MaxHeap_GetTopOption(maxHeapGetTopOption, isDarkMode, maxHeap);

    if (DrawCustomButton(Rectangle{ 0, 360, 150, 50 }, "Get Size", isDarkMode)) {
        maxHeapGetSizeOption = 1 - maxHeapGetSizeOption;
        if (maxHeapGetSizeOption) {
            maxHeapInitOption = false;
            maxHeapInsertOption = false;
            maxHeapDeleteOption = false;
            maxHeapGetTopOption = false;
        }
    }
    MaxHeap_GetSizeOption(maxHeapGetSizeOption, isDarkMode, maxHeap);
    //...
    if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Back", isDarkMode)) {
        maxHeapInitOption = false;
        maxHeapInsertOption = false;
        maxHeapDeleteOption = false;
        maxHeapGetTopOption = false;
        maxHeapGetSizeOption = false;
        maxHeap.deleteHeap();
        currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
    }
    if (DrawCustomButton(Rectangle{ 200, 10, 150, 50 }, isDarkMode ? "Bright Mode" : "Dark Mode", isDarkMode)) {
        isDarkMode = !isDarkMode;
    }
    // Draw Max Heap
    DrawMaxHeap(&maxHeap, 400, 1400, 150, 650, isDarkMode);
}
void maxHeapScreenUnload() {
    UnloadTexture(maxHeap_background);
    UnloadTexture(maxHeap_background_dark);
}