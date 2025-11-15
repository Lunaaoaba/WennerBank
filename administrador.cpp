#include "administrador.h"
#include "funciones.h"
#include <iostream>
#include <cstring>


Administrador* Administrador::instancia = nullptr;
Administrador* Administrador::getInstancia() {
    // si es la primera vez que se llama la función, 'instancia' sera nullptr.
    if (instancia == nullptr) {
        // Creamos el único objeto Administrador en memoria dinámica (Heap).
        // 'new' llama al constructor privado.
        instancia = new Administrador();
    }
    // Para todas las llamadas siguientes, simplemente devolvemos el puntero al objeto que ya existe.
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
){
    _permisosGlobales = true;
}
bool Administrador::getPermisosGlobales(){ return _permisosGlobales; }

// METODOS UNICOS DEL ADMINISTRADOR

// etc