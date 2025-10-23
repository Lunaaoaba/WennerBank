#include <iostream>
#include <limits>
#include "funciones.h"

using namespace std;

int validarEntero(const char* mensaje, int min, int max){
    int valor;
    while (true){
        cout << mensaje;
        if (!(cin >> valor)) {
            cout << "Error: Debe ingresar un numero entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (valor < min || valor > max) {
            cout << "Error: El valor debe estar entre " << min << " y " << max << "." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        return valor;
    }
}