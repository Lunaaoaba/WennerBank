#ifndef FUNCIONESARCHIVOSEMPLADOS_H
#define FUNCIONESARCHIVOSEMPLADOS_H
#include "tipoUsuario.h"

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE EMPLEADOS
// ----------------------------------------------------------------------
bool guardarEmpleados(const Empleado& empleado);
int generarLegajo();
Empleado crearEmpleado();
void modificarEmpleado(Empleado* empleadoModificado);
void listarEmpleados();

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE EMPLEADOS
// ----------------------------------------------------------------------
void buscarEmpleadoLegajo(int legajo, Empleado &empleadoEncontrado);
void buscarEmpleadoDni(int dni, Empleado &empleadoEncontrado);
void buscarEmpleadoNombre(const char* nombre, Empleado &empleadoEncontrado);
void buscarEmpleadoApellido(const char* apellido, Empleado &empleadoEncontrado);
void buscarEmpleadoLocalidad(const char* localidad, Empleado &empleadoEncontrado);
void buscarEmpleadoEdad(int edad, Empleado &empleadoEncontrado);
void buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado);

//----------------------------------------------------------------------
//             FUNCIONES PARA EL EMPLEADO
// ----------------------------------------------------------------------

#endif