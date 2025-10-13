#include "persona.h"
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
Persona::Persona(const char* dni, const char* nombre, const char* apellido, const char* localidad){
    strcpy(_dni, dni);
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_localidad, localidad);
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
//otros
void Persona::mostrarDatos(){
    cout << "DNI: " << _dni << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Localidad: " << _localidad << endl;
}

