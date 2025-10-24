#ifndef FUNCIONESARCHIVOSCUENTAS_H
#define FUNCIONESARCHIVOSCUENTAS_H
#include "cuentaBancaria.h"

bool guardarCuentas(const cuentaBancaria& cuenta);
int generarIdCuenta();
cuentaBancaria crearCuenta();

#endif
