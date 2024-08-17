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

bool HashTable::insertItem(int key, std::vector<TransformerHash>& transforms) {
    int index = linearProbing(key);
    if (index == -1) {
        TransformerHash errorTransform(
            index,
            "Error: Cannot insert value, table is full or no available slot!"
        );
        transforms.push_back(errorTransform);
        return false;
    }
    // Searching Process step-by-step
    TransformerHash searchingTransform(
        index,
        "Searching for the position to insert..."
    );
    transforms.push_back(searchingTransform);

    std::string hashfunction = std::to_string(hashFunction(key));
    std::string key_str = std::to_string(key);

    TransformerHash searchingTransform2(
        index,
        "Hash(" + key_str + ") = " + hashfunction
    );
    transforms.push_back(searchingTransform2);

    if (hashFunction(key) != linearProbing(key)) {
        std::string problingfunction = std::to_string(linearProbing(key));
        TransformerHash searchingTransform3(
            index,
            "Probling(" + key_str + ") = " + problingfunction
        );
        transforms.push_back(searchingTransform3);
    }

    // insert
    table[index] = key;
    isFilled[index] = true;
    // Inserting step-by-step

    TransformerHash insertingTransform(
        index,
        "Inserting value into the hash table!"
    );
    transforms.push_back(insertingTransform);

    return true;
}

bool HashTable::deleteItem(int key, std::vector<TransformerHash>& transforms, int& idx) {
    int index = hashFunction(key);
    int originalIndex = index;
    TransformerHash delete1(
        index,
        "Searching for value to delete..."
    );
    transforms.push_back(delete1);

    std::string hashfunction = std::to_string(hashFunction(key));
    std::string key_str = std::to_string(key);
    TransformerHash delete2(
        index,
        "Hash(" + key_str + ") = " + hashfunction
    );
    transforms.push_back(delete2);

    while (isFilled[index]) {
        TransformerHash delete3(
            index,
            "table[" + std::to_string(index) + "] = " + std::to_string(table[index])
        );
        transforms.push_back(delete3);

        if (table[index] == key) {
            TransformerHash searchingTransform3(
                index,
                "Because table[" + std::to_string(index) + "] = " + std::to_string(key)
                + ", we found the value."
            );
            transforms.push_back(searchingTransform3);
            table[index] = -1;
            isFilled[index] = false;

            TransformerHash delete4(
                index,
                "Value " + std::to_string(key) + " is deleted!\n"
                + "table[index] = -1; isFilled[index] = false;"
            );
            transforms.push_back(delete4);
            idx = index;
            return true;
        }
        TransformerHash delete5(
            index,
            "Because table[" + std::to_string(index) + "] != " + std::to_string(key)
            + ", we increase the index."
        );
        transforms.push_back(delete5);
        index = (index + 1) % size;

        if (index == originalIndex) {
            return false;
        }
    }
    TransformerHash delete6(
        index,
        "No such the value" + std::to_string(key) + " found!"
    );
    transforms.push_back(delete6);

    return false;
}

bool HashTable::searchItem(int key, std::vector<TransformerHash>& transforms, int& idx) {
    int index = hashFunction(key);
    int originalIndex = index;

    TransformerHash searchingTransform(
        index,
        "Searching..."
    );
    transforms.push_back(searchingTransform);

    std::string hashfunction = std::to_string(hashFunction(key));
    std::string key_str = std::to_string(key);
    TransformerHash searchingTransform1(
        index,
        "Hash(" + key_str + ") = " + hashfunction
    );
    transforms.push_back(searchingTransform1);

    while (isFilled[index]) {
        TransformerHash searchingTransform2(
            index,
            "table[" + std::to_string(index) + "] = " + std::to_string(table[index])
        );
        transforms.push_back(searchingTransform2);

        if (table[index] == key) {
            TransformerHash searchingTransform3(
                index,
                "Because table[" + std::to_string(index) + "] = " + std::to_string(key)
                + ", we found the value."
            );
            transforms.push_back(searchingTransform3);
            idx = index;
            return true;
        }

        TransformerHash searchingTransform4(
            index,
            "Because table[" + std::to_string(index) + "] != " + std::to_string(key)
            + ", we increase the index."
        );
        transforms.push_back(searchingTransform4);
        index = (index + 1) % size;

        if (index == originalIndex) {
            return false;
        }
    }
    TransformerHash searchingTransform5(
        index,
        "No such the value" + std::to_string(key) + " found!"
    );
    transforms.push_back(searchingTransform5);

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

void HashTable::FillTableMode(bool isDarkMode, std::vector<int> indexs) {
    std::vector<bool> check(size, false);
    for (int i : indexs) check[i] = true;

    for (int i = 0; i < table.size(); ++i) {
        if (!isFilled[i]) continue;
        // put table[i] in index 'i'
        std::string str = std::to_string(table[i]);
        const char* txt = str.c_str();
        if (check[i]) {
            Rectangle rect = Rectangle{ (float)500 + 80 * i, 200, 50, 50 };
            Color color = isDarkMode ? BEIGE : SKYBLUE;
            DrawRectangle((float)500 + 80 * (i % 10), (float)200 + 150 * (i / 10), 50, 50, color);
            DrawTextRectangle(txt, { (float)500 + 80 * (i % 10), (float)200 + 150 * (i / 10), 50, 50 }, 20, isDarkMode, BLACK, DARKBLUE);
        }
        else DrawTextRectangle(txt, { (float)500 + 80 * (i % 10), (float)200 + 150 * (i / 10), 50, 50 }, 20, isDarkMode, WHITE, BLACK);
    }
}