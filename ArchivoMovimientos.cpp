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
            // (!!!) preferiblemente no crear nuevos metodos a las clases solo para comparaciones simples o cosas que tranquilamente pueden ser funciones.
            // llamaron la atencion sobre algo similar (por no decir lo mismo) a otro equipo con el aviso de que se recursaba directamente la materia.
            Fecha fecha = reg.getFechaTransaccion();
            if((fecha.getDia() == fechaTransaccion.getDia()) && (fecha.getMes() == fechaTransaccion.getMes()) && (fecha.getAnio() == fechaTransaccion.getAnio())){
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
    }
    while(fread(&reg, sizeof(Transaccion), 1, archivo) == 1){
        Tiempo hora = reg.getHoraTransaccion();
        // (!!!) preferiblemente no crear nuevos metodos a las clases solo para comparaciones simples o cosas que tranquilamente pueden ser funciones.
        // llamaron la atencion sobre algo similar (por no decir lo mismo) a otro equipo con el aviso de que se recursaba directamente la materia.
        if((hora.getHoras() == horaTransaccion.getHoras()) && (hora.getMinutos() == horaTransaccion.getMinutos()) && (hora.getSegundos() == horaTransaccion.getSegundos())){ 
        transaccionEncontrada = reg;
        fclose(archivo);
        return;
        }
    }
    fclose(archivo);
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