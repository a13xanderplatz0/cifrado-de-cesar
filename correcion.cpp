#include <iostream>
#include <cctype>
#include <limits> // Para numeric_limits

using namespace std;

string cifrarCesar(string texto) {
    const int desplazamiento = 3;
    string resultado = "";
    
    for (char c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + desplazamiento) % 26;
            if (c < 0) c += 26;
            c += base;
            resultado += c;
        } else {
            resultado += c;
        }
    }
    return resultado;
}

string descifrarCesar(string texto) {
    const int desplazamiento = 3;
    string resultado = "";
    
    for (char c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - desplazamiento) % 26;
            if (c < 0) c += 26;
            c += base;
            resultado += c;
        } else {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    cout << "CIFRADO CÉSAR" << endl;
    cout << "1. Cifrar texto\n2. Descifrar texto\nSeleccione: ";
    
    int opcion;
    while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
        cout << "Entrada inválida. Ingrese 1 o 2: ";
        cin.clear(); // Limpiar flags de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
    }
    
    // Limpiar el buffer completamente
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Ingrese el texto (ej. 'buenos días'): ";
    string texto;
    getline(cin, texto);
    
    if (opcion == 1) {
        cout << "Texto cifrado: " << cifrarCesar(texto) << endl;
    } else {
        cout << "Texto descifrado: " << descifrarCesar(texto) << endl;
    }
    
    return 0;
}
