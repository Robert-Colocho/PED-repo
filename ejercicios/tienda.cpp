#include <iostream>
#include <cstring> // Agrega esta línea para usar strcmp
using namespace std;

const int MAX_PRENDAS = 50;

struct Prenda {
    char nombre[50];
    char talla[5]; // S, M, L, XL
    float precio;
    int stock;
};

void mostrarPrendas(Prenda prendas[], int n) {
    cout << "\nPrendas disponibles:\n";
    for(int i = 0; i < n; i++) {
        if(prendas[i].stock > 0) {
            cout << i+1 << ". Nombre: " << prendas[i].nombre
                 << ", Talla: " << prendas[i].talla
                 << ", Precio: " << prendas[i].precio
                 << ", Stock: " << prendas[i].stock << endl;
        }
    }
}

void venderPrenda(Prenda prendas[], int n, const char* nombre, const char* talla) {
    for(int i = 0; i < n; i++) {
        if(prendas[i].stock > 0 &&
           strcmp(prendas[i].nombre, nombre) == 0 &&
           strcmp(prendas[i].talla, talla) == 0) {
            prendas[i].stock--;
            cout << "Venta realizada. Stock restante: " << prendas[i].stock << endl;
            return;
        }
    }
    cout << "Prenda no disponible o sin stock.\n";
}

int main() {
    Prenda prendas[MAX_PRENDAS];
    int n = 0;
    int opcion;

    do {
        cout << "\n--- Tienda de Ropa ---\n";
        cout << "1. Registrar prenda\n";
        cout << "2. Mostrar prendas disponibles\n";
        cout << "3. Vender prenda\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if(opcion == 1) {
            if(n < MAX_PRENDAS) {
                cout << "Nombre: ";
                cin.getline(prendas[n].nombre, 50);
                cout << "Talla (S, M, L, XL): ";
                cin.getline(prendas[n].talla, 5);
                cout << "Precio: ";
                cin >> prendas[n].precio;
                cout << "Stock: ";
                cin >> prendas[n].stock;
                cin.ignore();
                n++;
            } else {
                cout << "No se pueden registrar más prendas.\n";
            }
        } else if(opcion == 2) {
            mostrarPrendas(prendas, n);
        } else if(opcion == 3) {
            char nombre[50], talla[5];
            cout << "Ingrese el nombre de la prenda: ";
            cin.ignore(); // Soluciona el error de salto de línea antes de getline
            cin.getline(nombre, 50);
            cout << "Ingrese la talla: ";
            cin.getline(talla, 5);
            venderPrenda(prendas, n, nombre, talla);
        } else if(opcion == 4) {
            cout << "Saliendo...\n";
        } else {
            cout << "Opción inválida.\n";
        }
    } while(opcion != 4);

    return 0;
}