#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>


class cuentaBancaria{
    private:
        char _idCuenta[5]; // 4 digitos + '\0'
        char _idCliente[5]; // 4 digitos + '\0'
        char _nombreCuenta[50];
        char _cvu[11]; // 10 digitos + '\0'
        char _alias[31]; // 30 caracteres + '\0'
        double _saldo;
        bool _cuentaEliminada;
    public:
    //constructores
        cuentaBancaria();
        cuentaBancaria(const char* idCuenta, const char* idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada);
    //setters
        void setIdCuenta(const char* idCuenta);
        void setIdCliente(const char* idCliente);
        void setNombreCuenta(const char* nombreCuenta);
        void setCvu(const char* cvu);
        void setAlias(const char* alias);
        void setSaldo(double saldo);
        void setCuentaEliminada(bool cuentaEliminada);
    //getters
        const char* getIdCuenta();
        const char* getIdCliente();
        const char* getNombreCuenta();
        const char* getCvu();
        const char* getAlias();
        double getSaldo();
        bool getCuentaEliminada();
    //operaciones bancarias
        bool depositar(double monto);
        bool retirar(double monto);
    //otros
        void mostrarDatos();
};

#endif
