#include <cstring>
#include <iostream>
#include "cliente.h"
#include "empleado.h"
#include "fecha.h"
#include "tiempo.h"
#include "administrador.h"
#include "cuentaBancaria.h"
#include "archivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "archivoTransacciones.h"
#include "funciones.h"

using namespace std;


bool existeMail(const char* mail){
    Administrador* admin = Administrador::getInstancia();
    if (strcmp(admin->getMail(), mail) == 0){
        return true;
    }
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        Cliente clienteActual;
        while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
            if (strcmp(clienteActual.getMail(), mail) == 0){
                fclose(archivoClientes);
                return true;
            }
        }
        fclose(archivoClientes);
    }
    FILE* archivoEmpleados = fopen("empleados.dat", "rb");
        if(archivoEmpleados != nullptr){
        Empleado empleadoActual;
        while(fread(&empleadoActual, sizeof(Empleado), 1, archivoEmpleados) == 1){
            if (strcmp(empleadoActual.getMail(), mail) == 0){
                fclose(archivoEmpleados);
                return true;
            }
        }
        fclose(archivoEmpleados);
    }
    return false;
}

bool existeDniCliente(int dni){
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        Cliente clienteActual;
        while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
            if (clienteActual.getDni() == dni){
                fclose(archivoClientes);
                return true;
            }
        }
        fclose(archivoClientes);
    }
    return false;
}

bool existeDniEmpleado(int dni){
    Administrador* admin = Administrador::getInstancia();
    if (admin->getDni() == dni) return true;
    
    FILE* archivoEmpleados = fopen("empleados.dat", "rb");
        if(archivoEmpleados != nullptr){
            Empleado empleadoActual;
            while(fread(&empleadoActual, sizeof(Empleado), 1, archivoEmpleados) == 1){
                if (empleadoActual.getDni() == dni){
                    fclose(archivoEmpleados);
                    return true;
                }
            }
        fclose(archivoEmpleados);
    }
    return false;
}

bool existeCvu(const char* cvu){
    FILE* archivoCuentas = fopen("cuentas.dat", "rb");
    if(archivoCuentas == nullptr) return false;

    cuentaBancaria cuentaActual;
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivoCuentas) == 1){
        if (strcmp(cuentaActual.getCvu(), cvu) == 0){
            fclose(archivoCuentas);
            return true;
        }
    }
    fclose(archivoCuentas);
    return false;
}

bool existeAlias(const char* alias){
    FILE* archivoCuentas = fopen("cuentas.dat", "rb");
    if(archivoCuentas == nullptr) return false;

    cuentaBancaria cuentaActual;
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivoCuentas) == 1){
        if (strcmp(cuentaActual.getAlias(), alias) == 0){
            fclose(archivoCuentas);
            return true;
        }
    }
    fclose(archivoCuentas);
    return false;
}

bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado){
    ArchivoClientes obj;
    if(!obj.buscarCliente("MAIL", mail, clienteEncontrado)){
        return false;
    }
    if(clienteEncontrado.getUsuarioEliminado()){
        return false;
    }
    if(strcmp(clienteEncontrado.getContrasena(), contrasena) != 0){
        return false;
    }

    return true;
}

bool validarLoginEmpleado(int legajo, const char* contrasena, Empleado& empleadoEncontrado){
    Administrador* admin = Administrador::getInstancia();
    if(admin->getLegajo() == legajo){
        if(strcmp(admin->getContrasena(), contrasena) == 0){
            empleadoEncontrado = *admin;
            return true;
        }
        else return false;
    }

    ArchivoEmpleados obj;
    if(!obj.buscarEmpleado("LEGAJO", legajo, empleadoEncontrado)){
        return false;
    }
    if(empleadoEncontrado.getUsuarioEliminado()){
        return false;
    }
    if(strcmp(empleadoEncontrado.getContrasena(), contrasena) != 0){
        return false;
    }

    return true;
}

bool compararFechas(const Fecha& fecha1, const Fecha& fecha2){
    if((fecha1.getDia() == fecha2.getDia())
    && (fecha1.getMes() == fecha2.getMes())
    && (fecha1.getAnio() == fecha2.getAnio())){
    return true;
    }
    else return false;
}

bool compararHorarios(const Tiempo& tiempo1, const Tiempo& tiempo2){
    if((tiempo1.getHora() == tiempo2.getHora())
    && (tiempo1.getMinuto() == tiempo2.getMinuto())
    && (tiempo1.getSegundo() == tiempo2.getSegundo())){
    return true;
    }
    else return false;
}

