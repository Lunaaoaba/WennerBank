#ifndef ART_H
#define ART_H
#include <iostream>
#include <string>

using namespace std;

void titulo(bool animado);
void entrada();
void entradaSA();

void mayusculas(char* palabra);

void centrarTexto(string palabra, char dato, size_t cantidad);
void centrarTexto(string palabra, char dato1, char dato2, size_t largo);

#endif