#include <iostream>
using namespace std;

const int TAM = 10;

// Generador pseudoaleatorio simple
int pseudoRandom(int semilla) {
    semilla = (semilla * 17 + 23) % 100;
    return semilla + 1;
}

void llenarArreglo(int arr[], int n) {
    int semilla = 37;
    for(int i = 0; i < n; i++) {
        semilla = pseudoRandom(semilla + i);
        arr[i] = semilla;
    }
}

int encontrarMaximo(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

int encontrarMinimo(int arr[], int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

float calcularPromedio(int arr[], int n) {
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += arr[i];
    return (float)suma / n;
}

void mostrarArreglo(int arr[], int n) {
    cout << "Arreglo: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arreglo[TAM];
    llenarArreglo(arreglo, TAM);

    mostrarArreglo(arreglo, TAM);

    cout << "Máximo: " << encontrarMaximo(arreglo, TAM) << endl;
    cout << "Mínimo: " << encontrarMinimo(arreglo, TAM) << endl;
    cout << "Promedio: " << calcularPromedio(arreglo, TAM) << endl;