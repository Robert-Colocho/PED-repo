#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "¿Cuántos números desea ingresar? ";
    cin >> n;

    int* arr = new int[n];

    int suma = 0, mayor;
    cout << "Ingrese los números:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        suma += arr[i];
        if(i == 0 || arr[i] > mayor)
            mayor = arr[i];
    }

    float promedio = (float)suma / n;

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor: " << mayor << endl;

    delete[] arr;

    return 0;
}