#ifndef BBTREE2_H
#define BBTREE2_H

#include <iostream>
#include <algorithm>
using namespace std;

// Binary Tree Node
template<class T>
class Tnode {
public:
    T data;
    int weight;
    Tnode<T>* left;
    Tnode<T>* right;
    
    // Creates a node. If the character is a space, it is replaced by '-' for encoding purposes.
    static Tnode<T>* createNode(T value, int wt) {
        Tnode<T>* node = new Tnode<T>;
        if (node) {
            if (value == ' ')
                value = '-';
            node->data = value;
            node->weight = wt;
            node->left = nullptr;
            node->right = nullptr;
        }
        return node;
    }
    
    // Destroys a node and returns its data.
    static T destroyNode(Tnode<T>* node) {
        T value;
        if (node) {
            value = node->data;
            delete node;
        }
        return value;
    }
};

// Binary Tree class (used to build the Huffman tree)
template<class T>
class BinaryTree {
public:
    Tnode<T>* root;
    int nodeCount;
    
    BinaryTree() : root(nullptr), nodeCount(0) {}
    
    // Constructor that combines two trees into a new tree with a root node.
    BinaryTree(Tnode<T>* leftTree, Tnode<T>* rightTree) {
        int weightLeft = leftTree->weight;
        int weightRight = rightTree->weight;
        root = Tnode<T>::createNode('_', weightLeft + weightRight);
        nodeCount = 3; // Count: root plus two children
        
        // The node with higher weight is placed to the right.
        if (weightLeft >= weightRight) {
            root->right = leftTree;
            root->left = rightTree;
        } else {
            root->right = rightTree;
            root->left = leftTree;
        }
    }
    
    int getWeight() {
        return root ? root->weight : 0;
    }
    
    Tnode<T>* getRoot() {
        return root;
    }
    
    // Recursively inserts a node based on its weight.
    bool insert(Tnode<T>* newNode, Tnode<T>** tree) {
        if (!*tree) {
            *tree = newNode;
            return true;
        }
        if ((*tree)->weight == newNode->weight) {
            Tnode<T>::destroyNode(newNode);
            return false;
        }
        if (newNode->weight < (*tree)->weight) { 
            return insert(newNode, &((*tree)->left));
        }
        return insert(newNode, &((*tree)->right));
    }
    
    // Inserts a new node using a value and its weight.
    bool insert(T value, int wt) {
        Tnode<T>* newNode = Tnode<T>::createNode(value, wt);
        if (!newNode)
            return false;
        if (insert(newNode, &root)) {
            nodeCount++;
            return true;
        }
        return false;
    }
    
    // Finds the node with the minimum weight in a subtree.
    Tnode<T>* findMin(Tnode<T>* tree) {
        while (tree && tree->left)
            tree = tree->left;
        return tree;
    }
    
    // Recursively erases a node by weight.
    Tnode<T>* erase(Tnode<T>** tree, int wt) {
        Tnode<T>* temp;
        if (!*tree)
            return nullptr;
        if (wt < (*tree)->weight)
            return erase(&((*tree)->left), wt);
        if (wt > (*tree)->weight)
            return erase(&((*tree)->right), wt);
        if (!(*tree)->left) {
            temp = *tree;
            *tree = (*tree)->right;
            return temp;
        }
        if (!(*tree)->right) {
            temp = *tree;
            *tree = (*tree)->left;
            return temp;
        }
        Tnode<T>* minNode = findMin((*tree)->right);
        swap(minNode->data, (*tree)->data);
        swap(minNode->weight, (*tree)->weight);
        return erase(&((*tree)->right), wt);
    }
    
    // Erases a node with the specified weight.
    bool erase(int wt) {
        if (!root)
            return false;
        Tnode<T>* temp = erase(&root, wt);
        if (temp != nullptr) {
            nodeCount--;
            Tnode<T>::destroyNode(temp);
            return true;
        }
        return false;
    }
    
    int size() {
        return nodeCount;
    }
    
    bool empty() {
        return root == nullptr;
    }
    
    // Recursively clears the tree freeing all nodes.
    static void clear(Tnode<T>* tree) {
        if (!tree)
            return;
        clear(tree->left);
        clear(tree->right);
        Tnode<T>::destroyNode(tree);
    }
    
    void clear() {
        clear(root);
        root = nullptr;
        nodeCount = 0;
    }
};

#endif // BBTREE2_H
