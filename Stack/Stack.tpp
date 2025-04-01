#ifndef STACK_TPP
#define STACK_TPP

#include "Stack.h"

template <typename T>
Stack<T>::Stack() : count(0), top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
bool Stack<T>::push(const T& value) {
    Node<T>* newNode = Node<T>::createNode(value);
    if (!newNode)
        return false;
    newNode->next = top;
    top = newNode;
    count++;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    T value{};
    if (top) {
        Node<T>* temp = top;
        top = top->next;
        value = Node<T>::destroyNode(temp);
        count--;
    }
    return value;
}

template <typename T>
int Stack<T>::size() const {
    return count;
}

template <typename T>
bool Stack<T>::empty() const {
    return top == nullptr;
}

template <typename T>
T Stack<T>::peek() const {
    T value{};
    if (top)
        value = top->data;
    return value;
}

template <typename T>
void Stack<T>::clear() {
    while (top) {
        Node<T>* temp = top;
        top = top->next;
        Node<T>::destroyNode(temp);
    }
    count = 0;
}

#endif // STACK_TPP
