#include <iostream>

using namespace std;
int factorial(int);
int fibonacciRec(int);
int fibonacciIter(int);

int main() {
    int n;
    cout << "Ingrese numero a calcular el fibonacci: ";
    cin >> n;
    cout << "fibonacciIter(" << n << ") = " << fibonacciIter(n) << endl;
    cout << "fibonacciRec(" << n << ") = " << fibonacciRec(n) << endl;
    return 0;
}

/*
// factoria n! = n * (n-1) * (n-2) * ... * 2 * 1 = n * (n-1)!
int factorial(int n) {
    if (n < 2) {
        return 1;
    }
    return n * factorial(n-1);
}
*/

int factorial(int n) {
    int ans = 1;
    for (int i = n; i > 1; i--) {
        ans = ans * i;
    }
    return ans;
}

int fibonacciRec(int n) {
    if (n < 3) {
        return 1;
    }
    return fibonacciRec(n-1) + fibonacciRec(n-2);
}

int fibonacciIter(int n) {
    int ant = 1;
    int act = 1;
    int aux;
    while (n > 2) {
        aux = ant + act;
        ant = act;
        act = aux;
        n--;
    }
    return act;
}