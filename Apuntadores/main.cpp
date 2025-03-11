#include <iostream>

using namespace std;

int testPointers() {
    int a,b, *   p = nullptr;
    int c,** q;
    void *r;
    a = 5;
    b = 10;
    
    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;
    cout << "&p: " << &p << endl;
    cout << "&q: " << &q << endl;
    cout << "&r: " << &r << endl;

    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "r: " << r << endl;

    /*
    cout << "*p: " << *p << endl;
    cout << "*p = 2;" << endl;
    *p = 2;
    cout << "*p: " << *p << endl;*/
    r = &p;
    r = &a;
    r = &c;
    r = &q;
    cout << "q = &p;" << endl;
    q = &p;
    cout << "q: " << q << endl;
    cout << "&q: " << &q << endl;
    
    p = &a;
    cout << "p = &a;" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    *p = 8;
    cout << "*p = 8;" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    p = &b;
    cout << "p = &b;" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    *p = b+7;
    cout << "*p = b+7;" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    cout << "Resultado final:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p: " << p << endl;

    return 0;
}

void intercambia(int *a,int *b) {
    int tmp = *a;
    cout << "intercambia() &a: " << &a << " &b: " << &b << " &tmp: " << &tmp << endl;
    cout << "Antes intercambio a: " << a << " b: " << b << endl;
    *a = *b;
    *b = tmp;
    cout << "Despues intercambio a: " << a << " b: " << b << endl;
}

void intercambia(int &a,int &b) {
    int tmp = a;
    cout << "intercambia() &a: " << &a << " &b: " << &b << " &tmp: " << &tmp << endl;
    cout << "Antes intercambio a: " << a << " b: " << b << endl;
    a = b;
    b = tmp;
    cout << "Despues intercambio a: " << a << " b: " << b << endl;
}

int pruebaIntercambio() {
    int a,b;
    cout << "main() &a: " << &a << " &b: " << &b << endl;
    cout << "Ingrese dos numeros: " << endl;
    cin >> a >> b;
    cout << "main(): a: " << a << " b: " << b << endl;
    intercambia(a,b);
    cout << "main(): a: " << a << " b: " << b << endl;
    return 0;
}

int main() {
    int a = 5, *p = nullptr;
    cout << "&a " << &a << endl;
    cout << "a " << a << endl;
    cout << "&p " << &p << endl;
    cout << "p " << p << endl;

    p = new int;
    cout << "p = new int;" << endl;
    cout << "&p " << &p << endl;
    cout << "p " << p << endl;
    cout << "*p " << *p << endl;

    *p = a;
    cout << "*p = a;" << endl; 
    cout << "&p " << &p << endl;
    cout << "p " << p << endl;
    cout << "*p " << *p << endl;

    a = *p + 2;
    cout << "a = *p + 2;" << endl;
    cout << "&a " << &a << endl;
    cout << "a " << a << endl;
    cout << "&p " << &p << endl;
    cout << "p " << p << endl;
    cout << "*p " << *p << endl;

    delete p;
    cout << "delete p;" << endl;
    cout << "&p " << &p << endl;
    cout << "p " << p << endl;
    cout << "*p " << *p << endl;
    return 0;
}