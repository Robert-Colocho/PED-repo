#include <iostream>
using namespace std;

struct Cuenta {
    int numeroCuenta;
    char nombreTitular[50];
    float saldo;
};

void crearCuentas(Cuenta* cuentas, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Cuenta " << i+1 << ":\n";
        cout << "Número de cuenta: ";
        cin >> cuentas[i].numeroCuenta;
        cin.ignore();
        cout << "Nombre del titular: ";
        cin.getline(cuentas[i].nombreTitular, 50);
        cout << "Saldo inicial: ";
        cin >> cuentas[i].saldo;
        cin.ignore();
    }
}

int buscarCuenta(Cuenta* cuentas, int n, int numero) {
    for(int i = 0; i < n; i++)
        if(cuentas[i].numeroCuenta == numero)
            return i;
    return -1;
}

void depositar(Cuenta* cuentas, int n) {
    int numero;
    float monto;
    cout << "Ingrese el número de cuenta: ";
    cin >> numero;
    int idx = buscarCuenta(cuentas, n, numero);
    if(idx == -1) {
        cout << "Cuenta no encontrada.\n";
        return;
    }
    cout << "Monto a depositar: ";
    cin >> monto;
    cuentas[idx].saldo += monto;
    cout << "Depósito realizado. Nuevo saldo: " << cuentas[idx].saldo << endl;
}

void retirar(Cuenta* cuentas, int n) {
    int numero;
    float monto;
    cout << "Ingrese el número de cuenta: ";
    cin >> numero;
    int idx = buscarCuenta(cuentas, n, numero);
    if(idx == -1) {
        cout << "Cuenta no encontrada.\n";
        return;
    }
    cout << "Monto a retirar: ";
    cin >> monto;
    if(monto > cuentas[idx].saldo) {
        cout << "Fondos insuficientes.\n";
        return;
    }
    cuentas[idx].saldo -= monto;
    cout << "Retiro realizado. Nuevo saldo: " << cuentas[idx].saldo << endl;
}

void transferir(Cuenta* cuentas, int n) {
    int origen, destino;
    float monto;
    cout << "Ingrese el número de cuenta origen: ";
    cin >> origen;
    int idxOrigen = buscarCuenta(cuentas, n, origen);
    if(idxOrigen == -1) {
        cout << "Cuenta origen no encontrada.\n";
        return;
    }
    cout << "Ingrese el número de cuenta destino: ";
    cin >> destino;
    int idxDestino = buscarCuenta(cuentas, n, destino);
    if(idxDestino == -1) {
        cout << "Cuenta destino no encontrada.\n";
        return;
    }
    cout << "Monto a transferir: ";
    cin >> monto;
    if(monto > cuentas[idxOrigen].saldo) {
        cout << "Fondos insuficientes en la cuenta origen.\n";
        return;
    }
    cuentas[idxOrigen].saldo -= monto;
    cuentas[idxDestino].saldo += monto;
    cout << "Transferencia realizada.\n";
    cout << "Saldo origen: " << cuentas[idxOrigen].saldo << endl;
    cout << "Saldo destino: " << cuentas[idxDestino].saldo << endl;
}

float saldoTotalBanco(Cuenta* cuentas, int n) {
    float total = 0;
    for(int i = 0; i < n; i++)
        total += cuentas[i].saldo;
    return total;
}

void mostrarCuentas(Cuenta* cuentas, int n) {
    cout << "\nListado de cuentas:\n";
    for(int i = 0; i < n; i++) {
        cout << "Cuenta: " << cuentas[i].numeroCuenta
             << ", Titular: " << cuentas[i].nombreTitular
             << ", Saldo: " << cuentas[i].saldo << endl;
    }
}

int main() {
    int n;
    cout << "¿Cuántas cuentas desea registrar? ";
    cin >> n;
    cin.ignore();

    Cuenta* cuentas = new Cuenta[n];
    crearCuentas(cuentas, n);

    int opcion;
    do {
        cout << "\n--- Menú Banco ---\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Transferir entre cuentas\n";
        cout << "4. Mostrar todas las cuentas\n";
        cout << "5. Mostrar saldo total del banco\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                depositar(cuentas, n);
                break;
            case 2:
                retirar(cuentas, n);
                break;
            case 3:
                transferir(cuentas, n);
                break;
            case 4:
                mostrarCuentas(cuentas, n);
                break;
            case 5:
                cout << "Saldo total del banco: " << saldoTotalBanco(cuentas, n) << endl;
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while(opcion != 6);

    delete[] cuentas;
    return 0;
}