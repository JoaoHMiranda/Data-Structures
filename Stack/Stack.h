#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {
private:
    int count;
    Node<T>* top;
public:
    Stack();
    ~Stack();

    bool push(const T& value);
    T pop();
    int size() const;
    bool empty() const;
    T peek() const;    
    void clear();
};

#include "Stack.tpp"

#endif // STACK_H
