#ifndef MENU_H
#define MENU_H
#include "cuentaBancaria.h"

// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------
// NOTA: dsp hago el .cpp

//Bienvenida
void menuBienvenida(); //saludo y seleccion de crear usuario o iniciar sesion
void iniciarSesion(); //ingresa el Usuario Cliente
void crearUsuario(); // solo crea Usuario cliente
void iniciarSesionEmpleado(); // ingresa el Usuario Empleado o Admin

//crear Usuario
//paso1
void crearUsuarioCliente(); //pide datos de persona, usuario y da id de cliente
void crearUsuarioEmpleado(); //pide datos de persona, usuario y da legajo de empleado

//paso2
void verificarDatosCliente(); //muestra datos y pregunta si son correctos
void verificarDatosEmpleado(); // lo mismo que cliente

//verificacion de datos
void DatosCorrectos(); //si los datos son correctos
void DatosIncorrectos(); //si los datos son incorrectos (literalmente lo dice el nombre :V)

//modificacion de datos (en caso de seleccionar datos incorrectos)
void ModificarDatosCliente(); // permite modificar los datos del cliente
void ModificarDatosEmpleado(); // permite modificar los datos del empleado

//Iniciar sesion cliente
void menuCliente(); //Bienvenida al usuario cliente
void menuAdmin();
void menuEmpleado();

//cuenta bancaria
void crearCuentaBancaria();
void listarCuentasPropias();
void IngresarCuentaBancaria();
void menuCuentaBancaria();





#endif
