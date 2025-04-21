#include <iostream>
#include "BST.h"

using namespace std;
int main() {
    BST arbol;
    int i = 20;
    while (i-- > 0) {
        arbol.add(rand()%100);
    }
    arbol.preorder();
    arbol.inorder();
    arbol.posorder();
    arbol.porNivel();

    int a;
    bool continuar = true;
    char c;
    do {
        cout << "Ingrese numero a buscar: ";
        cin >> a;
        if (arbol.search(a)) {
            cout << "El valor " << a << " se encuentra en el arbol" << endl;
            arbol.del(a);
            cout << "El arbol ahora es asi: ";
            arbol.preorder();
            arbol.inorder();
            arbol.posorder();
            arbol.porNivel();
        }
        else {
            cout << "El valor " << a << " NO se encuentra en el arbol" << endl;
        }
        cout << "Continuar (Y/n): ";
        cin >> c;
        continuar = (c == 'Y' || c == 'y');
    } while (continuar);
    return 0;
}