#include "LinkedList.h"
#include <iostream>
using namespace std;
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    node<T> *p = head, *q;
    while (p != nullptr) {
        q = p->getNext();
        //cout << "delete node<T> " << p << " " << p->getData() << endl;
        delete p;
        p = q;
    }
}

template <class T>
void LinkedList<T>::insertar(T data){
    node<T> *n = new node<T>(data,head);
    //cout << "new node<T> " << n << " " << n->getData() << endl;
    head = n;
    size++;
}

template <class T>
int LinkedList<T>::buscar(T data){
    int pos = 0;
    node<T> *p = head;
    while (p != nullptr) {
        if (p->getData() == data) {
            return pos;
        }
        p = p->getNext();
        pos++;
    }
    return -1;
}

template <class T>
void LinkedList<T>::eliminar(T){
    //ToDo
}

template <class T>
T LinkedList<T>::obtener(int pos){
    node<T> *p = head;
    while (pos > 0) {
        p = p->getNext();
        pos--;
    }
    return p->getData();
}

template <class T>
void LinkedList<T>::modificar(int,T){

}