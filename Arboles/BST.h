#pragma once
#include "NodeT.h"

class BST {
  private:
    NodeT *root;
    void del(NodeT*);
  public:
    BST();
    ~BST();
    bool search(int);
    void add(int);
    void del(int);  
};