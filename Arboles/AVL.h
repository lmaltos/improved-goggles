#pragma once
#include "BST.h"

class AVL : public BST {
  private:
    bool isBalanced(NodeT*);
    int altura(NodeT*);
    void changeParent(NodeT*,NodeT*);
  public:
    void add(int);
};