#include <iostream>
#include "tipoUsuario.h"
#include "Fecha.h"
#include "Tiempo.h"
#include "administrador.h"
#include "cuentaBancaria.h"
#include <cstring>

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
    FILE* archivoEmpleados = fopen("empleados.dat", "ab"); // "ab" es más seguro, crea si no existe
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
    // busca mail cliente q ya exista
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        Cliente clienteActual;
        while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
            if (strcmp(clienteActual.getMail(), mail) == 0){
                fclose(archivoClientes);
                return true; // existe el mail entonces no se puede usar ese mail
            }
        }
        fclose(archivoClientes);
    }
    // busca mail empleado q ya eexista
    FILE* archivoEmpleados = fopen("empleados.dat", "rb");
        if(archivoEmpleados != nullptr){
        Empleado empleadoActual;
        // if(strcmp(empleadoActual.getMail(), terminar dsp para q compare con el admin, esq como es singleton nose como se hace deaa)
        while(fread(&empleadoActual, sizeof(Empleado), 1, archivoEmpleados) == 1){
            if (strcmp(empleadoActual.getMail(), mail) == 0){
                fclose(archivoEmpleados);
                return true; // existe el mail entonces no se puede usar ese mail
            }
        }
        fclose(archivoEmpleados);
    }
    return false;
}

bool validarLoginCliente(const char* mail, const char* contrasena, Cliente& clienteEncontrado){
    FILE* archivo = fopen("clientes.dat", "rb");
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
    FILE* archivo = fopen("empleados.dat", "rb");
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

// para comparar dos fechas
bool compararFechas(const Fecha& fecha1, const Fecha& fecha2){
    if((fecha1.getDia() == fecha2.getDia()) && (fecha1.getMes() == fecha2.getMes()) && (fecha1.getAnio() == fecha2.getAnio())){
    return true;
    }
    else return false;
}

// para comparar dos horarios
bool compararHorarios(const Tiempo& tiempo1, const Tiempo& tiempo2){
    if((tiempo1.getHora() == tiempo2.getHora()) && (tiempo1.getMinuto() == tiempo2.getMinuto()) && (tiempo1.getSegundo() == tiempo2.getSegundo())){
    return true;
    }
    else return false;
}

