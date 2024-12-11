#include "StackQueue.h"
#include <stdexcept>

// Stack implementation
void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (!data.empty()) {
        int topValue = data.back();
        data.pop_back();
        return topValue;
    }
    throw std::runtime_error("Stack is empty");
}

int Stack::top() const {
    if (!data.empty()) {
        return data.back();
    }
    throw std::runtime_error("Stack is empty");
}

bool Stack::isEmpty() const {
    return data.empty();
}

// Queue implementation
void Queue::enqueue(int value) {
    data.push_back(value);
}

int Queue::dequeue() {
    if (!data.empty()) {
        int frontValue = data.front();
        data.pop_front();
        return frontValue;
    }
    throw std::runtime_error("Queue is empty");
}

int Queue::front() const {
    if (!data.empty()) {
        return data.front();
    }
    throw std::runtime_error("Queue is empty");
}

bool Queue::isEmpty() const {
    return data.empty();
}

