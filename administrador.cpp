#include "administrador.h" // Incluye la declaración de la clase
#include "funciones.h"     // Para llamar a las funciones de gestión de archivos
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

Administrador::Administrador() : Empleado(){
    setLegajo(10000000);
    setNombre("Admin");
    setApellido("Sistema");
    setLocalidad("Central");
    setFechaNacimiento(Fecha(1, 1, 2000));
    setMail("admin@wennerbank.com");
    setContrasena("culo");
    setUsuarioEliminado(false);
    strcpy(_claveMaestra, "wennerbank_master_key_2025");
    _permisosGlobales = true;
}

const char* Administrador::getClaveMaestra(){ return _claveMaestra; }

bool Administrador::getPermisosGlobales(){ return _permisosGlobales; }

// METODOS UNICOS DEL ADMINISTRADOR

void Administrador::crearEmpleado(){
    Empleado nuevoEmpleado;
    nuevoEmpleado.cargarDatos();
    // agregarEmpleadoArchivo(nuevoEmpleado);
}

// etc