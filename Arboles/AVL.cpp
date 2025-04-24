#include "AVL.h"

bool AVL::isBalanced(NodeT *p) {
    if (p != nullptr) {
        int L = altura(p->getLeft());
        int R = altura(p->getRight());
        if (R-L > 1 || R-L < -1) {
            return false;
        }
    }
    return true; // si esta balanceado
}

int AVL::altura(NodeT *p) {
    if (p == nullptr) {
        return 0;
    }
    int l = altura(p->getLeft());
    int r = altura(p->getRight());
    return (l > r ? l : r) + 1;
}

void AVL::add(int valor) {
    BST::add(valor);
    NodeT *p = root, *B = nullptr;
    while (p->getData() != valor) {
        if (!isBalanced(p)) {
            B = p;
        }
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    if (B != nullptr) {
        // nuestro arbol esta desbalanceado
        if (B->getData() > valor) {
            NodeT *A = B->getLeft();
            if (A->getData() > valor) {
                // RSD
                B->setLeft(A->getRight());
                A->setRight(B);
                changeParent(B,A);
            }
            else {
                // RDD
                NodeT *C = A->getRight();
                A->setRight(C->getLeft());
                B->setLeft(C->getRight());
                C->setLeft(A);
                C->setRight(B);
                changeParent(B,C);
            }
        }
        else {
            NodeT *A = B->getRight();
            if (A->getData() > valor) {
                // RDI
                NodeT *C = A->getLeft();
                B->setRight(C->getLeft());
                A->setLeft(C->getRight());
                C->setLeft(B);
                C->setRight(A);
                changeParent(B,C);
            }
            else {
                // RSI
                B->setRight(A->getLeft());
                A->setLeft(B);
                changeParent(B,A);
            }
        }
    }
}

void AVL::changeParent(NodeT *B, NodeT *A) {
    NodeT *p = root, *q = nullptr;
    while (p->getData() != B->getData()) {
        q = p;
        p = p->getData() > B->getData() ? p->getLeft() : p->getRight();
    } 
    // q es el padre del nodo B
    if (q == nullptr) {
        root = A;
    }
    else if (q->getData() > B->getData()) {
        q->setLeft(A);
    }
    else {
        q->setRight(A);
    }
}