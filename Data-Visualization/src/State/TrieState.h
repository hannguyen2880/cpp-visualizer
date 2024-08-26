#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/Trie/Trie.h"
#include "../Graphic.h"

void Trie_InitOption(bool& chosen, bool isDarkMode, Trie& trie);
void Trie_InsertOption(bool& chosen, bool isDarkMode, Trie& trie);
void Trie_DeleteOption(bool& chosen, bool isDarkMode, Trie& trie);
void Trie_SearchOption(bool& chosen, bool isDarkMode, Trie& trie, TrieState& state);
