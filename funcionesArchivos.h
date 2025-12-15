#ifndef FUNCIONES_ARCHIVOS_H
#define FUNCIONES_ARCHIVOS_H
#include "cliente.h"
#include "empleado.h"
#include "fecha.h"
#include "tiempo.h"


bool existeMail(const char* mail);
bool existeDniCliente(int dni);
bool existeDniEmpleado(int dni);
bool existeCvu(const char* cvu);
bool existeAlias(const char* alias);

bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado);
bool validarLoginEmpleado(int legajo, const char* contrasena, Empleado& empleadoEncontrado);

bool compararFechas(const Fecha& fecha1, const Fecha& fecha2);
bool compararHorarios(const Tiempo& tiempo1, const Tiempo& tiempo2);
#endif