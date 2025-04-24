#include <iostream>
#include <cctype> // Para isalpha, toupper, etc.

using namespace std;

// Función para cifrar como el verdadero César (desplazamiento 3)
string cifrarCesar(string texto) {
    const int desplazamiento = 3; // César usaba siempre 3
    string resultado = "";
    
    for (char c : texto) {
        if (isalpha(c)) { // Solo procesamos letras
            char base = isupper(c) ? 'A' : 'a';
            // Aplicamos el desplazamiento de 3 posiciones
            c = (c - base + desplazamiento) % 26;
            if (c < 0) c += 26; // Ajuste para evitar valores negativos
            c += base;
            resultado += c;
        } else {
            // Mantenemos caracteres que no son letras
            resultado += c;
        }
    }
    
    return resultado;
}

// Función para descifrar (desplazamiento inverso)
string descifrarCesar(string texto) {
    const int desplazamiento = 3;
    string resultado = "";
    
    for (char c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Aplicamos el desplazamiento negativo de 3 posiciones
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
    cout << "CIFRADO CÉSAR VERDADERO (desplazamiento = 3)" << endl;
    cout << "1. Cifrar texto" << endl;
    cout << "2. Descifrar texto" << endl;
    
    int opcion;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer
    
    string texto;
    cout << "Ingrese el texto: ";
    getline(cin, texto);
    
    if (opcion == 1) {
        string cifrado = cifrarCesar(texto);
        cout << "Texto cifrado: " << cifrado << endl;
    } else if (opcion == 2) {
        string descifrado = descifrarCesar(texto);
        cout << "Texto descifrado: " << descifrado << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
    
    return 0;
}
