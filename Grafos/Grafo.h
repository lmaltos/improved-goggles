#pragma once

template <class T>
class Arco {
  private:
    T tagOrigen;
    T tagDestino;
    Arco *nextOrigen;
    Arco *nextDestino;
  public:
    Arco(T,T);
    T getOrigen();
    T getDestino();
    void setNextOrigen(Arco*);
    void setNextDestino(Arco*);
    Arco* getNextOrigen();
    Arco* getNextDestino();
};

template <class T>
class NodeG {
  private:
    T tag;
    NodeG *next;
    Arco<T> *listaOrigen;
    Arco<T> *listaDestino;
  public:
    NodeG(T);
    NodeG(T,NodeG*);
    ~NodeG();
    T getTag();
    void setNext(NodeG*);
    NodeG* getNext();
    void addArcoOrigen(Arco<T>*);
    void addArcoDestino(Arco<T>*);
    bool isAdyacente(T);
};

template <class T>
class Grafo {
  private:
    NodeG<T> *nodos;
    NodeG<T>* find(T);
  public:
    Grafo();
    ~Grafo();
    void addNodo(T); //insertar Nodo
    void addArco(T,T);//insertar Arco
    void delNodo(T);//borrar Nodo
    void delArco(T,T);//borrar Arco
    //recorrer Grafo
    bool isAdyacent(T,T);
};

#include "Grafo.cpp"