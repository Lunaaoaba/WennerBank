#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cuentaBancaria.h" 
#include "menu.h" // Necesario para la declaración de menuCuenta, etc.
#include <iostream>

// ----------------------------------------------------------------------
// Funciones del Menú Principal (Implementadas en funciones.cpp)
// ----------------------------------------------------------------------
void crearCuenta();
void iniciarSesion();
void eliminarCuenta();
void listarCuentas();

// ----------------------------------------------------------------------
// Funciones de Lógica de Operaciones (Implementadas en funciones.cpp)
// ----------------------------------------------------------------------
// Reciben la cuenta por REFERENCIA para modificarla directamente antes de guardarla.
// El valor de retorno (bool) indica si la operación fue exitosa (ej. saldo suficiente).
bool realizarDeposito(cuentaBancaria &cuenta, double monto);
bool realizarRetiro(cuentaBancaria &cuenta, double monto);

// ----------------------------------------------------------------------
// Funciones de Lógica de Archivos (Implementadas en funciones.cpp)
// ----------------------------------------------------------------------
bool guardarCuenta(const cuentaBancaria &cuenta);
cuentaBancaria buscarCuenta(int idCuenta);
bool modificarCuenta(const cuentaBancaria &cuentaModificada); // NECESARIA PARA ACTUALIZAR REGISTROS
bool borrarCuenta(int idCuenta);
void listarTodasCuentas();

#endif // FUNCIONES_H
