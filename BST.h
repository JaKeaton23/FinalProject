#ifndef BST_H
#define BST_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    void insert(int value);
    void remove(int value);
    Node* search(int value) const;
    Node* getRoot() const;

private:
    Node* root;

    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* search(Node* node, int value) const;
    Node* findMin(Node* node) const;
};

#endif

