#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo
{
    // atributos
private:
    string marca;
    string modelo;

public:
    // Metodo constructor
    Vehiculo(string _marca, string _modelo)
    {
        marca = _marca;
        modelo = _modelo;
    }

    // Getters
    string getMarca()
    {
        return marca;
    }
};

virtual void mostrarInfo()
{
    cout << "marca: " << marca << endl;
    cout << "modelo" << modelo << endl;
}
//  destructor virtual
virtual ~Vehiculo() {}

class Auto : public Vehiculo
{
private:
    int numPuertas;

public:
    Auto(string _marca, string _modelo, int _numPuertas) : Vehiculo(_marca, _modelo), numPuertas(_numPuertas)
    {
        numPuertas = _numPuertas;
    }
};

void mostrarInfo() override
{
    Vehiculo::mostrarInfo();
    cout << "puertas: " << numPuertas << endl;
}

class Moto:public Vehiculo{
    private:
    string tipo;
    public:
    Moto(string _marca, string _modelo, string _tipo)
    :Vehiculo(_marca, _modelo), tipo(_tipo);
};

int main()
{
    Vehiculo vehiculo1;
    vehiculo1.marca = "Toyota";
    vehiculo1.modelo = "Corolla";

    Vehiculo vehiculo1 = new Vehiculo("Toyota", "Corolla");
    Vehiculo vehiculo2 = new Vehiculo("Honda", "Civic");
    Vehiculo vehiculo3 = new Vehiculo("Killer", "Soul");

    vehiculo1.mostrarInfo();
    vehiculo2.mostrarInfo();
    vehiculo3.mostrarInfo();

    string marca = vehiculo1.getMarca();

    Vehiculo* lista[3];

    lista[0]=new Auto("toyota", "corolla", 4);
    lista[1]=new Moto("honda", "civic", "deportiva");

        lista[0].mostrarInfo();
        cout<<endl;
        lista[1].mostrarInfo();


    return 0;
}