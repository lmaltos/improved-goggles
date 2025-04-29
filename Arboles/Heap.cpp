#include "Heap.h"

bool prioridad_default(int a,int b) {
    return a > b;
}

Heap::Heap() {
    n = 0;
    prioridad = prioridad_default;
}

Heap::Heap(bool (*miFuncionPrioridad)(int,int)) {
    n = 0;
    prioridad = miFuncionPrioridad;
}

void Heap::acomoda_abajo(int idx) {
    int hijo;
    while (2 * idx < n) {
        hijo = 2 * idx;
        if (prioridad(a[hijo],a[idx]) || (hijo+1 < n && prioridad(a[hijo+1],a[idx]))) {
            int hijoMay = (hijo+1 < n && prioridad(a[hijo+1],a[hijo])) ? hijo+1 : hijo;
            int tmp = a[idx];
            a[idx] = a[hijoMay];
            a[hijoMay] = tmp;
            idx = hijoMay;
        }
        else {
            return;
        }
    }
}

void Heap::acomoda_arriba(int idx) {
    while (idx > 1) {
        if (prioridad(a[idx], a[idx/2])) {
            int tmp = a[idx/2];
            a[idx/2] = a[idx];
            a[idx] = tmp;
            idx = idx/2;
        }
        else {
            return;
        }
    }
}

void Heap::push(int valor) {
    if (isFull()) {
        return;
    }
    a[++n] = valor;
    acomoda_arriba(n);
}

void Heap::pop() {
    a[1] = a[n--];
    acomoda_abajo(1);
}

int Heap::front() {
    return a[1];
}

bool Heap::isEmpty() {
    return n == 0;
}

bool Heap::isFull() {
    return n == MAX_HEAP_SIZE;
}

#include <iostream>
void Heap::print() {
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}