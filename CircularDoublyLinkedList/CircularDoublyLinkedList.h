#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include "CDNode.h"
#include <iostream>
using namespace std;

template <typename T>
class CircularDoublyLinkedList {
private:
    CDNode<T>* head;
    CDNode<T>* current; // iterator pointer
    int count;
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    // Inserts an element at the beginning.
    bool insert(const T& x);
    // Erases the element at the current iterator position and returns its value.
    T erase();
    // Moves the iterator to the next node.
    void moveNext();
    // Moves the iterator to the previous node.
    void movePrev();
    // Resets the iterator to the head.
    void resetIterator();
    // Returns the number of nodes in the list.
    int size() const;
    // Returns the value at the current iterator.
    T currentValue() const;
    // Returns true if the list is empty.
    bool empty() const;
    // Clears the list.
    void clear();
    // Searches for a value in the list. If found, sets the iterator to that node.
    bool search(const T& x);
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() : head(nullptr), current(nullptr), count(0) {}

template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    clear();
}

template <typename T>
bool CircularDoublyLinkedList<T>::insert(const T& x) {
    CDNode<T>* newNode = CDNode<T>::createNode(x);
    if (!newNode)
        return false;
    if (!head) {
        // Empty list: new node points to itself.
        head = newNode;
        current = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        // Insert new node before head and update head.
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    count++;
    return true;
}

template <typename T>
T CircularDoublyLinkedList<T>::erase() {
    T retValue{};
    if (!head)
        return retValue;
    
    CDNode<T>* toDelete = current;
    
    if (toDelete->next != toDelete) { // More than one node.
        toDelete->next->prev = toDelete->prev;
        toDelete->prev->next = toDelete->next;
    } else {
        // Only one node in the list.
        head = nullptr;
        current = nullptr;
        count = 0;
        retValue = CDNode<T>::destroyNode(toDelete);
        return retValue;
    }
    
    // If deleting head, update head pointer.
    if (toDelete == head)
        head = toDelete->next;
    
    // Move current to the next node.
    current = toDelete->next;
    retValue = CDNode<T>::destroyNode(toDelete);
    count--;
    return retValue;
}

template <typename T>
void CircularDoublyLinkedList<T>::moveNext() {
    if (current)
        current = current->next;
}

template <typename T>
void CircularDoublyLinkedList<T>::movePrev() {
    if (current)
        current = current->prev;
}

template <typename T>
void CircularDoublyLinkedList<T>::resetIterator() {
    current = head;
}

template <typename T>
int CircularDoublyLinkedList<T>::size() const {
    return count;
}

template <typename T>
T CircularDoublyLinkedList<T>::currentValue() const {
    T x{};
    if (current)
        x = current->data;
    return x;
}

template <typename T>
bool CircularDoublyLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void CircularDoublyLinkedList<T>::clear() {
    if (head) {
        CDNode<T>* temp = head->next;
        while (temp != head) {
            CDNode<T>* nextTemp = temp->next;
            CDNode<T>::destroyNode(temp);
            temp = nextTemp;
        }
        CDNode<T>::destroyNode(head);
    }
    head = nullptr;
    current = nullptr;
    count = 0;
}

template <typename T>
bool CircularDoublyLinkedList<T>::search(const T& x) {
    if (!head)
        return false;
    CDNode<T>* temp = head;
    do {
        if (temp->data == x) {
            current = temp;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

#endif // CIRCULARDOUBLYLINKEDLIST_H
