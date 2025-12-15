#ifndef ARCHIVOCUENTAS_H
#define ARCHIVOCUENTAS_H
#include "cuentaBancaria.h"


class ArchivoCuentas{
    private:
        char _nombreArchivo[30];
    public:
        ArchivoCuentas(const char* nombre = "cuentas.dat");

        bool guardarCuentas(const cuentaBancaria& cuenta);
        cuentaBancaria crearCuenta(int idCliente);

        bool modificarCuenta(const cuentaBancaria& cuentaModificada);
        bool modificarDatosCuenta(int idCuenta);
        bool eliminarCuenta(int idCuenta);
        bool restaurarCuenta(int idCuenta);
        
        void listarCuentasCliente(int idCliente);
        void listarCuentas();
        void listarTodasCuentas();
        
        bool buscarCuenta(const char* criterio, int valor, cuentaBancaria& encontrado);
        bool buscarCuenta(const char* criterio, const char* valor, cuentaBancaria& encontrado);
        
        bool depositar(int idCuenta, double monto);
        bool extraer(int idCuenta, double monto);
        bool transferir(int idCuentaOrigen, int idCuentaDestino, double monto);
        
        int generarIdCuenta();
        void generarCvu(char* cvu);
        void generarAlias(char* alias);
        int posicionCuentaPorId(int idCuenta);
};
#endif
