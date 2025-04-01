#ifndef LINKEDLIST_TPP
#define LINKEDLIST_TPP

#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : count(0), head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
bool LinkedList<T>::insert(const T& x) {
    Node<T>* newNode = Node<T>::createNode(x);
    if (!newNode)
        return false;
    newNode->next = head;
    head = newNode;
    count++;
    return true;
}

template <typename T>
T LinkedList<T>::pop() {
    T x{};
    if (head) {
        Node<T>* temp = head;
        head = head->next;
        x = Node<T>::destroyNode(temp);
        count--;
    }
    return x;
}

template <typename T>
int LinkedList<T>::size() const {
    return count;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
T LinkedList<T>::front() const {
    T x{};
    if (head)
        x = head->data;
    return x;
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* temp;
    while (head) {
        temp = head;
        head = head->next;
        Node<T>::destroyNode(temp);
    }
    count = 0;
}

template <typename T>
T LinkedList<T>::erase(const T& x) {
    T retValue{};
    Node<T>** current = &head;
    Node<T>* temp;
    // Traverse the list until we find the node with matching value.
    while (*current && ((*current)->data != x)) {
        current = &((*current)->next);
    }
    if (*current) {
        temp = *current;
        *current = temp->next;
        retValue = Node<T>::destroyNode(temp);
        count--;
    }
    return retValue;
}

template <typename T>
bool LinkedList<T>::search(const T& x, T* foundValue) {
    Node<T>* current = head;
    while (current && (current->data != x)) {
        current = current->next;
    }
    if (current) {
        *foundValue = current->data;
        return true;
    }
    return false;
}

#endif // LINKEDLIST_TPP
