#include <iostream>
using namespace std;

struct Serie
{
    string titulo;
    string genero;
    float horasVistas;
    float pagoRecibido;
    float ingresoGenerado;
};

void solicitarDatos(Serie serie[], int n)
{

    Serie serie[n];

    for (int i = 0; i < n; i++)
    {
        Serie serie[i];
        cout << "porfavor ingrese los datos de cada serie" << endl;
        cout << "ingrese el nombre de la serie" << endl;
        cin >> serie[i].titulo;
        cout << "ingrese el genero de la serie";
        cin >> serie[i].genero;
        cout << "ingrese las horas vistas en esa serie" << endl;
        cin >> serie[i].horasVistas;
    }

    return;
}

int main()
{
    int n;
    cout << "porfavor ingrese cuantas series ha visto" << endl;
    cin >> n;
    Serie serie[n];
    solicitarDatos(serie, n);

        return 0;
}