#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current.next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node *head)
{
}

void free(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int opc = 0;

    do
    {
        cout<<"ingrese una opcion "<<endl;
        cout<<"1. ingresar valor "<<endl;
        cout<<"2. insertar un final"<<endl;
        cout<<"3. imprimir"<<endl;
        cout<<"4. liberar"<<endl;
        cout<<"5. salir"<<endl;
        cin>>opc;

        switch (opc)
        {
        case 1:
            int value;
            cout << "ingrese un valor ";
            cin >> value;
            insert(lista1, value);
            break;
        case 2:
            int value2;
            cout << "ingrese un valor ";
            cin >> value2;
            insertAtEnd(lista1, value2);
            break;
        case 3:
            printList(lista1);
            break;
        case 4:
            free(lista 1);
            break;
        default:
        cout<<"ingrese una opcion valida"<<endl;
            break;
        }
    } while (opc!=5);

    return 0;
}