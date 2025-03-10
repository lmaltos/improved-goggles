#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        if ((i + 1) % 20 == 0) {
            cout << endl; // se quiere imprimir un brinco de linea cada 20 opciones
        }
    }
    cout << endl;
}

void swap(vector<int> &v, int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
    print(v);
    cout << "Termina funcion sawp" << endl;
}

int main() {
    int a[100];
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        int a = i + 1;
        v.push_back(a);
    }
    cout << "v.size(): " << v.size() << endl;
    print(v);
    cout << "swap(2,7)" << endl;
    swap(v,2,7);
    print(v);
    return 0;
}