#pragma once
#define MAX 100

class Stack {
  private:
    int datos[MAX];
    int tope;
  public:
    Stack();
    void push(int);
    void pop();
    int top();
    bool isFull();
    bool isEmpty();
};
