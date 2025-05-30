#include "Heap.h"

bool prioridad_default(int a,int b) {
    return a > b;
}

template <class T>
Heap<T>::Heap() {
    n = 0;
    prioridad = prioridad_default;
}

template <class T>
Heap<T>::Heap(bool (*miFuncionPrioridad)(T,T)) {
    n = 0;
    prioridad = miFuncionPrioridad;
}

template <class T>
void Heap<T>::acomoda_abajo(int idx) {
    int hijo;
    while (2 * idx < n) {
        hijo = 2 * idx;
        if (prioridad(a[hijo],a[idx]) || (hijo+1 < n && prioridad(a[hijo+1],a[idx]))) {
            int hijoMay = (hijo+1 < n && prioridad(a[hijo+1],a[hijo])) ? hijo+1 : hijo;
            T tmp = a[idx];
            a[idx] = a[hijoMay];
            a[hijoMay] = tmp;
            idx = hijoMay;
        }
        else {
            return;
        }
    }
}

template <class T>
void Heap<T>::acomoda_arriba(int idx) {
    while (idx > 1) {
        if (prioridad(a[idx], a[idx/2])) {
            T tmp = a[idx/2];
            a[idx/2] = a[idx];
            a[idx] = tmp;
            idx = idx/2;
        }
        else {
            return;
        }
    }
}

template <class T>
void Heap<T>::push(T valor) {
    if (isFull()) {
        return;
    }
    a[++n] = valor;
    acomoda_arriba(n);
}

template <class T>
void Heap<T>::pop() {
    a[1] = a[n--];
    acomoda_abajo(1);
}

template <class T>
T Heap<T>::front() {
    return a[1];
}

template <class T>
bool Heap<T>::isEmpty() {
    return n == 0;
}

template <class T>
bool Heap<T>::isFull() {
    return n == MAX_HEAP_SIZE;
}

#include <iostream>
template <class T>
void Heap<T>::print() {
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}