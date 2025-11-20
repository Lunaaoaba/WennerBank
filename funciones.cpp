#include <iostream>
#include <limits>
#include <cstring>
#include "funciones.h"

using namespace std;

int validarEntero(int min, int max){
    int valor;
    while (true){
        if (!(cin >> valor)){
            cout << "Error: Debe ingresar un numero entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (valor < min || valor > max){
            cout << "Error: El valor debe estar entre " << min << " y " << max << "." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return valor;
    }
}


// valida q sea un numero con max 2 decimales (XXX.XX)
bool esMonedaValida(const string& ingreso){
    int puntos = 0;
    int posicion_punto = -1;
    
    for(size_t i = 0; i < ingreso.length(); i++){
        if(ingreso[i] == '.'){
            puntos++;
            posicion_punto = static_cast<int>(i);
        }
        else if(!isdigit(ingreso[i])){
            return false; // No es digito ni punto
        }
    }
    // max 1 punto (separador decimal)
    if(puntos > 1) return false;
    // si hay punto, max 2 digitos despues
    if(puntos == 1){
        int digitos_despues = static_cast<int>(ingreso.length()) - posicion_punto - 1;
        if(digitos_despues > 2) return false; // Mas de 2 decimales
        if(digitos_despues == 0) return false; // Punto al final (ej: "100.")
    }
    return true;
}
// por ahora solo para saldo, por eso el mensaje "saldo valido"
double validarDouble(double min, double max){
    string ingreso;
    while (true){
        if (!(cin >> ingreso)){
            cout << "Error: Debe ingresar un valor valido (ej: XXX.XX)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(!esMonedaValida(ingreso)){
            cout << "Error: solo se aceptan valores con maximo de 2 decimales (ej: XXX.XX)" << endl;
            continue;
        }
        double valor = stod(ingreso);
        
        if (valor < min || valor > max) {
            cout << "Error: El valor del saldo debe estar entre " << min << " y " << max << "." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return valor;
    }
}

void validarCadenaNumeros(char* numero, int min, int max){
    while(true){
        cin.getline(numero, max + 1);
        if(cin.fail()){
            cout << "ERROR: El ingreso es demasiado largo (maximo " << max - 1 << " caracteres)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        size_t largo = strlen(numero);
        if((int)largo < min){
            cout << "ERROR: El ingreso debe tener al menos " << min << " caracteres." << endl;
            continue;
        }
        if(largo == 0){
            cout << "ERROR: El ingreso no puede estar vacio." << endl;
            continue;
        }
        bool soloNumero = true;
        for (size_t i = 0; i < strlen(numero); i++) {
            if (!(isdigit(numero[i]))){
                soloNumero = false;
                break;
            }
        }
        if (!soloNumero) {
            cout << "ERROR: El ingreso solo puede contener numeros." << endl;
            continue;
        }
        break;
    }
}

// maxLength +1 de lo que se quiere para el \0
// version que solo acepta letras y espacios (para nombres, apellidos, localidades, etc)
void validarCadenaLetras(char* palabra, int maxLength){
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            cout << "ERROR: El ingreso no puede estar vacio." << endl;
            continue;
        }
        // si se pasa de largo
        if(cin.fail()){
            cout << "ERROR: El ingreso es demasiado largo (maximo " << maxLength - 1 << " caracteres)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // si e solo letra o espacio o tildes
        bool letra = true;
        size_t largo = strlen(palabra);

        unsigned char c;
        for (size_t i = 0; i < largo; i++){
            c = (unsigned char)palabra[i];
            // letra normal o espacio
            if(isalpha(c) || c == ' ') continue;

            if(c == 160) continue;  // á
            if(c == 130) continue;  // é
            if(c == 161) continue;  // í
            if(c == 162) continue;  // ó
            if(c == 163) continue;  // ú

            if(c == 181) continue;  // Á
            if(c == 144) continue;  // É
            if(c == 214) continue;  // Í
            if(c == 224) continue;  // Ó
            if(c == 233) continue;  // Ú

            if(c == 164) continue;  // ñ
            if(c == 165) continue;  // Ñ

            letra = false;
            break;
        }

        if (!letra) {
            cout << "ERROR: El ingreso solo puede contener letras y espacios." << endl;
            continue;
        }
        break;
    }
}

// version que acepta cualquier caracter (para mails, etc)
void validarCadena(char* palabra, int maxLength){
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            cout << "ERROR: El ingreso no puede estar vacio." << endl;
            continue;
        }
        // si se pasa de largo
        if(cin.fail()){
            cout << "ERROR: El ingreso es demasiado largo (maximo " << maxLength - 1 << " caracteres)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

// version q acepta cualquier caracter + incluye un minimo de largo (para contrasenas y nose q mas)
void validarCadenaLargo(char* palabra, int minLength, int maxLength){
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            cout << "ERROR: El ingreso no puede estar vacio." << endl;
            continue;
        }
        // si no llega al minimo
        if(strlen(palabra) < (size_t)minLength){
            cout << "ERROR: El ingreso debe tener al menos " << minLength << " caracteres." << endl;
            continue;
        }
        // si se pasa de largo
        if(cin.fail()){
            cout << "ERROR: El ingreso es demasiado largo (maximo " << maxLength - 1 << " caracteres)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

char validarSiNo(){
    char c;
    while(true){
        cin >> c;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(c == 'S' || c == 's' || c == 'N' || c == 'n'){
            return c;
        }
        cout << "ERROR: Ingrese 'S' para Si o 'N' para No: ";
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




// Funcion auxiliar para pausar y limpiar el buffer de entrada
void pausa(){
    cout << "\n...";
    cin.ignore(10000, '\n');
    cin.get();
}

// Funcion auxiliar para limpiar la entrada despues de un error de cin
void limpiarEntrada(){
    cin.clear(); // LIMPIA EL ESTADO DE ERROR DEL CIN
    cin.ignore(10000, '\n'); // LIMPIA EL BUFFER DE ENTRADA
}


