#include <iostream>
#include <limits>
#include <cstring>
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

// al usar la funcion, en el maxLength +1 de lo que se quiere para el \0
void validarCadena(const char* mensaje, char* destino, int maxLength){
    while(true){
        cout << mensaje;
        cin.getline(destino, maxLength);

        // si no ta vacio
        if(strlen(destino) == 0){
            cout << "Error: El ingreso no puede estar vacío." << endl;
            continue;
        }

        // si se pasa de largo
        if(cin.fail()){
            cout << "Error: El ingreso es demasiado largo (máximo " << maxLength - 1 << " caracteres)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

    break;
    }
}



// para agregar 0 a la izquierda y un prefijo | uso en mostrarDatos de las clases | ej: Cl-00021
void formatearId(char* resultado, const char* prefijo, int idNumero, int largoTotal){
    sprintf(resultado, "%s%0*d", prefijo, largoTotal, idNumero);
    /*  "%s%0*d":
    %s : inserta el prefijo
    %0 : se llena con ceros a la izquierda
    * : toma el ancho del siguiente argumento (largoTotal)
    d : indica que es un entero */
}

// Función auxiliar para pausar y limpiar el buffer de entrada
void pausa(){
    cout << "\n...";
    cin.ignore(10000, '\n');
    cin.get();
}

// Función auxiliar para limpiar la entrada después de un error de cin
void limpiarEntrada(){
    cin.clear(); // LIMPIA EL ESTADO DE ERROR DEL CIN
    cin.ignore(10000, '\n'); // LIMPIA EL BUFFER DE ENTRADA
}


