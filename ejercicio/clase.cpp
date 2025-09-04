#include <iostream>
using namespace std;
struct Producto
{
    int codigo;
    string nombre;
    float precio;
    int cantidadenStock;
};

const int productosMaximos=100;
Producto producto[productosMaximos];
int totalProductos=0;

void llenarProductos(Producto producto[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"producto: "<<i+1<<endl;
        cout<<"codigo: ";
        cin>>producto[i].codigo;
        cin.ignore();
        cout<<"nombre: ";
        getline(cin, producto[i].nombre);
        cout<<"precio: ";
        cin>>producto[i].precio;
        cout<<"cantidad en stock: ";
        cin>>producto[i].cantidadenStock;
    }
    
}

int buscarProducto(Producto producto[], int n, int codigo ){
    bool encontrado = false;
    for (int i = 0; i < n; i++)
    {
        if (producto[i].codigo==codigo)
        {
            cout<<"producto encontrado"<<endl;
            cout<<"codigo"<<producto[i].codigo<<endl;
            cout<<"nombre"<<producto[i].nombre<<endl;
            cout<<"precio"<<producto[i].precio<<endl;
            cout<<"cantidad en stock"<<producto[i].cantidadenStock<<endl;
        }
        
    }

    return -1;
    
}

void mostrarEncontrado(Producto producto[], int n){
int codigo;
cout<<"codigo del producto que desea mostrar: "<<endl;
cin>>codigo;

int pos = buscarProducto(producto, n, codigo);
if (pos==-1)
{
    cout<<"no se ha encontrado el producto"<<endl;
    return;
}

cout<<"producto encontrado en la posicion: "<<pos<<endl;
cout<<"codigo: "<<producto[pos].codigo<<endl;
cout<<"nombre: "<<producto[pos].nombre<<endl;
cout<<"precio: "<<producto[pos].precio<<endl;
cout<<"cantidad en stock: "<<producto[pos].cantidadenStock<<endl;

}

float valorInventario(Producto producto[], int n){
    float suma=0;

    for (int i = 0; i < n; i++)
    {
        suma+=producto[i].precio*producto[i].cantidadenStock;
    }
    return suma;
    
}


int main(){
int n;
cout<<"cuantos productos quiere ingresar"<<endl;
cin>>n;

Producto producto[n];

llenarProductos(producto, n);

int codigo;
cout<<"ingrese el codigo del producto para buscarlo";
cin>>codigo;
buscarProducto(producto, n, codigo);

cout<<"valor del inventario"<<endl;
valorInventario(producto, n);

    return 0;
}