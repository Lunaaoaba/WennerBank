#ifndef FUNCIONESARCHIVOSMOVIMIENTOS_H
#define FUNCIONESARCHIVOSMOVIMIENTOS_H
#include "movimientos.h"



bool guardarTransaccion(const Transaccion& transaccion);
int generarIdTransaccion();
Transaccion crearTransaccion(); // sin hacer
void listarTransacciones();

// ----------------------------------------------------------------------

bool registrarMovimiento(int idCuentaOrigen, int idCuentaDestino, double monto);
bool realizarDeposito(double monto, int idCuenta);
bool realizarRetiro(double monto, int idCuenta);
bool realizarTransferencia(double monto, int idCuentaOrigen, int idCuentaDestino);

// ----------------------------------------------------------------------

bool buscarTransaccion(int tipo);
bool buscarTransaccion(char tipo);

// void buscarTransaccionId(int idTransaccion, Transaccion &transaccionEncontrada){}
// void buscarTransaccionCuentaOrigen(int idCuentaOrigen, Transaccion &transaccionEncontrada){}
// void buscarTransaccionCuentaDestino(int idCuentaDestino, Transaccion &transaccionEncontrada){}
// void buscarTransaccionMonto(double monto, Transaccion &transaccionEncontrada){}
// void buscarTransaccionFecha(Fecha fechaTransaccion, Transaccion &transaccionEncontrada){}
// void buscarTransaccionHora(Tiempo horaTransaccion, Transaccion &transaccionEncontrada){}

// =======================================================================

bool guardarPrestamo(const Prestamo& prestamo);
int generarIdPrestamo();
Prestamo crearPrestamo();
void listarPrestamos();

// ----------------------------------------------------------------------

// funciones de prestamos

// ----------------------------------------------------------------------

// busquedas

#endif