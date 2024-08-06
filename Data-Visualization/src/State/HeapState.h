#pragma once
#include "../Screen/screen.h"
#include <raylib.h>
#include "../tinyfiledialogs.h"
#include "../file_io.h"
#include "../DataStructures/Heap/MaxHeap.h"
#include "../DataStructures/Heap/MinHeap.h"
#include <string>
#include <iostream>
// max heap
void MaxHeap_InitOption(bool& chosen, bool isDarkMode, MaxHeap& heap);
void MaxHeap_InsertOption(bool& chosen, bool isDarkMode, MaxHeap& heap);
void MaxHeap_DeleteOption(bool& chosen, bool isDarkMode, MaxHeap& heap);
void MaxHeap_GetTopOption(bool& chosen, bool isDarkMode, MaxHeap& heap);
void MaxHeap_GetSizeOption(bool& chosen, bool isDarkMode, MaxHeap& heap);

// min heap
void MinHeap_InitOption(bool& chosen, bool isDarkMode, MinHeap& heap);
void MinHeap_InsertOption(bool& chosen, bool isDarkMode, MinHeap& heap);
void MinHeap_DeleteOption(bool& chosen, bool isDarkMode, MinHeap& heap);
void MinHeap_GetTopOption(bool& chosen, bool isDarkMode, MinHeap& heap);
void MinHeap_GetSizeOption(bool& chosen, bool isDarkMode, MinHeap& heap);