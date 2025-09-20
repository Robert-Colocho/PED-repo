#include <iostream>
using namespace std;

// Generador pseudoaleatorio simple entre 1 y 50
int pseudoRandom(int semilla) {
    semilla = (semilla * 17 + 23) % 50;
    return semilla + 1;
}

void llenarMatriz(int** mat, int n, int m) {
    int semilla = 37;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            semilla = pseudoRandom(semilla + i + j);
            mat[i][j] = semilla;
        }
}

void mostrarMatriz(int** mat, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

void sumaFilas(int** mat, int n, int m) {
    cout << "\nSuma de cada fila:\n";
    for(int i = 0; i < n; i++) {
        int suma = 0;
        for(int j = 0; j < m; j++)
            suma += mat[i][j];
        cout << "Fila " << i << ": " << suma << endl;
    }
}

int main() {
    int n, m;
    cout << "Ingrese el número de filas: ";
    cin >> n;
    cout << "Ingrese el número de columnas: ";
    cin >> m;

    // Crear matriz dinámica
    int** matriz = new int*[n];
    for(int i = 0; i < n; i++)
        matriz[i] = new int[m];

    llenarMatriz(matriz, n, m);

    cout << "\nMatriz generada:\n";
    mostrarMatriz(matriz, n, m);

    sumaFilas(matriz, n, m);

    // Liberar memoria
    for(int i = 0; i < n; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}