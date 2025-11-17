#define byte windows_byte
#include "rlutil.h"
#undef byte
#include "art.h"
#include <iostream>
#include <string>
using namespace std;


void tituloBeta(){
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    int i = 0;
    while(i<7){
        rlutil::msleep(200);
        // ╔══════════════════════════════════════════════════════════════╗
        rlutil::locate(40, 2 + i);  
        if(i==0){
            cout << char(201);
            centrarTexto("", char(205), 40);
            cout << char(187);
        }
        // ║                                                              ║
        if(i==1){
            cout << char(186);
            centrarTexto("", ' ', 40);
            cout << char(186);
        }
        // ║               BIENVENIDO/A A WENNER BANK                    ║
        if(i==2){
            cout << char(186);
            centrarTexto("BIENVENIDO/A A WENNER BANK", ' ', 40);
            cout << char(186);
        }
        // ╠══════════════════════════════════════════════════════════════╣
        if(i==3){
            cout << char(204);
            centrarTexto("", char(205), 40);
            cout << char(185);
        }
        // ║                  Su banco de confianza                      ║
        if(i==4){
            cout << char(186);
            centrarTexto("Su banco de confianza", ' ', 40);
            cout << char(186);
        }
        // ║                                                              ║
        if(i==5){
            cout << char(186);
            centrarTexto("", ' ', 40);
            cout << char(186);
        }
        // ╚══════════════════════════════════════════════════════════════╝
        if(i==6){
            cout << char(200);
            centrarTexto("", char(205), 40);
            cout << char(188) << endl;
        }
        i++;
    }
    rlutil::setColor(rlutil::WHITE);
}
// SA version sin animacion
void tituloBetaSA(){
    system("cls");
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(40, 2);
    cout << char(201);
    centrarTexto("", char(205), 40);
    cout << char(187);

    rlutil::locate(40, 3);
    cout << char(186);
    centrarTexto("", ' ', 40);
    cout << char(186);

    rlutil::locate(40, 4);
    cout << char(186);
    centrarTexto("BIENVENIDO/A A WENNER BANK", ' ', 40);
    cout << char(186);

    rlutil::locate(40, 5);
    cout << char(204);
    centrarTexto("", char(205), 40);
    cout << char(185);

    rlutil::locate(40, 6);
    cout << char(186);
    centrarTexto("Su banco de confianza", ' ', 40);
    cout << char(186);

    rlutil::locate(40, 7);
    cout << char(186);
    centrarTexto("", ' ', 40);
    cout << char(186);

    rlutil::locate(40, 8);
    cout << char(200);
    centrarTexto("", char(205), 40);
    cout << char(188) << endl;

    rlutil::setColor(rlutil::WHITE);
}

void mayusculas(char* palabra){
    size_t largo = strlen(palabra);
    for(size_t i = 0; i < largo; i++){
        unsigned char c = (unsigned char)palabra[i];
        
        if(c >= 'a' && c <= 'z') palabra[i] = c - 32;

        else if(c == 160) palabra[i] = 181;  // á → Á
        else if(c == 130) palabra[i] = 144;  // é → É
        else if(c == 161) palabra[i] = 214;  // í → Í
        else if(c == 162) palabra[i] = 224;  // ó → Ó
        else if(c == 163) palabra[i] = 233;  // ú → Ú

        else if(c == 164) palabra[i] = 165;  // ñ → Ñ
    }
}

// un dato
void centrarTexto(string palabra, char dato, size_t largo){
    size_t espacios_izq = (largo - palabra.length()) / 2;
    size_t espacios_der = largo - palabra.length() - espacios_izq;
    cout << string(espacios_izq, dato) << palabra << string(espacios_der, dato);
}
// dos datos intercalados
void centrarTexto(string palabra, char dato1, char dato2, size_t largo){
    size_t longitudPalabra = palabra.length();
    size_t espacios_izq = (largo - longitudPalabra) / 2;
    size_t espacios_der = largo - longitudPalabra - espacios_izq;
    string izq;
    for(size_t i = 0; i < espacios_izq; i++) izq += (i % 2 == 0) ? dato1 : dato2;
    string der;
    for(size_t i = 0; i < espacios_der; i++) der += ((espacios_izq + i) % 2 == 0) ? dato1 : dato2;
    
    cout << izq << palabra << der;
}

//-------------------------------------
// PARA UTILIZAR EN EL MENU CON RLUTIL
//-------------------------------------
//rlutil::cls(); -> Limpia la Pantalla: Borra todo el texto que se encuentra actualmente visible en la ventana de la consola. y vuelve a dibujar el menu.
//rlutil::setBackgroundColor(rlutil::BLUE); ->cambia el color del fondo
//rlutil::setColor(rlutil::WHITE); ->cambia el color de las letras
//rlutil::setColor(rlutil::RED); -> puede ir antes de un texto con error, luego de mostrar el mensaje devolver su color original.
//rlutil::locate(2, 5); -> coloca el mensaje en la posicion que le pongas
// =============================================
// |    system("cls")    |    rlutil::cls()    |
// |=====================|=====================|
// |   resetea colores   |  mantiene colores   |
// |---------------------|---------------------|
// | reset a locate(1,1) | reset a locate(1,1) |
// ---------------------------------------------