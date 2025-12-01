#include <iostream>

struct Movimiento {
    int id;
    char tipo;
    float monto;
    float saldo;
    Movimiento* anterior;
    Movimiento* siguiente;
};

Movimiento* head = nullptr;
Movimiento* tail = nullptr;

void agregarMovimiento(int id, char tipo, float monto, float /*saldo*/) {
    Movimiento* nuevo = new Movimiento{id, tipo, monto, 0, nullptr, nullptr};
    if (!head) {
        head = tail = nuevo;
    } else {
        tail->siguiente = nuevo;
        nuevo->anterior = tail;
        tail = nuevo;
    }
    // Recalcular saldos
    float saldoTemp = 0;
    Movimiento* actual = head;
    while (actual) {
        if (actual->tipo == 'D')
            saldoTemp += actual->monto;
        else if (actual->tipo == 'R')
            saldoTemp -= actual->monto;
        actual->saldo = saldoTemp;
        actual = actual->siguiente;
    }
}

void mostrarMovimientos() {
    Movimiento* actual = head;
    std::cout << "ID\tTipo\tMonto\tSaldo\n";
    while (actual) {
        std::cout << actual->id << "\t" << actual->tipo << "\t" << actual->monto << "\t" << actual->saldo << std::endl;
        actual = actual->siguiente;
    }
}

void eliminarMovimientos(int id) {
    Movimiento* actual = head;
    while (actual) {
        if (actual->id == id) {
            if (actual->anterior)
                actual->anterior->siguiente = actual->siguiente;
            else
                head = actual->siguiente;
            if (actual->siguiente)
                actual->siguiente->anterior = actual->anterior;
            else
                tail = actual->anterior;
            delete actual;
            // Recalcular saldos después de eliminar
            float saldoTemp = 0;
            Movimiento* temp = head;
            while (temp) {
                if (temp->tipo == 'D')
                    saldoTemp += temp->monto;
                else if (temp->tipo == 'R')
                    saldoTemp -= temp->monto;
                temp->saldo = saldoTemp;
                temp = temp->siguiente;
            }
            std::cout << "Movimiento eliminado.\n";
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Movimiento no encontrado.\n";
}

int main() {
    int opcion;
    do {
        std::cout << "\n1. Agregar movimiento\n2. Mostrar movimientos\n3. Eliminar movimiento\n0. Salir\nOpcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: {
                int id;
                char tipo;
                float monto;
                std::cout << "Ingrese ID: ";
                std::cin >> id;
                std::cout << "Ingrese tipo (D=Deposito, R=Retiro): ";
                std::cin >> tipo;
                std::cout << "Ingrese monto: ";
                std::cin >> monto;
                agregarMovimiento(id, tipo, monto, 0);
            }
            break;
            case 2:
                mostrarMovimientos();
                break;
            case 3: {
                int id;
                std::cout << "Ingrese ID del movimiento a eliminar: ";
                std::cin >> id;
                eliminarMovimientos(id);
            }
            break;
            case 0: break;
            default: std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
    return 0;
}