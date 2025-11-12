#include <ctime>
#include <iostream>
#include <cstring>
#include <limits>
#include "persona.h"
#include "funciones.h"
using namespace std;

//constructores
Persona::Persona(){
    _dni = 00000000;
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_localidad, "N/A");
}
Persona::Persona(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento){
    _dni = dni;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_localidad, localidad);
    _fechaNacimiento = fechaNacimiento;
}
//setters
void Persona::setDni(int dni){ _dni = dni; }
void Persona::setNombre(const char* nombre){ strcpy(_nombre, nombre); }
void Persona::setApellido(const char* apellido){ strcpy(_apellido, apellido); }
void Persona::setLocalidad(const char* localidad){ strcpy(_localidad, localidad); }
void Persona::setFechaNacimiento(Fecha fechaNacimiento){ _fechaNacimiento = fechaNacimiento; }
//getters
int Persona::getDni(){ return _dni; }
const char* Persona::getNombre(){ return _nombre; }
const char* Persona::getApellido(){ return _apellido; }
const char* Persona::getLocalidad(){ return _localidad; }
Fecha Persona::getFechaNacimiento(){ return _fechaNacimiento; }
int Persona::getEdad(){
    Fecha fechaActual;
    fechaActual.cargarFechaActual();

    int edad = fechaActual.getAnio() - _fechaNacimiento.getAnio();

    if (fechaActual.getMes() < _fechaNacimiento.getMes() || (fechaActual.getMes() == _fechaNacimiento.getMes() && fechaActual.getDia() < _fechaNacimiento.getDia())) {
        edad--;
    }

    return edad;
}
//otros
void Persona::cargarDatos(){
    cout << "\nCargando datos de la persona..." << endl;
    cout << "Ingrese DNI: " << endl;
    _dni = validarEntero(10000000, 99999999);
    cout << "Ingrese Nombre: " << endl;
    validarCadena(_nombre, 50);
    cout << "Ingrese Apellido: " << endl;
    validarCadena(_apellido, 50);
    cout << "Ingrese Localidad: " << endl;
    validarCadena(_localidad, 50);

    cout << "Ingrese Fecha de Nacimiento:" << endl;
    _fechaNacimiento.cargarFecha();
}
string Persona::mostrarDatos(){
    string datos = string("\nDNI: ") + to_string(_dni);
    datos += "\nNombre: " + string(_nombre);
    datos += "\nApellido: " + string(_apellido);
    datos += "\nLocalidad: " + string(_localidad);
    datos += "\nFecha de Nacimiento: " + _fechaNacimiento.mostrarFecha();
    datos += "\nEdad: " + to_string(getEdad()) + " a" + string(1, char(164)) + "os";
    return datos;
}

