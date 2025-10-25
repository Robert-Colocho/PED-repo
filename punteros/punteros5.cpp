#include <iostream>
using namespace std;

int main(){
    //x es una variable que guarda un 10
    int x = 10;
    //p es una variable que guarda la ubicacion
    //de la variable que guarda un 10
    int* p = &x;
    //pp es una variable que guarda la ubicacion
    //de la variable que guarda la ubicacion de x
    int** pp = &p;
    //ppp es un puntero a un puntero a un puntero
    int*** ppp = &pp;
    //pppp es un puntero a un puntero a un puntero a un puntero
    int**** pppp = &ppp;

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;
    cout << "Valor de p: " << p << " (direccion de x)" << endl;
    cout << "Valor apuntado por p: " << *p << endl;
    cout << "Valor de pp: " << pp << " (direccion de p)" << endl;
    cout << "Valor apuntado por pp: " << *pp << " (igual a p)" << endl;
    cout << "Valor final a traves de pp: " << **pp << " (igual a x)" << endl;

    return 0;
}