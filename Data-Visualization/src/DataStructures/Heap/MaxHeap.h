#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include "raylib.h"
#include <cmath>

class MaxHeap {
private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(int key);
    void deleteMax();
    void deleteHeap();
    int getMax();
    int getSize();
    void deleteNode(int key);
    const std::vector<int>& getHeap() const;
};
void DrawMaxHeap(MaxHeap* heap, int startX, int endX, int startY, int endY, bool isDarkMode);
#endif
