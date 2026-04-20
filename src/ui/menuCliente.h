#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

void menuCliente(int idCliente);

void verMisCuentas(int idCliente);
void ingresarACuenta(int idCliente);
void crearMiCuenta(int idCliente); 

void verMisDatos(int idCliente);
void modificarMisDatos(int idCliente);

void verMisTransacciones(int idCliente);
void cerrarMiCuenta(int idCliente);
void verSaldoTotal(int idCliente);
void cambiarPassword(int idCliente);

#endif