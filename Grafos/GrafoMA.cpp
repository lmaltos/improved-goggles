#include "GrafoMA.h"

template <class T>
GrafoMA<T>::GrafoMA(int n,bool d, bool p) {
    nodos = n;
    dirigido = d;
    ponderado = p;
    tagNodo = new T[n]; // espacio para etiquetas de los nodos
    matriz = new bool*[n]; // espacio para los pointers a arreglos de bool
    for (int i = 0; i < n; i++) {
        matriz[i] = new bool[n]; // arreglo de bools
        for (int j = 0; j < n; j++) {
            matriz[i][j] = false;
        }
    }
}

template <class T>
GrafoMA<T>::~GrafoMA() {
    delete[] tagNodo;
    for (int i = 0; i < nodos; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

template <class T>
void GrafoMA<T>::setTag(int x,T tag) {
    tagNodo[x] = tag;
}

template <class T>
void GrafoMA<T>::add(T origen,T destino){
    int o = find(origen);
    int d = find(destino);
    matriz[o][d] = true;
    if (!dirigido) {
        matriz[d][o] = true;
    }
}

template <class T>
void GrafoMA<T>::del(T origen,T destino){
    int o = find(origen);
    int d = find(destino);
    matriz[o][d] = false;
    if (!dirigido) {
        matriz[d][o] = false;
    }
}

template <class T>
int GrafoMA<T>::find(T tag) {
    for (int i = 0; i < nodos; i++) {
        if (tagNodo[i] == tag) {
            return i;
        }
    }
    return -1;
}

template <class T>
bool GrafoMA<T>::isAdyacent(T origen,T destino) {
    int o = find(origen);
    int d = find(destino);
    return matriz[o][d];
}