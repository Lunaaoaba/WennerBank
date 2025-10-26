#define byte windows_byte
#include "rlutil.h"
#undef byte
#include "art.h"
#include <iostream>
#include <string>
using namespace std;


void tituloBeta(){
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    // ╔══════════════════════════════════════════════════════════════╗
    rlutil::locate(40, 2);
    cout << char(201);
    centrarTexto("", char(205), 60);
    cout << char(187);
    // ║                                                              ║
    rlutil::locate(40, 3);
    cout << char(186);
    centrarTexto("", ' ', 60);
    cout << char(186);
    // ║               BIENVENIDO/A A WENNER BANK                    ║
    rlutil::locate(40, 4);
    cout << char(186);
    centrarTexto("BIENVENIDO/A A WENNER BANK", ' ', 60);
    cout << char(186);
    // ╠══════════════════════════════════════════════════════════════╣ 
    rlutil::locate(40, 5);
    cout << char(204);
    centrarTexto("", char(205), 60);
    cout << char(185);
    // ║                  Su banco de confianza                      ║
    rlutil::locate(40, 6);
    cout << char(186);
    centrarTexto("Su banco de confianza", ' ', 60);
    cout << char(186);
    // ║                                                              ║
    rlutil::locate(40, 7);
    cout << char(186);
    centrarTexto("", ' ', 60);
    cout << char(186);
    // ╚══════════════════════════════════════════════════════════════╝
    rlutil::locate(40, 8);
    cout << char(200);
    centrarTexto("", char(205), 60);
    cout << char(188) << endl;
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

void centrarTexto(string palabra, char dato, size_t largo){
    size_t espacios_izq = (largo - palabra.length()) / 2;
    size_t espacios_der = largo - palabra.length() - espacios_izq;
    cout << string(espacios_izq, dato) << palabra << string(espacios_der, dato);
}