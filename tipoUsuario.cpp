#include "tipoUsuario.h"
#include "usuario.h"
#include <iostream>
#include <cstring>
using namespace std;

//CLIENTE
//constructores
Cliente::Cliente(){ strcpy(_idCliente, "0000"); }
Cliente::Cliente(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* idCliente) : Usuario(dni, nombre, apellido, localidad){ strcpy(_idCliente, idCliente); }
//set
void Cliente::setIdCliente(const char* idCliente){ strcpy(_idCliente, idCliente); }
//get
const char* Cliente::getIdCliente(){ return _idCliente; }


//EMPLEADO
//constructores
Empleado::Empleado(){
    strcpy(_legajo, "00000");
    strcpy(_claveOperacion, "N/A");
}
Empleado::Empleado(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* legajo, const char* claveOperacion) : Usuario(dni, nombre, apellido, localidad){
    strcpy(_legajo, legajo);
    strcpy(_claveOperacion, claveOperacion);
}
 //setters
void Empleado::setLegajo(const char* legajo){ strcpy(_legajo, legajo); }    
void Empleado::setClaveOperacion(const char* claveOperacion){ strcpy(_claveOperacion, claveOperacion); }
 //getters
    const char* Empleado::getLegajo(){ return _legajo; }
    const char* Empleado::getClaveOperacion(){ return _claveOperacion; }

