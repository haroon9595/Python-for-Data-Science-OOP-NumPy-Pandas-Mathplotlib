#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

// New node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->color = RED;   // New node hamesha RED hoti hai
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left Rotate
void leftRotate(Node* &root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right Rotate
void rightRotate(Node* &root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree
void fixViolation(Node* &root, Node* z) {
    while (z != root && z->parent->color == RED) {

        Node* parent = z->parent;
        Node* grandparent = parent->parent;

        // Parent is left child
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            // Case 1: Uncle RED
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }
            else {
                // Case 2: z is right child
                if (z == parent->right) {
                    leftRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                // Case 3
                parent->color = BLACK;
                grandparent->color = RED;
                rightRotate(root, grandparent);
            }
        }
        // Parent is right child
        else {
            Node* uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }
            else {
                if (z == parent->left) {
                    rightRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                parent->color = BLACK;
                grandparent->color = RED;
                leftRotate(root, grandparent);
            }
        }
    }
    root->color = BLACK;
}

// BST Insert + Fix
void insert(Node* &root, int data) {
    Node* z = newNode(data);
    Node* y = NULL;
    Node* x = root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixViolation(root, z);
}

// Inorder Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main
int main() {
    Node* root = NULL;

    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 15);
    insert(root, 25);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
