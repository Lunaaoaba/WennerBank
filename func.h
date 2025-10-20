#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cuentaBancaria.h" 
#include "menu.h"
#include <iostream>

// ----------------------------------------------------------------------
//              MOVER / MODIFICAR PARA LLEVAR A FUNCIONES.H
// ----------------------------------------------------------------------

// Reciben la cuenta por REFERENCIA para modificarla directamente antes de guardarla.
// El valor de retorno (bool) indica si la operación fue exitosa (ej. saldo suficiente).
void mostrarSaldo(cuentaBancaria &cuenta, double saldo);
double realizarDeposito(cuentaBancaria &cuenta, double monto);
double realizarRetiro(cuentaBancaria &cuenta, double saldo);

// ----------------------------------------------------------------------


// bool modificarCuenta(const cuentaBancaria &cuentaModificada); // NECESARIA PARA ACTUALIZAR REGISTROS
// bool guardarCuenta(const cuentaBancaria &cuenta);
// cuentaBancaria buscarCuenta(int idCuenta);
// bool borrarCuenta(int idCuenta);
// void listarTodasCuentas();

//----------------------------------------------------------------------
//autogeneracion de IDs

//autoIdCuenta();
//autoIdCliente();
//autoLegajo();
//autoIdTransaccion();
//autoIdPrestamo();
//autoIdTarjeta();


//----------------------------------------------------------------------
// validaciones

// overflowText();
// overflowNum();
// mayorCero(valor, mensaje);
//


// ----------------------------------------------------------------------
#endif
