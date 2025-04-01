#include "Stack.h"

Stack::Stack(){
    tope = -1;
}

void Stack::push(int valor){
    if (!isFull()) {
        datos[++tope] = valor;
    }
}

void Stack::pop(){
    if (!isEmpty()) {
        tope--;
    }
}

int Stack::top(){
    return datos[tope];
}

bool Stack::isFull(){
    return tope + 1 == MAX;
}

bool Stack::isEmpty(){
    return tope == -1;
}