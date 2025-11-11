#ifndef FUNCIONESARCHIVOSMOVIMIENTOS_H
#define FUNCIONESARCHIVOSMOVIMIENTOS_H
#include "movimientos.h"

bool guardarTransacciones(const Transaccion& transaccion);
int generarIdTransaccion();
Transaccion crearTransaccion();

bool guardarPrestamos(const Prestamo& prestamo);
int generarIdPrestamo();
Prestamo crearPrestamo();


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE TRANSACCIONES
// ----------------------------------------------------------------------
void buscarTransaccionId(int idTransaccion, Transaccion &transaccionEncontrada){}
void buscarTransaccionCuentaOrigen(int idCuentaOrigen, Transaccion &transaccionEncontrada){}
void buscarTransaccionCuentaDestino(int idCuentaDestino, Transaccion &transaccionEncontrada){}
void buscarTransaccionMonto(double monto, Transaccion &transaccionEncontrada){}
void buscarTransaccionFecha(Fecha fechaTransaccion, Transaccion &transaccionEncontrada){}
void buscarTransaccionHora(Tiempo horaTransaccion, Transaccion &transaccionEncontrada){}

#endif