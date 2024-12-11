#include "AVL.h"
#include <algorithm> // For std::max

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::getHeight(AVLNode* node) const {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* AVLTree::rotateLeft(AVLNode* y) {
    AVLNode* x = y->right;
    AVLNode* T = x->left;

    x->left = y;
    y->right = T;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateRight(AVLNode* x) {
    AVLNode* y = x->left;
    AVLNode* T = y->right;

    y->right = x;
    x->left = T;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int value) {
    if (!node) return new AVLNode(value);

    if (value < node->key)
        node->left = insert(node->left, value);
    else if (value > node->key)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && value > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && value > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

AVLNode* AVLTree::remove(AVLNode* node, int value) {
    if (!node) return nullptr;

    if (value < node->key)
        node->left = remove(node->left, value);
    else if (value > node->key)
        node->right = remove(node->right, value);
    else {
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        AVLNode* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::remove(int value) {
    root = remove(root, value);
}

AVLNode* AVLTree::search(AVLNode* node, int value) const {
    if (!node || node->key == value) return node;

    if (value < node->key)
        return search(node->left, value);

    return search(node->right, value);
}

AVLNode* AVLTree::search(int value) const {
    return search(root, value);
}

AVLNode* AVLTree::findMin(AVLNode* node) const {
    while (node && node->left)
        node = node->left;
    return node;
}

AVLNode* AVLTree::getRoot() const {
    return root;
}

