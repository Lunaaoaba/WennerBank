#include "ArchivoTransacciones.h"
#include "Movimientos.h"
#include "config.h"         
#include "ArchivoCuentas.h"
#include "fecha.h"
#include "tiempo.h"
#include <cstdio>
#include <iostream>

using namespace std;

// ----------------------------------------------------------------------
//          FUNCIONES PARA MANEJO DE ARCHIVOS DE TRANSACCIONES
// ----------------------------------------------------------------------
bool guardarTransaccion(const Transaccion& transaccion){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones para guardar." << endl;
        return false;
    }
    fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
    fclose(archivo);
    return true;
}

int generarIdTransaccion(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    Transaccion reg;
    // Se recorre el archivo para encontrar el ID más alto 
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdTransaccion() > maxId){
            maxId = reg.getIdTransaccion();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

void listarTransacciones(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
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

bool buscarTransaccionId(int idTransaccion, Transaccion& transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    if(archivo == nullptr) return false;
    Transaccion reg;
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdTransaccion() == idTransaccion){
            transaccionEncontrada = reg;
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

int buscarTransaccionIdCuenta(int idCuenta, Transaccion listaTransacciones[], int maxTransacciones){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    if(archivo == nullptr) return 0;
    Transaccion reg;
    int contador = 0;
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){

        if(reg.getIdCuentaOrigen() == idCuenta || reg.getIdCuentaDestino() == idCuenta){
            if (contador < maxTransacciones) {
                listaTransacciones[contador] = reg;
                contador++;
            } else {
                break;
            }
        }
    }
    fclose(archivo);
    return contador;
}

// Función auxiliar para crear y guardar el registro de Transaccion
bool registrarMovimiento(int idCuentaOrigen, int idCuentaDestino, double monto){
    Transaccion nuevaTransaccion;
    nuevaTransaccion.setIdTransaccion(generarIdTransaccion());
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

// ----------------------------------------------------------------------
//          LOGICA DE NEGOCIO PARA TRANSACCIONES 
// ----------------------------------------------------------------------
bool realizarDeposito(double monto, int idCuenta){
    cuentaBancaria cuentaDestino;
    buscarCuentaId(idCuenta, cuentaDestino);

    if (cuentaDestino.getIdCuenta() != idCuenta) {
        cout << "ERROR: Cuenta de destino ID: " << idCuenta << " no encontrada." << endl;
        return false;
    }

    if(cuentaDestino.depositar(monto)){ 
        if(modificarCuenta(cuentaDestino)){
            return registrarMovimiento(0, idCuenta, monto);
        } else {
            cout << "ERROR: El deposito se realizó en memoria pero no se pudo guardar el saldo en el archivo." << endl;
            return false;
        }
    }
    return false; 
}

bool realizarRetiro(double monto, int idCuenta){
    cuentaBancaria cuentaOrigen;
    buscarCuentaId(idCuenta, cuentaOrigen);

    if (cuentaOrigen.getIdCuenta() != idCuenta) {
        cout << "ERROR: Cuenta de origen ID: " << idCuenta << " no encontrada." << endl;
        return false;
    }

    if(cuentaOrigen.retirar(monto)){
        if(modificarCuenta(cuentaOrigen)){
            return registrarMovimiento(idCuenta, 0, monto);
        } else {
            cout << "ERROR: El retiro se realizó en memoria pero no se pudo guardar el saldo en el archivo." << endl;
            return false;
        }
    }
    return false; 
}

bool realizarTransferencia(double monto, int idCuentaOrigen, int idCuentaDestino){
    if (idCuentaOrigen == idCuentaDestino) {
        cout << "ERROR: La cuenta de origen y destino deben ser diferentes." << endl;
        return false;
    }
    if (monto <= 0) {
        cout << "ERROR: El monto a transferir debe ser mayor a cero." << endl;
        return false;
    }

    cuentaBancaria cuentaOrigen;
    cuentaBancaria cuentaDestino;

    buscarCuentaId(idCuentaOrigen, cuentaOrigen);
    if (cuentaOrigen.getIdCuenta() != idCuentaOrigen) {
        cout << "ERROR: Cuenta de origen ID: " << idCuentaOrigen << " no encontrada." << endl;
        return false;
    }

    buscarCuentaId(idCuentaDestino, cuentaDestino);
    if (cuentaDestino.getIdCuenta() != idCuentaDestino) {
        cout << "ERROR: Cuenta de destino ID: " << idCuentaDestino << " no encontrada." << endl;
        return false;
    }


    if(!cuentaOrigen.retirar(monto)){
        cout << "ERROR: Saldo insuficiente en la cuenta de origen ID: " << idCuentaOrigen << "." << endl;
        return false;
    }

    if(!cuentaDestino.depositar(monto)){
        cout << "ERROR: Fallo al realizar el deposito en la cuenta de destino ID: " << idCuentaDestino << ". Se revierte el retiro." << endl;
        cuentaOrigen.depositar(monto);
        modificarCuenta(cuentaOrigen); 
        return false;
    }

    if(!modificarCuenta(cuentaOrigen) || !modificarCuenta(cuentaDestino)){
        cout << "ADVERTENCIA: Transferencia de saldo exitosa, pero falló al guardar una o ambas cuentas en archivo." << endl;
        return false;
    }

    return registrarMovimiento(idCuentaOrigen, idCuentaDestino, monto);
}