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

typedef enum {
    MENU_SCREEN,
    MENU_DARK_SCREEN,
    AVL_SCREEN,
    BST_SCREEN,
    GRAPH_SCREEN,
    HASH_SCREEN,
    TREE234_SCREEN,
    TRIE_SCREEN,
    MAXHEAP_SCREEN,
    MINHEAP_SCREEN,
} Screen;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    Screen currentScreen = MENU_SCREEN;
    Texture2D background = LoadTexture("Resources/background.png");
    Texture2D background_dark = LoadTexture("Resources/background_dark_mode.png");

    bool isDarkMode = false;

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
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            AVLScreen(isDarkMode);
            break;
        }
        case TREE234_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        case HASH_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        case GRAPH_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        case TRIE_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        case MAXHEAP_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        case MINHEAP_SCREEN: {
            if (DrawCustomButton(Rectangle{ 10, 10, 100, 50 }, "Home", isDarkMode)) {
                currentScreen = (isDarkMode ? MENU_DARK_SCREEN : MENU_SCREEN);
            }
            break;
        }
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(background_dark);
    CloseWindow();
    return 0;
}
