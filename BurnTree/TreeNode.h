#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;
    bool visited;

    // Creates a new node with the given value.
    static TreeNode* createNode(T value) {
        TreeNode<T>* node = new TreeNode<T>;
        if (node) {
            node->data = value;
            node->left = nullptr;
            node->right = nullptr;
            node->parent = nullptr;
            node->visited = false;
        }
        return node;
    }
    
    // Destroys the node and returns its stored value.
    static T destroyNode(TreeNode<T>* node) {
        T value{};
        if (node) {
            value = node->data;
            delete node;
        }
        return value;
    }
};

#endif // TREENODE_H
