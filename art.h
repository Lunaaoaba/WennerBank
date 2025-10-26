#ifndef ART_H
#define ART_H // <-- Faltaba este define

#include <iostream>
#include <string>
#define byte windows_byte // Mueve el workaround aquí si es necesario globalmente
#include "rlutil.h"
#undef byte

using namespace std;

void tituloBeta();

string mayusculas(string palabra);

void centrarTexto(string palabra, char dato, size_t cantidad); // <-- Cambia string dato por char dato

#endif