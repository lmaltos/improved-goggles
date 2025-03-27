#ifndef MYVECTOR_H
#define MYVECTOR_H

template <class T>
class MyVector {
  private:
    int maxSize;
    T *a;
    int n;
    void increase();
  public:
    MyVector();
    ~MyVector();
    void set(int pos,int val);
    void setSize(int);
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    T get(int);
};

#include "MyVector.cpp"
#endif