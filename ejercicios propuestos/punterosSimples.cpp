#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* px = &x;

    cout << "Direccion de x: " << px << endl;
    cout << "Valor de x usando el puntero: " << *px << endl;

    *px = 25; // Modifica el valor de x a través del puntero

    cout << "Nuevo valor de x: " << x << endl;
    cout << "Valor de x usando el puntero: " << *px << endl;

    return 0;}