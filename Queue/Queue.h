#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
private:
    int count;
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    ~Queue();

    bool push(const T& x);
    T pop();
    int size() const;
    bool empty() const;
    T front() const;
    void clear();
};

#include "Queue.tpp" // Include the template definitions

#endif // QUEUE_H
