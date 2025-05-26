#include "GrafoLA.h"


template <class T>
NodoG<T>::NodoG(T tag) : node<T>(tag) {
    listaAdyacencia = nullptr;
}

template <class T>
NodoG<T>::NodoG(T tag,node<T>*p) : node<T>(tag,p) {
    listaAdyacencia = nullptr;
}

template <class T>
NodoG<T>::~NodoG() {
    node<T> *p = listaAdyacencia, *q;
    while (p != nullptr) {
        q = p->getNext();
        delete p;
        p = q;
    }
}

template <class T>
void NodoG<T>::add(T tag) {
    node<T> *p = listaAdyacencia, *q = nullptr, *r;
    while (p != nullptr) {
        if (p->getData() == tag) {
            return; // no se agrega tag porque ya esta
        }
        q = p;
        p = p->getNext();
    }
    r = new node<T>(tag);
    if (q != nullptr) {
        q->setNext(r); // se agrega al final
    }
    else {
        listaAdyacencia = r; // es el primer elemento a agregar
    }
}

template <class T>
void NodoG<T>::del(T tag) {
    node<T> *p = listaAdyacencia, *q = nullptr, *r;
    while (p != nullptr || p->getData() == tag) {
        q = p;
        p = p->getNext();
    }
    if (p != nullptr) {
        if (q != nullptr) {
            q->setNext(p->getNext());
        }
        else {
            listaAdyacencia = p->getNext();
        }
    }
}

template <class T>
bool NodoG<T>::isAdyacent(T tag) {
    node<T> *p = listaAdyacencia;
    while (p != nullptr) {
        if (p->getData() == tag) {
            return true;
        }
        p = p->getNext();
    }
    return false;
}

// Funciones del Grafo
template <class T>
NodoG<T>* GrafoLA<T>::find(T tag) {
    NodoG<T> *p = nodos;
    while (p != nullptr) {
        if (p->getData() == tag) {
            return p;
        }
        p = (NodoG<T>*)p->getNext();
    }
    return nullptr;
}

template <class T>
GrafoLA<T>::GrafoLA(bool d,bool p) {
    dirigido = d;
    ponderado = p;
    nodos = nullptr;
}

#include <iostream>

template <class T>
GrafoLA<T>::~GrafoLA() {
    NodoG<T> *p = nodos, *q;
    while (p != nullptr) {
        q = (NodoG<T>*)p->getNext();
        delete p;
        p = q;
    }
}

template <class T>
void GrafoLA<T>::addNodo(T tag) {
    NodoG<T> *p = nodos, *q = nullptr, *r;
    while (p != nullptr) {
        if (p->getData() == tag) {
            return; // no se agrega tag porque ya esta
        }
        q = p;
        p = (NodoG<T>*)p->getNext();
    }
    r = new NodoG<T>(tag);
    if (q != nullptr) {
        q->setNext(r); // se agrega al final
    }
    else {
        nodos = r; // es el primer nodo a agregar
    }
}

template <class T>
void GrafoLA<T>::add(T tagO,T tagD) {
    NodoG<T> *p = find(tagO);
    if (p != nullptr) {
        p->add(tagD);
        if (!dirigido) {
            p = find(tagD);
            if (p != nullptr) {
                p->add(tagO);
            }
        }
    }
}

template <class T>
void GrafoLA<T>::delNodo(T tag) {
    NodoG<T> *p = nodos, *q = nullptr, *r;
    // borramos adyacencias de los otros nodos con este
    while (p != nullptr) {
        if (p->getData() != tag) {
            p->del(tag);
        }
        p = p->getNext();
    }
    p = nodos;
    while (p != nullptr || p->getData() == tag) {
        q = p;
        p = p->getNext();
    }
    if (p != nullptr) {
        if (q != nullptr) {
            q->setNext(p->getNext());
        }
        else {
            nodos = p->getNext();
        }
    }
}

template <class T>
void GrafoLA<T>::del(T tagO,T tagD) {
    NodoG<T> *p = find(tagO);
    if (p != nullptr) {
        p->del(tagD);
        if (!dirigido) {
            p = find(tagD);
            if (p != nullptr) {
                p->del(tagO);
            }
        }
    }
}

template <class T>
bool GrafoLA<T>::isAdyacent(T tagO,T tagD) {
    NodoG<T> *p = find(tagO);
    if (p != nullptr) {
        return p->isAdyacent(tagD);
    }
    return false; // no existe el nodo origen
}

// Recorridos
#include "..\Listas\LinkedList.h"
#include "..\Listas\Queue2.h"

template <class T>
void GrafoLA<T>::breadthFirst() {
    LinkedList<T> procesados;
    Queue<NodoG<T>*> fila;
    NodoG<T> *p = nodos;
    while (p != nullptr) {
        if (procesados.buscar(p->getData()) == -1) {
            // nodo en  espera
            //std::cout << "BSF: " << p->getData() << std::endl;
            fila.push(p);
            procesados.insertar(p->getData());
            while (!fila.isEmpty()) {
                NodoG<T> *q = fila.front();
                fila.pop();
                std::cout << q->getData() << " ";
                NodoG<T> *r = nodos;
                while (r != nullptr) {
                    if (procesados.buscar(r->getData()) == -1 && q->isAdyacent(r->getData())) {
                        //std::cout << "BSF: " << r->getData() << std::endl;
                        fila.push(r);
                        procesados.insertar(r->getData());
                    }
                    r = (NodoG<T>*)r->getNext();
                }
            }
        }
        p = (NodoG<T>*)p->getNext();
    }
    std::cout << std::endl;
}