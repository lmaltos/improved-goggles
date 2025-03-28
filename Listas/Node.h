#ifndef NODE_H
#define NODE_H

template <class T>
class node {
  private:
    T data;
    node<T> * next;
  public:
    node(T);
    node(T,node<T>*);
    T getData();
    node<T>* getNext();
    void setData(T);
    void setNext(node<T>*);
};

#include "Node.cpp"
#endif