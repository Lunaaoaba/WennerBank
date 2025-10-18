//#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cuentaBancaria.h"
#include "menu.h"
#include <iostream>

// ----------------------------------------------------------------------
//              MOVER / MODIFICAR PARA LLEVAR A FUNCIONES.H
// ----------------------------------------------------------------------

// Funciones CRUD (CREATE, READ, UPDATE, DELETE)
void agregarDatos();
void listarDatos();
void buscarDatos();
void eliminarDatos();
void actualizarDatos();
void manejoCuenta(); // Para depositos/retiros
void reportes();


// Funciones de Reporte y Archivo
void generarArchivo(int op, const char* id_cliente_buscado, const char* id_cuenta_buscado, double monto_min, double monto_max);


// Funciones de Utilidad
void gotoxy(int x, int y);
void cuadro(int x1, int y1, int x2, int y2);
void cursorOff();
void cursorOn(bool visible = true, int size = 20); // Se añadieron parámetros por defecto
void limpiarEntrada();
void pause();









































































// ----------------------------------------------------------------------


<<<<<<< HEAD
/*void crearCuenta();
void iniciarSesion();
void eliminarCuenta();
void listarCuentas();
*/
=======
>>>>>>> 93873b8b341767d8020b819732a805e918f87822
// ----------------------------------------------------------------------

// Reciben la cuenta por REFERENCIA para modificarla directamente antes de guardarla.
// El valor de retorno (bool) indica si la operación fue exitosa (ej. saldo suficiente).

/*bool realizarDeposito(cuentaBancaria &cuenta, double monto);
bool realizarRetiro(cuentaBancaria &cuenta, double monto);*/

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

//IMPORTANTE-------------------------------------------------------------
//se crearon funciones de prueba para ver que es mejor
