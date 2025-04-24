#include <iostream>
#include "BST.h"

using namespace std;
void test_BST() {
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
}

#include "AVL.h"

void Test_AVL() {
    AVL arbolAVL;
    BST arbolBST;
    int a;
    for (int i = 1; i < 50; i++) {
        a = rand()%100;
        arbolAVL.add(a);
        arbolBST.add(a);
        if (i % 10 == 0) {
            cout << "BST ";
            arbolBST.preorder();
            cout << "AVL ";
            arbolAVL.preorder();
        }
    }
    cout << "BST ";
    arbolBST.preorder();
    cout << "AVL ";
    arbolAVL.preorder();
}

int main() {
    Test_AVL();
    return 0;
}