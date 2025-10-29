#include "movimientos.h"
#include "config.h"

//                         =====================
//                         =   TRANSACCIONES   =
//                         =====================

// ----------------------------------------------------------------------
//             FUNCIONES PARA MANEJO DE ARCHIVOS DE TRANSACCIONES
// ----------------------------------------------------------------------
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