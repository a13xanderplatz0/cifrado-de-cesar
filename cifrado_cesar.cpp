#include <iostream>
#include <cctype>
#include <locale> // Para manejar caracteres acentuados

using namespace std;

// Función para cifrar (desplazamiento 3)
string cifrarCesar(string texto) {
    const int desplazamiento = 3;
    string resultado = "";
    
    for (char c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Manejo de vocales acentuadas (á, é, í, ó, ú)
            switch(c) {
                case 'á': c = 'a'; break;
                case 'é': c = 'e'; break;
                case 'í': c = 'i'; break;
                case 'ó': c = 'o'; break;
                case 'ú': c = 'u'; break;
                case 'Á': c = 'A'; break;
                case 'É': c = 'E'; break;
                case 'Í': c = 'I'; break;
                case 'Ó': c = 'O'; break;
                case 'Ú': c = 'U'; break;
            }
            // Aplicamos el cifrado
            c = (c - base + desplazamiento) % 26;
            if (c < 0) c += 26;
            c += base;
            resultado += c;
        } else {
            // Mantenemos espacios, signos y acentos sin cambios
            resultado += c;
        }
    }
    
    return resultado;
}

// Función para descifrar
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
    // Configurar locale para caracteres en español
    setlocale(LC_ALL, "es_ES.UTF-8");
    
    cout << "CIFRADO CÉSAR PARA 'BUENOS DÍAS'" << endl;
    cout << "1. Cifrar texto" << endl;
    cout << "2. Descifrar texto" << endl;
    
    int opcion;
    cout << "Seleccione opción: ";
    cin >> opcion;
    cin.ignore();
    
    string texto;
    cout << "Ingrese el texto (ej. 'buenos días'): ";
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
