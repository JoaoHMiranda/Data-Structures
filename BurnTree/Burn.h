#ifndef BURN_H
#define BURN_H

#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class T>
class BinaryTree {
public:
    TreeNode<T>* root;
    int nodeCount;

    BinaryTree() : root(nullptr), nodeCount(0) {}

    // Recursively searches for a node with the given value starting at 'node'.
    TreeNode<T>* find(TreeNode<T>* node, T value) {
        if (!node)
            return nullptr;
        if (node->data == value)
            return node;
        TreeNode<T>* leftResult = find(node->left, value);
        if (leftResult)
            return leftResult;
        return find(node->right, value);
    }

    // Searches for a node with the given value starting from the root.
    TreeNode<T>* find(T value) {
        return find(root, value);
    }

    // Burns (spreads) the tree starting from node 'r' using breadth-first search.
    void burn(TreeNode<T>* r) {
        if (!r) {
            cout << "Not found" << endl;
            return;
        }
        cout << r->data << " ";
        queue<TreeNode<T>*> q;
        q.push(r);
        r->visited = true;

        while (!q.empty()) {
            TreeNode<T>* u = q.front();
            q.pop();
            if (u->left && !u->left->visited) {
                q.push(u->left);
                cout << u->left->data << " ";
                u->left->visited = true;
            }
            if (u->right && !u->right->visited) {
                q.push(u->right);
                cout << u->right->data << " ";
                u->right->visited = true;
            }
            if (u->parent && !u->parent->visited) {
                q.push(u->parent);
                cout << u->parent->data << " ";
                u->parent->visited = true;
            }
        }
        cout << endl;
    }

    // Builds a binary tree in level order from a vector.
    void buildFromVector(vector<T>& vec) {
        queue<TreeNode<T>*> q;
        nodeCount = vec.size();
        if (!vec.empty()) {
            TreeNode<T>* R = TreeNode<T>::createNode(vec[0]);
            root = R;
            q.push(R);
        }
        for (int i = 1; i < (int)vec.size(); i += 2) {
            TreeNode<T>* current = q.front();
            q.pop();
            TreeNode<T>* leftChild = TreeNode<T>::createNode(vec[i]);
            current->left = leftChild;
            leftChild->parent = current;
            q.push(leftChild);
            if (i + 1 < (int)vec.size()) {
                TreeNode<T>* rightChild = TreeNode<T>::createNode(vec[i + 1]);
                current->right = rightChild;
                rightChild->parent = current;
                q.push(rightChild);
            }
        }
    }

    int size() const {
        return nodeCount;
    }

    bool empty() const {
        return root == nullptr;
    }

    // Recursively clears the tree.
    static void clear(TreeNode<T>* node) {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        TreeNode<T>::destroyNode(node);
    }

    void clear() {
        clear(root);
        root = nullptr;
        nodeCount = 0;
    }
};

#endif // BURN_H
