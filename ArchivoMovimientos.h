#ifndef FUNCIONESARCHIVOSMOVIMIENTOS_H
#define FUNCIONESARCHIVOSMOVIMIENTOS_H
#include "movimientos.h"

bool guardarTransacciones(const Transaccion& transaccion);
int generarIdTransaccion();
Transaccion crearTransaccion();

bool guardarPrestamos(const Prestamo& prestamo);
int generarIdPrestamo();
Prestamo crearPrestamo();

#endif