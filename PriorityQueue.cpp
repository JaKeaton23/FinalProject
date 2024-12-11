#include "PriorityQueue.h"
#include <stdexcept>
#include <algorithm>

PriorityQueue::PriorityQueue(std::function<bool(int, int)> cmp) : comparator(cmp) {}

void PriorityQueue::enqueue(int value) {
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

int PriorityQueue::dequeue() {
    if (data.empty()) throw std::runtime_error("PriorityQueue is empty");

    int topValue = data.front();
    data[0] = data.back();
    data.pop_back();
    heapifyDown(0);

    return topValue;
}

int PriorityQueue::peek() const {
    if (data.empty()) throw std::runtime_error("PriorityQueue is empty");
    return data.front();
}

bool PriorityQueue::isEmpty() const {
    return data.empty();
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (comparator(data[index], data[parent])) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index) {
    int size = data.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < size && comparator(data[left], data[best])) best = left;
        if (right < size && comparator(data[right], data[best])) best = right;

        if (best != index) {
            std::swap(data[index], data[best]);
            index = best;
        } else {
            break;
        }
    }
}

