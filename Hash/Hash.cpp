#include "Hash.h"

int funcionDefault(int v) {
    return v % MAX_TABLE_SIZE;
}

Hash::Hash() {
    funcionHash = funcionDefault;
}

Hash::Hash(int(*fun)(int)) {
    funcionHash = fun;
}

bool Hash::buscar(int v) {
    int idx = funcionHash(v);
    int pos = idx;
    while (tabla[idx].estatus != vacio) {
        if (tabla[idx].estatus == ocupado) {
            if (tabla[idx].valor == v) {
                return true;
            }
        }
        idx++;
        idx = idx % size;
        if (idx == pos) {
            break; // se reviso toda la tabla
        }
    }
    return false;
}

void Hash::agregar(int v) {
    if (buscar(v)) {
        return;
    }
    int idx = funcionHash(v);
    int pos = idx;
    while (tabla[idx].estatus == ocupado) {
        idx++;
        idx = idx % size;
        if (idx == pos) {
            return; // se reviso toda la tabla
        }
    }
    tabla[idx].valor = v;
    tabla[idx].estatus = ocupado;
}

void Hash::borrar(int v) {
    if (!buscar(v)) {
        return;
    }
    int idx = funcionHash(v);
    while (tabla[idx].estatus != vacio) {
        idx++;
        idx = idx % size;
        if (tabla[idx].estatus == ocupado && tabla[idx].valor == v) {
            tabla[idx].estatus = borrado;
        }
    }
}

std::ostream& operator<<(std::ostream& os, Hash& H) {
    os << "[ ";
    for (int i = 0; i < H.size; i++) {
        if (H.tabla[i].estatus == ocupado) {
            os << H.tabla[i].valor << " ";
        }
    }
    os << "]";
    return os;
}