#ifndef FUNCIONESARCHIVOSCLIENTES_H
#define FUNCIONESARCHIVOSCLIENTES_H
#include "tipoUsuario.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES
// ----------------------------------------------------------------------
bool guardarClientes(const Cliente& cliente);
int generarIdCliente();
Cliente crearCliente();
bool modificarCliente(Cliente& clienteModificado);
void listarClientes();

//----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------
//bool borrarCliente(int id);

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------
bool buscarClienteId(int idCliente, Cliente &clienteEncontrado);
bool buscarClienteDni(int dni, Cliente &clienteEncontrado);
void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado);
void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado);
void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado);
void buscarClienteEdad(int edad, Cliente &clienteEncontrado);
void buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado);


// ----------------------------------------------------------------------
//             FUNCIONES PARA MODIFICAR CLIENTES
// ----------------------------------------------------------------------
//bool modificarCliente(Cliente& clienteModificado);

#endif