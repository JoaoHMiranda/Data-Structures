#ifndef CDNODE_H
#define CDNODE_H

template <typename T>
struct CDNode {
    T data;
    CDNode<T>* next;
    CDNode<T>* prev;  // renamed from Back

    // Creates a new node with the given value.
    static CDNode* createNode(const T& value) {
        CDNode<T>* node = new CDNode<T>;
        if (node) {
            node->data = value;
            node->next = nullptr;
            node->prev = nullptr;
        }
        return node;
    }

    // Destroys the node and returns its stored value.
    static T destroyNode(CDNode<T>* node) {
        T value{};
        if (node) {
            value = node->data;
            delete node;
        }
        return value;
    }
};

#endif // CDNODE_H
