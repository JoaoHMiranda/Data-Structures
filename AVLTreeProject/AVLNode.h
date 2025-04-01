#ifndef AVLNODE_H
#define AVLNODE_H

template<typename T>
class AVLNode {
public:
    T data;
    int balanceFactor;
    AVLNode<T>* left;
    AVLNode<T>* right;

    // Creates a new AVL node with the given value.
    static AVLNode* createNode(T value) {
        AVLNode<T>* node = new AVLNode<T>;
        if (node) {
            node->data = value;
            node->left = nullptr;
            node->right = nullptr;
            node->balanceFactor = 0;
        }
        return node;
    }
    
    // Destroys the node and returns its stored value.
    static T destroyNode(AVLNode<T>* node) {
        T value{};
        if (node) {
            value = node->data;
            delete node;
        }
        return value;
    }
};

#endif // AVLNODE_H
