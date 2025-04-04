#pragma once
#include "Node.h"

class Queue {
  private:
    node<int> *tail;
  public:
    Queue();
    ~Queue();
    void push(int);
    void pop();
    int front();
    bool isEmpty();
    bool isFull();
};

#include "Queue2.cpp"