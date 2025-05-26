#include "Stack2.h"
#include <iostream>

using namespace std;
template <class T>
Stack<T>::Stack(){
    pTop = nullptr;
}

template <class T>
Stack<T>::~Stack(){
    node<T> *p = pTop, *q;
    while (p != nullptr) {
        q = p->getNext();
        cout << "del node " << p << " -> " << q << " : " << p->getData() << endl;
        delete p;
        p = q;
    }
}

template <class T>
void Stack<T>::push(T valor){
    node<T> *p = new node<T>(valor,pTop);
    //cout << "new node " << p << " -> " << pTop << " : " << valor << endl;
    pTop = p;
}

template <class T>
void Stack<T>::pop(){
    if (!isEmpty()) {
        node<T> *p = pTop->getNext();
        //cout << "del node " << pTop << " -> " << p << " : " << pTop->getData() << endl;
        delete pTop;
        pTop = p;
    }
}

template <class T>
T Stack<T>::top(){
    return pTop->getData();
}

template <class T>
bool Stack<T>::isFull(){
    return false;
}

template <class T>
bool Stack<T>::isEmpty(){
    return pTop == nullptr;
}