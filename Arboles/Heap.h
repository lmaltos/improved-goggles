#pragma once
#define MAX_HEAP_SIZE 100

template <class T>
class Heap {
  private:
    T a[MAX_HEAP_SIZE];
    int n;
    bool (*prioridad)(T,T); // pointer a funcion return_type bool, parameters (int,int)
    void acomoda_abajo(int);
    void acomoda_arriba(int);
  public:
    Heap();
    Heap(bool (*)(T,T));
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
    void print();
};

#include "Heap.cpp"