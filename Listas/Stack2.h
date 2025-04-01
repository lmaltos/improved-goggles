#pragma once
#include "Node.h"

template <class T>
class Stack {
  private:
    node<T> *pTop;
public:
    Stack();
    ~Stack();
    void push(T);
    void pop();
    T top();
    bool isFull();
    bool isEmpty();
};

#include "Stack2.cpp"