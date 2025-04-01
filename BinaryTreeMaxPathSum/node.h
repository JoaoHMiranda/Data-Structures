#ifndef NODE_H
#define NODE_H

template<class T>
class Tnode {
public:
    T data;
    Tnode<T>* left;
    Tnode<T>* right;

    // Creates a node with the given value.
    static Tnode* createNode(T value);
    // Destroys a node and returns its data.
    static T destroyNode(Tnode* node);
};

template<class T>
Tnode<T>* Tnode<T>::createNode(T value) {
    Tnode<T>* node = new Tnode<T>;
    if (node) {
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
    }
    return node;
}

template<class T>
T Tnode<T>::destroyNode(Tnode<T>* node) {
    T value;
    if (node) {
        value = node->data;
        delete node;
    }
    return value;
}

#endif // NODE_H
