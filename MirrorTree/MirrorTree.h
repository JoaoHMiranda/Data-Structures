#ifndef MIRRORTREE_H
#define MIRRORTREE_H

#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class BinaryTree {
public:
    TreeNode<T>* root;
    string checkString;
    int nodeCount;
    
    BinaryTree() : root(nullptr), checkString(""), nodeCount(0) {}

    // Builds the tree in level order from a vector.
    void insert(const vector<T>& vec) {
        queue<TreeNode<T>*> q;
        nodeCount = vec.size();
        if (!vec.empty()) {
            TreeNode<T>* R = TreeNode<T>::createNode(vec[0]);
            root = R;
            q.push(R);
        }
        for (size_t i = 1; i < vec.size(); i += 2) {
            TreeNode<T>* current = q.front();
            q.pop();
            TreeNode<T>* leftChild = TreeNode<T>::createNode(vec[i]);
            current->left = leftChild;
            q.push(leftChild);
            if (i + 1 < vec.size()) {
                TreeNode<T>* rightChild = TreeNode<T>::createNode(vec[i + 1]);
                current->right = rightChild;
                q.push(rightChild);
            }
        }
    }
    
    // Performs an inorder traversal and appends each node's data (converted to string) to checkString.
    void inorder(TreeNode<T>* node) {
        if (node) {
            inorder(node->left);
            checkString += to_string(node->data);
            inorder(node->right);
        }
    }
    
    // Checks if the tree is mirrored by comparing the inorder traversal string with its reverse.
    // (Note: This method is simplistic and may not work for all cases.)
    bool isMirror() {
        checkString = "";
        inorder(root);
        string original = checkString;
        string reversed = original;
        reverse(reversed.begin(), reversed.end());
        return (original == reversed);
    }
    
    // Preorder traversal.
    void preorder(TreeNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void preorder() {
        preorder(root);
    }
    
    // Postorder traversal.
    void postorder(TreeNode<T>* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    
    void postorder() {
        postorder(root);
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

#endif // MIRRORTREE_H
