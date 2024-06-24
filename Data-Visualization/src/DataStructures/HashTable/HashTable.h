#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int hashFunction(int key);

public:
    HashTable(int size);
    void insertItem(int key);
    void deleteItem(int key);
    bool searchItem(int key);
};

#endif
