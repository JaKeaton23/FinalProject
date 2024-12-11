#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <functional>

class PriorityQueue {
private:
    std::vector<int> data;
    std::function<bool(int, int)> comparator;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue(std::function<bool(int, int)> cmp = std::greater<int>());
    void enqueue(int value);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
};

#endif
