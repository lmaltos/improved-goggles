#include <iostream>
#include "Hash.h"

using namespace std;
int main() {
    Hash H;
    H.agregar(7);
    H.agregar(17);
    H.agregar(6);
    H.agregar(33);
    H.agregar(28);
    H.agregar(52);
    H.agregar(76);

    for (int i = 1; i < 100; i++) {
        if (H.buscar(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << H << endl;
    cout << "Se elimina el 6" << endl;
    H.borrar(6);

    cout << H << endl;
    for (int i = 1; i < 100; i++) {
        if (H.buscar(i)) {
            cout << i << " ";
        }
    }
    return 0;
}