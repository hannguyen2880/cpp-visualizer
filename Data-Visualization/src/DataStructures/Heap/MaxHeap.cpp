#include "MaxHeap.h"

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

int MaxHeap::getMax() {
	return heap.size() ? heap[0] : -1;
}

int MaxHeap::getSize() {
	return heap.size();
}


