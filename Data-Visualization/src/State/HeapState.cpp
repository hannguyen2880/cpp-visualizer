#include "HeapState.h"

//-------------------MAX HEAP----------------------------
bool showEmptyMessMaxHeap = false, showRandomMessMaxHeap = false, showFileMessMaxHeap = false;

void MaxHeap_InitOption(bool& chosen, bool isDarkMode, MaxHeap& heap) {
	if (!chosen) return;

	if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Heap", isDarkMode)) {
		heap.deleteHeap();
		showEmptyMessMaxHeap = true;
	}
	if (showEmptyMessMaxHeap) {
		DrawTextInArea("An empty max heap has been created.", 30, 380, 480, isDarkMode);
		showRandomMessMaxHeap = false;
		showFileMessMaxHeap = false;
	}

	if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "A Random Heap", isDarkMode)) {
		heap.deleteHeap();
		int nNodes = GetRandomValue(10, 20);
		while (nNodes--) {
			int value = GetRandomValue(1, 50);
			heap.insert(value);
		}
		showRandomMessMaxHeap = true;
	}
	if (showRandomMessMaxHeap) {
		DrawTextInArea("A random max heap has been created.", 30, 380, 480, isDarkMode);
		showEmptyMessMaxHeap = false;
		showFileMessMaxHeap = false;
	}
	if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
		const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
		if (fileName) {
			heap.deleteHeap();
			std::vector<int> path = readDataFromFile(fileName);
			for (auto x : path) heap.insert(x);
		}
		showFileMessMaxHeap = true;
	}

	if (showFileMessMaxHeap) {
		DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 480, isDarkMode);
		showEmptyMessMaxHeap = false;
		showRandomMessMaxHeap = false;
	}
}
char inputTextMaxHeap[10] = "\0";
bool textBoxEditModeMaxHeap = false;

static int stepIndexMaxHeap = 0;
static bool stepByStepModeMaxHeap = false;

void MaxHeap_InsertOption(bool& chosen, bool isDarkMode, MaxHeap& heap) {
	if (!chosen) return;
	showEmptyMessMaxHeap = false;
	showFileMessMaxHeap = false;
	showRandomMessMaxHeap = false;

	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	DrawTextInArea("Input the value in want to insert in the box.", 30, 380, 480, isDarkMode);

	if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputTextMaxHeap, 200, textBoxEditModeMaxHeap)) {
		textBoxEditModeMaxHeap = 1 - textBoxEditModeMaxHeap;
	}
	
	if (!textBoxEditModeMaxHeap && inputTextMaxHeap[0] != '\0') {
		int value = atoi(inputTextMaxHeap);
		heap.insert(value);
		inputTextMaxHeap[0] = '\0';
	}
}
void MaxHeap_DeleteOption(bool& chosen, bool isDarkMode, MaxHeap& heap) {
	if (!chosen) return;
	showEmptyMessMaxHeap = false;
	showFileMessMaxHeap = false;
	showRandomMessMaxHeap = false;

	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	DrawTextInArea("Input the value in want to delete in the box.", 30, 380, 480, isDarkMode);

	if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputTextMaxHeap, 200, textBoxEditModeMaxHeap)) {
		textBoxEditModeMaxHeap = 1 - textBoxEditModeMaxHeap;
	}

	if (!textBoxEditModeMaxHeap && inputTextMaxHeap[0] != '\0') {
		int value = atoi(inputTextMaxHeap);
		heap.deleteNode(value);
		inputTextMaxHeap[0] = '\0';
	}
}

void MaxHeap_GetTopOption(bool& chosen, bool isDarkMode, MaxHeap& heap) {
	if (!chosen) return;
	showEmptyMessMaxHeap = false;
	showFileMessMaxHeap = false;
	showRandomMessMaxHeap = false;

	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	std::string txt = "The top of current heap is " + std::to_string(heap.getHeap()[0]);
	const char* text = txt.c_str();
	DrawTextInArea(text, 30, 380, 480, isDarkMode);
}
void MaxHeap_GetSizeOption(bool& chosen, bool isDarkMode, MaxHeap& heap) {
	if (!chosen) return;
	showEmptyMessMaxHeap = false;
	showFileMessMaxHeap = false;
	showRandomMessMaxHeap = false;

	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	std::string txt = "The size of current heap is " + std::to_string(heap.getSize());
	const char* text = txt.c_str();
	DrawTextInArea(text, 30, 380, 480, isDarkMode);
}

