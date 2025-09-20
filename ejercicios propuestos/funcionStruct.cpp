#include <iostream>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

Estudiante leerEstudiante() {
    Estudiante e;
    cout << "Nombre: ";
    cin.getline(e.nombre, 50);
    cout << "Edad: ";
    cin >> e.edad;
    cout << "Promedio: ";
    cin >> e.promedio;
    cin.ignore(); // Limpiar buffer para el siguiente nombre
    return e;
}

int mejorPromedio(Estudiante arr[], int n) {
    int mejor = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i].promedio > arr[mejor].promedio)
            mejor = i;
    }
    return mejor;
}

int main() {
    const int N = 3;
    Estudiante estudiantes[N];

    for(int i = 0; i < N; i++) {
        cout << "Datos del estudiante " << i+1 << ":\n";
        estudiantes[i] = leerEstudiante();
    }

    int idx = mejorPromedio(estudiantes, N);

    cout << "\nEl estudiante con mejor promedio es:\n";
    cout << "Nombre: " << estudiantes[idx].nombre << endl;
    cout << "Edad: " << estudiantes[idx].edad << endl;
    cout << "Promedio: " << estudiantes[idx].promedio << endl;

    return 0;}