#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
    int count;
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();

    bool insert(const T& x);
    T pop();
    int size() const;
    bool empty() const;
    T front() const;    
    void clear();
    T erase(const T& x);
    bool search(const T& x, T* foundValue);
};

#include "LinkedList.tpp" // Include template definitions

#endif // LINKEDLIST_H
