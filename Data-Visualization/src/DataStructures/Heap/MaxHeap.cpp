#include "MaxHeap.h"
#include <iostream>

void MaxHeap::heapifyUp(int index) {
	int parentIndex = (index - 1) / 2;
	if (index > 0 && heap[parentIndex] < heap[index]) {
		std::swap(heap[parentIndex], heap[index]);
		heapifyUp(parentIndex);
	}
}

void MaxHeap::heapifyDown(int index) {
	int biggest = index;
	int left = index * 2 + 1, right = index * 2 + 2;

	if (left < heap.size() && heap[left] > heap[biggest]) biggest = left;
	if (right < heap.size() && heap[right] > heap[biggest]) biggest = right;
	if (biggest != index) {
		std::swap(heap[index], heap[biggest]);
		heapifyDown(biggest);
	}
}

void MaxHeap::insert(int key) {
	heap.push_back(key);
	heapifyUp(heap.size() - 1);
}

void MaxHeap::deleteMax() {
	if (heap.size() > 0) {
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
	}
}
void MaxHeap::deleteNode(int key) {
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
void MaxHeap::deleteHeap() {
	heap.clear();
}

int MaxHeap::getMax() {
	return heap.size() ? heap[0] : -1;
}

int MaxHeap::getSize() {
	return heap.size();
}

const std::vector<int>& MaxHeap::getHeap() const {
    return heap;
}

void drawNode(int x, int y, int value, bool isDarkMode) {
    Color nodeColor = isDarkMode ? SKYBLUE : RED;
    Color textColor = isDarkMode ? WHITE : BLACK;

    DrawCircle(x, y, 20, nodeColor);
    DrawText(TextFormat("%d", value), x - MeasureText(TextFormat("%d", value), 20) / 2, y - 10, 20, textColor);
}


void drawLine(int x1, int y1, int x2, int y2, bool isDarkMode) {
    Color lineColor = isDarkMode ? RAYWHITE : BLACK;
    double angle = atan2(y2 - y1, x2 - x1);
    int offsetX = cos(angle) * 20;
    int offsetY = sin(angle) * 20;
    DrawLine(x1 + offsetX, y1 + offsetY, x2 - offsetX, y2 - offsetY, lineColor);
}

void DrawMaxHeap(MaxHeap* heap, int startX, int endX, int startY, int endY, bool isDarkMode) {
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

        drawNode(x, y, heapData[i], isDarkMode);

        if (i > 0) {
            int parentIndex = (i - 1) / 2;
            int parentLevel = (int)std::log2(parentIndex + 1);
            int parentNodesInLevel = 1 << parentLevel;
            int parentXSpacing = width / parentNodesInLevel;
            int parentXOffset = startX + parentXSpacing / 2;
            int parentX = parentXOffset + (parentIndex - (parentNodesInLevel - 1)) * parentXSpacing;
            int parentY = startY + parentLevel * levelHeight;

            drawLine(parentX, parentY, x, y, isDarkMode);
        }
    }    
}