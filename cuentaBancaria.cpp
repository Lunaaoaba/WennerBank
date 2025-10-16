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
    strcpy(_nombreCuenta, "N/A");
    strcpy(_cvu, "0000000000");
    strcpy(_alias, "N/A");
    _saldo = 0;
    _cuentaEliminada = false;
}
cuentaBancaria::cuentaBancaria(const char* idCuenta, const char* idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada){
    strcpy(_idCuenta, idCuenta);
    strcpy(_idCliente, idCliente);
    strcpy(_nombreCuenta, nombreCuenta);
    strcpy(_cvu, cvu);
    strcpy(_alias, alias);
    _saldo = saldo;
    _cuentaEliminada = cuentaEliminada;
}
//setters
void cuentaBancaria::setIdCuenta(const char* idCuenta){ strcpy(_idCuenta, idCuenta); }
void cuentaBancaria::setIdCliente(const char* idCliente){ strcpy(_idCliente, idCliente); }
void cuentaBancaria::setNombreCuenta(const char* nombreCuenta){ strcpy(_nombreCuenta, nombreCuenta); }
void cuentaBancaria::setCvu(const char* cvu){ strcpy(_cvu, cvu); }
void cuentaBancaria::setAlias(const char* alias){ strcpy(_alias, alias); }
void cuentaBancaria::setSaldo(double saldo){ _saldo = saldo; }
void cuentaBancaria::setCuentaEliminada(bool cuentaEliminada){ _cuentaEliminada = cuentaEliminada; }
//getters
const char* cuentaBancaria::getIdCuenta(){ return _idCuenta; }
const char* cuentaBancaria::getIdCliente(){ return _idCliente; }
const char* cuentaBancaria::getNombreCuenta(){ return _nombreCuenta; }
const char* cuentaBancaria::getCvu(){ return _cvu; }
const char* cuentaBancaria::getAlias(){ return _alias; }
double cuentaBancaria::getSaldo(){ return _saldo; }
bool cuentaBancaria::getCuentaEliminada(){ return _cuentaEliminada; }
//operaciones bancarias
// Aumenta el saldo si el monto es positivo.
bool cuentaBancaria::depositar(double saldo){
    if (saldo > 0){
        _saldo += saldo;
        cout << "Deposito realizado. Su saldo actual es: $" << _saldo << endl;
        return true;
    }
    else {
        cout << "ERROR: El monto debe ser mayor a cero." << endl;
        return false;
    }
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

void cuentaBancaria::mostrarDatos(){
    cout << "\n--- Datos de la cuenta bancaria ---" << endl;
    cout << "ID Cuenta: " << _idCuenta << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre de la Cuenta: " << _nombreCuenta << endl;
    cout << "CVU: " << _cvu << endl;
    cout << "Alias: " << _alias << endl;
    cout << "Saldo: $" << _saldo << endl;
    cout << "Estado: " << (_cuentaEliminada ? "Eliminada" : "Activa") << endl; // Muestra "Eliminada" o "Activa" basado en el estado booleano
    cout << "--------------------------------------\n" << endl;
}