//-------------------MIN HEAP----------------------------
bool showEmptyMessMinHeap = false, showRandomMessMinHeap = false, showFileMessMinHeap = false;

void MinHeap_InitOption(bool& chosen, bool isDarkMode, MinHeap& heap) {
	if (!chosen) return;
	if (DrawCustomButton2(Rectangle{ 180, 120, 180, 50 }, "Empty Heap", isDarkMode)) {
		heap.deleteHeap();
		showEmptyMessMinHeap = true;
	}
	if (showEmptyMessMinHeap) {
		DrawTextInArea("An empty min heap has been created.", 30, 380, 480, isDarkMode);
		showRandomMessMinHeap = false;
		showFileMessMinHeap = false;
	}

	if (DrawCustomButton2(Rectangle{ 180, 180, 180, 50 }, "A Random Heap", isDarkMode)) {
		heap.deleteHeap();
		int nNodes = GetRandomValue(10, 20);
		while (nNodes--) {
			int value = GetRandomValue(1, 50);
			heap.insert(value);
		}
		showRandomMessMinHeap = true;
	}
	if (showRandomMessMinHeap) {
		DrawTextInArea("A random min heap has been created.", 30, 380, 480, isDarkMode);
		showEmptyMessMinHeap = false;
		showFileMessMinHeap = false;
	}
	if (DrawCustomButton2(Rectangle{ 180, 240, 180, 50 }, "Open File", isDarkMode)) {
		const char* fileName = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
		if (fileName) {
			heap.deleteHeap();
			std::vector<int> path = readDataFromFile(fileName);
			for (auto x : path) heap.insert(x);
		}
		showFileMessMinHeap = true;
	}

	if (showFileMessMinHeap) {
		DrawTextInArea("Your data in the file has been uploaded.", 30, 380, 480, isDarkMode);
		showEmptyMessMinHeap = false;
		showRandomMessMinHeap = false;
	}
}
void MinHeap_InsertOption(bool& chosen, bool isDarkMode, MinHeap& heap) {
	if (!chosen) return;
	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	DrawTextInArea("Input the value in want to insert in the box.", 30, 380, 480, isDarkMode);

	if (GuiTextBox(Rectangle{ 200, 180, 100, 50 }, inputTextMaxHeap, 200, textBoxEditModeMaxHeap)) {
		textBoxEditModeMaxHeap = 1 - textBoxEditModeMaxHeap;
	}

	if (!textBoxEditModeMaxHeap && inputTextMaxHeap[0] != '\0') {
		int value = atoi(inputTextMaxHeap);
		heap.insert(value);
		inputTextMaxHeap[0] = '\0';
	}
}
void MinHeap_DeleteOption(bool& chosen, bool isDarkMode, MinHeap& heap) {
	if (!chosen) return;
	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	DrawTextInArea("Input the value in want to delete in the box.", 30, 380, 480, isDarkMode);

	if (GuiTextBox(Rectangle{ 200, 240, 100, 50 }, inputTextMaxHeap, 200, textBoxEditModeMaxHeap)) {
		textBoxEditModeMaxHeap = 1 - textBoxEditModeMaxHeap;
	}

	if (!textBoxEditModeMaxHeap && inputTextMaxHeap[0] != '\0') {
		int value = atoi(inputTextMaxHeap);
		heap.deleteNode(value);
		inputTextMaxHeap[0] = '\0';
	}
}
void MinHeap_GetTopOption(bool& chosen, bool isDarkMode, MinHeap& heap) {
	if (!chosen) return;
	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	std::string txt = "The top of current heap is " + std::to_string(heap.getHeap()[0]);
	const char* text = txt.c_str();
	DrawTextInArea(text, 30, 380, 480, isDarkMode);
}
void MinHeap_GetSizeOption(bool& chosen, bool isDarkMode, MinHeap& heap) {
	if (!chosen) return;
	showEmptyMessMaxHeap = false;
	showFileMessMaxHeap = false;
	showRandomMessMaxHeap = false;

	GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(isDarkMode ? DARKGRAY : LIGHTGRAY));
	GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(isDarkMode ? RAYWHITE : BLACK));
	std::string txt = "The size of current heap is " + std::to_string(heap.getSize());
	const char* text = txt.c_str();
	DrawTextInArea(text, 30, 380, 480, isDarkMode);
}