#include <iostream>
using namespace std;

struct Producto {
    int id;
    char nombre[50];
    float precio;
    int cantidad;
};

void agregarProducto(Producto* arr, int& n) {
    cout << "Ingrese datos del producto:\n";
    cout << "ID: ";
    cin >> arr[n].id;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(arr[n].nombre, 50);
    cout << "Precio: ";
    cin >> arr[n].precio;
    cout << "Cantidad: ";
    cin >> arr[n].cantidad;
    cin.ignore();
    n++;
}

int buscarPorId(Producto* arr, int n, int id) {
    for(int i = 0; i < n; i++)
        if(arr[i].id == id)
            return i;
    return -1;
}

void actualizarCantidad(Producto* arr, int n) {
    int id, nuevaCantidad;
    cout << "Ingrese el ID del producto a actualizar: ";
    cin >> id;
    int idx = buscarPorId(arr, n, id);
    if(idx == -1) {
        cout << "Producto no encontrado.\n";
        return;
    }
    cout << "Cantidad actual: " << arr[idx].cantidad << endl;
    cout << "Ingrese la nueva cantidad: ";
    cin >> nuevaCantidad;
    arr[idx].cantidad = nuevaCantidad;
    cout << "Cantidad actualizada.\n";
}

float valorTotalInventario(Producto* arr, int n) {
    float total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i].precio * arr[i].cantidad;
    return total;
}

void mostrarProductos(Producto* arr, int n) {
    cout << "\nInventario actual:\n";
    for(int i = 0; i < n; i++) {
        cout << "ID: " << arr[i].id << ", Nombre: " << arr[i].nombre
             << ", Precio: " << arr[i].precio << ", Cantidad: " << arr[i].cantidad << endl;
    }
}

int main() {
    int capacidad, n = 0;
    cout << "¿Cuántos productos desea manejar? ";
    cin >> capacidad;
    cin.ignore();

    Producto* inventario = new Producto[capacidad];

    int opcion;
    do {
        cout << "\n--- Menú Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto por ID\n";
        cout << "3. Actualizar cantidad\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Calcular valor total\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                if(n < capacidad)
                    agregarProducto(inventario, n);
                else
                    cout << "Inventario lleno.\n";
                break;
            case 2: {
                int id;
                cout << "Ingrese el ID a buscar: ";
                cin >> id;
                int idx = buscarPorId(inventario, n, id);
                if(idx == -1)
                    cout << "Producto no encontrado.\n";
                else {
                    cout << "Producto encontrado:\n";
                    cout << "ID: " << inventario[idx].id << ", Nombre: " << inventario[idx].nombre
                         << ", Precio: " << inventario[idx].precio << ", Cantidad: " << inventario[idx].cantidad << endl;
                }
                break;
            }
            case 3:
                actualizarCantidad(inventario, n);
                break;
            case 4:
                mostrarProductos(inventario, n);
                break;
            case 5:
                cout << "Valor total del inventario: " << valorTotalInventario(inventario, n) << endl;
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while(opcion != 6);

    delete[] inventario;
    return 0;
}