#include "administrador.h"
#include "funciones.h"
#include <iostream>
#include <cstring>


Administrador* Administrador::instancia = nullptr;
Administrador* Administrador::getInstancia(){
    if (instancia == nullptr){
        instancia = new Administrador();
    }
    return instancia;
}
Administrador::Administrador() : Empleado(
    10000000,
    "Admin",
    "Sistema",
    "Central",
    Fecha(26,6,1985),
    "admin1234@gmail.com"
    ,"contraSeguraAdmin5678",
    false,
    1
){ _permisosGlobales = true; }
bool Administrador::getPermisosGlobales() const{ return _permisosGlobales; }