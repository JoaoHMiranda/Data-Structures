#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Color definitions
#define RED 1
#define BLACK 0

// Node structure for the Red-Black Tree.
struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    int color; // RED or BLACK
};

typedef Node* RBNodePtr;

class RBTree {
private:
    RBNodePtr root;
    RBNodePtr nil;      // Sentinel node representing TNULL
    int nodeCount;

    // Helper functions for tree traversals.
    void preorderHelper(RBNodePtr node) {
        if (node != nil) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    void inorderHelper(RBNodePtr node) {
        if (node != nil) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    void postorderHelper(RBNodePtr node) {
        if (node != nil) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    RBNodePtr searchTreeHelper(RBNodePtr node, int key) {
        if (node == nil || key == node->data)
            return node;
        if (key < node->data)
            return searchTreeHelper(node->left, key);
        return searchTreeHelper(node->right, key);
    }

    // Fix the tree after deletion.
    void fixDelete(RBNodePtr x) {
        RBNodePtr s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // Replace subtree u with subtree v.
    void rbTransplant(RBNodePtr u, RBNodePtr v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    // Helper for deletion.
    void deleteNodeHelper(RBNodePtr node, int key) {
        RBNodePtr z = nil;
        RBNodePtr x, y;
        while (node != nil) {
            if (node->data == key)
                z = node;
            if (node->data <= key)
                node = node->right;
            else
                node = node->left;
        }
        if (z == nil) {
            cout << "Couldn't find key in the tree" << endl;
            return;
        }
        y = z;
        int yOriginalColor = y->color;
        if (z->left == nil) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        nodeCount--;
        if (yOriginalColor == BLACK)
            fixDelete(x);
    }

    // Fix the tree after insertion.
    void fixInsert(RBNodePtr k) {
        RBNodePtr u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
                break;
        }
        root->color = BLACK;
    }

    // Left rotate x.
    void leftRotate(RBNodePtr x) {
        RBNodePtr y = x->right;
        x->right = y->left;
        if (y->left != nil)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    // Right rotate x.
    void rightRotate(RBNodePtr x) {
        RBNodePtr y = x->left;
        x->left = y->right;
        if (y->right != nil)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    // Prints the tree in a pretty format.
    void printHelper(RBNodePtr node, std::string indent, bool last) {
        if (node != nil) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }
            string sColor = (node->color == RED) ? "RED" : "BLACK";
            cout << node->data << "(" << sColor << ")" << endl;
            printHelper(node->left, indent, false);
            printHelper(node->right, indent, true);
        }
    }

public:
    RBTree() {
        nil = new Node;
        nil->color = BLACK;
        nil->left = nullptr;
        nil->right = nullptr;
        root = nil;
        nodeCount = 0;
    }

    // Insert a new key into the tree.
    void insert(int key) {
        RBNodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = nil;
        node->right = nil;
        node->color = RED; // New node must be red
        nodeCount++;

        RBNodePtr y = nullptr;
        RBNodePtr x = root;

        while (x != nil) {
            y = x;
            if (node->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        node->parent = y;
        if (y == nullptr)
            root = node;
        else if (node->data < y->data)
            y->left = node;
        else
            y->right = node;

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }
        if (node->parent->parent == nullptr)
            return;
        fixInsert(node);
    }

    // Delete a node with the given key.
    void deleteNode(int key) {
        deleteNodeHelper(root, key);
    }

    // Returns the node with the minimum key in the subtree rooted at node.
    RBNodePtr minimum(RBNodePtr node) {
        while (node->left != nil)
            node = node->left;
        return node;
    }

    // Returns the node with the maximum key in the subtree rooted at node.
    RBNodePtr maximum(RBNodePtr node) {
        while (node->right != nil)
            node = node->right;
        return node;
    }

    // Search the tree for a key.
    RBNodePtr searchTree(int key) {
        return searchTreeHelper(root, key);
    }

    // Tree traversals.
    void preorder() {
        if (nodeCount == 0)
            cout << "Tree is empty" << endl;
        else
            preorderHelper(root);
        cout << endl;
    }

    void inorder() {
        if (nodeCount == 0)
            cout << "Tree has no elements" << endl;
        else
            inorderHelper(root);
        cout << endl;
    }

    void postorder() {
        if (nodeCount == 0)
            cout << "Tree has no elements" << endl;
        else
            postorderHelper(root);
        cout << endl;
    }

    // Pretty print the tree.
    void prettyPrint() {
        if (nodeCount == 0)
            cout << "Tree has no elements" << endl;
        else
            printHelper(root, "", true);
    }

    // Clears the tree.
    void clearTree() {
        if (!isEmpty()) {
            queue<RBNodePtr> q;
            q.push(root);
            RBNodePtr p;
            while (!q.empty()) {
                p = q.front();
                q.pop();
                if (p->left != nil)
                    q.push(p->left);
                if (p->right != nil)
                    q.push(p->right);
                delete p;
                nodeCount--;
            }
            root = nil;
        } else {
            cout << "Tree is empty" << endl;
        }
    }

    // Returns the number of elements.
    int getSize() {
        return nodeCount;
    }

    // Returns true if the tree is empty.
    bool isEmpty() {
        return nodeCount <= 0;
    }

    // Returns the root of the tree.
    RBNodePtr getRoot() {
        return root;
    }
};

#endif // RBTREE_H
