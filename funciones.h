#ifndef FUNCIONES_H 
#define FUNCIONES_H 
#include <limits>


// valida que el ingreso sea un entero dentro de un rango
int validarEntero(int min, int max);

void validarCadenaLetras(char* palabra, int maxLength);
void validarCadena(char* palabra, int maxLength);
void validarCadenaLargo(char* palabra, int minLength, int maxLength);

// agrega 0 a la izquierda y un prefijo al idNumero, guardando el resultado en "resultado"
void formatearId(char* resultado, const char* prefijo, int idNumero, int largoTotal);

// pausa y limpia el buffer de entrada
void pausa();

// limpia la entrada después de un error de cin
void limpiarEntrada();

#endif