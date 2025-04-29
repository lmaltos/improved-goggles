#pragma once
#define MAX_HEAP_SIZE 100

class Heap {
  private:
    int a[MAX_HEAP_SIZE];
    int n;
    bool (*prioridad)(int,int); // pointer a funcion return_type bool, parameters (int,int)
    void acomoda_abajo(int);
    void acomoda_arriba(int);
  public:
    Heap();
    Heap(bool (*)(int,int));
    void push(int);
    void pop();
    int front();
    bool isEmpty();
    bool isFull();
    void print();
};