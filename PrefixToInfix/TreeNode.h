#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    // Creates a node with the given value.
    static TreeNode* createNode(T value);
    // Destroys a node and returns its data.
    static T destroyNode(TreeNode* node);
};

template <class T>
TreeNode<T>* TreeNode<T>::createNode(T value) {
    TreeNode<T>* node = new TreeNode<T>;
    if (node) {
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
    }
    return node;
}

template <class T>
T TreeNode<T>::destroyNode(TreeNode<T>* node) {
    T value;
    if (node) {
        value = node->data;
        delete node;
    }
    return value;
}

#endif // TREENODE_H
