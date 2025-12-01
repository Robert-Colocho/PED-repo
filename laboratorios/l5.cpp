#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

// estructura para representar una habitacion
struct Habitacion
{
    int numero;
    string tipo;
    double precio;
    int capacidad;
    bool disponible;
};

// funcion para comparar las habitaciones por el precio (para el sort)
bool compararPorPrecio(const Habitacion &h1, const Habitacion &h2)
{
    return h1.precio < h2.precio;
}

// funcion para comparar las habitaciones por el numero (para binary_search)
bool compararPorNumero(const Habitacion &h1, const Habitacion &h2)
{
    return h1.numero < h2.numero;
}

// funcion para agregar una nueva habitacion al hotel
void agregarHabitacion(list<Habitacion> &hotel)
{
    Habitacion nueva;
    cout << "ingrese el numero de habitacion: " << endl;
    cin >> nueva.numero;
    cout << "ingrese tipo de habitacion: " << endl;
    cin.ignore();
    getline(cin, nueva.tipo);
    cout << "ingrese precio por noche: " << endl;
    cin >> nueva.precio;
    cout << "ingrese la capacidad de personas: " << endl;
    cin >> nueva.capacidad;
    nueva.disponible = true;

    hotel.push_back(nueva);
    cout << "habitacion agregada exitosamente " << endl;
}

// funcion para ordenar las habitaciones por precio
void ordenarPorPrecio(list<Habitacion> &hotel)
{
    hotel.sort(compararPorPrecio);
    cout << "habitaciones ordenadas por precio " << endl;
}

// funcion para buscar una habitacion por numero
bool buscarHabitacion(const list<Habitacion> &hotel, int numero)
{
    list<Habitacion> temp = hotel;
    temp.sort(compararPorNumero);

    Habitacion buscar;
    buscar.numero = numero;

    auto it = find_if(temp.begin(), temp.end(),
                      [numero](const Habitacion &h)
                      { return h.numero == numero; });

    if (it != temp.end())
    {
        cout << "habitacion encontrada: " << endl;
        cout << "numero: " << it->numero << endl;
        cout << "tipo: " << it->tipo << endl;
        cout << "precio: $" << it->precio << endl;
        cout << "capacidad: " << it->capacidad << " personas" << endl;
        cout << "estado: " << (it->disponible ? "disponible" : "reservada") << endl;
        return true;
    }
    return false;
}

// funcion para mostrar las habitaciones
void mostrarHabitaciones(const list<Habitacion> &hotel)
{
    if (hotel.empty())
    {
        cout << "no hay habitaciones registradas." << endl;
        return;
    }

    cout << "lista de habitaciones: " << endl;
    for (const auto &h : hotel)
    {
        cout << "numero: " << h.numero << endl;
        cout << "tipo: " << h.tipo << endl;
        cout << "precio: $" << h.precio << endl;
        cout << "capacidad: " << h.capacidad << " personas" << endl;
        cout << "estado: " << (h.disponible ? "Disponible" : "Reservada") << endl;
    }
}

void menu(list<Habitacion> &hotel)
{
    int opcion, numeroBuscar;

    do
    {
        cout << "1. agregar habitacion" << endl;
        cout << "2. ordenar por precio" << endl;
        cout << "3. buscar habitacion" << endl;
        cout << "4. mostrar habitaciones" << endl;
        cout << "5. salir" << endl;
        cout << "seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarHabitacion(hotel);
            break;
        case 2:
            ordenarPorPrecio(hotel);
            break;
        case 3:
            cout << "ingrese un numero de habitación a buscar: " << endl;
            cin >> numeroBuscar;
            if (!buscarHabitacion(hotel, numeroBuscar))
            {
                cout << "habitacion no encontrada." << endl;
            }
            break;
        case 4:
            mostrarHabitaciones(hotel);
            break;
        case 5:
            cout << "cerrando programa" << endl;
            break;
        default:
            cout << "opcion invalida." << endl;
        }
    } while (opcion != 5);
}

int main()
{
    list<Habitacion> hotel;
    menu(hotel);
    return 0;
}