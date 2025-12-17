#include <iostream>
#include <cstring>
#include "persona.h"
#include "usuario.h"
#include "ArchivoClientes.h"
#include "funcionesArchivos.h"
#include "funciones.h"

using namespace std;


Usuario::Usuario(){
    strcpy(_mail, "N/A");
    strcpy(_contrasena, "N/A");
    _UsuarioEliminado = false;
}
Usuario::Usuario(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado) : Persona(dni, nombre, apellido, localidad, fechaNacimiento){
    strcpy(_mail, mail);
    strcpy(_contrasena, contrasena);
    _UsuarioEliminado = UsuarioEliminado;
}

void Usuario::setMail(const char* mail){ strcpy(_mail, mail);}
void Usuario::setContrasena(const char* contrasena){ strcpy(_contrasena, contrasena); }
void Usuario::setUsuarioEliminado(bool UsuarioEliminado){ _UsuarioEliminado = UsuarioEliminado;}

const char* Usuario::getMail() const{ return _mail; }
const char* Usuario::getContrasena() const{ return _contrasena; }
bool Usuario::getUsuarioEliminado() const{ return _UsuarioEliminado; }

string Usuario::mostrarDatos() const{
    string datos = Persona::mostrarDatos();
    datos += "\nMail: " + string(_mail);
    return datos;
}
