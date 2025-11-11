#include "movimientos.h"
#include "config.h"
#include <cstring>
#include <iostream>
#include "fecha.h"
using namespace std;
//                         =====================
//                         =   TRANSACCIONES   =
//                         =====================

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE TRANSACCIONES
// ----------------------------------------------------------------------
bool guardarTransacciones(const Transaccion& transaccion){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
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
    while(fread(&reg, sizeof(Transaccion), 1, archivo)) if(reg.getIdTransaccion() > maxId) maxId = reg.getIdTransaccion();
    fclose(archivo);
    return maxId + 1;
}
// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE TRANSACCIONES
// ----------------------------------------------------------------------
void buscarTransaccionId(int idTransaccion, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){ 
        if(reg.getIdTransaccion() == idTransaccion){
            transaccionEncontrada = reg;
            fclose(archivo);
            return; // ¡Encontrado!
        }
    }

    fclose(archivo);
}
    }

void buscarTransaccionCuentaOrigen(int idCuentaOrigen, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdCuentaOrigen() == idCuentaOrigen){
            transaccionEncontrada = reg;
            fclose(archivo);
            return; 
        }
    }

    fclose(archivo);
}


void buscarTransaccionCuentaDestino(int idCuentaDestino, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        if(reg.getIdCuentaDestino() == idCuentaDestino){
            transaccionEncontrada = reg;
            fclose(archivo);
            return; 
        }
    }

    fclose(archivo);
}
}

void buscarTransaccionMonto(double monto, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){ 
        if(reg.getMonto() == monto){
            transaccionEncontrada = reg;
            fclose(archivo);
            return; 
        }
    }

    fclose(archivo);
}
}

void buscarTransaccionFecha(Fecha fechaTransaccion, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        // Usamos el método esIgual() de la clase Fecha para comparar la fecha.
        if(reg.getFechaTransaccion().esIgual(fechaTransaccion)){
            transaccionEncontrada = reg;
            fclose(archivo);
            return; 
        }
    }

    fclose(archivo);
}
}

void buscarTransaccionHora(Tiempo horaTransaccion, Transaccion &transaccionEncontrada){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "rb");
    Transaccion reg;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;

        while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){ 
        // Se asume que la clase Tiempo tiene un método bool esIgual(Tiempo).
        if(reg.getHoraTransaccion().esIgual(horaTransaccion)){ 
            transaccionEncontrada = reg;
            fclose(archivo);
            return; // ¡Encontrado!
        }
    }

    fclose(archivo);
}
}



// ----------------------------------------------------------------------
//             FUNCIONES PARA LAS TRANSACCIONES
// ----------------------------------------------------------------------



//                        =====================
//                        =     PRESTAMOS     =
//                        =====================
// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE PRESTAMOS
// ----------------------------------------------------------------------
// bool guardarPrestamos(const Prestamo& prestamo){
//     FILE* archivo = fopen(NOMBRE_ARCHIVO_PRESTAMOS, "ab");
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