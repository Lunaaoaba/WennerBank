#ifndef FUNCIONESARCHIVOSEMPLADOS_H
#define FUNCIONESARCHIVOSEMPLADOS_H
#include "tipoUsuario.h"

// ------ FUNCIONES PARA MANEJO DE ARCHIVOS DE EMPLEADOS ------

bool guardarEmpleados(const Empleado& empleado);
Empleado crearEmpleado();

bool modificarEmpleado(const Empleado& empleadoModificado);
bool modificarDatosEmpleado(int legajo);

bool eliminarEmpleado(int legajo);
bool restaurarEmpleado(int legajo);

// ------ FUNCIONES PARA BUSQUEDA DE EMPLEADOS ------

void listarEmpleados();
void listarTodosEmpleados();

bool buscarEmpleado(const char* criterio, int valor, Empleado& encontrado);
bool buscarEmpleado(const char* criterio, const char* valor, Empleado& encontrado);
bool buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado);

// ------ FUNCIONES PARA EL EMPLEADO ------

// (etc)

// ----- FUNCIONES AUXILIARES PARA EMPLEADOS -----
int generarLegajo();
int posicionEmpleadoPorLegajo(int legajo);



#endif