#include "Heap.h"
#include <algorithm> // For std::swap

void Heap::insert(int value) {
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

void Heap::deleteRoot() {
    if (data.empty()) return;
    data[0] = data.back();
    data.pop_back();
    heapifyDown(0);
}

const std::vector<int>& Heap::getHeap() const {
    return data;
}

void Heap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (data[index] > data[parent]) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void Heap::heapifyDown(int index) {
    int size = data.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && data[left] > data[largest])
            largest = left;
        if (right < size && data[right] > data[largest])
            largest = right;

        if (largest != index) {
            std::swap(data[index], data[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

