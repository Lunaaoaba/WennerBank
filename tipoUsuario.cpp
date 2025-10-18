#include "tipoUsuario.h"
#include "usuario.h"
#include <iostream>
#include <cstring>
using namespace std;

//CLIENTE
//constructores
Cliente::Cliente(){ strcpy(_idCliente, "0000"); }
Cliente::Cliente(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, const char* idCliente) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, estado){
    strcpy(_idCliente, idCliente);
}
//set
void Cliente::setIdCliente(const char* idCliente){ strcpy(_idCliente, idCliente); }
//get
const char* Cliente::getIdCliente(){ return _idCliente; }
//otros
void Cliente::cargarDatos(){
    Usuario::cargarDatos();
    cout << "Ingrese ID Cliente: ";
    cin >> _idCliente;
}
string Cliente::mostrarDatos(){
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "ID Cliente: " + string(_idCliente) + "\n";
    return datos;
}


//EMPLEADO
//constructores
Empleado::Empleado(){
    strcpy(_legajo, "00000");
    strcpy(_claveOperacion, "N/A");
}
Empleado::Empleado(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  const char* legajo, const char* claveOperacion) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, UsuarioEliminado){
    strcpy(_legajo, legajo);
    strcpy(_claveOperacion, claveOperacion);
}
//setters
void Empleado::setLegajo(const char* legajo){ strcpy(_legajo, legajo); }
void Empleado::setClaveOperacion(const char* claveOperacion){ strcpy(_claveOperacion, claveOperacion); }
//getters
    const char* Empleado::getLegajo(){ return _legajo; }
    const char* Empleado::getClaveOperacion(){ return _claveOperacion; }
//otros
void Empleado::cargarDatos(){
    Usuario::cargarDatos();
    cout << "Ingrese legajo: ";
    cin >> _legajo;
    cout << "Ingrese clave de operacion: ";
    cin >> _claveOperacion;
}
string Empleado::mostrarDatos(){
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "Legajo: " + string(_legajo) + "\n";
    datos += "Clave de Operacion: " + string(_claveOperacion) + "\n";
    return datos;
}