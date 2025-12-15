#include <cstring>
#include <iostream>
#include "transaccion.h"
#include "cuentaBancaria.h"
#include "fecha.h"
#include "archivoTransacciones.h"

using namespace std;

ArchivoTransacciones::ArchivoTransacciones(const char* nombre){ strcpy(_nombreArchivo, nombre); }

bool ArchivoTransacciones::guardarTransaccion(const Transaccion& transaccion){
    FILE* archivo = fopen(_nombreArchivo, "ab");
    if(archivo == nullptr) return false;
    fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
    fclose(archivo);
    return true;
}

int ArchivoTransacciones::generarIdTransaccion(){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    
    Transaccion reg;
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdTransaccion() > maxId){
            maxId = reg.getIdTransaccion();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

void ArchivoTransacciones::listarTransacciones(){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }

    Transaccion transaccionActual;
    int i = 0;
    cout << "----- LISTADO DE TRANSACCIONES -----" << endl;
    cout << "------------------------------------" << endl << endl;

    while (fread(&transaccionActual, sizeof(Transaccion), 1, archivo) == 1){
        cout << transaccionActual.mostrarDatos() << endl;
        cout << endl << "------------------------------------" << endl << endl;
        i++;
    }
    if(i == 0){
        cout << "No hay transacciones registradas." << endl;
        cout << "--------------------------------" << endl << endl;
    }
    else cout << "Total: " << i << " transacciones" << endl;

    fclose(archivo);
}

void ArchivoTransacciones::listarTransaccionesCuenta(int idCuenta){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }

    Transaccion transaccionActual;
    int i = 0;
    cout << "----- LISTADO DE TRANSACCIONES DE LA CUENTA " << idCuenta << " -----" << endl;
    cout << "--------------------------------------------------------" << endl << endl;

    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivo) == 1){
        if(transaccionActual.getIdCuentaOrigen() == idCuenta || transaccionActual.getIdCuentaDestino() == idCuenta){
            cout << transaccionActual.mostrarDatos() << endl;
            // Indicar si es entrada o salida
            if(transaccionActual.getIdCuentaOrigen() == idCuenta && transaccionActual.getIdCuentaDestino() == idCuenta) cout << "[INTERNO]" << endl;
            else if(transaccionActual.getIdCuentaOrigen() == idCuenta) cout << "[SALIDA -]" << endl;
            else cout << "[ENTRADA +]" << endl;
            
            cout << "------------------------------------" << endl << endl;
            i++;
        }
    }
    if(i == 0){
        cout << "No hay transacciones registradas." << endl;
        cout << "--------------------------------" << endl << endl;
    }
    else cout << "Total: " << i << " transacciones" << endl;

    fclose(archivo);
}

bool ArchivoTransacciones::buscarTransaccion(int idTransaccion, Transaccion& encontrada){
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo == nullptr) return false;

    while(fread(&encontrada, sizeof(Transaccion), 1, archivo) == 1){
        if(encontrada.getIdTransaccion() == idTransaccion){
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}