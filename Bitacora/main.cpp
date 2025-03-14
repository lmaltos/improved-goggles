#include <iostream>
#include <fstream>
#include "Registro.h"
#include <vector>

using namespace std;

int main() {
    fstream f("bitacora.txt");
    Registro r;
    int n;
    vector<Registro> bitacora;
    while (!f.eof()) {
        f >> r;
        bitacora.push_back(r);
    }
    cout << "indice registo a inspeccionar: ";
    cin >> n;
    if (n < bitacora.size()) {
        cout << bitacora[n] << endl;
    }
    f.close();
    return 0;
}