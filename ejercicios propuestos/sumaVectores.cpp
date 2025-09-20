#include <iostream>
using namespace std;

void llenarArreglo(int arr[], int n, const char* nombre) {
    cout << "Ingrese " << n << " elementos para el arreglo " << nombre << ":\n";
    for(int i = 0; i < n; i++) {
        cout << nombre << "[" << i << "]: ";
        cin >> arr[i];
    }
}

void sumaVectores(int a[], int b[], int suma[], int n) {
    for(int i = 0; i < n; i++)
        suma[i] = a[i] + b[i];
}

int productoEscalar(int a[], int b[], int n) {
    int prod = 0;
    for(int i = 0; i < n; i++)
        prod += a[i] * b[i];
    return prod;
}

void mostrarArreglo(int arr[], int n, const char* nombre) {
    cout << nombre << ": ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de los vectores: ";
    cin >> n;

    int v1[100], v2[100], suma[100];

    llenarArreglo(v1, n, "v1");
    llenarArreglo(v2, n, "v2");

    sumaVectores(v1, v2, suma, n);

    cout << "Suma elemento a elemento:\n";
    mostrarArreglo(suma, n, "suma");

    cout << "Producto escalar: " << productoEscalar(v1, v2, n) << endl;