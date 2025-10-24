#include "ArchivoMovimientos.h"


// bool guardarTransacciones(const Transaccion& transaccion){
//     FILE* archivo = fopen(NOMBRE_ARCHIVO_TRANSACCIONES, "ab");
//     if(archivo == nullptr){
//         cout << "Error al abrir el archivo de transacciones." << endl;
//         return false;
//     }
//     fwrite(&transaccion, sizeof(Transaccion), 1, archivo);
//     fclose(archivo);
//     return true;
// }

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
