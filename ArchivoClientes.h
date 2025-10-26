#ifndef FUNCIONESARCHIVOSCLIENTES_H
#define FUNCIONESARCHIVOSCLIENTES_H
#include "tipoUsuario.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CLIENTES
// ----------------------------------------------------------------------
bool guardarClientes(const Cliente& cliente);
int generarIdCliente();
Cliente crearCliente();
void modificarCliente(Cliente* clienteModificado);
void listarClientes();

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CLIENTES
// ----------------------------------------------------------------------
void buscarClienteId(int idCliente, Cliente &clienteEncontrado);
void buscarClienteDni(int dni, Cliente &clienteEncontrado);
void buscarClienteNombre(const char* nombre, Cliente &clienteEncontrado);
void buscarClienteApellido(const char* apellido, Cliente &clienteEncontrado);
void buscarClienteLocalidad(const char* localidad, Cliente &clienteEncontrado);
void buscarClienteEdad(int edad, Cliente &clienteEncontrado);
void buscarClienteNacimiento(Fecha fechaNacimiento, Cliente &clienteEncontrado);

//----------------------------------------------------------------------
//             FUNCIONES PARA EL CLIENTE
// ----------------------------------------------------------------------


#endif