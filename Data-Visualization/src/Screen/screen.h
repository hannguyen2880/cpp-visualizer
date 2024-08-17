#pragma once
#include "../Graphic.h"
#include "../Transform.h"
//State
#include "../State/AVLState.h"
#include "../State/HeapState.h"
#include "../State/Tree234State.h"
#include "../State/HashState.h"
#include "../State/TrieState.h"
#include "../State/GraphState.h"

//Structure
#include "../State/Tree234State.h"
#include "../DataStructures/AVL/AVLTree.h"
#include "../DataStructures/Heap/MaxHeap.h"
#include "../DataStructures/Heap/MinHeap.h"
#include "../DataStructures/HashTable/HashTable.h"
#include "../DataStructures/Trie/Trie.h"
#include "../DataStructures/Graph/Graph.h"

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
// AVL Screen
void AVLScreenInit();
void AVLScreen(Screen& currentScreen, bool& isDarkMode);
void AVLScreenUnload();
// Tree234
void Tree234_ScreenInit();
void Tree234_Screen(Screen& currentScreen, bool& isDarkMode);
void Tree234_ScreenUnload();
// Hash Table
void HashScreenInit();
void HashScreen(Screen& currentScreen, bool& isDarkMode);
void HashScreenUnload();
// Graph
void GraphScreenInit();
void GraphScreen(Screen& currentScreen, bool& isDarkMode);
void GraphScreenUnload();
// Trie
void TrieScreenInit();
void TrieScreen(Screen& currentScreen, bool& isDarkMode);
void TrieScreenUnload();
// Max Heap
void maxHeapScreenInit();
void maxHeapScreen(Screen& currentScreen, bool& isDarkMode);
void maxHeapScreenUnload();
// Min Heap
void minHeapScreenInit();
void minHeapScreen(Screen& currentScreen, bool& isDarkMode);
void minHeapScreenUnload();

