#ifndef MENUCUENTA_H
#define MENUCUENTA_H

void menuCuenta(int idCuenta, int idCliente);

void ingresarDinero(int idCuenta);
void retirarDinero(int idCuenta);
void transferirDinero(int idCuenta);

void misPrestamos(int idCuenta, int idCliente);
void pedirPrestamo(int idCuenta, int idCliente);
void pagarPrestamo(int idCuenta, int idCliente);

void modificarDatosCuentaMenu(int idCuenta, int idCliente);

void cerrarCuenta(int idCuenta, int idCliente);

#endif