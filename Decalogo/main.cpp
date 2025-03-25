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
void regla04();
void regla05();
void regla06();
void regla07();
void regla08();
void regla09();
void regla10();

int main() {
    regla10();
    return 0;
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

/**
 * Basura es diferente de NADA
 */
void regla04() {
    int *p, *q = NULL;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "*p: " << *p << endl;
    //cout << "*q: " << *q << endl; Segmentation faul (core dumed)
    //delete p; munmap_chunk(): invalid pointer
    //cout << "delete p;" << endl;
    delete q;
    cout << "delete q;" << endl;
}

/**
 * DELETE a un pointer que no hace referencia a un espacio de memoria dinamica
 */
void regla05() {
    int *p,*q;
    int a;

    //delete p; munmap_chunk(): invalid pointer

    //p = &a;
    //delete p; //Segmentation fault (core dumped)

    q = new int;
    p = q;
    delete q;
    cout << "delete q;" << endl;
    //delete p; // free(): double free detected in tcache 2
}

void regla06() {
    int *p = NULL;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    //cout << "*p: " << *p << endl; // Segmentation fault (core dumped)
}

void regla07(){
    int *A[10];
    int *p;
    for (int i = 0; i < 10; i++) {
        p = new int;
        A[i] = p;
        cout << "&p: " << &p << endl;
        cout << "p: " << p << endl;
    }

    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "]: " << A[i] << endl;
        delete A[i];
    }
}

void regla08() {
    int *p;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    
    int a;
    p = &a;
    cout << "p = &a;" << endl;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;

    p = usaR3();
    cout << "p = usaR3();" << endl;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    delete p;
}

void regla09() {
    int *p,*q,*r;
    p = new int;
    q = new int;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "r: " << r << endl;

    char ans;
    cout << "r = ? (p/q)" << endl;
    cin >> ans;
    if (ans == 'p') {
        r = p;
    }
    else if (ans = 'q') {
        r = q;
    }


    if (r == p) {
        cout << "r == p" << endl
            << r << " == " << p << endl;
    }
    else {
        cout << "r != p" << endl;
    }

    if (r == q) {
        cout << "r == q" << endl
            << r << " == " << q << endl;
    }
    else {
        cout << "r != q" << endl;
    }

    if (q != p) {
        cout << "q != p" << endl
            << q << " != " << p << endl;
    }
    else {
        cout << "q == p" << endl;
    }
    delete q;
    delete p;
}

void regla10() {
    int *p, a;
    p = &a;
    cout << "p = &a; " << *p << endl;
    *p = 5;
    cout << "*p = 5; " << *p << endl; 
    (*p)++;
    cout << "(*p)++; " << *p << endl;
    *p /= 2;
    cout << "*p /= 2; " << *p << endl;
    *p *= 7;
    cout << "*p *= 7; " << *p << endl;
    (*p)--;
    cout << "(*p)--; " << *p << endl;
    *p %= 5;
    cout << "*p %= 5; " << *p << endl;
}