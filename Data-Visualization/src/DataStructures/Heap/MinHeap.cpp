#include "MinHeap.h"

void MinHeap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && heap[parentIndex] > heap[index]) {
        std::swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}

void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;

    if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::insert(int key) {
    heap.push_back(key);
    heapifyUp(heap.size() - 1);
}

void MinHeap::deleteMin() {
    if (heap.size() > 0) {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
}

int MinHeap::getMin() {
    return heap.size() ? heap[0] : -1;
}

int MinHeap::getSize() {
    return heap.size();
}

void MinHeap::deleteNode(int key) {
    auto it = std::find(heap.begin(), heap.end(), key);
    if (it != heap.end()) {
        int index = std::distance(heap.begin(), it);
        heap[index] = heap.back();
        heap.pop_back();
        if (index < heap.size()) {
            heapifyDown(index);
            heapifyUp(index);
        }
    }
}

void MinHeap::deleteHeap() {
    heap.clear();
}

const std::vector<int>& MinHeap::getHeap() const {
    return heap;
}

void drawNodeMinHeap(int x, int y, int value, bool isDarkMode) {
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;

    DrawCircle(x, y, 20, nodeColor);
    DrawText(TextFormat("%d", value), x - MeasureText(TextFormat("%d", value), 20) / 2, y - 10, 20, textColor);
}


void drawLineMinHeap(int x1, int y1, int x2, int y2, bool isDarkMode) {
    Color lineColor = isDarkMode ? RAYWHITE : BLACK;
    double angle = atan2(y2 - y1, x2 - x1);
    int offsetX = cos(angle) * 20;
    int offsetY = sin(angle) * 20;
    DrawLine(x1 + offsetX, y1 + offsetY, x2 - offsetX, y2 - offsetY, lineColor);
}

void DrawMinHeap(MinHeap* heap, int startX, int endX, int startY, int endY, bool isDarkMode) {
    int size = heap->getSize();
    if (size == 0) return;

    Color backgroundColor = isDarkMode ? BLACK : RAYWHITE;
    Color nodeColor = isDarkMode ? RAYWHITE : BLACK;
    ClearBackground(backgroundColor);

    const std::vector<int>& heapData = heap->getHeap();

    int height = (int)std::log2(size) + 1;
    int width = endX - startX;
    int levelHeight = (endY - startY) / height;

    for (int i = 0; i < size; ++i) {
        int level = (int)std::log2(i + 1);
        int nodesInLevel = 1 << level;
        int xSpacing = width / nodesInLevel;
        int xOffset = startX + xSpacing / 2;
        int x = xOffset + (i - (nodesInLevel - 1)) * xSpacing;
        int y = startY + level * levelHeight;

        drawNodeMinHeap(x, y, heapData[i], isDarkMode);

        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            int parentLevel = (int)std::log2(parentIndex + 1);
            int parentNodesInLevel = 1 << parentLevel;
            int parentXSpacing = width / parentNodesInLevel;
            int parentXOffset = startX + parentXSpacing / 2;
            int parentX = parentXOffset + (parentIndex - (parentNodesInLevel - 1)) * parentXSpacing;
            int parentY = startY + parentLevel * levelHeight;

            drawLineMinHeap(parentX, parentY, x, y, isDarkMode);
        }
    }
}
