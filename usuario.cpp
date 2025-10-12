// #include "persona.h"
#include "usuario.h"
#include <iostream>
#include <cstring>
using namespace std;


//constructores
Usuario::Usuario(){
    strcpy(_mail, "N/A");
    strcpy(_contrasena, "N/A");
    _eliminado = false;
}
Usuario::Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* mail, const char* contrasena, bool eliminado) : Persona(dni, nombre, apellido, localidad){
    strcpy(_mail, mail);
    strcpy(_contrasena, contrasena);
    _eliminado = eliminado;
}
Usuario::Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad) : Persona(dni, nombre, apellido, localidad){
    strcpy(_mail, "N/A");
    strcpy(_contrasena, "N/A");
    _eliminado = false;
}
//setters
void Usuario::setMail(const char* mail){ strcpy(_mail, mail);}
void Usuario::setContrasena(const char* contrasena){ strcpy(_contrasena, contrasena); }
void Usuario::setEliminado(bool eliminado){ _eliminado = eliminado;}
//getters
const char* Usuario::getMail(){ return _mail; }
const char* Usuario::getContrasena(){ return _contrasena; }
bool Usuario::getEliminado(){ return _eliminado; }