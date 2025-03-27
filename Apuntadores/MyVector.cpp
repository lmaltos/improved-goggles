#include "MyVector.h"
#include <iostream>

using namespace std;

template <class T>
MyVector<T>::MyVector() {
    n = 0;
    a = nullptr;
    maxSize = 0;
}

template <class T>
MyVector<T>::~MyVector(){
    cout << "~MyVector() delete[" << maxSize << "] " << a << endl;
    delete[] a;
}

template <class T>
void MyVector<T>::set(int pos,int val){}
template <class T>
void MyVector<T>::setSize(int){}
template <class T>
void MyVector<T>::push_back(T val){
    if (n >= maxSize) {
        increase();
    }
    a[n] = val;
    n++;
}

template <class T>
void MyVector<T>::increase() {
    int newMaxSize = maxSize > 0 ? 2 * maxSize : 1;
    T *b = new T[newMaxSize];
    cout << "increase() new int[" << newMaxSize <<"] " << b << endl;
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    cout << "increase() delete[" << maxSize << "] " << a << endl;
    delete[] a;
    a = b;
    maxSize = newMaxSize;
}

template <class T>
void MyVector<T>::push_front(T){}
template <class T>
void MyVector<T>::pop_back(){}
template <class T>
void MyVector<T>::pop_front(){}

template <class T>
T MyVector<T>::get(int i){
    return a[i];
}