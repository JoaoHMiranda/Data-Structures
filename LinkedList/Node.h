#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    // Creates a new node with the given value.
    static Node* createNode(const T& value) {
        Node<T>* newNode = new Node<T>;
        if (newNode) {
            newNode->data = value;
            newNode->next = nullptr;
        }
        return newNode;
    }
    
    // Destroys the node and returns its stored value.
    static T destroyNode(Node<T>* node) {
        T value{};
        if (node) {
            value = node->data;
            delete node;
        }
        return value;
    }
};

#endif // NODE_H
