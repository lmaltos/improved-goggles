#include "Queue2.h"
#include <iostream>

using namespace std;
template <class D>
Queue<D>::Queue(){
    tail = nullptr;
}

template <class D>
Queue<D>::~Queue(){
    while (!isEmpty()) {
        pop();
    }
}

template <class D>
void Queue<D>::push(D valor){
    node<D> *n = new node<D>(valor);
    //cout << "new node " << n << " : " << valor << endl;
    if (isEmpty()) {
        n->setNext(n);
    }
    else {
        n->setNext(tail->getNext());
        tail->setNext(n);
    }
    tail = n;
}

template <class D>
void Queue<D>::pop(){
    if (isEmpty()) {
        return;
    }
    node<D> *first = tail->getNext();
    //cout << "del node " << first << " : " << first->getData() << endl;
    if (first != tail) {
        tail->setNext(first->getNext());
    }
    else {
        tail = nullptr; // se vació la fila
        //cout << "Se vacio la fila" << endl;
    }
    delete first;
}

template <class D>
D Queue<D>::front(){
    return tail->getNext()->getData();
}

template <class D>
bool Queue<D>::isEmpty(){
    return tail == nullptr;
}

template <class D>
bool Queue<D>::isFull(){
    return false;
}