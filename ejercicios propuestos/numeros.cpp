#include <iostream>
using namespace std;

const int TAM = 20;

// Genera números pseudoaleatorios entre 1 y 100 usando una semilla simple
int pseudoRandom(int semilla) {
    semilla = (semilla * 17 + 23) % 100;
    return semilla + 1;
}

void generarNumeros(int arr[], int n) {
    int semilla = 37;
    for(int i = 0; i < n; i++) {
        semilla = pseudoRandom(semilla + i);
        arr[i] = semilla;
    }
}

void mostrarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void contarParesImpares(int arr[], int n, int &pares, int &impares) {
    pares = impares = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0)
            pares++;
        else
            impares++;
    }
}

int segundoMayor(int arr[], int n) {
    int mayor = arr[0], segundo = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > mayor)
            mayor = arr[i];
    for(int i = 0; i < n; i++)
        if(arr[i] < mayor && (segundo == arr[0] || arr[i] > segundo))
            segundo = arr[i];
    return segundo;
}

int segundoMenor(int arr[], int n) {
    int menor = arr[0], segundo = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < menor)
            menor = arr[i];
    for(int i = 0; i < n; i++)
        if(arr[i] > menor && (segundo == arr[0] || arr[i] < segundo))
            segundo = arr[i];
    return segundo;
}

void invertirArreglo(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int main() {
    int numeros[TAM];
    generarNumeros(numeros, TAM);

    cout << "Arreglo generado:\n";
    mostrarArreglo(numeros, TAM);

    int pares, impares;
    contarParesImpares(numeros, TAM, pares, impares);
    cout << "Cantidad de pares: " << pares << endl;
    cout << "Cantidad de impares: " << impares << endl;

    cout << "Segundo mayor: " << segundoMayor(numeros, TAM) << endl;
    cout << "Segundo menor: " << segundoMenor(numeros, TAM) << endl;

    invertirArreglo(numeros, TAM);
    cout << "Arreglo invertido:\n";
return 0;
    }