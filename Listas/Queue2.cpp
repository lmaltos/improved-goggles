#include "Queue2.h"
#include <iostream>

using namespace std;
Queue::Queue(){
    tail = nullptr;
}

Queue::~Queue(){
    while (!isEmpty()) {
        pop();
    }
}

void Queue::push(int valor){
    node<int> *n = new node<int>(valor);
    cout << "new node " << n << " : " << valor << endl;
    if (isEmpty()) {
        n->setNext(n);
    }
    else {
        n->setNext(tail->getNext());
        tail->setNext(n);
    }
    tail = n;
}

void Queue::pop(){
    if (isEmpty()) {
        return;
    }
    node<int> *first = tail->getNext();
    cout << "del node " << first << " : " << first->getData() << endl;
    if (first != tail) {
        tail->setNext(first->getNext());
    }
    else {
        tail = nullptr; // se vació la fila
        cout << "Se vació la fila" << endl;
    }
    delete first;
}

int Queue::front(){
    return tail->getNext()->getData();
}

bool Queue::isEmpty(){
    return tail == nullptr;
}

bool Queue::isFull(){
    return false;
}