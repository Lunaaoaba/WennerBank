// #include "persona.h"
#include "usuario.h"
#include <iostream>
#include <cstring>
using namespace std;


//constructores
Usuario::Usuario(){
    strcpy(_mail, "N/A");
    strcpy(_contrasena, "N/A");
    _UsuarioEliminado = false;
}
Usuario::Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* mail, const char* contrasena, bool UsuarioEliminado) : Persona(dni, nombre, apellido, localidad){
    strcpy(_mail, mail);
    strcpy(_contrasena, contrasena);
    _UsuarioEliminado = UsuarioEliminado;
}
Usuario::Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad) : Persona(dni, nombre, apellido, localidad){
    strcpy(_mail, "N/A");
    strcpy(_contrasena, "N/A");
    _UsuarioEliminado = false;
}
//setters
void Usuario::setMail(const char* mail){ strcpy(_mail, mail);}
void Usuario::setContrasena(const char* contrasena){ strcpy(_contrasena, contrasena); }
void Usuario::setUsuarioEliminado(bool UsuarioEliminado){ _UsuarioEliminado = UsuarioEliminado;}
//getters
const char* Usuario::getMail(){ return _mail; }
const char* Usuario::getContrasena(){ return _contrasena; }
bool Usuario::getUsuarioEliminado(){ return _UsuarioEliminado; }
//otros
void Usuario::mostrarDatos(){
    Persona::mostrarDatos(); // Muestra los datos heredados de Persona
    cout << "Mail: " << _mail << endl;
    // cout << "Contrasena: " << _contrasena << endl;
    cout << "Usuario Eliminado: " << (_UsuarioEliminado ? "Si" : "No") << endl;
}
