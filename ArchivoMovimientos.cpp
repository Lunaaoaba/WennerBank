#include "movimientos.h"
#include "cuentaBancaria.h"
#include <cstring>
#include <iostream>
#include "fecha.h"
using namespace std;


// Empezar cuando se termine con ArchivoClientes -> ArchivoEmpleados -> ArchivoCuentas
// recien ahi se puede empezar con este archivo

//                         =====================
//                         =   TRANSACCIONES   =
//                         =====================

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE TRANSACCIONES
// ----------------------------------------------------------------------
bool guardarTransaccion(const Transaccion& transaccion){
    FILE* archivo = fopen("transacciones.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return false;
    }
    fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdTransaccion(){
    FILE* archivo = fopen("transacciones.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    Transaccion reg;
    while(fread(&reg, sizeof(Transaccion), 1, archivo)) if(reg.getIdTransaccion() > maxId) maxId = reg.getIdTransaccion();
    fclose(archivo);
    return maxId + 1;
}

// Transaccion crearTransaccion(){}

// inutilizable por ahora / revisar despues
void listarTransacciones(){
    FILE* archivo = fopen("transacciones.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones para listar." << endl;
        return;
    }
    Transaccion reg;
    cout << "--- Listado de Transacciones ---" << endl;
    while (fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        cout << "ID Transaccion: " << reg.getIdTransaccion() << endl;
        cout << "Cuenta Origen: " << reg.getIdCuentaOrigen() << endl;
        cout << "Cuenta Destino: " << reg.getIdCuentaDestino() << endl;
        cout << "Monto: " << reg.getMonto() << endl;
        cout << "Fecha: " << reg.getFechaTransaccion().mostrarFecha() << endl;
        cout << "Hora: " << reg.getHoraTransaccion().mostrarTiempo() << endl;
        cout << "---------------------------------" << endl;
    }
    fclose(archivo);
}


// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE TRANSACCIONES
// ----------------------------------------------------------------------
// va a usar la misma logica de busqueda como en ArchivoClientes.cpp
// el q usa int
// bool buscarTransaccion(){
// }
// // el q usa char
// bool buscarTransaccion(){
// }
// bool buscarTransaccionId(int idTransaccion, Transaccion &transaccionEncontrada){
// }
// bool buscarTransaccionIdCuenta(int idCuenta, Transaccion listaTransacciones[], int maxTransacciones){
// }
// bool buscarTransaccionCuentaOrigen(int idCuentaOrigen, Transaccion &transaccionEncontrada){
// }
// bool buscarTransaccionCuentaDestino(int idCuentaDestino, Transaccion &transaccionEncontrada){
// }
// bool buscarTransaccionMonto(double monto, Transaccion &transaccionEncontrada){
// }
// bool buscarTransaccionFecha(Fecha fechaTransaccion, Transaccion &transaccionEncontrada){
// }
// bool buscarTransaccionHora(Tiempo horaTransaccion, Transaccion &transaccionEncontrada){
// }




// ----------------------------------------------------------------------
//             FUNCIONES PARA LAS TRANSACCIONES
// ----------------------------------------------------------------------

// revisar
bool registrarMovimiento(int idCuentaOrigen, int idCuentaDestino, double monto){
    Transaccion nuevaTransaccion;
    // nuevaTransaccion.setIdTransaccion(generarIdTransaccion());
    nuevaTransaccion.setIdCuentaOrigen(idCuentaOrigen);
    nuevaTransaccion.setIdCuentaDestino(idCuentaDestino);
    nuevaTransaccion.setMonto(monto);

    Fecha fechaActual;
    fechaActual.cargarFechaActual();
    Tiempo horaActual;
    horaActual.cargarTiempoActual();

    nuevaTransaccion.setFechaTransaccion(fechaActual);
    nuevaTransaccion.setHoraTransaccion(horaActual);

    if (guardarTransaccion(nuevaTransaccion)) {
        cout << "Transaccion " << nuevaTransaccion.getIdTransaccion() << " registrada con exito." << endl;
        return true;
    }
    cout << "ERROR: No se pudo registrar la transaccion." << endl;
    return false;
}

// revisar
// bool realizarDeposito(double monto, int idCuenta){
//     cuentaBancaria cuentaDestino;
//     buscarCuentaId(idCuenta, cuentaDestino); // aca da error

//     if (cuentaDestino.getIdCuenta() != idCuenta) {
//         cout << "ERROR: Cuenta de destino ID: " << idCuenta << " no encontrada." << endl;
//         return false;
//     }

//     if(cuentaDestino.depositar(monto)){ 
//         if(modificarCuenta(cuentaDestino)){ // aca da error
//             return registrarMovimiento(0, idCuenta, monto);
//         } else {
//             cout << "ERROR: El deposito se realizó en memoria pero no se pudo guardar el saldo en el archivo." << endl;
//             return false;
//         }
//     }
//     return false; 
// }

// revisar
// bool realizarRetiro(double monto, int idCuenta){
//     cuentaBancaria cuentaOrigen;
//     buscarCuentaId(idCuenta, cuentaOrigen);

//     if (cuentaOrigen.getIdCuenta() != idCuenta) {
//         cout << "ERROR: Cuenta de origen ID: " << idCuenta << " no encontrada." << endl;
//         return false;
//     }

//     if(cuentaOrigen.retirar(monto)){
//         if(modificarCuenta(cuentaOrigen)){
//             return registrarMovimiento(idCuenta, 0, monto);
//         } else {
//             cout << "ERROR: El retiro se realizó en memoria pero no se pudo guardar el saldo en el archivo." << endl;
//             return false;
//         }
//     }
//     return false; 
// }

// revisar
// bool realizarTransferencia(double monto, int idCuentaOrigen, int idCuentaDestino){
//     if (idCuentaOrigen == idCuentaDestino) {
//         cout << "ERROR: La cuenta de origen y destino deben ser diferentes." << endl;
//         return false;
//     }
//     if (monto <= 0) {
//         cout << "ERROR: El monto a transferir debe ser mayor a cero." << endl;
//         return false;
//     }

//     cuentaBancaria cuentaOrigen;
//     cuentaBancaria cuentaDestino;

//     buscarCuentaId(idCuentaOrigen, cuentaOrigen);
//     if (cuentaOrigen.getIdCuenta() != idCuentaOrigen) {
//         cout << "ERROR: Cuenta de origen ID: " << idCuentaOrigen << " no encontrada." << endl;
//         return false;
//     }

//     buscarCuentaId(idCuentaDestino, cuentaDestino);
//     if (cuentaDestino.getIdCuenta() != idCuentaDestino) {
//         cout << "ERROR: Cuenta de destino ID: " << idCuentaDestino << " no encontrada." << endl;
//         return false;
//     }


//     if(!cuentaOrigen.retirar(monto)){
//         cout << "ERROR: Saldo insuficiente en la cuenta de origen ID: " << idCuentaOrigen << "." << endl;
//         return false;
//     }

//     if(!cuentaDestino.depositar(monto)){
//         cout << "ERROR: Fallo al realizar el deposito en la cuenta de destino ID: " << idCuentaDestino << ". Se revierte el retiro." << endl;
//         cuentaOrigen.depositar(monto);
//         modificarCuenta(cuentaOrigen); 
//         return false;
//     }

//     if(!modificarCuenta(cuentaOrigen) || !modificarCuenta(cuentaDestino)){
//         cout << "ADVERTENCIA: Transferencia de saldo exitosa, pero falló al guardar una o ambas cuentas en archivo." << endl;
//         return false;
//     }

//     return registrarMovimiento(idCuentaOrigen, idCuentaDestino, monto);
// }


// ======================================================================================

//                        =====================
//                        =     PRESTAMOS     =
//                        =====================
// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE PRESTAMOS
// ----------------------------------------------------------------------
// bool guardarPrestamos(const Prestamo& prestamo){
//     FILE* archivo = fopen("prestamos.dat", "ab");
//     if(archivo == nullptr){
//         cout << "Error al abrir el archivo de prestamos." << endl;
//         return false;
//     }
//     fwrite(&prestamo, sizeof(Prestamo), 1, archivo);
//     fclose(archivo);
//     return true;
// }




// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE PRESTAMOS
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
//             FUNCIONES PARA LOS PRESTAMOS
// ----------------------------------------------------------------------