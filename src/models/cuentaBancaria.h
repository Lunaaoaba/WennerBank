#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>
#include <string>
using namespace std;


class cuentaBancaria{
    private:
        int _idCuenta;
        int _idCliente;
        char _nombreCuenta[50];
        char _cvu[11];
        char _alias[31];
        double _saldo;
        bool _cuentaEliminada;
    public:
        cuentaBancaria();
        cuentaBancaria(int idCuenta, int idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada);

        void setIdCliente(int idCliente);
        void setNombreCuenta(const char* nombreCuenta);
        void setAlias(const char* alias);
        void setSaldo(double saldo);
        void setCuentaEliminada(bool cuentaEliminada);

        int getIdCuenta() const;
        int getIdCliente() const;
        const char* getNombreCuenta() const;
        const char* getCvu() const;
        const char* getAlias() const;
        double getSaldo() const;
        bool getCuentaEliminada() const;

        void cargarDatos();
        string mostrarDatos() const;
};

#endif
