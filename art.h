#define byte windows_byte
#include "rlutil.h"
#undef byte

#ifndef ART_H
#define ART_H
using namespace std;

void tituloBeta();

string mayusculas(string palabra);
void centrar_texto(string palabra, char dato, size_t cantidad);
#endif 