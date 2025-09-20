#include <iostream>
#include <cstring>
using namespace std;

struct Contacto {
    char nombre[50];
    char telefono[20];
    char correo[50];
};

void agregarContacto(Contacto**& lista, int& n) {
    Contacto* nuevo = new Contacto;
    cout << "Nombre: ";
    cin.getline(nuevo->nombre, 50);
    cout << "Telefono: ";
    cin.getline(nuevo->telefono, 20);
    cout << "Correo: ";
    cin.getline(nuevo->correo, 50);

    Contacto** temp = new Contacto*[n + 1];
    for(int i = 0; i < n; i++)
        temp[i] = lista[i];
    temp[n] = nuevo;

    delete[] lista;
    lista = temp;
    n++;
}

void mostrarContactos(Contacto** lista, int n) {
    cout << "\nLista de contactos:\n";
    for(int i = 0; i < n; i++) {
        cout << i+1 << ". Nombre: " << lista[i]->nombre
             << ", Telefono: " << lista[i]->telefono
             << ", Correo: " << lista[i]->correo << endl;
    }
}

int buscarContacto(Contacto** lista, int n, const char* nombre) {
    for(int i = 0; i < n; i++)
        if(strcmp(lista[i]->nombre, nombre) == 0)
            return i;
    return -1;
}

void eliminarContacto(Contacto**& lista, int& n, const char* nombre) {
    int idx = buscarContacto(lista, n, nombre);
    if(idx == -1) {
        cout << "Contacto no encontrado.\n";
        return;
    }
    delete lista[idx];
    for(int i = idx; i < n - 1; i++)
        lista[i] = lista[i + 1];
    Contacto** temp = new Contacto*[n - 1];
    for(int i = 0; i < n - 1; i++)
        temp[i] = lista[i];
    delete[] lista;
    lista = temp;
    n--;
    cout << "Contacto eliminado.\n";
}

int main() {
    Contacto** lista = nullptr;
    int n = 0;
    int opcion;
    char nombre[50];

    do {
        cout << "\n--- Agenda de Contactos ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar contactos\n";
        cout << "3. Buscar contacto por nombre\n";
        cout << "4. Eliminar contacto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                agregarContacto(lista, n);
                break;
            case 2:
                mostrarContactos(lista, n);
                break;
            case 3:
                cout << "Ingrese el nombre a buscar: ";
                cin.getline(nombre, 50);
                {
                    int idx = buscarContacto(lista, n, nombre);
                    if(idx == -1)
                        cout << "Contacto no encontrado.\n";
                    else {
                        cout << "Contacto encontrado:\n";
                        cout << "Nombre: " << lista[idx]->nombre << endl;
                        cout << "Telefono: " << lista[idx]->telefono << endl;
                        cout << "Correo: " << lista[idx]->correo << endl;
                    }
                }
                break;
            case 4:
                cout << "Ingrese el nombre a eliminar: ";
                cin.getline(nombre, 50);
                eliminarContacto(lista, n, nombre);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while(opcion != 5);

    for(int i = 0; i < n; i++)
        delete lista[i];
    delete[] lista;

    return 0;
}