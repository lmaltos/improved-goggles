#pragma once
#include "..\Listas\Node.h"

template <class T>
class NodoG : public node<T> {
  private:
    node<T> *listaAdyacencia;
  public:
    NodoG(T);
    NodoG(T,node<T>*);
    ~NodoG();
    void add(T);//insertar Arco
    void del(T);//borrar Arco
    bool isAdyacent(T);
};

template <class T>
class GrafoLA {
  private:
    int n;
    bool dirigido;
    bool ponderado;
    NodoG<T> *nodos;
    NodoG<T>* find(T); //buscar Nodo
  public:
    GrafoLA(bool,bool);
    ~GrafoLA();
    void addNodo(T); //insertar Nodo
    void add(T,T);//insertar Arco
    void delNodo(T);//borrar Nodo
    void del(T,T);//borrar Arco
    //recorrer Grafo
    void breadthFirst();
    void deepthFirst();
    bool isAdyacent(T,T);
};

#include "GrafoLA.cpp"