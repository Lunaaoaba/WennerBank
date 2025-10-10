#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "personaUsuario.h"

class cuentaBancaria : public Usuario{
    private:
        double _saldo;
    public:
    //constructores
        cuentaBancaria();
        cuentaBancaria(int idCuenta, int idCliente, double saldo, bool eliminado);
    //setters
        void setIdCuenta(int idCuenta);
        void setIdCliente(int idCliente);
        void setSaldo(double saldo);
        void setEliminado(bool eliminado);
    //getters
        int getIdCuenta(int idCuenta);
        int getIdCliente(int idCliente);
        double getSaldo(double saldo);
        bool getEliminado(bool eliminado);
    //operaciones bancarias
        void depositar(double monto);
        // Retirar: Modifica el saldo, retorna éxito (true) o fallo (false)
        bool retirar(double monto); 
    //otros
        void mostrarDatos() const;
};

#endif
