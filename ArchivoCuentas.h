#ifndef FUNCIONESARCHIVOSCUENTAS_H
#define FUNCIONESARCHIVOSCUENTAS_H
#include "cuentaBancaria.h"

// ----- FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS -----

bool guardarCuentas(const cuentaBancaria& cuenta);
cuentaBancaria crearCuenta(int idCliente);

int posicionCuentaPorId(int idCuenta);
bool modificarCuenta(const cuentaBancaria& cuentaModificada);

bool modificarDatosCuenta(int idCuenta);
bool eliminarCuenta(int idCuenta);
bool restaurarCuenta(int idCuenta);

// ----- FUNCIONES PARA BUSQUEDA DE CUENTAS -----

void listarCuentasCliente(int idCliente);
void listarCuentas();
void listarTodasCuentas();

bool buscarCuenta(const char* criterio, int valor, cuentaBancaria& encontrado);
bool buscarCuenta(const char* criterio, const char* valor, cuentaBancaria& encontrado);

// ----- FUNCIONES PARA LA CUENTA BANCARIA -----

void mostrarSaldo(const cuentaBancaria& cuenta);
// Transacciones básicas
bool depositar(int idCuenta, double monto);
bool extraer(int idCuenta, double monto);
bool transferir(int idCuentaOrigen, int idCuentaDestino, double monto);

// ----- FUNCIONES AUXILIARES PARA CUENTAS -----

int generarIdCuenta();
void generarCvu(char* cvu);
void generarAlias(char* alias);

#endif
