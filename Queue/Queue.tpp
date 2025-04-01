#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "Queue.h"

template <typename T>
Queue<T>::Queue() : count(0), head(nullptr), tail(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
bool Queue<T>::push(const T& x) {
    Node<T>* newNode = Node<T>::createNode(x);
    if (!newNode)
        return false;
    if (head) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    newNode->next = nullptr;
    count++;
    return true;
}

template <typename T>
T Queue<T>::pop() {
    T x{};
    if (head) {
        Node<T>* temp = head;
        head = head->next;
        x = Node<T>::destroyNode(temp);
        if (!head) {
            tail = nullptr;
        }
        count--;
    }
    return x;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return head == nullptr;
}

template <typename T>
T Queue<T>::front() const {
    T x{};
    if (head) {
        x = head->data;
    }
    return x;
}

template <typename T>
void Queue<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        Node<T>::destroyNode(temp);
    }
    count = 0;
    tail = nullptr;
}

#endif // QUEUE_TPP
