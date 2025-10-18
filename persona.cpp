#include "persona.h"
#include <ctime>
#include <iostream>
#include <cstring>
using namespace std;

//constructores
Persona::Persona(){
    strcpy(_dni, "00000000");
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_localidad, "N/A");
}
Persona::Persona(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento){
    strcpy(_dni, dni);
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_localidad, localidad);
    _fechaNacimiento = fechaNacimiento;
}
//setters
void Persona::setDni(const char* dni){ strcpy(_dni, dni); }
void Persona::setNombre(const char* nombre){ strcpy(_nombre, nombre); }
void Persona::setApellido(const char* apellido){ strcpy(_apellido, apellido); }
void Persona::setLocalidad(const char* localidad){ strcpy(_localidad, localidad); }
//getters
const char* Persona::getDni(){ return _dni; }
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
string Persona::mostrarDatos(){
    string linea = string("DNI: ") + _dni
                    + "\nNombre: " + _nombre
                    + "\nApellido: " + _apellido
                    + "\nLocalidad: " + _localidad
                    + "\nFecha de Nacimiento: " + _fechaNacimiento.mostrarFecha();
                    + "\nEdad: " + to_string(getEdad()) + " años\n";
    return linea;
}

