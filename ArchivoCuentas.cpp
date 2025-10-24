#include "ArchivoCuentas.h"
#include "cuentaBancaria.h"
#include "config.h"
#include <cstdio>
using namespace std;

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

// int generarIdCuenta(){

// }

cuentaBancaria crearCuenta(){
    cuentaBancaria nuevaCuenta;
    // nuevaCuenta.cargarDatos();
    // nuevaCuenta.setIdCuenta(generarIdCuenta());
    // guardarCuentas(nuevaCuenta);
    return nuevaCuenta;
}