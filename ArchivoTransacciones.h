#ifndef ARCHIVOTRANSACCIONES_H
#define ARCHIVOTRANSACCIONES_H

#include "Movimientos.h"     
#include "cuentaBancaria.h"  

// ----------------------------------------------------------------------
//          FUNCIONES PARA MANEJO DE ARCHIVOS DE TRANSACCIONES
// ----------------------------------------------------------------------
bool guardarTransaccion(const Transaccion& transaccion);
int generarIdTransaccion();
void listarTransacciones();
bool buscarTransaccionId(int idTransaccion, Transaccion& transaccionEncontrada);
// Función para buscar todas las transacciones de una cuenta (origen o destino)
int buscarTransaccionIdCuenta(int idCuenta, Transaccion listaTransacciones[], int maxTransacciones);

// ----------------------------------------------------------------------
//          LOGICA DE NEGOCIO PARA TRANSACCIONES
// ----------------------------------------------------------------------
bool realizarDeposito(double monto, int idCuenta);
bool realizarRetiro(double monto, int idCuenta);
bool realizarTransferencia(double monto, int idCuentaOrigen, int idCuentaDestino);

#endif