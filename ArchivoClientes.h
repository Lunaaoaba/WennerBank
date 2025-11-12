#ifndef FUNCIONESARCHIVOSCLIENTES_H
#define FUNCIONESARCHIVOSCLIENTES_H
#include "tipoUsuario.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES
// ----------------------------------------------------------------------
bool guardarClientes(const Cliente& cliente);
int generarIdCliente();
Cliente crearCliente();
bool modificarCliente(int idCliente, Cliente clienteModificado, int posicion);
void listarClientes();

//----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------

// aca se ponen nose, crear cuentas bancarias, ver saldo, etc
// no hacer funciones de archivo aca y no copypaste de ia :P

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------
bool buscarCliente(const char* criterio, int valor, Cliente& encontrado);
bool buscarCliente(const char* criterio, const char* valor, Cliente& encontrado);
bool buscarClienteNacimiento(const Fecha& fecha, Cliente& encontrado);

bool buscarClienteId(int idCliente, Cliente &clienteEncontrado);
bool buscarClienteDni(int dni, Cliente &clienteEncontrado);
bool buscarClienteEdad(int edad, Cliente &clienteEncontrado);

bool buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado);
bool buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado);
bool buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado);

#endif