#include <iostream>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    Estudiante estudiantes[3];
    int mejor = 0;

    for(int i = 0; i < 3; i++) {
        cout << "Datos del estudiante " << i+1 << ":\n";
        cout << "Nombre: ";
        cin.getline(estudiantes[i].nombre, 50);
        cout << "Edad: ";
        cin >> estudiantes[i].edad;
        cout << "Promedio: ";
        cin >> estudiantes[i].promedio;
        cin.ignore(); // Limpiar buffer para el siguiente nombre
        if(estudiantes[i].promedio > estudiantes[mejor].promedio)
            mejor = i;
    }

    cout << "\nEl estudiante con mejor promedio es:\n";
    cout << "Nombre: " << estudiantes[mejor].nombre << endl;
    cout << "Edad: " << estudiantes[mejor].edad << endl;
    cout << "Promedio: " << estudiantes[mejor].promedio << endl;

    return 0;}