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
//set
void Cliente::setIdCliente(int idCliente){ _idCliente = idCliente; }
//get
int Cliente::getIdCliente(){ return _idCliente; }
//otros
void Cliente::cargarDatos(){
    Usuario::cargarDatos();
    _idCliente = generarIdCliente();
}
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
//setters
void Empleado::setLegajo(int legajo){ _legajo = legajo; }
//getters
int Empleado::getLegajo(){ return _legajo; }
//otros
void Empleado::cargarDatos(){
    Usuario::cargarDatos();
    _legajo = generarLegajo();
}
string Empleado::mostrarDatos(){
    char legajoFormateado[12];
    formatearId(legajoFormateado, "EM-", _legajo, 6);
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "\nLegajo: " + string(legajoFormateado);
    return datos;
}