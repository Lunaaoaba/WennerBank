#ifndef FUNCIONESARCHIVOSCUENTAS_H
#define FUNCIONESARCHIVOSCUENTAS_H
#include "cuentaBancaria.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS
// ----------------------------------------------------------------------
bool guardarCuentas(const cuentaBancaria& cuenta);
int generarIdCuenta();
cuentaBancaria crearCuenta();

bool posicionCuentaPorId(int idCuenta);
bool modificarCuenta(const cuentaBancaria& cuentaModificada);

bool modificarDatosCuenta(int idCuenta);
bool eliminarCuenta(int idCuenta);
bool restaurarCuenta(int idCuenta);

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CUENTAS
// ----------------------------------------------------------------------

void listarCuentas();
void listarTodasCuentas();

bool buscarCuenta(const char* criterio, int valor, cuentaBancaria& encontrado);
bool buscarCuenta(const char* criterio, const char* valor, cuentaBancaria& encontrado);

bool buscarCuentaId(int idCuenta, cuentaBancaria &cuentaEncontrada);
bool buscarCuentaIdCliente(int idCliente, cuentaBancaria &cuentaEncontrada);
bool buscarCuentaSaldo(double saldo, cuentaBancaria &cuentaEncontrada);

bool buscarCuentaCvu(const char* cvu, cuentaBancaria &cuentaEncontrada);
bool buscarCuentaAlias(const char* alias, cuentaBancaria &cuentaEncontrada);
bool buscarCuentaNombre(const char* nombreCuenta, cuentaBancaria &cuentaEncontrada);

//----------------------------------------------------------------------
//             FUNCIONES PARA LA CUENTA BANCARIA
// ----------------------------------------------------------------------
void mostrarSaldo(cuentaBancaria &cuenta, double saldo);


#endif
