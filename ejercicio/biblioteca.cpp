#include <iostream>
#include <string>
using namespace std;

const int librosMaximos = 10;

struct Libro {
    string titulo;
    string autor;
    int año;
    bool estado;
};

void mostrarLibrosDisponibles(Libro biblioteca[], int cantidad) {
    cout << "Libros disponibles: "<<endl;
    for (int i = 0; i < cantidad; ++i) {
        if (biblioteca[i].estado) {
            cout << "- " << biblioteca[i].titulo << " por " << biblioteca[i].autor
                 << " (" << biblioteca[i].año << ")"<< endl;
        }
    }
}

bool prestarLibro(Libro biblioteca[], int cantidad, const string & tituloBuscado) {
    for (int i = 0; i < cantidad; ++i) {
        if (biblioteca[i].titulo == tituloBuscado) {
            if (biblioteca[i].estado) {
                biblioteca[i].estado = false;
                cout << "Libro prestado: " << tituloBuscado << endl;
                return true;
            } else {
                cout << "El libro ya está prestado" << endl;
                return false;
            }
        }
    }
    cout << "Libro no encontrado" << endl;
    return false;
}

int main() {
    Libro biblioteca[librosMaximos] = {
        {"Cien Años de Soledad", "Gabriel García Márquez", 1967, true},
        {"El Principito", "Antoine de Saint-Exupéry", 1943, true},
        {"1984", "George Orwell", 1949, true},
        {"Rayuela", "Julio Cortázar", 1963, true},
        {"Don Quijote", "Miguel de Cervantes", 1605, true},
        {"Orgullo y Prejuicio", "Jane Austen", 1813, true},
        {"Fahrenheit 451", "Ray Bradbury", 1953, true},
        {"La Odisea", "Homero", -800, true},
        {"Crimen y Castigo", "Fiódor Dostoyevski", 1866, true},
        {"El Hobbit", "J.R.R. Tolkien", 1937, true}
    };

    int cantidadLibros = librosMaximos;

    mostrarLibrosDisponibles(biblioteca, cantidadLibros);

    string titulo;
    cout << "Ingresa el título del libro que deseas prestar: "<<endl;
    getline(cin, titulo);

    prestarLibro(biblioteca, cantidadLibros, titulo);

    mostrarLibrosDisponibles(biblioteca, cantidadLibros);

    return 0;
}

void col8 (){} //firma personal
//esta hecho en linux asi que no hay ejecutable .exe