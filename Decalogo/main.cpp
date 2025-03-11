/**
 * Decalogo de programacion con memoria dinamica
 * Luis Maltos
 * 10 de Marzo 2025
 */

#include <iostream>

using namespace std;

void regla01();
void regla02();
void regla03();

int main() {
    regla03();
}

/**
 * Por cada vez que se ejecute un NEW, debe de haber un DELETE
 */
void regla01() {
    int *p,*q = nullptr;
    cout << "&p: " << &p << endl;
    cout << "&q: " << &q << endl;
    for (int i = 0; i < 5; i++) {
        p = new int;
        *p = rand() % 100;
        cout << "p = new int; " << p << endl;
        cout << "*p: " << *p << endl;
        //cout << "*q: " << *q << endl;
        cout << "delete q " << q << endl;
        delete q;
        //cout << "*q: " << *q << endl;
        q = p;
    }
    cout << "delete p " << p << endl;
    delete p;
    cout << "*p: " << *p << endl;
}

/**
 * Un DELETE actua liberando liberando el espacio de memoria apuntado,
 * independientemente de que existan mas apuntadores
 */
void regla02() {
    int *p,*q,*r;
    p = new int;
    q = p;
    r = q;
    *p = 100;
    *q = *q * 2;
    *r = *r + 5;
    cout << "&p: " << &p << endl;
    cout << "&q: " << &q << endl;
    cout << "&r: " << &r << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "r: " << r << endl;
    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    cout << "*r: " << *r << endl;
    delete r;
    cout << "delete r;" << endl;
    cout << "&p: " << &p << endl;
    cout << "&q: " << &q << endl;
    cout << "&r: " << &r << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "r: " << r << endl;
    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    cout << "*r: " << *r << endl;
}

int* usaR3() {
    int *p = new int;
    *p = 55;
    cout << "usaR3(): *p = new int; " << p << endl;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    return p;
}

void regla03() {
    int *q;
    q = usaR3();
    cout << "&q: " << &q << endl;
    cout << "q: " << q << endl;
    cout << "*q: " << *q << endl;
    delete q;
}