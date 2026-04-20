#ifndef FUNCIONES_H 
#define FUNCIONES_H 
#include <limits>

int wherex();
int wherey();

int validarEntero(int min, int max);
double validarDouble(double min, double max);

void validarCadenaNumeros(char* numero, int min, int max);
void validarCadenaLetras(char* palabra, int maxLength);
void validarCadena(char* palabra, int maxLength);
void validarCadenaLargo(char* palabra, int minLength, int maxLength);

char validarSiNo();

void formatearId(char* resultado, const char* prefijo, int idNumero, int largoTotal);


#endif