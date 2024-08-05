#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>
#include "raygui.h" 
#include "tinyfiledialogs.h"  
#include "Graphic.h"
#include "Screen/screen.h"
#include <vector>
#include <fstream>
#include <sstream>
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 800
#define SCREEN_TITLE "DATA STRUCTURE VISUALIZER"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    Screen currentScreen = MENU_SCREEN;
    Texture2D background = LoadTexture("Resources/background.png");
    Texture2D background_dark = LoadTexture("Resources/background_dark_mode.png");

    bool isDarkMode = false;
    AVLScreenInit();
    Tree234_ScreenInit();
    HashScreenInit();
    GraphScreenInit();
    TrieScreenInit();
    maxHeapScreenInit();
    minHeapScreenInit();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        switch (currentScreen) {
        case MENU_SCREEN: {
            Rectangle source = Rectangle{ 0, 0, (float)background.width, (float)background.height };
            Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
            DrawTexturePro(background, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);
            if (DrawCustomButton(Rectangle{ 1260, 50, 120, 20 }, "Dark Mode", isDarkMode)) {
                isDarkMode = true;
                currentScreen = MENU_DARK_SCREEN;
            }

            if (DrawCustomButton(Rectangle{ 125, 350, 300, 100 }, "AVL Tree", isDarkMode)) {
                currentScreen = AVL_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 125, 550, 300, 100 }, "234 Tree", isDarkMode)) {
                currentScreen = TREE234_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 300, 300, 100 }, "Hash Table", isDarkMode)) {
                currentScreen = HASH_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 450, 300, 100 }, "Graph", isDarkMode)) {
                currentScreen = GRAPH_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 600, 300, 100 }, "Trie", isDarkMode)) {
                currentScreen = TRIE_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 975, 350, 300, 100 }, "Max Heap", isDarkMode)) {
                currentScreen = MAXHEAP_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 975, 550, 300, 100 }, "Min Heap", isDarkMode)) {
                currentScreen = MINHEAP_SCREEN;
            }
            break;
        }
        case MENU_DARK_SCREEN: {
            Rectangle source = Rectangle{ 0, 0, (float)background_dark.width, (float)background_dark.height };
            Rectangle dest = Rectangle{ 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
            DrawTexturePro(background_dark, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);

            if (DrawCustomButton(Rectangle{ 1260, 50, 120, 20 }, "Bright Mode", isDarkMode)) {
                isDarkMode = false;
                currentScreen = MENU_SCREEN;
            }

            if (DrawCustomButton(Rectangle{ 125, 350, 300, 100 }, "AVL Tree", isDarkMode)) {
                currentScreen = AVL_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 125, 550, 300, 100 }, "234 Tree", isDarkMode)) {
                currentScreen = TREE234_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 300, 300, 100 }, "Hash Table", isDarkMode)) {
                currentScreen = HASH_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 450, 300, 100 }, "Graph", isDarkMode)) {
                currentScreen = GRAPH_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 550, 600, 300, 100 }, "Trie", isDarkMode)) {
                currentScreen = TRIE_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 975, 350, 300, 100 }, "Max Heap", isDarkMode)) {
                currentScreen = MAXHEAP_SCREEN;
            }
            if (DrawCustomButton(Rectangle{ 975, 550, 300, 100 }, "Min Heap", isDarkMode)) {
                currentScreen = MINHEAP_SCREEN;
            }
            break;
        }
        case AVL_SCREEN: {
            AVLScreen(currentScreen, isDarkMode);
            break;
        }
        case TREE234_SCREEN: {
            Tree234_Screen(currentScreen, isDarkMode);
            break;
        }
        case HASH_SCREEN: {
            HashScreen(currentScreen, isDarkMode);
            break;
        }
        case GRAPH_SCREEN: {
            GraphScreen(currentScreen, isDarkMode);
            break;
        }
        case TRIE_SCREEN: {
            TrieScreen(currentScreen, isDarkMode);
            break;
        }
        case MAXHEAP_SCREEN: {
            maxHeapScreen(currentScreen, isDarkMode);
            break;
        }
        case MINHEAP_SCREEN: {
            minHeapScreen(currentScreen, isDarkMode);
            break;
        }
        }

        EndDrawing();
    }
    AVLScreenUnload();
    Tree234_ScreenUnload();
    HashScreenUnload();
    GraphScreenUnload();
    TrieScreenUnload();
    maxHeapScreenUnload();
    minHeapScreenUnload();
    UnloadTexture(background);
    UnloadTexture(background_dark);
    CloseWindow();
    return 0;
}
