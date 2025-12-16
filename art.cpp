#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <string>
#include "art.h"
#include "config.h"

using namespace std;

void titulo(bool animado){
    limpiarPantalla();
    colorTexto(5);

    if(!animado){
        string titulo[4] = {
            " _ _ _                        _____         _   ",
            "| | | |___ ___ ___ ___ ___   | __  |___ ___| |_ ",
            "| | | | -_|   |   | -_|  _|  | __ -| .'|   | '_|",
            "|_____|___|_|_|_|_|___|_|    |_____|__,|_|_|_,_|"
        };
        
        for(int i = 0; i < 4; i++){
            rlutil::locate(40, 5 + i);
            cout << titulo[i] << endl;
        }
    }
    else{
        // LETRAS
        string w[4] = {" _ _ _ ", "| | | |", "| | | |", "|_____|"};
        string e[4] = {"    ", "___ ", " -_|", "___|"};
        string n[4] = {"    ", "___ ", "   |", "_|_|"};
        string r[4] = {"      ", "___   ", "  _|  ", "_|    "};
        string b[4] = {" _____ ", "|  __ |", "|  __-|", "|_____|"};
        string a[4] = {"    ", "___ ", " .'|", "_|_|"};
        string nk[4] = {"    ", "___|", "   |", "_|_|"};
        string k[4] = {"_   ", " |_ ", " '_|", "_,_|"};     
        
        string* palabra[] = {w, e, n, n, e, r, b, a, n, k};
        int numLetras = 10;
        
        int posX = 36;
        int posY = 5;
        int espacioX = posX;
        
        for(int i = 0; i < numLetras; i++){
            rlutil::msleep(150);
            
            for(int linea = 0; linea < 4; linea++){
                rlutil::locate(espacioX, posY + linea);
                colorTexto(5);
                cout << palabra[i][linea];
            }
            
            espacioX += static_cast<int>(palabra[i][0].length());
        }
    }
    // rlutil::anykey();
}
void entrada(){
    limpiarPantalla();
    colorTexto(5);

    titulo(true);

    rlutil::locate(36, 9);
    string linea = "------------------------------------------------";
    for(char c : linea){
        rlutil::msleep(20);
        cout << c << flush;
    }

    rlutil::locate(40, 11);
    centrarTexto("Bienvenido/a a su banco de confianza!", ' ', 40);

    rlutil::locate(1, 30);
    rlutil::anykey();
    colorTexto(1);
}

void entradaSA(){
    colorTexto(5);
    limpiarPantalla();

    titulo(false);
    rlutil::locate(40, 11);
    centrarTexto("Bienvenido/a a su banco de confianza", ' ', 40);

    rlutil::anykey();
    colorTexto(1);

}

void mayusculas(char* palabra){
    size_t largo = strlen(palabra);
    for(size_t i = 0; i < largo; i++){
        unsigned char c = (unsigned char)palabra[i];

        if(c >= 'a' && c <= 'z') palabra[i] = static_cast<char>(c - 32);

        else if(c == 160) palabra[i] = static_cast<char>(181);  // á -> Á
        else if(c == 130) palabra[i] = static_cast<char>(144);  // é -> É
        else if(c == 161) palabra[i] = static_cast<char>(214);  // í -> Í
        else if(c == 162) palabra[i] = static_cast<char>(224);  // ó -> Ó
        else if(c == 163) palabra[i] = static_cast<char>(233);  // ú -> Ú
        else if(c == 164) palabra[i] = static_cast<char>(165);  // ñ -> Ñ
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
//system("cls"); -> Limpia la Pantalla: Borra todo el texto que se encuentra actualmente visible en la ventana de la consola. y vuelve a dibujar el menu.
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
