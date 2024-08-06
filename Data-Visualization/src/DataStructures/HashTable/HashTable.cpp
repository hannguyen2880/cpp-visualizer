#include "HashTable.h"

HashTable::HashTable(int size) {
    table.resize(size);
}

int HashTable::hashFunction(int key) {
    return key % table.size();
}

void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
}

bool HashTable::searchItem(int key) {
    int index = hashFunction(key);
    for (int i : table[index]) {
        if (i == key) return true;
    }
    return false;
}

std::vector<std::list<int>> HashTable::getTable() {
    return table;
}
