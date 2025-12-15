#ifndef ARCHIVOTRANSACCIONES_H
#define ARCHIVOTRANSACCIONES_H
#include "transaccion.h"

class ArchivoTransacciones{
    private:
        char _nombreArchivo[30];
    public:
        ArchivoTransacciones(const char* nombre = "transacciones.dat");

        bool guardarTransaccion(const Transaccion& transaccion);
        int generarIdTransaccion();
        
        void listarTransacciones();
        void listarTransaccionesCuenta(int idCuenta);
        
        bool buscarTransaccion(int idTransaccion, Transaccion& encontrada);
    };

#endif