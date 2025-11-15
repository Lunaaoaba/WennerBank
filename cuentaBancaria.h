#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>
#include <string>
using namespace std;


class cuentaBancaria{
    private:
        int _idCuenta; // 4 digitos + '\0'
        int _idCliente; // 4 digitos + '\0'
        char _nombreCuenta[50];
        char _cvu[11]; // 10 digitos + '\0'
        char _alias[31]; // 30 caracteres + '\0'
        double _saldo;
        bool _cuentaEliminada;
    public:
        cuentaBancaria();
        cuentaBancaria(int idCuenta, int idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada);
        //set
        void setIdCliente(int idCliente);
        void setNombreCuenta(const char* nombreCuenta);
        void setAlias(const char* alias);
        void setSaldo(double saldo);
        void setCuentaEliminada(bool cuentaEliminada);
        //get
        int getIdCuenta();
        int getIdCliente();
        const char* getNombreCuenta();
        const char* getCvu();
        const char* getAlias();
        double getSaldo();
        bool getCuentaEliminada();
        //otros
        bool depositar(double monto);
        bool retirar(double monto);
        void cargarDatos();
        string mostrarDatos();
};


#endif
