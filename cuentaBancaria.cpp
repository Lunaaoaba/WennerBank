#include "cuentaBancaria.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// MODIFICADO PARA SACAR LO "IA" DE LA CLASE

//constructores
cuentaBancaria::cuentaBancaria(){
    strcpy(_idCuenta, "0000");
    strcpy(_idCliente, "0000");
    strcpy(_nombreCuenta, "Sin Nombre");
    _saldo = 0.0;
    _CuentaEliminada = false;
}

cuentaBancaria::cuentaBancaria(const char* idCuenta, const char* idCliente, const char* nombreCuenta, double saldo, bool CuentaEliminada){
    strcpy(_idCuenta, idCuenta);
    strcpy(_idCliente, idCliente);
    strcpy(_nombreCuenta, nombreCuenta);
    _saldo = saldo;
    _CuentaEliminada = CuentaEliminada;
}


// --- Setters ---
void cuentaBancaria::setIdCuenta(const char* idCuenta) { strcpy(_idCuenta, idCuenta); }

void cuentaBancaria::setIdCliente(const char* idCliente){ strcpy(_idCliente, idCliente); }

void cuentaBancaria::setNombreCuenta(const char* nombreCuenta){ strcpy(_nombreCuenta, nombreCuenta); }

void cuentaBancaria::setSaldo(double saldo){ _saldo = saldo; }

void cuentaBancaria::setCuentaEliminada(bool CuentaEliminada)
{
    _CuentaEliminada = CuentaEliminada;
}

//getters
const char* cuentaBancaria::getIdCuenta() { return _idCuenta; }

const char* cuentaBancaria::getIdCliente() { return _idCliente; }

double cuentaBancaria::getSaldo() { return _saldo; }

bool cuentaBancaria::getCuentaEliminada() { return _CuentaEliminada; }

// --- Métodos de Operaciones Bancarias ---
// Aumenta el saldo si el monto es positivo.
void cuentaBancaria::depositar(double saldo){
    if (saldo > 0){
        _saldo += saldo;
        cout << "Deposito realizado. Su saldo actual es: $" << _saldo << endl;
    }
    else cout << "ERROR: El monto debe ser mayor a cero." << endl;
}

// Disminuye el saldo si el monto es positivo y hay fondos suficientes.
// Retorna true si el retiro es exitoso, false en caso contrario.
bool cuentaBancaria::retirar(double saldo){
    if (saldo > 0 && saldo <= _saldo){
        _saldo -= saldo;
        cout << "Retiro realizado. Su saldo actual es: $" << _saldo << endl;
        return true;
    }
    else{
        cout << "ERROR: fondos insuficientes o monto invalido." << endl;
        return false;
    }
}

//--- Metodo auxiliar ---
// Muestra todos los datos de la cuenta en la consola.
void cuentaBancaria::mostrarDatos(){
    cout << "\n--- Datos de la cuenta bancaria ---" << endl;
    cout << "ID Cuenta: " << _idCuenta << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Saldo: $" << _saldo << endl;
    // Muestra "Eliminada" o "Activa" basado en el estado booleano
    cout << "Estado: " << (_CuentaEliminada ? "Eliminada" : "Activa") << endl;
}