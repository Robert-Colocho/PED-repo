#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int x = 5, y = 6;
    cout << "antes del swap: " << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    swap(&x, &y);

    cout << "despues del swap: " << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    int n;
    cout << "ingrese la cantidad de elementos: " << endl;
    cin >> n;
    // new
    int *vector = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "ingrese un elemento: " << i << endl;
        cin >> vector[i];

        cout << "los elementos son: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << vector[i] << endl;
        }
    }

    // delete
    delete[] vector;

    return 0;
}