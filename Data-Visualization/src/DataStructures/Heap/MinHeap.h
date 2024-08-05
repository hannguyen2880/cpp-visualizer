#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(int key);
    void deleteMin();
    int getMin();
    int getSize();
};

#endif
