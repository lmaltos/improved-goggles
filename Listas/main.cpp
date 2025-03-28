#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
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
    return 0;
}