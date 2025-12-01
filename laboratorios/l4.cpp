#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Persona
{
    string nombre;
    int asiento;
    string categoria;
};

queue<Persona> cola;
int siguienteAsiento = 1;

void agregarPersona()
{
    Persona p;
    cout << "ingrese el nombre: " << endl;
    cin >> p.nombre;
    cout << "ingrese la categoria (adulto, niño, etc): " << endl;
    cin >> p.categoria;
    p.asiento = siguienteAsiento++;
    cola.push(p);
    cout << "persona agregada con asiento #" << p.asiento << endl;
}

void mostrarCola()
{
    if (cola.empty())
    {
        cout << "no hay personas en la cola " << endl;
        return;
    }
    queue<Persona> temp = cola;
    cout << "personas en espera:" << endl;
    while (!temp.empty())
    {
        Persona p = temp.front();
        cout << "nombre: " << p.nombre << ", asiento: " << p.asiento << ", categoria: " << p.categoria << endl;
        temp.pop();
    }
}

void iniciarViaje(int capacidad = 5)
{
    if (cola.empty())
    {
        cout << "no hay personas en la cola para iniciar el viaje " << endl;
        return;
    }
    cout << "personas que suben al viaje: " << endl;
    int count = 0;
    while (!cola.empty() && count < capacidad)
    {
        Persona p = cola.front();
        cout << "nombre: " << p.nombre << ", asiento: " << p.asiento << ", categoria: " << p.categoria << endl;
        cola.pop();
        count++;
    }
    if (count == 0)
    {
        cout << "no hay suficientes personas para iniciar el viaje " << endl;
    }
}

void menu()
{
    int opcion;
    do
    {
        cout << "montaña rusa " << endl;
        cout << "1. agregar persona " << endl;
        cout << "2. mostrar cola " << endl;
        cout << "3. iniciar viaje " << endl;
        cout << "0. salir " << endl;
        cout << "seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarPersona();
            break;
        case 2:
            mostrarCola();
            break;
        case 3:
            iniciarViaje();
            break;
        case 0:
            cout << "saliendo del programa" << endl;
            break;
        default:
            cout << "opcion no valida" << endl;
        }
    } while (opcion != 0);
}

int main()
{

    menu();

    return 0;
}