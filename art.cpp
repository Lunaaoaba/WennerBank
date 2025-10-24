#include "art.h"
using namespace std;

// #define byte windows_byte
// #include "rlutil.h"
// #undef byte

void tituloBeta(){
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(30, 2);
    cout << "===============================" << endl;
    rlutil::locate(30, 3);
    cout << "|  BIENVENIDO/A A WENNER BANK  |" << endl;
    rlutil::locate(30, 4);
    cout << "===============================" << endl;
    rlutil::locate(30, 5);
    cout << "|     Su banco de confianza    |" << endl;
    rlutil::locate(30, 6);
    cout << "===============================" << endl;
    rlutil::setColor(rlutil::WHITE);
}

string mayusculas(string palabra){
    string resultado;
    for(char caracter : palabra){
        if(caracter >= 'a' && caracter <= 'z') caracter -= 32;
        resultado += caracter;
    }
    return resultado;
}

void centrar_texto(string palabra, char dato, size_t cantidad){
    size_t espacios_izq = (cantidad - palabra.length()) / 2;
    size_t espacios_der = cantidad - palabra.length() - espacios_izq;

    cout << string(espacios_izq, dato) << palabra << string(espacios_der, dato);
}