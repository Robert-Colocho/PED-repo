#include <iostream>
using namespace std;

int main() {
    int arr[5] = {3, 7, 2, 8, 5};
    int* p = arr;
    int suma = 0;

    cout << "Elementos del arreglo:\n";
    for(int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
        suma += *(p + i);
    }
    cout << endl;

    cout << "Suma de los elementos: " << suma << endl;

    return 0;}