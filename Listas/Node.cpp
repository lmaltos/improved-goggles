#include "Node.h"

template <class T>
node<T>::node(T d) {
    data = d;
    next = nullptr;
}

template <class T>
node<T>::node(T d,node<T>* p){
    data = d;
    next = p;
}

template <class T>
T node<T>::getData(){
    return data;
}

template <class T>
node<T>* node<T>::getNext(){
    return next;
}

template <class T>
void node<T>::setData(T d){
    data = d;
}

template <class T>
void node<T>::setNext(node<T>* p){
    next = p;
}