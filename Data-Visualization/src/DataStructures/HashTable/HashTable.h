#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "raylib.h"
#include "../../Graphic.h"
#include "../../Transform.h"

class HashTable {
private:
    std::vector<int> table;     
    int size;
    int hashFunction(int key);
    int linearProbing(int key);

public:
    HashTable(int size);
    bool insertItem(int key, std::vector<TransformerHash>& transforms);
    bool deleteItem(int key, std::vector<TransformerHash>& transforms, int& idx);
    bool searchItem(int key, std::vector<TransformerHash>& transforms, int& idx);
    std::vector<int> getTable();
    void deleteTable();
    std::vector<bool> isFilled;
    void FillTable(bool isDarkMode);
    void FillTableMode(bool isDarkMode, std::vector<int> indexs);
};
void DrawTable(bool isDarkMode);

#endif