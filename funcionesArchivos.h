#ifndef FUNCIONES_ARCHIVOS_H
#define FUNCIONES_ARCHIVOS_H
#include "tipoUsuario.h"

void crearArchivos();
bool existeMail(const char* mail);
bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado);
bool validarLoginEmpleado(int legajo, const char* contrasena, Empleado& empleadoEncontrado);

#endif