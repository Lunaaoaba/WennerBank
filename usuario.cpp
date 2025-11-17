#include "persona.h"
#include "usuario.h"
#include "ArchivoClientes.h"
#include "funcionesArchivos.h"
#include "funciones.h"
#include <iostream>
#include <cstring>
using namespace std;


//constructores
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
//setters
void Usuario::setMail(const char* mail){ strcpy(_mail, mail);}
void Usuario::setContrasena(const char* contrasena){ strcpy(_contrasena, contrasena); }
void Usuario::setUsuarioEliminado(bool UsuarioEliminado){ _UsuarioEliminado = UsuarioEliminado;}
//getters
const char* Usuario::getMail() const{ return _mail; }
const char* Usuario::getContrasena() const{ return _contrasena; }
bool Usuario::getUsuarioEliminado() const{ return _UsuarioEliminado; }
//otros
void Usuario::cargarDatos(){
    Persona::cargarDatos();
    cout << "Ingrese el mail: ";
    cin >> _mail;
    while(existeMail(_mail)){
        cout << "ERROR: Mail ya registrado." << endl;
        cout << "Ingrese el mail: ";
        cin >> _mail;
    }
    cout << "Ingrese la contrase" << char(164) << "a: ";
    validarCadenaLargo(_contrasena, 8, 20);
    _UsuarioEliminado = false; // Por defecto, al cargar un usuario, no esta eliminado
}
string Usuario::mostrarDatos() const{
    string datos = Persona::mostrarDatos();
    datos += "\nMail: " + string(_mail);
    // datos que no deberian mostrarse (solo con admin)
    // datos += "\nContrase" + string(1, char(164)) + "a: " + string(_contrasena);
    // datos += "\nUsuario Eliminado: " + string(_UsuarioEliminado ? "Si" : "No");
    return datos;
}
