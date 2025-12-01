#include <iostream>
#include <iostream>
#include <map>
#include <string>
#include <limits>


using namespace std;

struct Sensor
{
    string id;
    string ubicacion;
    double valor;
};

struct SistemaMonitoreo
{
    map<string, Sensor> sensores;
};



void agregarSensor(SistemaMonitoreo &sistemaSensores) {
    string id;
    string ubicacion;
    double valor;

    cout << "\n--- AGREGAR SENSOR ---" << endl;
    cout << "Ingrese el ID del sensor (numero entero): ";
    if (!(cin >> id)) {
        cout << "Error al leer el ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Validación: El ID no debe repetirse
    if (sistemaSensores.sensores.count(id) > 0) {
        cout << "Error: Ya existe un sensor con el ID " << id << "." << endl;
        return;
    }

    cout << "Ingrese la ubicacion del sensor (ej. Sala, Jardin): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer antes de leer strings con espacios
    getline(cin, ubicacion);

    cout << "Ingrese el valor actual (ej. 25.5): ";
    while (!(cin >> valor)) { // Validación: El valor debe ser numérico
        cout << "Error: El valor debe ser un numero valido. Intente de nuevo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Insertamos en el mapa
    Sensor nuevosDatos = {id, ubicacion, valor};
    sistemaSensores.sensores[id] = nuevosDatos;
    
    cout << "Sensor registrado exitosamente." << endl;
}


void buscarSensor(SistemaMonitoreo &sistema)
{
    string id;

    cout << "ingrese el ID del sensor a buscar: "<< endl;
    getline(cin, id);

    auto it = sistema.sensores.find(id);

    if (it != sistema.sensores.end())
    {
        cout << "ID: " << it->second.id <<endl;
        cout << "ubicacion: " << it->second.ubicacion <<endl;
        cout << "valor: " << it->second.valor << endl;
    }
    else
    {
        cout << "sensor no encontrado ";
    }
}


void eliminarSensor(SistemaMonitoreo &sistema)
{
    string id;
    cout << "\n--- ELIMINAR SENSOR ---" << endl;
    cout << "Ingrese el ID a eliminar: ";
    getline(cin, id);

    if (sistema.sensores.erase(id))
    {
        cout << "Sensor eliminado correctamente." << endl;
    }
    else
    {
        cout << "No se encontro ningun sensor con ese ID." << endl;
    }
}

void mostrarSensores(SistemaMonitoreo &sistema)
{
    cout << "\n--- LISTA DE SENSORES REGISTRADOS ---" << endl;
    if (sistema.sensores.empty())
    {
        cout << "No hay sensores registrados." << endl;
        return;
    }

    cout << "ID\t| Valor\t| Ubicacion" << endl;
    cout << "------------------------------------" << endl;
    for (const auto &par : sistema.sensores)
    {
        cout << par.first << "\t| "
             << par.second.valor << "\t| "
             << par.second.ubicacion << endl;
    }
}

bool validacion(const SistemaMonitoreo &sistema, const string &id, const string &valorStr, double &valorOut)
{
    if (id.empty())
    {
        cout << "error: El ID no puede estar vacio" << endl;
        return false;
    }

    if (sistema.sensores.find(id) != sistema.sensores.end())
    {
        cout << "error: El ID ya existe" << endl;
        return false;
    }

    if (valorStr.empty())
    {
        cout << "error: El valor no puede estar vacio" << endl;
        return false;
    }

    try
    {
        size_t idx;
        double v = stod(valorStr, &idx);
        if (idx != valorStr.length())
        {
            cout << "error: el valor debe ser numerico valido" << endl;
            return false;
        }
        valorOut = v;
        return true;
    }
    catch (...) 
    {
        cout << "error: El valor debe ser numerico valido" << endl;
        return false;
    }
}



int main()
{
    SistemaMonitoreo sistemaSensores;
    int opcion;
    do
    {
        cout << "1. Agregar Sensor" << endl;
        cout << "2. Buscar Sensor" << endl;
        cout << "3. Eliminar Sensor" << endl;
        cout << "4. Mostrar Todos los Sensores" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregarSensor(sistemaSensores);
            break;
        case 2:
            buscarSensor(sistemaSensores);
            break;
        case 3:
            eliminarSensor(sistemaSensores);
            break;
        case 4:
            mostrarSensores(sistemaSensores);
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            std::cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}