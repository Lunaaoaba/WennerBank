#ifndef MENU_H
#define MENU_H
#include "cuentaBancaria.h"

// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------
// NOTA: dsp hago el .cpp

/*
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
*/

// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void menuPrincipal(); // Es el bucle principal que muestra la bienvenida y gestiona la navegación inicial.

// --- 1. FLUJO DE BIENVENIDA Y ACCESO ---
void menuBienvenida();      // Muestra las opciones iniciales: Iniciar Sesión, Crear Usuario, Salir.
void iniciarSesion();       // Pide credenciales (mail/pass) y valida si es Cliente, Empleado o Admin.
void menuCrearUsuario();    // Menú para elegir si crear un Cliente o un Empleado.

// --- 2. FLUJO DE CREACIÓN DE USUARIOS ---
void crearUsuarioCliente(); // Orquesta todo el proceso de creación de un Cliente.
void crearUsuarioEmpleado(); // Orquesta todo el proceso de creación de un Empleado.
// (Nota: No hay función para crear Admin, ya que es un Singleton).

// --- 3. MENÚS PRINCIPALES POR ROL ---
void menuCliente();     // Panel principal para un Cliente que ha iniciado sesión.
void menuEmpleado();    // Panel principal para un Empleado.
void menuAdministrador(); // Panel principal para el Administrador.

// --- 4. SUB-MENÚS Y ACCIONES DEL CLIENTE ---
void menuGestionCuentas();      // Permite al cliente listar, crear o ingresar a una de sus cuentas.
void menuOperacionesCuenta();   // Menú de una cuenta específica: Ingresar, Retirar, Transferir.
void realizarTransferencia();   // Guía al cliente a través de los pasos para transferir dinero.
void realizarDeposito();        // Pide monto y realiza un depósito.
void realizarRetiro();          // Pide monto y realiza un retiro.

// --- 5. SUB-MENÚS Y ACCIONES DE EMPLEADO/ADMINISTRADOR ---
// -- Gestión de Clientes --
void menuGestionClientes();         // Opciones: Crear, Modificar, Eliminar, Listar, Buscar.
void modificarCliente();            // Pide DNI de un cliente y permite cambiar sus datos.
void eliminarCliente();             // Pide DNI y realiza una baja lógica de un cliente.

// -- Gestión de Empleados (Solo Admin) --
void menuGestionEmpleados();        // Opciones: Crear, Modificar, Eliminar, Listar.
void modificarEmpleado();           // Pide legajo y permite cambiar datos.
void eliminarEmpleado();            // Pide legajo y realiza una baja lógica.

// -- Listados y Búsquedas --
void menuListados();                // Muestra opciones para listar todo (Clientes, Cuentas, etc.).
void menuBusquedas();               // Muestra opciones para buscar registros específicos.

// -- Operaciones Bancarias (Empleado/Admin) --
void menuOperacionesBancarias();    // Opciones para transferir, dar préstamos, etc.
void realizarTransferenciaInterbancaria(); // Transferencia realizada por un empleado.
void otorgarPrestamo();             // Proceso para que un empleado dé un préstamo a un cliente.



#endif
