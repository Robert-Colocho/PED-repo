#include <iostream>
using namespace std;

const int N = 5;

// Genera números pseudoaleatorios entre 1 y 99
int pseudoRandom(int semilla) {
    semilla = (semilla * 17 + 23) % 99;
    return semilla + 1;
}

void llenarMatriz(int mat[N][N]) {
    int semilla = 37;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            semilla = pseudoRandom(semilla + i + j);
            mat[i][j] = semilla;
        }
}

void mostrarMatriz(int mat[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

void sumaFilas(int mat[N][N], int sumaFilas[N]) {
    for(int i = 0; i < N; i++) {
        sumaFilas[i] = 0;
        for(int j = 0; j < N; j++)
            sumaFilas[i] += mat[i][j];
    }
}

void sumaColumnas(int mat[N][N], int sumaColumnas[N]) {
    for(int j = 0; j < N; j++) {
        sumaColumnas[j] = 0;
        for(int i = 0; i < N; i++)
            sumaColumnas[j] += mat[i][j];
    }
}

int filaMayorSuma(int sumaFilas[N]) {
    int mayor = sumaFilas[0], fila = 0;
    for(int i = 1; i < N; i++) {
        if(sumaFilas[i] > mayor) {
            mayor = sumaFilas[i];
            fila = i;
        }
    }
    return fila;
}

void transponerMatriz(int mat[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {
    int matriz[N][N];
    int sumaF[N], sumaC[N];

    llenarMatriz(matriz);

    cout << "Matriz generada:\n";
    mostrarMatriz(matriz);

    sumaFilas(matriz, sumaF);
    sumaColumnas(matriz, sumaC);

    cout << "\nSuma de cada fila:\n";
    for(int i = 0; i < N; i++)
        cout << "Fila " << i << ": " << sumaF[i] << endl;

    cout << "\nSuma de cada columna:\n";
    for(int j = 0; j < N; j++)
        cout << "Columna " << j << ": " << sumaC[j] << endl;

    int filaMax = filaMayorSuma(sumaF);
    cout << "\nLa fila con mayor suma es la fila " << filaMax << " (suma: " << sumaF[filaMax] << ")\n";

    transponerMatriz(matriz);
    cout << "\nMatriz transpuesta:\n";
    mostrarMatriz(matriz);