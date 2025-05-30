#include <iostream>
#include "GrafoMA.h"
#include "GrafoLA.h"
#include "Grafo.h"

using namespace std;
int test_Creacion() {
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
    G.addArco('A','B',30);
    G.addArco('A','C',75);
    G.addArco('B','C',15);
    G.addArco('D','A',20);
    G.addArco('D','B',70);
    G.addArco('D','C',90);

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

void test_Recorridos() {
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
}

int main() {
    Grafo<char> G;
    cout << "Agrega nodos" << endl;
    for (char a = 'A'; a <= 'L'; a++) {
        G.addNodo(a);
    }

    
    cout << "Agrega arcos" << endl;
    G.addArco('A','B',10);
    G.addArco('A','C',8);
    G.addArco('A','D',15);
    G.addArco('B','E',15);
    G.addArco('C','G',15);
    G.addArco('C','J',14);
    G.addArco('D','G',6);
    G.addArco('D','I',15);
    G.addArco('E','J',8);
    G.addArco('E','H',30);
    G.addArco('F','L',15);
    G.addArco('G','F',8);
    G.addArco('G','I',7);
    G.addArco('H','L',15);
    G.addArco('I','K',10);
    G.addArco('J','F',9);
    G.addArco('J','H',18);
    G.addArco('K','L',10);
    
    cout << "Comienza Dijkstra" << endl;
    G.Dijkstra('A');

}