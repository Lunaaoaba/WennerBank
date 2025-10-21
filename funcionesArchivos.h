#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H
#include "cuentaBancaria.h"
#include "movimientos.h"
#include "tipoUsuario.h"
#include <iostream>
#include <cstdio>

bool guardarClientes(const Cliente& cliente);
int generarIdCliente();

bool guardarEmpleados(const Empleado& empleado);
int generarLegajoEmpleado();

bool guardarCuentas(const cuentaBancaria& cuenta);
int generarIdCuenta();

bool guardarTransacciones(const Transaccion& transaccion);
int generarIdTransaccion();

bool guardarPrestamos(const Prestamo& prestamo);
int generarIdPrestamo();




#endif