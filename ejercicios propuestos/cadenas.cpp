#include <iostream>
using namespace std;

bool esPalindromo(const char cad[]) {
    int i = 0, j;
    while (cad[i] != '\0') i++;
    j = i - 1;
    for (int k = 0; k < i / 2; k++)
        if (cad[k] != cad[j - k])
            return false;
    return true;
}

void aMayusculas(char cad[]) {
    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] >= 'a' && cad[i] <= 'z')
            cad[i] = cad[i] - ('a' - 'A');
    }
}

void contarVocalesConsonantes(const char cad[], int &vocales, int &consonantes) {
    vocales = consonantes = 0;
    for (int i = 0; cad[i] != '\0'; i++) {
        char c = cad[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            char lower = (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                vocales++;
            else
                consonantes++;
        }
    }
}

int main() {
    char cadena[100];
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 100);

    if (esPalindromo(cadena))
        cout << "La cadena es palindromo.\n";
    else
        cout << "La cadena no es palindromo.\n";

    aMayusculas(cadena);
    cout << "Cadena en mayusculas: " << cadena << endl;

    int vocales, consonantes;
    contarVocalesConsonantes(cadena, vocales, consonantes);
    cout << "Vocales: " << vocales << endl;
    cout << "Consonantes: " << consonantes << endl;

    return 0;}