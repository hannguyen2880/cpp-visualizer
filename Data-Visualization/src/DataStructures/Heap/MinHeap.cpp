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
