#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

const vector<char> alfabeto = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                              'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                              'U', 'V', 'W', 'X', 'Y', 'Z'};
const int a = 3;

// Función para convertir texto a formato numérico (como en tu ejemplo)
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

string cifrar(const string& mensaje) {
    string cifrado;
    for (char c : mensaje) {
        if (c == ' ') {
            // 0 + 3 mod 27 = 3 → 'D'
            cifrado += alfabeto[3];
        } else if (isalpha(c)) {
            int indice = toupper(c) - 'A' + 1;
            int nuevoIndice = (indice + a) % 27;
            cifrado += alfabeto[nuevoIndice];
        }
    }
    return cifrado;
}

string descifrar(const string& cifrado) {
    string mensaje;
    for (char c : cifrado) {
        if (isalpha(c) || c == ' ') {
            int indice = (c == ' ') ? 0 : (toupper(c) - 'A' + 1);
            int nuevoIndice = (indice - a) % 27;
            if (nuevoIndice < 0) nuevoIndice += 27;
            mensaje += alfabeto[nuevoIndice];
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
    
    // Ejemplo específico de tu imagen
    cout << "\nEjemplo de tu imagen (BUENOS DAS):\n";
    string ejemplo = "BUENOS DAS";
    string cifradoEjemplo = cifrar(ejemplo);
    cout << "Texto original: " << ejemplo << endl;
    cout << "Cifrado: " << cifradoEjemplo << endl;
    cout << "Formato numérico: " << textoANumeros(cifradoEjemplo) << endl;
    
    return 0;
}
