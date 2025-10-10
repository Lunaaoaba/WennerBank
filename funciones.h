#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cuentaBancaria.h" 
#include "menu.h"
#include <iostream>

// ----------------------------------------------------------------------


void crearCuenta();
void iniciarSesion();
void eliminarCuenta();
void listarCuentas();

// ----------------------------------------------------------------------

// Reciben la cuenta por REFERENCIA para modificarla directamente antes de guardarla.
// El valor de retorno (bool) indica si la operación fue exitosa (ej. saldo suficiente).

bool realizarDeposito(cuentaBancaria &cuenta, double monto);
bool realizarRetiro(cuentaBancaria &cuenta, double monto);

// ----------------------------------------------------------------------


// bool modificarCuenta(const cuentaBancaria &cuentaModificada); // NECESARIA PARA ACTUALIZAR REGISTROS
// bool guardarCuenta(const cuentaBancaria &cuenta);
// cuentaBancaria buscarCuenta(int idCuenta);
// bool borrarCuenta(int idCuenta);
// void listarTodasCuentas();

#endif
