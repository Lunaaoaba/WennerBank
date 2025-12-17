#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "cuentaBancaria.h"
#include "funciones.h"

using namespace std;


cuentaBancaria::cuentaBancaria(){
    _idCuenta = 0;
    _idCliente = 0;
    strcpy(_nombreCuenta, "N/A");
    strcpy(_cvu, "0000000000");
    strcpy(_alias, "N/A");
    _saldo = 0;
    _cuentaEliminada = false;
}
cuentaBancaria::cuentaBancaria(int idCuenta, int idCliente, const char* nombreCuenta, const char* cvu, const char* alias, double saldo, bool cuentaEliminada){
    _idCuenta = idCuenta;
    _idCliente = idCliente;
    strcpy(_nombreCuenta, nombreCuenta);
    strcpy(_cvu, cvu);
    strcpy(_alias, alias);
    _saldo = saldo;
    _cuentaEliminada = cuentaEliminada;
}

void cuentaBancaria::setIdCliente(int idCliente){ _idCliente = idCliente; }
void cuentaBancaria::setNombreCuenta(const char* nombreCuenta){ strcpy(_nombreCuenta, nombreCuenta); }
void cuentaBancaria::setAlias(const char* alias){ strcpy(_alias, alias); }
void cuentaBancaria::setSaldo(double saldo){ _saldo = saldo; }
void cuentaBancaria::setCuentaEliminada(bool cuentaEliminada){ _cuentaEliminada = cuentaEliminada; }

int cuentaBancaria::getIdCuenta() const{ return _idCuenta; }
int cuentaBancaria::getIdCliente() const{ return _idCliente; }
const char* cuentaBancaria::getNombreCuenta() const{ return _nombreCuenta; }
const char* cuentaBancaria::getCvu() const{ return _cvu; }
const char* cuentaBancaria::getAlias() const{ return _alias; }
double cuentaBancaria::getSaldo() const{ return _saldo; }
bool cuentaBancaria::getCuentaEliminada() const{ return _cuentaEliminada; }

string cuentaBancaria::mostrarDatos() const{
    string linea = string("ID Cuenta: ") + to_string(_idCuenta)
            + "\nID Cliente: " + to_string(_idCliente)
            + "\nNombre de la Cuenta: " + _nombreCuenta
            + "\nCVU: " + _cvu
            + "\nAlias: " + _alias
            + "\nSaldo: $" + to_string(_saldo)
            + "\nEstado: " + (_cuentaEliminada ? "Eliminada" : "Activa") + "\n";
    return linea;
}