#include <iostream>
using namespace std;

int main()
{

    int n = 10;
    int *p = &n;

    cout << "valor de n: " << n << endl;
    cout << "direccion de n: " << &n << endl;

    cout << "valor de p: " << p << endl;
    cout << "a lo que apunta p: " << *p << endl;

    *p = 20;

    cout << "valor de n: " << n << endl;

    int numeros[5] = {10, 20, 30, 40, 50};
    int *p = numeros;

    cout << "Elemento: " << *(p) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento: " << *(p + i) << endl;
    }

    return 0;
}