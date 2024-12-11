#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <deque>

class Stack {
private:
    std::deque<int> data;

public:
    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
};

class Queue {
private:
    std::deque<int> data;

public:
    void enqueue(int value);
    int dequeue();
    int front() const;
    bool isEmpty() const;
};

#endif

