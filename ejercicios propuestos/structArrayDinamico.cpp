#include <iostream>
using namespace std;

struct Producto {
    int codigo;
    char nombre[50];
    float precio;
};

void leerProductos(Producto* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Producto " << i+1 << ":\n";
        cout << "Código: ";
        cin >> arr[i].codigo;
        cin.ignore();
        cout << "Nombre: ";
        cin.getline(arr[i].nombre, 50);
        cout << "Precio: ";
        cin >> arr[i].precio;
        cin.ignore();
    }
}

void mostrarProductos(const Producto* arr, int n) {
    cout << "\nLista de productos:\n";
    for(int i = 0; i < n; i++) {
        cout << "Código: " << arr[i].codigo << ", Nombre: " << arr[i].nombre << ", Precio: " << arr[i].precio << endl;
    }
}

int productoMasCaro(const Producto* arr, int n) {
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i].precio > arr[idx].precio)
            idx = i;
    }
    return idx;
}

int main() {
    int n;
    cout << "¿Cuántos productos desea registrar? ";
    cin >> n;
    cin.ignore();

    Producto* productos = new Producto[n];

    leerProductos(productos, n);
    mostrarProductos(productos, n);

    int idx = productoMasCaro(productos, n);
    cout << "\nEl producto más caro es:\n";
    cout << "Código: " << productos[idx].codigo << ", Nombre: " << productos[idx].nombre << ", Precio: " << productos[idx].precio << endl;

    delete[] productos;
    return 0;
}