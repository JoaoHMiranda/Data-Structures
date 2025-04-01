#ifndef DIST_H
#define DIST_H

#include "node.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

template<class T>
class BinaryTree {
public:
    Tnode<T>* root;
    int nodeCount;
    int maxSum; // Stores the maximum path sum (max distance between two nodes)

    BinaryTree() : root(nullptr), nodeCount(0), maxSum(numeric_limits<int>::min()) {}

    // Computes and returns the maximum distance (max path sum between two leaves).
    int maxDistance() {
        maxSum = numeric_limits<int>::min(); // Reset before calculation
        computeMaxDistance(root);
        return maxSum;
    }
    
    // Recursive helper that computes the maximum path sum starting at 'node' and updates maxSum.
    int computeMaxDistance(Tnode<T>* node) {
        if (!node)
            return 0;
        int leftMax = computeMaxDistance(node->left);
        int rightMax = computeMaxDistance(node->right);
        // Update maxSum only if both children exist.
        if (node->left && node->right) {
            maxSum = max(maxSum, leftMax + rightMax + node->data);
        }
        return max(leftMax, rightMax) + node->data;
    }
    
    // Builds a complete binary tree from a vector of integers (level order).
    void buildFromVector(vector<T>& vec) {
        queue<Tnode<T>*> q;
        nodeCount = vec.size();
        if (!vec.empty()) {
            Tnode<T>* rootNode = Tnode<T>::createNode(vec[0]);
            root = rootNode;
            q.push(rootNode);
        }
        for (int i = 1; i < int(vec.size()); i += 2) {
            Tnode<T>* current = q.front();
            q.pop();
            Tnode<T>* leftChild = Tnode<T>::createNode(vec[i]);
            current->left = leftChild;
            q.push(leftChild);
            if (i + 1 < int(vec.size())) {
                Tnode<T>* rightChild = Tnode<T>::createNode(vec[i + 1]);
                current->right = rightChild;
                q.push(rightChild);
            }
        }
    }
    
    int size() {
        return nodeCount;
    }
    
    bool empty() {
        return root == nullptr;
    }
    
    // Inorder traversal printing the node values.
    void inorder() {
        inorderTraversal(root);
    }
    
    void inorderTraversal(Tnode<T>* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
    
    // Recursively clears the tree and frees memory.
    static void clear(Tnode<T>* node) {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        Tnode<T>::destroyNode(node);
    }
    
    // Clears the tree and resets attributes.
    void clear() {
        clear(root);
        root = nullptr;
        nodeCount = 0;
    }
};

#endif // DIST_H
