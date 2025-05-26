#include <iostream>
#include "GrafoMA.h"
#include "GrafoLA.h"
#include "Grafo.h"

using namespace std;
int test() {
    /*GrafoMA<char> Grafo(5,true,false);

    // cargar nodos
    Grafo.setTag(0,'A');
    Grafo.setTag(1,'B');
    Grafo.setTag(2,'C');
    Grafo.setTag(3,'D');
    Grafo.setTag(4,'E');
    */
   
    /*GrafoLA<char> Grafo(true,false);
    for (char a = 'A'; a <= 'E'; a++) {
        Grafo.addNodo(a);
    }
    cout << "Termina de cargar nodos" << endl;

    // cargar arcos
    Grafo.add('A','B');
    Grafo.add('A','C');
    Grafo.add('A','E');
    Grafo.add('B','D');
    Grafo.add('C','D');
    Grafo.add('D','E');
    */

    Grafo<char> G;
    for (char a = 'A'; a <= 'D'; a++) {
        G.addNodo(a);
    }
    G.addArco('A','B');
    G.addArco('A','C');
    G.addArco('B','C');
    G.addArco('D','A');
    G.addArco('D','B');
    G.addArco('D','C');

    for (char a = 'A'; a <= 'D'; a++) {
        cout << a << ": ";
        for (char b = 'A'; b <= 'D'; b++) {
            if (a != b && G.isAdyacent(a,b)) {
                cout << b << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

int main() {
    GrafoLA<char> G(false,false);

    cout << "Agrega nodos" << endl;
    for (char a = 'A'; a <= 'J'; a++) {
        G.addNodo(a);
    }
    
    cout << "Agrega arcos" << endl;
    G.add('A','B');
    G.add('A','E');
    G.add('A','H');
    G.add('B','C');
    G.add('B','E');
    G.add('C','D');
    G.add('C','E');
    G.add('C','F');
    G.add('E','G');
    G.add('E','H');
    G.add('F','J');
    G.add('G','J');
    G.add('H','J');
    G.add('H','I');

    cout << "Comienza recorido a lo ancho" << endl;
    G.deepthFirst();

    return 0;
}