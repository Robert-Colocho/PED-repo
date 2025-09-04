#include <iostream>
using namespace std;

struct Contacto
{
    string nombre;
    string telefono;
    string email;
};

const int contactosMaximos = 100;
Contacto agenda[contactosMaximos];
int totalContactos = 0;

void mostrarAgenda(Contacto agenda[], int n)
{
    cout << "Agenda de contactos " << endl;

    if (n == 0)
    {
        cout << "No hay contacto " << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Nombre: " << agenda[i].nombre << endl;
        cout << "Telefono: " << agenda[i].telefono << endl;
        cout << "Email: " << agenda[i].email << endl;
    }
}

int agregarContacto(Contacto agenda[], int n)
{
    if (n > contactosMaximos)
    {
        cout << "Agenda llena: " << endl;
        return n;
    }

    Contacto nuevoContacto;
    cout << "Ingrese el nombre: ";
    getline(cin >> ws, nuevoContacto.nombre);
    cout << "Ingrese el telefono: ";
    getline(cin, nuevoContacto.telefono);
    cout << "Ingrese el email: ";
    getline(cin, nuevoContacto.email);

    agenda[n] = nuevoContacto;
    cout << "contacto creado ";
    return n + 1;
}

int buscarContacto(Contacto agenda[], int n, string nombre)
{
    for (int i = 0; i < n; i++)
    {
        if (agenda[i].nombre == nombre)
        {
            return i;
        }
    }

    return -1;
}

void editarContacto(Contacto agenda[], int n)
{
    string nombre;
    cout << "Nombre del contacto que desea editar: ";
    getline(cin >> ws, nombre);

    int pos = buscarContacto(agenda, n, nombre);

    if (pos == -1)
    {
        cout << "no se encontro el contacto " << endl;
        return;
    }

    cout << "editando contacto: " << agenda[pos].nombre << endl;
    cout << "nuevo telefono ";
    getline(cin, agenda[pos].telefono);
}

int eliminarContacto(Contacto agenda[], int n)
{
    string nombre;
    cout << "Nombre del contacto que desea eliminar: ";
    getline(cin >> ws, nombre);

    int pos = buscarContacto(agenda, n, nombre);

    if (pos == -1)
    {
        cout << "no se ha encontrado el contacto o ya fue eliminado" << endl;
        return n;
    }

    for (int i = 0; i < n - 1; i++)
    {
        agenda[i] = agenda[i - 1];
    }

    cout<<"contacto eliminado"<<endl;
    return n-1;
}

void mostrarEncontrado(Contacto agenda[], int n)
{
    string nombre;
    cout << "Nombre del contacto que desea mostrar: ";
    getline(cin >> ws, nombre);

    int pos = buscarContacto(agenda, n, nombre);

    if (pos == -1)
    {
        cout << "no se ha encontrado el contacto " << endl;
        return;
    }

    cout << "contacto encontrado en la posicion: " << pos << endl;
    cout << "nombre: " << agenda[pos].nombre << endl;
    cout << "telefono: " << agenda[pos].telefono << endl;
    cout << "email: " << agenda[pos].email << endl;
}

void mostrarMenu()
{
    cout << "seleccione la opcion" << endl;
    cout << "1. mostrar agenda" << endl;
    cout << "2. agregar contacto" << endl;
    cout << "3. mostrar contacto" << endl;
    cout << "4. editar contacto" << endl;
    cout << "5. eliminar contacto" << endl;
    cout << "6. salir" << endl;
}

void ejecutarAgenda()
{
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            mostrarAgenda(agenda, totalContactos);
            break;
        case 2:
            totalContactos = agregarContacto(agenda, totalContactos);
            break;
        case 3:
            mostrarEncontrado(agenda, totalContactos);
            break;
        case 4:
            editarContacto(agenda, totalContactos);
            break;
        case 5:
            totalContactos = eliminarContacto(agenda, totalContactos);
            break;
        case 6:
            cout << "saliendo" << endl;
        default:
            cout << "opcion no valida" << endl;
            break;
        }
    } while (opcion != 6);
}
int main()
{
    ejecutarAgenda();
    return 0;
}