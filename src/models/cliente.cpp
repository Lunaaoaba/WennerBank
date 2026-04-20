#include <iostream>
#include <cstring>
#include "cliente.h"
#include "usuario.h"
#include "archivoClientes.h"
#include "funciones.h"

using namespace std;

Cliente::Cliente(){ _idCliente = 0; }
Cliente::Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente) : Usuario(dni, nombre, apellido, localidad, fechaNacimiento, mail, contrasena, estado){
    _idCliente = idCliente;
}

int Cliente::getIdCliente() const{ return _idCliente; }

string Cliente::mostrarDatos() const{
    char idFormateado[12];
    formatearId(idFormateado, "CL-", _idCliente, 6);
    string datos = Usuario::mostrarDatos();
    datos += "\nID Cliente: " + string(idFormateado);
    return datos;
}