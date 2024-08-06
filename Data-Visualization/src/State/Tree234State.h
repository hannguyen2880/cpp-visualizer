#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/Tree234/Tree234.h"
#include "../DataStructures/Tree234/Tree234_Draw.h"

void Tree234_InitOption(bool& chosen, bool isDarkMode, Tree234& tree);
