#include "BTree.h"
#include <iostream>

BTreeNode::BTreeNode(int t, bool isLeaf) : t(t), isLeaf(isLeaf) {}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }
    if (!isLeaf)
        children[i]->traverse();
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
        i++;

    if (i < keys.size() && keys[i] == key)
        return this;

    if (isLeaf)
        return nullptr;

    return children[i]->search(key);
}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.resize(keys.size() + 1);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;
        i++;

        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);

            if (keys[i] < key)
                i++;
        }
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    auto z = new BTreeNode(y->t, y->isLeaf);
    z->keys.resize(t - 1);

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        z->children.resize(t);
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->keys.resize(t - 1);

    children.insert(children.begin() + i + 1, z);

    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

BTree::BTree(int t) : root(nullptr), t(t) {}

void BTree::traverse() {
    if (root)
        root->traverse();
}

BTreeNode* BTree::search(int key) {
    return root ? root->search(key) : nullptr;
}

void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            auto s = new BTreeNode(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);

            int i = (s->keys[0] < key) ? 1 : 0;
            s->children[i]->insertNonFull(key);

            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}
