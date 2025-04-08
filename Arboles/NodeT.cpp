#include "NodeT.h"

NodeT::NodeT(){
    left = right = nullptr;
}

NodeT::NodeT(int valor){
    data = valor;
    left = right = nullptr;
}

int NodeT::getData(){
    return data;
}

NodeT *NodeT::getLeft(){
    return left;
}

NodeT *NodeT::getRight(){
    return left;
}

void NodeT::setData(int valor){
    data = valor;
}

void NodeT::setLeft(NodeT* p){
    left = p;
}

void NodeT::setRight(NodeT* p){
    right = p;
}