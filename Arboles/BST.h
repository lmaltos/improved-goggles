#pragma once
#include "NodeT.h"

class BST {
  private:
    NodeT *root;
    void del(NodeT*);
    void preorder(NodeT*);
    void inorder(NodeT*);
    void posorder(NodeT*);
  public:
    BST();
    ~BST();
    bool search(int);
    void add(int);
    void del(int);
    void preorder();
    void inorder();
    void posorder();
    void porNivel();
};