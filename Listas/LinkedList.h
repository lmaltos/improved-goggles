#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
  private:
    node<T> *head;
    int size;
  public:
    LinkedList();
    ~LinkedList();
    void insertar(T);
    int buscar(T);
    void eliminar(T);
    T obtener(int);
    void modificar(int,T);
};

#include "LinkedList.cpp"
#endif