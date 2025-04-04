#include "Queue.h"

Queue::Queue() {
    frente = fin = -1;
}

void Queue::push(int valor){
    if (isFull()) {
        return; // no se puede agregar otro elemento
    }
    if (isEmpty()) {
        frente = 0;
    }
    if (++fin == MAX)
        fin = 0;
    Datos[fin] = valor;
}

void Queue::pop(){
    if (fin == frente) {
        frente = fin = -1; // se ha vaciado la fila
    }
    else if (++frente == MAX) {
        frente = 0;
    }

}

int Queue::front(){
    return Datos[frente];
}

bool Queue::isEmpty(){
    return frente == -1;
}

bool Queue::isFull(){
    return (fin + 1) % MAX == frente;
}