#include <iostream>
#include "BST.h"

using namespace std;
int main() {
    BST arbol;
    int i = 10;
    while (i-- > 0) {
        arbol.add(rand()%100);
    }

    int a;
    cout << "Ingrese numero a buscar: ";
    cin >> a;
    if (arbol.search(a)) {
        cout << "El valor " << a << " se encuentra en el arbol" << endl;
    }
    else {    
        cout << "El valor " << a << " NO se encuentra en el arbol" << endl;
    }
    return 0;
}