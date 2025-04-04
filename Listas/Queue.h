#pragma once
#define MAX 10

class Queue {
  private:
    int Datos[MAX];
    int frente,fin;
  public:
    Queue();
    void push(int);
    void pop();
    int front();
    bool isEmpty();
    bool isFull();
};

#include "Queue.cpp"