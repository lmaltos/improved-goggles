#include <iostream>

// Logica
template <class T>
T maximo(T,T);

// Aplicativa
int main() {
    std::string a,b;
    std::cout << "Introduzca dos strings: ";
    std::cin >> a >> b;
    std::cout << "maximo entre " << a << " y " << b << " es: " << maximo(a,b) << std::endl;
    int x,y;
    std::cout << "Introduzca dos enteros: ";
    std::cin >> x >> y;
    std::cout << "maximo entre " << x << " y " << y << " es: " << maximo(x,y) << std::endl;
    return 0;
}

// Funcional
template <class T>
T maximo(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}