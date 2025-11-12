#ifndef FUNCIONESARCHIVOSCUENTAS_H
#define FUNCIONESARCHIVOSCUENTAS_H
#include "cuentaBancaria.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS
// ----------------------------------------------------------------------
bool guardarCuentas(const cuentaBancaria& cuenta);
int generarIdCuenta();
cuentaBancaria crearCuenta();
bool modificarCuenta(cuentaBancaria& cuentaModificada);
void listarCuentas();


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CUENTAS
// ----------------------------------------------------------------------
void buscarCuentaId(int idCuenta, cuentaBancaria &cuentaEncontrada);
void buscarCuentaClienteId(int idCliente, cuentaBancaria &cuentaEncontrada);
void buscarCuentaCvu(const char* cvu, cuentaBancaria &cuentaEncontrada);
void buscarCuentaAlias(const char* alias, cuentaBancaria &cuentaEncontrada);
void buscarCuentaNombre(const char* nombreCuenta, cuentaBancaria &cuentaEncontrada);
// por las dudas
void buscarCuentaSaldo(double saldo, cuentaBancaria &cuentaEncontrada);
//----------------------------------------------------------------------
//             FUNCIONES PARA LA CUENTA BANCARIA
// ----------------------------------------------------------------------

void mostrarSaldo(cuentaBancaria &cuenta, double saldo);

//----------------------------------------------------------------------
//             FUNCIONES PARA BORRAR CUENTA BANCARIA
// ----------------------------------------------------------------------
bool borrarCuenta(int idCuenta);

#endif
