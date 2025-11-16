#ifndef FUNCIONESARCHIVOSEMPLADOS_H
#define FUNCIONESARCHIVOSEMPLADOS_H
#include "tipoUsuario.h"

// ------ FUNCIONES PARA MANEJO DE ARCHIVOS DE EMPLEADOS ------

bool guardarEmpleados(const Empleado& empleado);
int generarLegajo();
Empleado crearEmpleado();

int posicionEmpleadoPorLegajo(int legajo);
bool modificarEmpleado(const Empleado& empleadoModificado);

bool modificarDatosEmpleado(int legajo);
bool eliminarEmpleado(int legajo);
bool restaurarEmpleado(int legajo);

// ------ FUNCIONES PARA EL EMPLEADO ------

// (etc)

// ------ FUNCIONES PARA BUSQUEDA DE EMPLEADOS ------

void listarEmpleados();
void listarTodosEmpleados();

bool buscarEmpleado(const char* criterio, int valor, Empleado& encontrado);
bool buscarEmpleado(const char* criterio, const char* valor, Empleado& encontrado);
bool buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado);

bool buscarEmpleadoLegajo(int legajo, Empleado &empleadoEncontrado);
bool buscarEmpleadoDni(int dni, Empleado &empleadoEncontrado);
bool buscarEmpleadoEdad(int edad, Empleado &empleadoEncontrado);

bool buscarEmpleadoNombre(const char* nombre, Empleado &empleadoEncontrado);
bool buscarEmpleadoApellido(const char* apellido, Empleado &empleadoEncontrado);
bool buscarEmpleadoLocalidad(const char* localidad, Empleado &empleadoEncontrado);

#endif