#include <iostream>
using namespace std;

int main(){
int x=10;
int* p=&x;
int** pp=&p;
// x es una variable que guarda 10
// p es una variable que guarda la ubicacion de la variable que guarda 10
// pp es una variable que guarda la ubicacion de la variable que guarda la ubicacion de la variable que guarda 10
cout<<"valor de x: "<<x<<endl;
cout<<"valor de p: "<<p<<endl;
cout<<"valor de pp: "<<pp<<endl;
    return 0;
}