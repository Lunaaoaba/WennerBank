#ifndef FUNCIONESARCHIVOSCUENTAS_H
#define FUNCIONESARCHIVOSCUENTAS_H
#include "cuentaBancaria.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS
// ----------------------------------------------------------------------
bool guardarCuentas(const cuentaBancaria& cuenta);
int generarIdCuenta();
cuentaBancaria crearCuenta();
void listarCuentas();

//----------------------------------------------------------------------
//             FUNCIONES PARA LA CUENTA BANCARIA
// ----------------------------------------------------------------------

void mostrarSaldo(cuentaBancaria &cuenta, double saldo);

#endif
