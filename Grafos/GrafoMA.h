#pragma once

template <class T>
class GrafoMA {
  private:
    int nodos;
    bool dirigido;
    bool ponderado;
    T *tagNodo;
    bool **matriz;
  public:
    GrafoMA(int,bool,bool);
    ~GrafoMA();
    void setTag(int,T); //insertar Nodo
    void add(T,T);//insertar Arco
    //borrar Nodo
    void del(T,T);//borrar Arco
    int find(T);//buscar Nodo
    //recorrer Grafo
    bool isAdyacent(T,T);
};

#include "GrafoMA.cpp"