#include "cuentaBancaria.h"
#include <iostream>
using namespace std;

// MODIFICADO PARA SACAR LO "IA" DE LA CLASE

//constructores
cuentaBancaria::cuentaBancaria(){
    _idCuenta = 0;
    _idCliente = 0;
    _saldo = 0.0;
    _eliminado = false;
}

cuentaBancaria::cuentaBancaria(int idCuenta, int idCliente, double saldo, bool eliminado){
    _idCuenta = idCuenta;
    _idCliente = idCliente;
    _saldo = saldo;
    _eliminado = eliminado;
}


// --- Setters ---
void cuentaBancaria::setIdCuenta(int idCuenta)
{
    _idCuenta = idCuenta;
}

void cuentaBancaria::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void cuentaBancaria::setSaldo(double saldo)
{
    _saldo = saldo;
}

void cuentaBancaria::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

//getters
int cuentaBancaria::getIdCuenta(int idCuenta) { return _idCuenta; }

int cuentaBancaria::getIdCliente() const
{
    return _idCliente;
}

double cuentaBancaria::getSaldo() const
{
    return _saldo;
}

bool cuentaBancaria::getEliminado() const
{
    return _eliminado;
}


// --- Métodos de Operaciones Bancarias ---
// Deposito: Aumenta el saldo si el monto es positivo.
void cuentaBancaria::depositar(double monto)
{
    if (monto > 0)
    {
        _saldo += monto;
        cout << "Deposito realizado. Su saldo actual es: $" << saldo << endl;
    }
    else
    {
        cout << "ERROR: El monto debe ser mayor a cero." << endl;
    }
}

// Retiro: Disminuye el saldo si el monto es positivo y hay fondos suficientes.
// Retorna true si el retiro es exitoso, false en caso contrario.
bool cuentaBancaria::retirar(double monto)
{
    if (monto > 0 && monto <= _saldo)
    {
        _saldo -= monto;
        cout << "Retiro realizado. Su saldo actual es: $" << saldo << endl;
        return true;
    }
    else
    {
        cout << "ERROR: fondos insuficientes o monto invalido." << endl;
        return false;
    }
}

//--- Metodo auxiliar ---
// Muestra todos los datos de la cuenta en la consola.
void cuentaBancaria::mostrarDatos() const
{
    cout << "\n--- Datos de la cuenta bancaria ---" << endl;
    cout << "ID Cuenta: " << _idCuenta << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Saldo: $" << _saldo << endl;
    // Muestra "Eliminada" o "Activa" basado en el estado booleano
    cout << "Estado: " << (_eliminado ? "Eliminada" : "Activa") << endl;
}