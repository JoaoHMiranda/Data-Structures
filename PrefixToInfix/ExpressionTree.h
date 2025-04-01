#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <class T>
class ExpressionTree {
public:
    TreeNode<T>* root;
    int nodeCount;

    ExpressionTree() : root(nullptr), nodeCount(0) {}

    // Helper function: returns true if the character is an operator.
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    // Recursively inserts a new node into the tree.
    // Only operator nodes can have children.
    bool insert(TreeNode<T>* newNode, TreeNode<T>** p) {
        if (!*p) {
            *p = newNode;
            return true;
        }
        // If the current node is not an operator, it cannot have children.
        if (!isOperator((*p)->data)) {
            return false;
        }
        // Try inserting into the left subtree; if it fails, try the right subtree.
        if (!insert(newNode, &((*p)->left))) {
            return insert(newNode, &((*p)->right));
        }
        return true;
    }

    // Inserts a new node with the given value into the tree.
    bool insert(T value) {
        TreeNode<T>* newNode = TreeNode<T>::createNode(value);
        if (!newNode)
            return false;
        bool inserted = insert(newNode, &root);
        if (inserted)
            nodeCount++;
        return inserted;
    }

    // Inorder traversal that prints the infix expression with parentheses.
    void inorderTraversal() {
        inorder(root);
    }

    void inorder(TreeNode<T>* node) {
        if (node) {
            bool op = isOperator(node->data);
            if (op)
                cout << "( ";
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
            if (op)
                cout << ") ";
        }
    }

    // Preorder traversal.
    void preorderTraversal() {
        preorder(root);
    }

    void preorder(TreeNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder traversal.
    void postorderTraversal() {
        postorder(root);
    }

    void postorder(TreeNode<T>* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    int size() {
        return nodeCount;
    }

    bool empty() {
        return root == nullptr;
    }

    // Recursively clears the tree and frees the memory.
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

#endif // EXPRESSION_TREE_H
