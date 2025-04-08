#include "BST.h"
#include <iostream>

using namespace std;
BST::BST(){
    root = nullptr;
}

BST::~BST(){
    del(root);
}

void BST::del(NodeT *p) {
    if (p != nullptr) {
        del(p->getLeft());
        del(p->getRight());
        cout << "~BST " << p << " : " << p->getData() << endl;
        delete p;
    }
}

bool BST::search(int valor){
    NodeT *p = root;
    while (p != nullptr){
        if (p->getData() == valor) {
            return true; // valor encontrado
        }
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    return false; // no se encontró el valor
}

void BST::add(int valor){
    if (search(valor)) {
        return; // el valor ya existe en el arbol
    }
    NodeT *p = root, *q = nullptr;
    while (p != nullptr){
        q = p;
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    p = new NodeT(valor);
    if (q == nullptr) {
        root = p;
        cout << "nodo root " << p << " : " << valor << endl;
    }
    else {
        cout << "hijo del nodo " << q << " : " << q->getData() << endl;
        cout << " nuevo nodo " << p << " : " << valor << endl;
        if (q->getData() > valor) {
            q->setLeft(p);
        }
        else {
            q->setRight(p);
        }
    }
}

void BST::del(int){}