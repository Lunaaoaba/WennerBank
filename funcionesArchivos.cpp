#include "funcionesArchivos.h"
#include "congif.h"
#include "cuentaBancaria.h"
#include "movimientos.h"
#include "tipoUsuario.h"
#include <fstream>
#include <iostream>

using namespace std;

bool guardarClientes(const Cliente& cliente){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de clientes." << endl;
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdCliente(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CLIENTES, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1; // si no existe el archivo el primer id es 1
    
    Cliente reg;
    while (fread(&reg, sizeof(Cliente), 1, archivo) == 1){
        if(reg.getIdCliente() > maxId){
            maxId = reg.getIdCliente();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

bool guardarEmpleados(const Empleado& empleado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de empleados." << endl;
        return false;
    }
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
    fclose(archivo);
    return true;
}

bool guardarCuentas(const cuentaBancaria& cuenta){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de cuentas." << endl;
        return false;
    }
    fwrite(&cuenta, sizeof(cuentaBancaria), 1, archivo);
    fclose(archivo);
    return true;
}

bool guardarTransacciones(const Transaccion& transaccion){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de transacciones." << endl;
        return false;
    }
    fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
    fclose(archivo);
    return true;
}

bool guardarPrestamos(const Prestamo& prestamo){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_PRESTAMOS, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de prestamos." << endl;
        return false;
    }
    fwrite(&prestamo, sizeof(Prestamo), 1, archivo);
    fclose(archivo);
    return true;
}
