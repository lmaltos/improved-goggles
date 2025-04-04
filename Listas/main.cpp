#include <iostream>
#include "LinkedList.h"

using namespace std;

void test_linkedlist() {
    LinkedList<int> lista;
    lista.insertar(1);
    lista.insertar(2);
    lista.insertar(3);
    lista.insertar(4);
    lista.insertar(5);
    lista.insertar(6);
    lista.insertar(7);
    lista.insertar(8);
    lista.insertar(9);
    lista.insertar(10);
    for (int i = 0; i < 10; i++) {
        cout << lista.obtener(i) << " ";
    }
}

#include "Stack2.h"
void test_stack() {
    Stack<int> s;
    int i;
    cout << "Se crea stack" << endl;
    i = 1;
    while (i <= 100) {
        s.push(rand()%100);
        cout << s.top() << " ";
        if (i++ % 10 == 0) cout << endl;
    }
    cout << "Se llena stack" << endl;
    /*
    while (!s.isEmpty()) {
        cout << s.top() << " ";
        if (i++ % 10 == 0) cout << endl;
        s.pop();
    }
    cout << "Se vacia stack" << endl;
    */
}

#include "Queue2.h"
void test_queue() {
    Queue q;
    int i = 0;
    while (i++ < 10) {
        q.pop();
        q.push(rand()%100);
        q.push(rand()%100);
        cout << "front: " << q.front() << endl;
    }
    /*
    cout << "Vacia queue" << endl;
    while (!q.isEmpty()) {
        cout << "front: " << q.front() << endl;
        q.pop();
    }
    */
}


int main() {
    test_queue();
}