#include <iostream>
using namespace std;

void mayorMenor(const int* arr, int n, int& mayor, int& menor) {
    mayor = menor = arr[0];
    for(int i = 1; i < n; i++) {
        if(*(arr + i) > mayor)
            mayor = *(arr + i);
        if(*(arr + i) < menor)
            menor = *(arr + i);
    }
}

int main() {
    int n;
    cout << "¿Cuántos números desea ingresar? ";
    cin >> n;

    int* numeros = new int[n];

    cout << "Ingrese los números:\n";
    for(int i = 0; i < n; i++)
        cin >> numeros[i];

    int mayor, menor;
    mayorMenor(numeros, n, mayor, menor);

    cout << "Mayor número: " << mayor << endl;
    cout << "Menor número: " << menor << endl;

    delete[] numeros;
    return 0;
}