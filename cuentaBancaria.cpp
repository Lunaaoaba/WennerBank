#include "cuentaBancaria.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

// MODIFICADO PARA SACAR LO "IA" DE LA CLASE

//constructores
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
//setters
void cuentaBancaria::setIdCliente(int idCliente){ _idCliente = idCliente; }
void cuentaBancaria::setNombreCuenta(const char* nombreCuenta){ strcpy(_nombreCuenta, nombreCuenta); }
void cuentaBancaria::setAlias(const char* alias){ strcpy(_alias, alias); }
void cuentaBancaria::setSaldo(double saldo){ _saldo = saldo; }
void cuentaBancaria::setCuentaEliminada(bool cuentaEliminada){ _cuentaEliminada = cuentaEliminada; }
//getters
int cuentaBancaria::getIdCuenta(){ return _idCuenta; }
int cuentaBancaria::getIdCliente(){ return _idCliente; }
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
        cout << "ERROR: Fondos insuficientes o monto invalido." << endl;
        return false;
    }
}
void cuentaBancaria::cargarDatos(){
    cout << "\n--- Ingrese los datos de la cuenta bancaria ---" << endl;
    cout << "ID Cuenta (4 digitos): ";
    cin >> _idCuenta;
    cout << "ID Cliente (4 digitos): ";
    cin >> _idCliente;
    cout << "Nombre de la Cuenta: ";
    cin.ignore(); // Limpiar el buffer antes de usar getline
    cin.getline(_nombreCuenta, 50);
    cout << "CVU (10 digitos): ";
    cin >> _cvu;
    cout << "Alias (max 30 caracteres): ";
    cin.ignore(); // Limpiar el buffer antes de usar getline
    cin.getline(_alias, 31);
    cout << "Saldo inicial: $";
    cin >> _saldo;
    _cuentaEliminada = false; // Por defecto, la cuenta no está eliminada al cargar datos
    cout << "----------------------------------------------\n" << endl;
}
string cuentaBancaria::mostrarDatos(){
    string linea = string("ID Cuenta: ") + to_string(_idCuenta)
            + "\nID Cliente: " + to_string(_idCliente)
            + "\nNombre de la Cuenta: " + _nombreCuenta
            + "\nCVU: " + _cvu
            + "\nAlias: " + _alias
            + "\nSaldo: $" + to_string(_saldo)
            + "\nEstado: " + (_cuentaEliminada ? "Eliminada" : "Activa") + "\n";
    return linea;
}