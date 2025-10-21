#include <iostream>
using namespace std;

// enfoque iterativo
int contarHastaN(int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << endl;
    }
}

// enfoque recursivo
int contarHastaNRecursivo(int n)
{
    if (n == 0)
        return; // caso base

    contarHastaNRecursivo(n - 1); // caso recursivo
    cout << n;
}

// enfoque recursivo
int sumarN(int n)
{
    // caso base
    if (n == 0)
        return 0;
    // caso recursivo
    return n + sumarN(n - 1);
}

// enfoque recursivo
int factorial(int n)
{
    // caso base
    if (n == 0)
        return 1;
    // caso recursivo
    return n * factorial(n - 1);
}

// enfoque recursivo
int contarDigitos(int n)
{
    // caso base
    if (n < 10)
        return 1;

    // caso recursivo
    return 1 + contarDigitos(n / 10);
}

// enfoque recursivo
int fibonacci(int n)
{
    // caso base: si 0 es 0 retorna 0
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 5;
    int r = 1234;
    cout << factorial(n);
    sumarN(n);
    cout << contarHastaN(n);
    return 0;
}