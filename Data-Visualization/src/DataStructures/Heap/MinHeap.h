#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>
#include "raylib.h"
#include <cmath>

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
    void deleteNode(int key);
    void deleteHeap();
    const std::vector<int>& getHeap() const;
};
void DrawMinHeap(MinHeap* heap, int startX, int endX, int startY, int endY, bool isDarkMode);
#endif
