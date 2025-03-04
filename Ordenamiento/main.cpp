/*
    
*/
#include <iostream>
#include <ctime>

using namespace std;

void imprimeArreglo(int [], int);
void copiarArreglo(int [],int [], int);
void ordenIntercambio(int [], int);
void burbuja(int [], int);
void seleccion(int [], int);
void insercion(int [], int);
void quickSort(int [], int);

int main() {
    int x[100],y[100];
    cout << "time(0): " << time(0) << endl;
    srand(time(0)); // semilla aleatoria, con el tiempo de ejecucion
    // Llenando el arreglo
    for (int i = 0; i < 100; i++) {
        y[i] = rand() % 1000;
     }
    // Imprimri arrego desordenado
    imprimeArreglo(y,100);
    
    cout << "Se llama ordenIntercambio" << endl;
    copiarArreglo(x,y,100);
    ordenIntercambio(x,100);
    cout << "Resultaod ordenamiento intercambio:" << endl;
    imprimeArreglo(x,100);
    
    cout << "Se llama orden burbuja" << endl;
    copiarArreglo(x,y,100);
    burbuja(x,100);
    cout << "Resultaod ordenamiento burbuja:" << endl;
    imprimeArreglo(x,100);

    cout << "Se llama orden seleccion" << endl;
    copiarArreglo(x,y,100);
    seleccion(x,100);
    cout << "Resultaod ordenamiento seleccion:" << endl;
    imprimeArreglo(x,100);
    
    cout << "Se llama orden insercion" << endl;
    copiarArreglo(x,y,100);
    insercion(x,100);
    cout << "Resultaod ordenamiento insercion:" << endl;
    imprimeArreglo(x,100);
    
    cout << "Se llama orden quickSort" << endl;
    copiarArreglo(x,y,100);
    quickSort(x,100);
    cout << "Resultaod ordenamiento quickSort:" << endl;
    imprimeArreglo(x,100);
    return 0;
}

void imprimeArreglo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        if ((i + 1) % 20 == 0) {
            cout << endl; // se quiere imprimir un brinco de linea cada 20 opciones
        }
    }
}


void copiarArreglo(int a[],int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
     }
}

void ordenIntercambio(int arr[], int n) {
    int i,j;
    int aux;
    int comparaciones = 0;
    int intercambios = 0;
    for (i = 0; i <= n-2; i++) {
        for (j = i+1; j <= n-1; j++) {
            comparaciones++;
            if (arr[i] > arr[j]) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                intercambios++;
            }
        }
    }
    cout << "comparaciones: " << comparaciones << endl 
        << "intercambios: " << intercambios << endl;
}

void burbuja(int arr[], int n) {
    bool interruptor = true;
    int aux;
    int comparaciones = 0;
    int intercambios = 0;
    for (int pasada = 0; (pasada < n-1) && interruptor; pasada++) {
        interruptor = false;
        for (int j = 0; j < n - 1 - pasada; j++) {
            comparaciones++;
            if (arr[j+1] < arr[j]) {
                aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
                interruptor = true;
                intercambios++;
            }
        }
    }
    cout << "comparaciones: " << comparaciones << endl 
        << "intercambios: " << intercambios << endl;
}

void seleccion(int arr[], int n) {
    int indiceMenor,i,j;
    int aux;
    int comparaciones = 0;
    int intercambios = 0;
    for (i = 0; i < n-1; i++) {
        indiceMenor = i;
        for (j = i+1; j < n; j++) {
            comparaciones++;
            if (arr[j] < arr[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            aux = arr[i];
            arr[i] = arr[indiceMenor];
            arr[indiceMenor] = aux;
            intercambios++;
        }
    }
    cout << "comparaciones: " << comparaciones << endl 
        << "intercambios: " << intercambios << endl;
}

void insercion(int arr[], int n) {
    int i,j;
    int aux;
    int comparaciones = 0;
    int intercambios = 0;
    for (i = 1; i < n; i++) {
        j = i;
        aux = arr[i];
        comparaciones++;
        while (j > 0 && aux < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
            comparaciones++;
            //intercambios++; // los consideramos o no?
        }
        if (j != i) {
            arr[j] = aux;
            intercambios++;
        }
    }
    cout << "comparaciones: " << comparaciones << endl 
        << "intercambios: " << intercambios << endl;
}

int comparaciones_qs,intercambios_qs;

int particion(int arr[], int inicio, int fin) {
    int elementoPivote = arr[inicio];
    int j = inicio;
    for (int i = inicio+1; i <= fin; i++) {
        comparaciones_qs++;
        if (arr[i] < elementoPivote) {
            intercambios_qs++;
            int aux = arr[i];
            arr[i] = arr[++j];
            arr[j] = aux;
        }
    }
    intercambios_qs++;
    arr[inicio] = arr[j];
    arr[j] = elementoPivote;
    return j;
} 

void quickSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = particion(arr,inicio,fin);
        quickSort(arr,inicio,pivote-1);
        quickSort(arr,pivote+1,fin);
    }
}

void quickSort(int arr[], int n) {
    comparaciones_qs = 0;
    intercambios_qs = 0;
    quickSort(arr,0,n-1);
    cout << "comparaciones: " << comparaciones_qs << endl 
        << "intercambios: " << intercambios_qs << endl;
}
