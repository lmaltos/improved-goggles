#pragma once

class NodeT {
  private:
    int data;
    NodeT *left, *right;
  public:
    NodeT();
    NodeT(int);
    int getData();
    NodeT *getLeft();
    NodeT *getRight();
    void setData(int); // Warning!
    void setLeft(NodeT*);
    void setRight(NodeT*);
};