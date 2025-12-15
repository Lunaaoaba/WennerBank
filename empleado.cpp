#include <iostream>
#include <cstring>
#include "empleado.h"
#include "usuario.h"
#include "ArchivoEmpleados.h"
#include "funciones.h"

using namespace std;

Empleado::Empleado(){ _legajo = 0; }
Empleado::Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, UsuarioEliminado){
    _legajo = legajo;
}

int Empleado::getLegajo() const{ return _legajo; }

string Empleado::mostrarDatos() const{
    char legajoFormateado[12];
    formatearId(legajoFormateado, "EM-", _legajo, 6);
    string datos = Usuario::mostrarDatos();
    datos += "\nLegajo: " + string(legajoFormateado);
    return datos;
}