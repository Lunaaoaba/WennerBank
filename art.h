#ifndef ART_H
#define ART_H // <-- Faltaba este define

#include <iostream>
#include <string>
#define byte windows_byte // Mueve el workaround aquí si es necesario globalmente
#include "rlutil.h"
#undef byte

using namespace std;

void tituloBeta();
void tituloBetaSA();

string mayusculas(string palabra);

void centrarTexto(string palabra, char dato, size_t cantidad);
void centrarTexto(string palabra, char dato1, char dato2, size_t largo);

#endif