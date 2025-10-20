#include "tipoUsuario.h"
#include "usuario.h"
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
    cout << "Ingrese ID Cliente: ";
    cin >> _idCliente;
}
string Cliente::mostrarDatos(){
    string datos = Usuario::mostrarDatos(); // Muestra los datos heredados de Usuario (y Persona)
    datos += "ID Cliente: " + to_string(_idCliente) + "\n";
    return datos;
}


//EMPLEADO
//constructores
Empleado::Empleado(){
    _legajo = 0;
    strcpy(_claveOperacion, "N/A");
}
Empleado::Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo, const char* claveOperacion) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, UsuarioEliminado){
    _legajo = legajo;
    strcpy(_claveOperacion, claveOperacion);
}
//setters
void Empleado::setLegajo(int legajo){ _legajo = legajo; }
void Empleado::setClaveOperacion(const char* claveOperacion){ strcpy(_claveOperacion, claveOperacion); }
//getters
    int Empleado::getLegajo(){ return _legajo; }
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
    datos += "Legajo: " + to_string(_legajo) + "\n";
    datos += "Clave de Operacion: " + string(_claveOperacion) + "\n";
    return datos;
}