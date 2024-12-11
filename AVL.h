#ifndef AVL_H
#define AVL_H

struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    AVLTree();
    void insert(int value);
    void remove(int value);
    AVLNode* search(int value) const;
    AVLNode* getRoot() const;

private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, int value);
    AVLNode* remove(AVLNode* node, int value);
    AVLNode* search(AVLNode* node, int value) const;

    int getHeight(AVLNode* node) const;
    int getBalance(AVLNode* node) const;

    AVLNode* rotateLeft(AVLNode* y);
    AVLNode* rotateRight(AVLNode* x);

    AVLNode* findMin(AVLNode* node) const;
};

#endif

