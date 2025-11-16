#include "tipoUsuario.h"
#include "usuario.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "funciones.h"
#include <iostream>
#include <cstring>
using namespace std;


Cliente::Cliente(){ _idCliente = 0; }
Cliente::Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, estado){
    _idCliente = idCliente;
}

int Cliente::getIdCliente() const{ return _idCliente; }

string Cliente::mostrarDatos() const{
    char idFormateado[12];
    formatearId(idFormateado, "CL-", _idCliente, 6);
    string datos = Usuario::mostrarDatos();
    datos += "\nID Cliente: " + string(idFormateado);
    return datos;
}


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