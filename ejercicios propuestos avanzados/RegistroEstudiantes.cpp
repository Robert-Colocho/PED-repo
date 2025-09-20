#include <iostream>
using namespace std;

struct Estudiante {
    char carnet[20];
    char nombre[50];
    float promedio;
};

void ingresarEstudiantes(Estudiante* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Estudiante " << i+1 << ":\n";
        cout << "Carnet: ";
        cin.getline(arr[i].carnet, 20);
        cout << "Nombre: ";
        cin.getline(arr[i].nombre, 50);
        cout << "Promedio: ";
        cin >> arr[i].promedio;
        cin.ignore();
    }
}

void ordenarPorPromedio(Estudiante* arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j].promedio > arr[j+1].promedio) {
                Estudiante* a = &arr[j];
                Estudiante* b = &arr[j+1];
                Estudiante temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}

void mostrarEstudiantes(Estudiante* arr, int n) {
    cout << "\nLista de estudiantes ordenados por promedio:\n";
    for(int i = 0; i < n; i++) {
        cout << "Carnet: " << arr[i].carnet << ", Nombre: " << arr[i].nombre << ", Promedio: " << arr[i].promedio << endl;
    }
}

void mostrarMejorPeor(Estudiante* arr, int n) {
    cout << "\nEstudiante con mejor promedio:\n";
    cout << "Carnet: " << arr[n-1].carnet << ", Nombre: " << arr[n-1].nombre << ", Promedio: " << arr[n-1].promedio << endl;
    cout << "\nEstudiante con peor promedio:\n";
    cout << "Carnet: " << arr[0].carnet << ", Nombre: " << arr[0].nombre << ", Promedio: " << arr[0].promedio << endl;
}

int main() {
    int n;
    cout << "¿Cuántos estudiantes desea registrar? ";
    cin >> n;
    cin.ignore();

    Estudiante* estudiantes = new Estudiante[n];

    ingresarEstudiantes(estudiantes, n);
    ordenarPorPromedio(estudiantes, n);
    mostrarEstudiantes(estudiantes, n);
    mostrarMejorPeor(estudiantes, n);

    delete[] estudiantes;
    return 0;
}