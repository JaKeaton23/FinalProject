#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
public:
    void insert(int value);
    void deleteRoot();
    const std::vector<int>& getHeap() const;

private:
    std::vector<int> data;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif
