#ifndef ART_H
#define ART_H

#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <string>

using namespace std;

void tituloBeta();
void tituloBetaSA();

string mayusculas(string palabra);

void centrarTexto(string palabra, char dato, size_t cantidad);
void centrarTexto(string palabra, char dato1, char dato2, size_t largo);

#endif