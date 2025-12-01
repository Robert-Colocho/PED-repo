#include <iostream>
using namespace std;

void sumarRef(int &xp, int pts)
{
    xp += pts;
}

void restarPtr(int *xp, int pts)
{
    if (xp != nullptr)
    {
        *xp -= pts;
        if (*xp < 0)
            *xp = 0;
    }
}

int simularOperacionValor(int xp, int pts, char op)
{
    if (op == '+')
    {
        return xp + pts;
    }
    else if (op == '-')
    {
        int resultado = xp - pts;
        return resultado < 0 ? 0 : resultado;
    }
    else
    {
        cout << "operacion no valida, tiene que usar '+' o '-' " << endl;
        return xp;
    }
}

void mostrarMenu()
{
    int xp = 100;
    int pts;
    char op;
    int opcion;

    do
    {
        cout << " XP actual: " << xp << endl;
        cout << "1. ganar XP real " << endl;
        cout << "2. perder XP real " << endl;
        cout << "3. simular operacion XP " << endl;
        cout << "0. salir " << endl;
        cout << "elige opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "puntos a ganar: ";
            cin >> pts;
            sumarRef(xp, pts);
            cout << "XP actualizado: " << xp << endl;
            break;
        case 2:
            cout << "puntos a perder: ";
            cin >> pts;
            restarPtr(&xp, pts);
            cout << "XP actualizado: " << xp << endl;
            break;
        case 3:
            cout << "puntos a simular: ";
            cin >> pts;
            cout << "operacion (+/-): ";
            cin >> op;
            cout << "resultado simulado: " << simularOperacionValor(xp, pts, op) << endl;
            break;
        case 0:
            cout << "saliendo ";
            break;
        default:
            cout << "opcion invalida ";
        }
    } while (opcion != 0);
}

int main()
{
    mostrarMenu();
    return 0;
}