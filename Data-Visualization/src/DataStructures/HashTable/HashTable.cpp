#include "HashTable.h"

HashTable::HashTable(int size) : size(size) {
    table.resize(size, -1);
    isFilled.resize(size, false);
}

int HashTable::hashFunction(int key) {
    return key % size;
}

int HashTable::linearProbing(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (isFilled[index]) {
        index = (index + 1) % size;
        if (index == originalIndex) {
            return -1;
        }
    }

    return index;
}

bool HashTable::insertItem(int key) {
    int index = linearProbing(key);
    if (index == -1) {
        return false;
    }
    table[index] = key;
    isFilled[index] = true;
    return true;
}

bool HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (isFilled[index] && table[index] != key) {
        index = (index + 1) % size;
        if (index == originalIndex) {
            return false;
        }
    }

    if (table[index] == key) {
        table[index] = -1;
        isFilled[index] = false;
    }
    else {
        return false;
    }
    return true;
}

bool HashTable::searchItem(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (isFilled[index]) {
        if (table[index] == key) {
            return true;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            return false;
        }
    }

    return false;
}

std::vector<int> HashTable::getTable() {
    return table;
}

void HashTable::deleteTable() {
    table.clear();
    isFilled.clear();
    table.resize(size, -1);
    isFilled.resize(size, false);
}

void DrawTable(bool isDarkMode) {
    Color color = isDarkMode ? WHITE : RED;
    
    float startX = 500;

    for (int i = 0; i < 10; ++i) {
        Rectangle rect = Rectangle{ startX + 80 * i, 200, 50, 50 };
        DrawRectangleLinesEx(rect, 2, color);
        std::string str = std::to_string(i);
        const char* txt = str.c_str();
        DrawTextRectangle(txt, { startX + 80 * i, 250, 50, 50 }, 20, isDarkMode, BEIGE, RED);
    }

    for (int i = 0; i < 10; ++i) {
        Rectangle rect = Rectangle{ startX + 80 * i, 350, 50, 50 };
        DrawRectangleLinesEx(rect, 2, color);
        std::string str = std::to_string(i + 10);
        const char* txt = str.c_str();
        DrawTextRectangle(txt, { startX + 80 * i, 400, 50, 50 }, 20, isDarkMode, BEIGE, RED);
    }

    for (int i = 0; i < 10; ++i) {
        Rectangle rect = Rectangle{ startX + 80 * i, 500, 50, 50 };
        DrawRectangleLinesEx(rect, 2, color);
        std::string str = std::to_string(i + 20);
        const char* txt = str.c_str();
        DrawTextRectangle(txt, { startX + 80 * i, 550, 50, 50 }, 20, isDarkMode, BEIGE, RED);
    }
}

void HashTable::FillTable(bool isDarkMode) {
    for (int i = 0; i < table.size(); ++i) {
        if (!isFilled[i]) continue;
        // put table[i] in index 'i'
        std::string str = std::to_string(table[i]);
        const char* txt = str.c_str();
        DrawTextRectangle(txt, { (float)500 + 80 * (i % 10), (float)200 + 150 * (i / 10), 50, 50 }, 20, isDarkMode, WHITE, BLACK);
    }
}