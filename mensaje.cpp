#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>
#include <limits>

using namespace std;

const vector<char> alfabeto = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                              'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                              'U', 'V', 'W', 'X', 'Y', 'Z'};
const int a = 3;
const int a_inversa = 9; // Inversa modular de 3 módulo 27

// Función para convertir texto a formato numérico
string textoANumeros(const string& texto) {
    stringstream resultado;
    for (char c : texto) {
        if (c == ' ') {
            resultado << "0";
        } else if (isalpha(c)) {
            resultado << (toupper(c) - 'A' + 1);
        }
    }
    return resultado.str();
}

// Función para cifrar
string cifrar(const string& mensaje) {
    string cifrado;
    for (char c : mensaje) {
        if (c == ' ') {
            int nuevoIndice = (0 + a) % 27; // Cifrado del espacio
            cifrado += alfabeto[nuevoIndice];
        } else if (isalpha(c)) {
            int indice = toupper(c) - 'A' + 1;
            int nuevoIndice = (indice + a) % 27;
            cifrado += alfabeto[nuevoIndice];
        } else {
            cifrado += c; // Mantener caracteres no válidos
        }
    }
    return cifrado;
}

// Función para descifrar (corregida con inversa modular)
string descifrar(const string& cifrado) {
    string mensaje;
    for (char c : cifrado) {
        if (c == ' ') {
            int nuevoIndice = (0 * a_inversa) % 27; // Descifrado del espacio
            if (nuevoIndice < 0) nuevoIndice += 27;
            mensaje += alfabeto[nuevoIndice];
        } else if (isalpha(c)) {
            int indice = toupper(c) - 'A' + 1;
            int nuevoIndice = (indice * a_inversa) % 27;
            if (nuevoIndice < 0) nuevoIndice += 27;
            mensaje += alfabeto[nuevoIndice];
        } else {
            mensaje += c; // Mantener caracteres no válidos
        }
    }
    return mensaje;
}

int main() {
    cout << "SISTEMA DE CIFRADO MODULO 27 (a=3)\n";
    cout << "1. Cifrar texto\n2. Descifrar texto\n3. Convertir a formato numérico\n";
    
    int opcion;
    cout << "Seleccione opción: ";
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string texto;
    cout << "Ingrese el texto (ej. BUENOS DAS): ";
    getline(cin, texto);
    
    switch(opcion) {
        case 1: {
            string resultado = cifrar(texto);
            cout << "Texto cifrado: " << resultado << endl;
            cout << "Formato numérico: " << textoANumeros(resultado) << endl;
            break;
        }
        case 2: {
            string resultado = descifrar(texto);
            cout << "Texto descifrado: " << resultado << endl;
            break;
        }
        case 3: {
            cout << "Formato numérico: " << textoANumeros(texto) << endl;
            break;
        }
        default:
            cout << "Opción no válida" << endl;
    }
    
    // Ejemplo específico
    cout << "\nEjemplo (BUENOS DAS):\n";
    string ejemplo = "BUENOS DAS";
    string cifradoEjemplo = cifrar(ejemplo);
    cout << "Texto original: " << ejemplo << endl;
    cout << "Cifrado: " << cifradoEjemplo << endl;
    cout << "Formato numérico: " << textoANumeros(cifradoEjemplo) << endl;
    cout << "Descifrado: " << descifrar(cifradoEjemplo) << endl;
    
    return 0;
}
