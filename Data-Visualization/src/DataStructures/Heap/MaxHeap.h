#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(int key);
    void deleteMax();
    int getMax();
};
#endif
