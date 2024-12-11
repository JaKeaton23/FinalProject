#include "RedBlack.h"
#include <iostream>

RedBlackTree::RedBlackTree() {
    TNULL = new RedBlackNode(0);
    TNULL->color = BLACK;
    root = TNULL;
}

void RedBlackTree::rotateLeft(RedBlackNode* x) {
    RedBlackNode* y = x->right;
    x->right = y->left;

    if (y->left != TNULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(RedBlackNode* x) {
    RedBlackNode* y = x->left;
    x->left = y->right;

    if (y->right != TNULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void RedBlackTree::fixInsert(RedBlackNode* k) {
    while (k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) {
            RedBlackNode* uncle = k->parent->parent->right;

            if (uncle->color == RED) {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    rotateLeft(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rotateRight(k->parent->parent);
            }
        } else {
            RedBlackNode* uncle = k->parent->parent->left;

            if (uncle->color == RED) {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rotateRight(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rotateLeft(k->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int key) {
    RedBlackNode* node = new RedBlackNode(key);
    node->parent = nullptr;
    node->left = TNULL;
    node->right = TNULL;

    RedBlackNode* y = nullptr;
    RedBlackNode* x = root;

    while (x != TNULL) {
        y = x;
        x = (node->key < x->key) ? x->left : x->right;
    }

    node->parent = y;

    if (!y)
        root = node;
    else if (node->key < y->key)
        y->left = node;
    else
        y->right = node;

    if (!node->parent) {
        node->color = BLACK;
        return;
    }

    if (!node->parent->parent)
        return;

    fixInsert(node);
}

void RedBlackTree::traverse() const {

}
