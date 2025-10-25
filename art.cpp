#define byte windows_byte
#include "rlutil.h"
#undef byte
#include "art.h"
using namespace std;


void tituloBeta(){
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(40, 2);
    cout << (char)201; centrar_texto("", char(205), 41); cout << (char)187;

    rlutil::locate(40, 3);
    cout << (char)186; centrar_texto("", ' ', 41); cout << (char)186;

    rlutil::locate(40, 4);
    cout << (char)186; centrar_texto(" BIENVENIDO/A A WENNER BANK ", ' ', 41); cout << (char)186;

    rlutil::locate(30, 4);
    cout << (char)201; centrar_texto("", (char)205, 41); cout << (char)187;

    rlutil::locate(40, 5);
    cout << (char)186; centrar_texto("Su banco de confianza", ' ', 41); cout << (char)186;

    rlutil::locate(30, 6);
    cout << (char)204; centrar_texto("", (char)205, 41); cout << (char)185 << endl;
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