#include "tipoUsuario.h"
#include "usuario.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "funciones.h"
#include <iostream>
#include <cstring>
using namespace std;

//CLIENTE
//constructores
Cliente::Cliente(){ _idCliente = 0; }
Cliente::Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, estado){
    _idCliente = idCliente;
}
//get
int Cliente::getIdCliente(){ return _idCliente; }
//otros
string Cliente::mostrarDatos(){
    char idFormateado[12];
    formatearId(idFormateado, "CL-", _idCliente, 6);
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "\nID Cliente: " + string(idFormateado);
    return datos;
}


//EMPLEADO
//constructores
Empleado::Empleado(){ _legajo = 0; }
Empleado::Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, UsuarioEliminado){
    _legajo = legajo;
}
//get
int Empleado::getLegajo(){ return _legajo; }
//otros
string Empleado::mostrarDatos(){
    char legajoFormateado[12];
    formatearId(legajoFormateado, "EM-", _legajo, 6);
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "\nLegajo: " + string(legajoFormateado);
    return datos;
}