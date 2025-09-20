#include <iostream>
using namespace std;

// Generador pseudoaleatorio simple entre 1 y 99
int pseudoRandom(int semilla) {
    semilla = (semilla * 17 + 23) % 99;
    return semilla + 1;
}

void llenarMatriz(int** mat, int n) {
    int semilla = 37;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            semilla = pseudoRandom(semilla + i + j);
            mat[i][j] = semilla;
        }
}

void mostrarMatriz(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int sumaDiagonalPrincipal(int** mat, int n) {
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += mat[i][i];
    return suma;
}

int sumaDiagonalSecundaria(int** mat, int n) {
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += mat[i][n - 1 - i];
    return suma;
}

void transponerMatriz(int** mat, int n) {
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
}

void liberarMatriz(int** mat, int n) {
    for(int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;

    // Crear matriz dinámica n x n
    int** matriz = new int*[n];
    for(int i = 0; i < n; i++)
        matriz[i] = new int[n];

    llenarMatriz(matriz, n);

    cout << "\nMatriz generada:\n";
    mostrarMatriz(matriz, n);

    cout << "Suma diagonal principal: " << sumaDiagonalPrincipal(matriz, n) << endl;
    cout << "Suma diagonal secundaria: " << sumaDiagonalSecundaria(matriz, n) << endl;

    transponerMatriz(matriz, n);
    cout << "\nMatriz transpuesta:\n";
    mostrarMatriz(matriz, n);

    liberarMatriz(matriz, n);

    return 0;