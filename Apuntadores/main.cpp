#include <iostream>

using namespace std;

int main() {
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