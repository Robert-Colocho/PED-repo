#include <iostream>
using namespace std;

struct Facultad
{
    int numeroFacultad;
    string carreraPrincipal;
    int numeroEstudiantes;
};

const int cantidadFacultades = 5;

struct Universidad
{
    string nombre;
    string direccion;
    Facultad facultades[cantidadFacultades];
};

Universidad solicitarDatos()
{
    Universidad u;
    cout << "ingrese el nombre de la universidad: " << endl;
    getline(cin, u.nombre);
    cout << "ingrese la direccion: " << endl;
    getline(cin, u.direccion);

    for (int i = 0; i < cantidadFacultades; i++)
    {
        cout << "ingrese el numero de la facultad: " << endl;
        cin >> u.facultades[i].numeroFacultad;
        cin.ignore(); // Limpiar el buffer antes de getline
        cout << "ingrese la carrera principal de la facultad: " << endl;
        getline(cin, u.facultades[i].carreraPrincipal);
        cout << "ingrese el numero de estudiantes de la facultad: " << endl;
        cin >> u.facultades[i].numeroEstudiantes;
        cin.ignore(); // Limpiar el buffer antes de la siguiente entrada de texto
    }

    return u;
}

int main()
{
    Universidad u;
    u = solicitarDatos();

    return 0;
}