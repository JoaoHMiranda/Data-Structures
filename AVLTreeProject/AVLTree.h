#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class AVLTree {
public:
    int nodeCount;
    AVLNode<T>* root;
    
    AVLTree() : nodeCount(0), root(nullptr) {}

    // Returns the minimum node in the subtree.
    static AVLNode<T>* findMin(AVLNode<T>* node) {
        if (node->left)
            return findMin(node->left);
        return node;
    }
    
    // Returns the minimum value stored in the tree.
    T min() {
        if (!root) {
            T temp{};
            return temp;
        }
        AVLNode<T>* node = findMin(root);
        return node->data;
    }
    
    // Returns the maximum node in the subtree.
    static AVLNode<T>* findMax(AVLNode<T>* node) {
        if (node->right)
            return findMax(node->right);
        return node;
    }
    
    // Returns the maximum value stored in the tree.
    T max() {
        if (!root) {
            T temp{};
            return temp;
        }
        AVLNode<T>* node = findMax(root);
        return node->data;
    }
    
    // Computes the height of the subtree.
    static int height(AVLNode<T>* node) {
        if (!node)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
    
    // Returns the height of the tree.
    int height() {
        return AVLTree<T>::height(root);
    }
    
    // Searches for a node with the given value.
    static AVLNode<T>* find(AVLNode<T>* node, T value) {
        if (!node || node->data == value)
            return node;
        if (value < node->data)
            return find(node->left, value);
        return find(node->right, value);
    }
    
    // Returns true if the value is found in the tree.
    bool search(T value) {
        return (find(root, value) != nullptr);
    }
    
    // --- Rotations ---
    
    // Simple right rotation.
    static void rotateRight(AVLNode<T>** nodeRef) {
        AVLNode<T>* a = *nodeRef;
        AVLNode<T>* b = a->left;
        a->left = b->right;
        b->right = a;
        *nodeRef = b;
        if (b->balanceFactor == -1) {
            a->balanceFactor = b->balanceFactor = 0;
        } else {
            a->balanceFactor = -1;
            b->balanceFactor = 1;
        }
    }
    
    // Simple left rotation.
    static void rotateLeft(AVLNode<T>** nodeRef) {
        AVLNode<T>* a = *nodeRef;
        AVLNode<T>* b = a->right;
        a->right = b->left;
        b->left = a;
        *nodeRef = b;
        if (b->balanceFactor == 1) {
            a->balanceFactor = b->balanceFactor = 0;
        } else {
            a->balanceFactor = 1;
            b->balanceFactor = -1;
        }
    }
    
    // Double rotation: left-right.
    static void rotateLeftRight(AVLNode<T>** nodeRef) {
        AVLNode<T>* a = *nodeRef;
        AVLNode<T>* b = a->left;
        AVLNode<T>* c = b->right;
        b->right = c->left;
        a->left = c->right;
        c->right = a;
        c->left = b;
        *nodeRef = c;
        if (c->balanceFactor == 0) {
            a->balanceFactor = b->balanceFactor = 0;
        } else if (c->balanceFactor == -1) {
            b->balanceFactor = 0;
            a->balanceFactor = 1;
            c->balanceFactor = 0;
        } else { // c->balanceFactor == 1
            a->balanceFactor = 0;
            b->balanceFactor = -1;
            c->balanceFactor = 0;
        }
    }
    
    // Double rotation: right-left.
    static void rotateRightLeft(AVLNode<T>** nodeRef) {
        AVLNode<T>* a = *nodeRef;
        AVLNode<T>* b = a->right;
        AVLNode<T>* c = b->left;
        b->left = c->right;
        a->right = c->left;
        c->left = a;
        c->right = b;
        *nodeRef = c;
        if (c->balanceFactor == 0) {
            a->balanceFactor = b->balanceFactor = 0;
        } else if (c->balanceFactor == 1) {
            a->balanceFactor = -1;
            b->balanceFactor = 0;
            c->balanceFactor = 0;
        } else { // c->balanceFactor == -1
            a->balanceFactor = 0;
            b->balanceFactor = 1;
            c->balanceFactor = 0;
        }
    }
    
    // --- Insertion ---
    
    // Recursive insertion; 'heightIncreased' indicates if the subtree's height increased.
    static bool insertRec(AVLNode<T>** nodeRef, AVLNode<T>* newNode, bool* heightIncreased) {
        if (!(*nodeRef)) {
            *nodeRef = newNode;
            newNode->balanceFactor = 0;
            *heightIncreased = true;
            return true;
        }
        if ((*nodeRef)->data == newNode->data) {
            AVLNode<T>::destroyNode(newNode);
            *heightIncreased = false;
            return false;
        }
        if (newNode->data < (*nodeRef)->data) {
            if (insertRec(&((*nodeRef)->left), newNode, heightIncreased)) {
                if (*heightIncreased) {
                    switch ((*nodeRef)->balanceFactor) {
                        case 0:
                            (*nodeRef)->balanceFactor = -1;
                            *heightIncreased = true;
                            break;
                        case 1:
                            (*nodeRef)->balanceFactor = 0;
                            *heightIncreased = false;
                            break;
                        case -1:
                            if (((*nodeRef)->left)->balanceFactor == -1) {
                                // Single right rotation
                                rotateRight(nodeRef);
                            } else {
                                // Double left-right rotation
                                rotateLeftRight(nodeRef);
                            }
                            *heightIncreased = false;
                            break;
                    }
                }
                return true;
            }
            return false;
        } else {
            if (insertRec(&((*nodeRef)->right), newNode, heightIncreased)) {
                if (*heightIncreased) {
                    switch ((*nodeRef)->balanceFactor) {
                        case 0:
                            (*nodeRef)->balanceFactor = 1;
                            *heightIncreased = true;
                            break;
                        case -1:
                            (*nodeRef)->balanceFactor = 0;
                            *heightIncreased = false;
                            break;
                        case 1:
                            if (((*nodeRef)->right)->balanceFactor == 1) {
                                // Single left rotation
                                rotateLeft(nodeRef);
                            } else {
                                // Double right-left rotation
                                rotateRightLeft(nodeRef);
                            }
                            *heightIncreased = false;
                            break;
                    }
                }
                return true;
            }
            return false;
        }
    }
    
    // Inserts a value into the AVL tree.
    bool insert(T value) {
        AVLNode<T>* newNode = AVLNode<T>::createNode(value);
        bool heightIncreased = false;
        if (!newNode)
            return false;
        nodeCount++;
        if (!root) {
            root = newNode;
            heightIncreased = true;
            return heightIncreased;
        }
        insertRec(&root, newNode, &heightIncreased);
        return heightIncreased;
    }
    
    // --- Removal ---
    
    // Recursive removal; 'deletedNode' will point to the removed node.
    static bool removeRec(AVLNode<T>** nodeRef, T value, AVLNode<T>** deletedNode) {
        if (!(*nodeRef))
            return false;
        if (value < (*nodeRef)->data) {
            if (removeRec(&((*nodeRef)->left), value, deletedNode)) {
                // Adjust balance factor after deletion from left subtree.
                if ((*nodeRef)->balanceFactor == -1) {
                    (*nodeRef)->balanceFactor = 0;
                    return true;
                }
                if ((*nodeRef)->balanceFactor == 0) {
                    (*nodeRef)->balanceFactor = 1;
                    return false;
                }
                if (((*nodeRef)->right) && ((*nodeRef)->right->balanceFactor >= 0)) {
                    rotateLeft(nodeRef);
                    return true;
                } else {
                    rotateRightLeft(nodeRef);
                    return true;
                }
            }
            return false;
        }
        if (value > (*nodeRef)->data) {
            if (removeRec(&((*nodeRef)->right), value, deletedNode)) {
                // Adjust balance factor after deletion from right subtree.
                if ((*nodeRef)->balanceFactor == 1) {
                    (*nodeRef)->balanceFactor = 0;
                    return true;
                }
                if ((*nodeRef)->balanceFactor == 0) {
                    (*nodeRef)->balanceFactor = -1;
                    return false;
                }
                if (((*nodeRef)->left) && ((*nodeRef)->left->balanceFactor <= 0)) {
                    rotateRight(nodeRef);
                    return true;
                } else {
                    rotateLeftRight(nodeRef);
                    return true;
                }
            }
            return false;
        }
        // Node found.
        if (!(*nodeRef)->left) {
            *deletedNode = *nodeRef;
            *nodeRef = (*nodeRef)->right;
            return true;
        }
        if (!(*nodeRef)->right) {
            *deletedNode = *nodeRef;
            *nodeRef = (*nodeRef)->left;
            return true;
        }
        // Node with two children: swap with minimum in right subtree.
        AVLNode<T>* minNode = findMin((*nodeRef)->right);
        std::swap((*nodeRef)->data, minNode->data);
        if (removeRec(&((*nodeRef)->right), value, deletedNode)) {
            if ((*nodeRef)->balanceFactor == 1) {
                (*nodeRef)->balanceFactor = 0;
                return true;
            }
            if ((*nodeRef)->balanceFactor == 0) {
                (*nodeRef)->balanceFactor = -1;
                return false;
            }
            if (((*nodeRef)->left) && ((*nodeRef)->left->balanceFactor <= 0)) {
                rotateRight(nodeRef);
                return true;
            } else {
                rotateLeftRight(nodeRef);
                return true;
            }
        }
        return false;
    }
    
    // Removes a value from the AVL tree; stores the removed value in 'removedValue'.
    bool remove(T value, T* removedValue) {
        *removedValue = T{}; // Default-initialized
        if (!root)
            return false;
        AVLNode<T>* deletedNode = nullptr;
        removeRec(&root, value, &deletedNode);
        if (deletedNode != nullptr) {
            *removedValue = AVLNode<T>::destroyNode(deletedNode);
            nodeCount--;
            return true;
        }
        return false;
    }
    
    // Overloaded remove without return value.
    bool remove(T value) {
        if (!root)
            return false;
        AVLNode<T>* deletedNode = nullptr;
        bool result = removeRec(&root, value, &deletedNode);
        if (deletedNode != nullptr) {
            AVLNode<T>::destroyNode(deletedNode);
            nodeCount--;
            return result;
        }
        return false;
    }
    
    // --- Traversals ---
    
    static void inorder(AVLNode<T>* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    
    void inorder() {
        inorder(root);
    }
    
    static void preorder(AVLNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void preorder() {
        preorder(root);
    }
    
    static void postorder(AVLNode<T>* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    
    void postorder() {
        postorder(root);
    }
    
    // --- Clear and Destructor ---
    
    static void clear(AVLNode<T>* node) {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        AVLNode<T>::destroyNode(node);
    }
    
    void clear() {
        clear(root);
        root = nullptr;
        nodeCount = 0;
    }
    
    ~AVLTree() {
        clear();
    }
};

#endif // AVLTREE_H
