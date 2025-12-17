#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <limits>
#include <cstring>
#include "funciones.h"
#include "config.h"
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

// Funciones para obtener la posición del cursor
int wherex(){
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)){
        return csbi.dwCursorPosition.X + 1; // +1 porque rlutil usa 1-based
    }
#endif
    return 1;
}

int wherey(){
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)){
        return csbi.dwCursorPosition.Y + 1; // +1 porque rlutil usa 1-based
    }
#endif
    return 1;
}

int validarEntero(int min, int max){
    int valor;
    int posX = wherex();
    int posY = wherey();
    
    while (true){
        if (!(cin >> valor)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Debe ingresar un numero entero";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(30, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        if (valor < min || valor > max){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "El valor debe estar entre " << min << " y " << max;
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(30, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        return valor;
    }
}


bool esMonedaValida(const string& ingreso){
    int puntos = 0;
    int posicion_punto = -1;
    
    for(size_t i = 0; i < ingreso.length(); i++){
        if(ingreso[i] == '.'){
            puntos++;
            posicion_punto = static_cast<int>(i);
        }
        else if(!isdigit(ingreso[i])){
            return false;
        }
    }

    if(puntos > 1) return false;

    if(puntos == 1){
        int digitos_despues = static_cast<int>(ingreso.length()) - posicion_punto - 1;
        if(digitos_despues > 2) return false;
        if(digitos_despues == 0) return false;
    }
    return true;
}

double validarDouble(double min, double max){
    string ingreso;
    int posX = wherex();
    int posY = wherey();
    
    while (true){
        if (!(cin >> ingreso)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Debe ingresar un valor valido (ej: XXX.XX)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(30, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        if(!esMonedaValida(ingreso)){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Maximo 2 decimales (ej: XXX.XX)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(30, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        double valor = stod(ingreso);
        
        if (valor < min || valor > max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "El valor debe estar entre " << min << " y " << max;
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(30, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        return valor;
    }
}

void validarCadenaNumeros(char* numero, int min, int max){
    int posX = wherex();
    int posY = wherey();
    
    while(true){
        cin.getline(numero, max + 1);
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Demasiado largo (max " << max - 1 << " caracteres)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        size_t largo = strlen(numero);
        if(largo == 0){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "No puede estar vacio";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        if((int)largo < min){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Minimo " << min << " caracteres";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
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
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Solo puede contener numeros";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        break;
    }
}

void validarCadenaLetras(char* palabra, int maxLength){
    int posX = wherex();
    int posY = wherey();
    
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "No puede estar vacio";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Demasiado largo (max " << maxLength - 1 << " caracteres)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }

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
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Solo puede contener letras y espacios";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        break;
    }
}


void validarCadena(char* palabra, int maxLength){
    int posX = wherex();
    int posY = wherey();
    
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "No puede estar vacio";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Demasiado largo (max " << maxLength - 1 << " caracteres)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        break;
    }
}

void validarCadenaLargo(char* palabra, int minLength, int maxLength){
    int posX = wherex();
    int posY = wherey();
    
    while(true){
        cin.getline(palabra, maxLength + 1);
        // si no ta vacio
        if(strlen(palabra) == 0){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "No puede estar vacio";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }

        if(strlen(palabra) < (size_t)minLength){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Minimo " << minLength << " caracteres";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            rlutil::locate(44, 15);
            colorTexto(3);
            cout << "Demasiado largo (max " << maxLength - 1 << " caracteres)";
            colorTexto(7);
            rlutil::msleep(1500);
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            
            rlutil::locate(posX, posY);
            cout << string(50, ' ');
            rlutil::locate(posX, posY);
            continue;
        }
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        break;
    }
}

char validarSiNo(){
    char c;
    int posX = wherex();
    int posY = wherey();
    
    while(true){
        cin >> c;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(c == 'S' || c == 's' || c == 'N' || c == 'n'){
            rlutil::locate(44, 15);
            cout << string(80, ' ');
            return c;
        }
        
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        rlutil::locate(44, 15);
        colorTexto(3);
        cout << "Ingrese 'S' para Si o 'N' para No";
        colorTexto(7);
        rlutil::msleep(1500);
        rlutil::locate(44, 15);
        cout << string(80, ' ');
        
        rlutil::locate(posX, posY);
        cout << string(10, ' ');
        rlutil::locate(posX, posY);
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