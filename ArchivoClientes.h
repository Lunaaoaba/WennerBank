#ifndef FUNCIONESARCHIVOSCLIENTES_H
#define FUNCIONESARCHIVOSCLIENTES_H
#include "tipoUsuario.h"

// ------ FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES ------

bool guardarClientes(const Cliente& cliente);
int generarIdCliente();
Cliente crearCliente();

int posicionClientePorId(int idCliente);
bool modificarCliente(const Cliente& clienteModificado);

bool modificarDatosCliente(int idCliente);
bool eliminarCliente(int idCliente);
bool restaurarCliente(int idCliente);

// ------ FUNCIONES PARA EL CLIENTE ------

// aca se ponen nose, crear cuentas bancarias, ver saldo, etc
// no hacer funciones de archivo aca y no copypaste de ia :P

// ------ FUNCIONES PARA BUSQUEDA DE CLIENTES ------

void listarClientes();
void listarTodosClientes();

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