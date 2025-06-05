#pragma once
#include <iostream>
#define MAX_TABLE_SIZE 11

enum estatus {
    vacio = 1,
    ocupado = 403,
    borrado,
};

class celda {
  public:
    estatus estatus = vacio;
    int valor;
};

class Hash {
  private:
    int size = MAX_TABLE_SIZE;
    celda tabla[MAX_TABLE_SIZE];
    int (*funcionHash)(int);
  public:
    Hash();
    Hash(int(*)(int));
    bool buscar(int);
    void agregar(int);
    void borrar(int);
    friend std::ostream& operator<<(std::ostream&, Hash&);
};