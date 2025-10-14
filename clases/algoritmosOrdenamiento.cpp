#include <iostream>
#include <algorithm>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = 3;

    // algoritmo de busqueda binaria
    int inicio = 0;
    int final = n - 1;
    // si quieren usar libreria
// bool encontrado = binary_search(array, array+n,  search);
    while (inicio <= final)
    {
        int mitad = (inicio + final) / 2;
        if (arr[mitad] == search)
        {
            cout << "elemento encontrado" << mitad << endl;
            break;
        }
        else if (arr[mitad] < search)
        {
            inicio = mitad + 1;
        }
        else
        {
            final = mitad - 1;
        }
    }

    // algoritmo de busqueda lineal
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            cout << "elemento encontrado" << i << endl;
            return;
        }
    }

    // libreria de algoritmo
    sort(arr, arr + n);

    cout << "sorted" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }

    cout << "Original: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "Bubble Sort: ";
    printArray(arr, n);

    int arr2[] = {5, 2, 9, 1, 5, 6};
    insertionSort(arr2, n);
    cout << "Insertion Sort: ";
    printArray(arr2, n);

    int arr3[] = {5, 2, 9, 1, 5, 6};
    selectionSort(arr3, n);
    cout << "Selection Sort: ";
    printArray(arr3, n);

    return 0;
}