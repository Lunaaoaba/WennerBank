#include <iostream>
#include "tipoUsuario.h"
#include "administrador.h"
#include "config.h"
#include <cstring>

using namespace std;

// para ver si el mail existe en algun usuario (cliente o empleado)
bool existeMail(const char* mail){
    // busca mail cliente q ya exista
    FILE* archivoClientes = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivoClientes != nullptr){
        Cliente reg;
        while(fread(&reg, sizeof(Cliente), 1, archivoClientes) == 1){
            if (strcmp(reg.getMail(), mail) == 0){
                fclose(archivoClientes);
                return true; // existe el mail entonces no se puede usar ese mail
            }
        }
        fclose(archivoClientes);
    }
    // busca mail empleado q ya eexista
    FILE* archivoEmpleados = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "rb");
        if(archivoEmpleados != nullptr){
        Empleado reg;
        while(fread(&reg, sizeof(Empleado), 1, archivoEmpleados) == 1){
            if (strcmp(reg.getMail(), mail) == 0){
                fclose(archivoEmpleados);
                return true; // existe el mail entonces no se puede usar ese mail
            }
        }
        fclose(archivoEmpleados);
    }
    return false;
}

bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No existen registros de usuarios." << endl;
        return false;
    }
    bool mailEncontrado = false;
    
    while(fread(&clienteEncontrado, sizeof(Cliente), 1, archivo) == 1){
        if(strcmp(clienteEncontrado.getMail(), mail) == 0){
            mailEncontrado = true;
            if(strcmp(clienteEncontrado.getContrasena(), contrasena) == 0){
                fclose(archivo);
                return true;
            }
            else{
                cout << "ERROR: Contrase" << char(164) << "a incorrecta." << endl;
                fclose(archivo);
                return false;
            }
        }
    }
    if(!mailEncontrado) cout << "ERROR: Mail incorrecto." << endl;
    fclose(archivo);
    return false;
}

bool validarLoginEmpleado(int legajo, const char* contrasena, Empleado& empleadoEncontrado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No existen registros de empleados." << endl;
        return false;
    }
    bool legajoEncontrado = false;
        while(fread(&empleadoEncontrado, sizeof(Empleado), 1, archivo) == 1){
        if(empleadoEncontrado.getLegajo() == legajo){
            legajoEncontrado = true;
            if(strcmp(empleadoEncontrado.getContrasena(), contrasena) == 0){
                fclose(archivo);
                return true;
            }
            else{
                cout << "ERROR: Contrase" << char(164) << "a incorrecta." << endl;
                fclose(archivo);
                return false;
            }
        }
    }
    if(!legajoEncontrado) cout << "ERROR: Legajo incorrecto." << endl;
    fclose(archivo);
    return false;
}



