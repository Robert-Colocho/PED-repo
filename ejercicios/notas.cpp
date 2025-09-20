#include <iostream>
using namespace std;

const int M = 3; // Número de alumnos
const int N = 4; // Número de materias

void ingresarNotas(float notas[M][N]) {
    for(int i = 0; i < M; i++) {
        cout << "Alumno " << i+1 << ":\n";
        for(int j = 0; j < N; j++) {
            cout << "  Nota materia " << j+1 << ": ";
            cin >> notas[i][j];
        }
    }
}

void promedioAlumnos(float notas[M][N], float promedios[M]) {
    for(int i = 0; i < M; i++) {
        float suma = 0;
        for(int j = 0; j < N; j++)
            suma += notas[i][j];
        promedios[i] = suma / N;
    }
}

void promedioMaterias(float notas[M][N], float promedios[N]) {
    for(int j = 0; j < N; j++) {
        float suma = 0;
        for(int i = 0; i < M; i++)
            suma += notas[i][j];
        promedios[j] = suma / M;
    }
}

void mostrarResultados(float promediosAlumnos[M], float promediosMaterias[N]) {
    cout << "\nPromedio por alumno:\n";
    for(int i = 0; i < M; i++)
        cout << "Alumno " << i+1 << ": " << promediosAlumnos[i] << endl;

    cout << "\nPromedio por materia:\n";
    for(int j = 0; j < N; j++)
        cout << "Materia " << j+1 << ": " << promediosMaterias[j] << endl;
}

int main() {
    float notas[M][N];
    float promediosAlumnos[M];
    float promediosMaterias[N];

    ingresarNotas(notas);
    promedioAlumnos(notas, promediosAlumnos);
    promedioMaterias(notas, promediosMaterias);
    mostrarResultados(promediosAlumnos, promediosMaterias);