#include "personaUsuario.h"
#include <iostream>
#include <cstring>
using namespace std;

Usuario::Usuario(){
    _idCliente = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_localidad, "");
    strcpy(_mail, "");
    strcpy(_contrasena, "");
    _eliminado = false;
}

Usuario::Usuario(int idCliente, const char* nombre, const char* apellido, const char* localidad, const char* mail, const char* contrasena, bool  eliminado){
    _idCliente = idCliente;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_localidad, localidad);
    strcpy(_mail, mail);
    strcpy(_contrasena, contrasena);
    _eliminado = eliminado;
}
//setters
void Usuario::setIdCliente(int idCliente){ _idCliente = idCliente; }

void Usuario::setNombre(const char* nombre){ strcpy(_nombre, nombre); }

void Usuario::setApellido(const char* apellido){ strcpy(_apellido, apellido); }

void Usuario::setLocalidad(const char* localidad){ strcpy(_localidad, localidad); }

void Usuario::setMail(const char* mail){ strcpy(_mail, mail); }

void Usuario::setContrasena(const char* contrasena){ strcpy(_contrasena, contrasena); }

void Usuario::setEliminado(bool eliminado){ _eliminado = eliminado; }

//getters
int Usuario::getIdCliente(){ return _idCliente; }

const char* Usuario::getNombre(){ return _nombre; }

const char* Usuario::getApellido(){ return _apellido; }

const char* Usuario::getLocalidad(){ return _localidad; }

const char* Usuario::getMail(){ return _mail; }

const char* Usuario::getContrasena(){ return _contrasena; }

bool Usuario::getEliminado(){ return _eliminado; }
