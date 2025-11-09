#include "ArchivoCuentas.h"
#include "cuentaBancaria.h"
#include "config.h"
#include <cstdio>
#include <iomanip>
using namespace std;

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE CUENTAS
// ----------------------------------------------------------------------
bool guardarCuentas(const cuentaBancaria& cuenta){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    fwrite(&cuenta, sizeof(cuentaBancaria), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdCuenta(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_CUENTAS, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    cuentaBancaria reg;
    while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1) if(reg.getIdCuenta() > maxId) maxId = reg.getIdCliente();
    fclose(archivo);
    return maxId + 1;
}

cuentaBancaria crearCuenta(){
    cuentaBancaria nuevaCuenta;
    nuevaCuenta.cargarDatos();
    nuevaCuenta.setIdCuenta(generarIdCuenta());
    guardarCuentas(nuevaCuenta);
    return nuevaCuenta;
}

// void modificarCuenta(cuentaBancaria* cuentaModificada){

// }

void listarCuentas(){

}

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE CUENTAS
// ----------------------------------------------------------------------

// void buscarCuentaId(int idCuenta, cuentaBancaria &cuentaEncontrada){

// }
// void buscarCuentaClienteId(int idCliente, cuentaBancaria &cuentaEncontrada){

// }
// void buscarCuentaCvu(const char* cvu, cuentaBancaria &cuentaEncontrada){

// }
// void buscarCuentaAlias(const char* alias, cuentaBancaria &cuentaEncontrada){

// }
// void buscarCuentaNombre(const char* nombreCuenta, cuentaBancaria &cuentaEncontrada){

// }

// // por las dudas
// void buscarCuentaSaldo(double saldo, cuentaBancaria &cuentaEncontrada){

// }

//----------------------------------------------------------------------
//             FUNCIONES PARA LA CUENTA BANCARIA
// ----------------------------------------------------------------------

void mostrarSaldo (double saldo) {
cout<<"Su balance es: $ " <<setprecision(2) << fixed << saldo << endl;
}