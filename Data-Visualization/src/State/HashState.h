#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/HashTable/HashTable.h"
#include "../Graphic.h"

void Hash_InitOption(bool& chosen, bool isDarkMode, HashTable& hash);
void Hash_InsertOption(bool& chosen, bool isDarkMode, HashTable& hash);
void Hash_DeleteOption(bool& chosen, bool isDarkMode, HashTable& hash);
void Hash_SearchOption(bool& chosen, bool isDarkMode, HashTable& hash);
