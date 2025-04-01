#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
public:
    TreeNode<T>* root;
    int count;

    BinaryTree() : root(nullptr), count(0) {}

    // Inserts a value into the binary search tree.
    bool insert(const T& value) {
        TreeNode<T>* newNode = TreeNode<T>::createNode(value);
        if (!newNode)
            return false;
        if (!root) {
            root = newNode;
            count++;
            return true;
        }
        TreeNode<T>* current = root;
        TreeNode<T>* parent = nullptr;
        while (current) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else {
                // Value already exists; do not insert duplicates.
                TreeNode<T>::destroyNode(newNode);
                return false;
            }
        }
        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        count++;
        return true;
    }

    // Returns the number of nodes in the tree.
    int size() const {
        return count;
    }

    // Searches for a value in the tree.
    bool search(const T& value) const {
        TreeNode<T>* current = root;
        while (current) {
            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    // Removes a node with the specified value from the tree.
    bool erase(const T& value) {
        return eraseNode(root, value);
    }

private:
    // Helper recursive function to remove a node.
    bool eraseNode(TreeNode<T>*& node, const T& value) {
        if (!node)
            return false;
        if (value < node->data)
            return eraseNode(node->left, value);
        else if (value > node->data)
            return eraseNode(node->right, value);
        else { // Node found.
            if (!node->left) {
                TreeNode<T>* temp = node;
                node = node->right;
                TreeNode<T>::destroyNode(temp);
            } else if (!node->right) {
                TreeNode<T>* temp = node;
                node = node->left;
                TreeNode<T>::destroyNode(temp);
            } else {
                // Node with two children: find the inorder successor.
                TreeNode<T>* successor = node->right;
                while (successor->left)
                    successor = successor->left;
                node->data = successor->data;
                eraseNode(node->right, successor->data);
            }
            count--;
            return true;
        }
    }

public:
    // Clears the tree.
    void clear() {
        clearTree(root);
        root = nullptr;
        count = 0;
    }

private:
    // Helper recursive function to clear the tree.
    void clearTree(TreeNode<T>* node) {
        if (node) {
            clearTree(node->left);
            clearTree(node->right);
            TreeNode<T>::destroyNode(node);
        }
    }

public:
    // Preorder traversal (root, left, right).
    void preorder() const {
        preorderTraversal(root);
    }

private:
    void preorderTraversal(TreeNode<T>* node) const {
        if (node) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

public:
    // Inorder traversal (left, root, right).
    void inorder() const {
        inorderTraversal(root);
    }

private:
    void inorderTraversal(TreeNode<T>* node) const {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    // Postorder traversal (left, right, root).
    void postorder() const {
        postorderTraversal(root);
    }

private:
    void postorderTraversal(TreeNode<T>* node) const {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

#endif // BINARYTREE_H
