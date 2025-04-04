#pragma once
#include "Node.h"

template <class D>
class Queue {
  private:
    node<D> *tail;
  public:
    Queue();
    ~Queue();
    void push(D);
    void pop();
    D front();
    bool isEmpty();
    bool isFull();
};

#include "Queue2.cpp"