#include "Grafo.h"

// Arco
template <class T>
Arco<T>::Arco(T origen,T destino) : 
tagOrigen(origen),
tagDestino(destino) {
    nextOrigen = nullptr;
    nextDestino = nullptr;
}

template <class T>
T Arco<T>::getOrigen() {
    return tagOrigen;
}

template <class T>
T Arco<T>::getDestino() {
    return tagDestino;
}

template <class T>
void Arco<T>::setNextOrigen(Arco* arc) {
    nextOrigen = arc;
}

template <class T>
void Arco<T>::setNextDestino(Arco* arc) {
    nextDestino = arc;
}

template <class T>
Arco<T>* Arco<T>::getNextOrigen() {
    return nextOrigen;
}

template <class T>
Arco<T>* Arco<T>::getNextDestino() {
    return nextDestino;
}

// Nodo
template <class T>
NodeG<T>::NodeG(T t) {
    tag = t;
    next = nullptr;
    listaOrigen = nullptr;
    listaDestino = nullptr;
}

template <class T>
NodeG<T>::NodeG(T t,NodeG* p) {
    tag = t;
    next = p;
    listaOrigen = nullptr;
    listaDestino = nullptr;
}

template <class T>
NodeG<T>::~NodeG() {
    Arco<T> *p = listaOrigen, *q = nullptr;
    while (p != nullptr) {
        q = p->getNextOrigen();
        delete p;
        p = q;
    }
}

template <class T>
T NodeG<T>::getTag() {
    return tag;
}

template <class T>
void NodeG<T>::setNext(NodeG* p) {
    next = p;
}

template <class T>
NodeG<T>* NodeG<T>::getNext() {
    return next;
}

template <class T>
void NodeG<T>::addArcoOrigen(Arco<T>* arc) {
    Arco<T> *p = listaOrigen, *q = nullptr;
    while (p != nullptr) {
        q = p;
        p = p->getNextOrigen();
    }
    if (q != nullptr) {
        q->setNextOrigen(arc);
    }
    else {
        listaOrigen = arc;
    }
}

template <class T>
void NodeG<T>::addArcoDestino(Arco<T>* arc) {
    Arco<T> *p = listaDestino, *q = nullptr;
    while (p != nullptr) {
        q = p;
        p = p->getNextDestino();
    }
    if (q != nullptr) {
        q->setNextDestino(arc);
    }
    else {
        listaOrigen = arc;
    }
}

template <class T>
bool NodeG<T>::isAdyacente(T tagD) {
    Arco<T> *p = listaOrigen;
    while (p != nullptr) {
        if (p->getDestino() == tagD) {
            return true;
        }
        p = p->getNextOrigen();
    }
    return false;
}

// Grafo
template <class T>
NodeG<T>* Grafo<T>::find(T tag) {
    NodeG<T> *p = nodos;
    while (p != nullptr) {
        if (p->getTag() == tag) {
            return p;
        }
        p = p->getNext();
    }
    return nullptr;
}

template <class T>
Grafo<T>::Grafo() {
    nodos = nullptr;
}

template <class T>
Grafo<T>::~Grafo() {
    NodeG<T> *p = nodos, *q;
    while (p != nullptr) {
        q = p->getNext();
        delete p;
        p = q; 
    }
}

template <class T>
void Grafo<T>::addNodo(T tag) {
    NodeG<T> *p = nodos, *q = nullptr, *r;
    while (p != nullptr) {
        if (p->getTag() == tag) {
            return; // no se agrega tag porque ya esta
        }
        q = p;
        p = p->getNext();
    }
    r = new NodeG<T>(tag);
    if (q != nullptr) {
        q->setNext(r); // se agrega al final
    }
    else {
        nodos = r; // es el primer nodo a agregar
    }
}

#include <iostream>
template <class T>
void Grafo<T>::addArco(T tagO,T tagD) {
    NodeG<T> *nodoOrigen = find(tagO);
    NodeG<T> *nodoDestino = find(tagD);
    if (nodoOrigen == nullptr || nodoDestino == nullptr) {
        std::cout << "No se agrega arco " << tagO << " - " << tagD << std::endl;
        return;
    }
    Arco<T> *arc = new Arco<T>(tagO,tagD);
    std::cout << "Se crea arco " << tagO << " - " << tagD << std::endl;
    nodoOrigen->addArcoOrigen(arc);
    nodoDestino->addArcoDestino(arc);
}

template <class T>
void Grafo<T>::delNodo(T tag) {
    // ToDo
}

template <class T>
void Grafo<T>::delArco(T tagO,T tagD) {
    // ToDo
}

template <class T>
bool Grafo<T>::isAdyacent(T tagO,T tagD) {
    NodeG<T> *nodoOrigen = find(tagO);
    return nodoOrigen->isAdyacente(tagD);
}
