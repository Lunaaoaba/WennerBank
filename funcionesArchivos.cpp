#include <cstring>
#include <iostream>
#include "tipoUsuario.h"
#include "Fecha.h"
#include "Tiempo.h"
#include "administrador.h"
#include "cuentaBancaria.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "ArchivoMovimientos.h"

using namespace std;


void iniciarArchivos(){
// ARCHIVO CLIENTES
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if (archivoClientes == nullptr){ // si no existe, lo crea
        archivoClientes = fopen ("clientes.dat", "wb");
        if (archivoClientes == nullptr) {
            cout << "ERROR FATAL: No se pudo crear el archivo de clientes." << endl;
            exit(-1);
        }
        cout << "Archivo 'clientes.dat' no encontrado. Creando y guardando Cliente Banco..." << endl;
        // crear cliente del banco
        Cliente clienteBanco(
            10000000, // dni
            "Sistema", // nombre
            "WennerBank", // apellido
            "Central", // localidad
            Fecha(14, 11, 1987), // fecha "nacimiento" / "creacion del banco"
            "bancoWennerBank@mail.com", // mail
            "contrasenaSegura123", // contrasena
            false, // Usuario eliminado (obviamente falso)
            1 // idCliente
        );
        fwrite(&clienteBanco, sizeof(Cliente), 1, archivoClientes);
        fclose(archivoClientes);
    }
    else fclose(archivoClientes);

// ARCHIVO CUENTAS
    FILE* archivoCuentas = fopen("cuentas.dat", "rb");
    if (archivoCuentas == nullptr){ // si no existe, lo crea
        archivoCuentas = fopen ("cuentas.dat", "wb");
        if (archivoCuentas == nullptr) {
            cout << "ERROR FATAL: No se pudo crear el archivo de cuentas." << endl;
            exit(-1);
        }
        cout << "Archivo 'cuentas.dat' no encontrado. Creando y guardando Cuenta Banco..." << endl;
        // crear cuenta bancaria del banco
        cuentaBancaria cuentaBanco(
            1, // id cuenta
            1, // id cliente
            "Banco Central", // nombre cuenta
            "0000000000000000000000", // cvu
            "BANCO.CENTRAL.WENNER", // alias
            10000000.00, // saldo inicial
            false // cuenta eliminada
        );
        fwrite(&cuentaBanco, sizeof(cuentaBancaria), 1, archivoCuentas);
        fclose(archivoCuentas);
    }
    else fclose(archivoCuentas);

// ARCHIVO EMPLEADOS
    FILE* archivoEmpleados = fopen("empleados.dat", "ab"); // "ab" es mas seguro, crea si no existe
    if(archivoEmpleados != nullptr) fclose(archivoEmpleados);
    else cout << "ERROR FATAL: No se pudo crear el archivo de empleados." << endl;

// ARCHIVO TRANSACCIONES
    FILE* archivoTransacciones = fopen("transacciones.dat", "ab");
    if(archivoTransacciones != nullptr) fclose(archivoTransacciones);
    else cout << "ERROR FATAL: No se pudo crear el archivo de transacciones." << endl;

// ARCHIVO PRESTAMOS
    FILE* archivoPrestamos = fopen("prestamos.dat", "ab");
    if(archivoPrestamos != nullptr) fclose(archivoPrestamos);
    else cout << "ERROR FATAL: No se pudo crear el archivo de prestamos." << endl;
}


// para ver si el mail existe en algun usuario (cliente o empleado)
bool existeMail(const char* mail){
    // primero revisa si es el mail del admin
    Administrador* admin = Administrador::getInstancia();
    if (strcmp(admin->getMail(), mail) == 0){
        return true;
    }
    // busca mail cliente q ya exista
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
    // busca mail empleado q ya exista
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


// --- LOGIN ---

bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado){
    if(!buscarCliente("MAIL", mail, clienteEncontrado)){
        cout << "ERROR: Mail incorrecto." << endl;
        return false;
    }
    if(clienteEncontrado.getUsuarioEliminado()){
        cout << "ERROR: El cliente con mail " << mail << " esta eliminado." << endl;
        return false;
    }
    if(strcmp(clienteEncontrado.getContrasena(), contrasena) != 0){
        cout << "ERROR: Contrase" << char(164) << "a incorrecta." << endl;
        return false;
    }

    return true;
}

bool validarLoginEmpleado(int legajo, const char* contrasena, Empleado& empleadoEncontrado){
    Administrador* admin = Administrador::getInstancia();
    if(admin->getLegajo() == legajo){
        if(strcmp(admin->getContrasena(), contrasena) == 0){
            return true;
        }
        else return false;
    }

    if(!buscarEmpleado("LEGAJO", legajo, empleadoEncontrado)){
        cout << "ERROR: Empleado no encontrado." << endl;
        return false;
    }
    if(empleadoEncontrado.getUsuarioEliminado()){
        cout << "ERROR: Empleado no encontrado." << endl;
        return false;
    }
    if(strcmp(empleadoEncontrado.getContrasena(), contrasena) != 0){
        cout << "ERROR: Contrase" << char(164) << "a incorrecta." << endl;
        return false;
    }

    return true;
}

// para comparar dos fechas
bool compararFechas(const Fecha& fecha1, const Fecha& fecha2){
    if((fecha1.getDia() == fecha2.getDia())
    && (fecha1.getMes() == fecha2.getMes())
    && (fecha1.getAnio() == fecha2.getAnio())){
    return true;
    }
    else return false;
}

// para comparar dos horarios
bool compararHorarios(const Tiempo& tiempo1, const Tiempo& tiempo2){
    if((tiempo1.getHora() == tiempo2.getHora())
    && (tiempo1.getMinuto() == tiempo2.getMinuto())
    && (tiempo1.getSegundo() == tiempo2.getSegundo())){
    return true;
    }
    else return false;
}

