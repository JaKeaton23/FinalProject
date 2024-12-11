#include "BST.h"

BST::BST() : root(nullptr) {}

void BST::insert(int value) {
    root = insert(root, value);
}

Node* BST::insert(Node* node, int value) {
    if (!node) return new Node(value);

    if (value < node->key)
        node->left = insert(node->left, value);
    else if (value > node->key)
        node->right = insert(node->right, value);

    return node;
}

void BST::remove(int value) {
    root = remove(root, value);
}

Node* BST::remove(Node* node, int value) {
    if (!node) return nullptr;

    if (value < node->key) {
        node->left = remove(node->left, value);
    } else if (value > node->key) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node* BST::search(int value) const {
    return search(root, value);
}

Node* BST::search(Node* node, int value) const {
    if (!node || node->key == value) return node;

    if (value < node->key)
        return search(node->left, value);

    return search(node->right, value);
}

Node* BST::getRoot() const {
    return root;
}

Node* BST::findMin(Node* node) const {
    while (node && node->left)
        node = node->left;
    return node;
}

