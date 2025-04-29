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

#include "Heap.h"

bool myFuncionPrioridad(int a,int b) {
    cout << "myFuncionPrioridad " << a << " < " << b << " ? " << (a < b) << endl;
    return a < b;
}

void Test_Heap() {
    Heap h(myFuncionPrioridad);
    h.push(28);
    h.push(21);
    h.push(17);
    h.push(19);
    h.push(5);
    h.push(8);
    h.print();
    cout << "Agrega 20" << endl;
    h.push(20);
    h.print();
}

int main() {
    Test_Heap();
    return 0;
}