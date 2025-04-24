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
        //if (q != nullptr) cout << " -> ";
        q = p;
        //cout << p->getData();
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    p = new NodeT(valor);
    if (q == nullptr) {
        root = p;
        //cout << "nodo root " << endl;
    }
    else {
        //cout << "hijo del nodo " << q << " : " << q->getData() << endl;
        if (q->getData() > valor) {
            q->setLeft(p);
        }
        else {
            q->setRight(p);
        }
    }
    //cout << " nuevo nodo " << p << " : " << valor << endl;
        
}

void BST::del(int valor){
    if (!search(valor)) {
        return; // el valor no existe en el arbol
    }
    NodeT *p = root, *padre = nullptr;
    while (p->getData() != valor){
        padre = p;
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    if (p->getLeft() == nullptr && p->getRight() == nullptr) { // Nodo hoja (sin hijos)
        if (padre == nullptr) {
            root = nullptr; // se vació el arbol
        }
        else if (padre->getData() > valor) {
            padre->setLeft(nullptr);
        }
        else {
            padre->setRight(nullptr);
        }
        delete p;
    }
    else if (p->getLeft() == nullptr || p->getRight() == nullptr) { // Nodo con un hijo
        NodeT *r = p->getLeft() == nullptr ? p->getRight() : p->getLeft();
        if (padre == nullptr) {
            root = r; // se borro el root y su hijo tomo el lugar
        }
        else if (padre->getData() > valor) {
            padre->setLeft(r);
        }
        else {
            padre->setRight(r);
        }
        delete p;
    }
    else { // Nodo con dos hijos
        NodeT *predecesor = p->getLeft();
        while (predecesor->getRight() != nullptr) {
            predecesor = predecesor->getRight(); // fondo a la derecha
        }
        int valorPredecesor = predecesor->getData();
        del(valorPredecesor);
        p->setData(valorPredecesor);
    }
}

void BST::preorder() {
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
}

void BST::preorder(NodeT *p) {
    if (p != nullptr) {
        cout << p->getData() << ", ";
        preorder(p->getLeft());
        preorder(p->getRight());
    }
}

void BST::inorder() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}

void BST::inorder(NodeT *p) {
    if (p != nullptr) {
        inorder(p->getLeft());
        cout << p->getData() << ", ";
        inorder(p->getRight());
    }
}

void BST::posorder() {
    cout << "Posorder: ";
    posorder(root);
    cout << endl;
}

void BST::posorder(NodeT *p) {
    if (p != nullptr) {
        posorder(p->getLeft());
        posorder(p->getRight());
        cout << p->getData() << ", ";
    }
}

#include "Queue2.h"
void BST::porNivel() {
    Queue<NodeT*> fila;
    cout << "Por Nivel: ";
    if (root != nullptr) 
        fila.push(root);
    while (!fila.isEmpty()) {
        NodeT *p = fila.front();
        fila.pop();
        cout << p->getData() << ", ";
        if (p->getLeft() != nullptr) {
            fila.push(p->getLeft()); 
        }
        if (p->getRight() != nullptr) {
            fila.push(p->getRight()); 
        }
    }
    cout << endl;
}