#ifndef REDBLACK_H
#define REDBLACK_H

enum Color { RED, BLACK };

struct RedBlackNode {
    int key;
    Color color;
    RedBlackNode* left;
    RedBlackNode* right;
    RedBlackNode* parent;

    RedBlackNode(int value) : key(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RedBlackNode* root;
    RedBlackNode* TNULL;

    void rotateLeft(RedBlackNode* x);
    void rotateRight(RedBlackNode* x);
    void fixInsert(RedBlackNode* node);

public:
    RedBlackTree();
    void insert(int key);
    void traverse() const;
};

#endif

