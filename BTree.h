#ifndef BTREE_H
#define BTREE_H

#include <vector>

class BTreeNode {
public:
    std::vector<int> keys; // Keys in the node
    std::vector<BTreeNode*> children; // Child pointers
    bool isLeaf; // True if the node is a leaf node
    int t; // Minimum degree

    BTreeNode(int t, bool isLeaf);

    void traverse();
    BTreeNode* search(int key);

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root; // Pointer to root node
    int t; // Minimum degree

public:
    BTree(int t);

    void traverse();
    BTreeNode* search(int key);
    void insert(int key);
};

#endif

