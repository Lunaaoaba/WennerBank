#include "cuentaBancaria.h"
#include <iostream>
using namespace std;

// --- Constructores ---
// Constructor por defecto
// Inicializa una cuenta bancaria con valores seguros y el estado 'eliminado' en falso.
cuentaBancaria::cuentaBancaria()
{
    idCuenta = 0;
    idCliente = 0;
    saldo = 0.0;
    eliminado = false;
}

// Constructor con parámetros
// Permite inicializar todos los atributos de la cuenta al momento de la creación.
cuentaBancaria::cuentaBancaria(int idCta, int idCli, double sal, bool elim)
{
    idCuenta = idCta;
    idCliente = idCli;
    saldo = sal;
    eliminado = elim;
}

// --- Getters ---
int cuentaBancaria::getIdCuenta() const
{
    return idCuenta;
}

int cuentaBancaria::getIdCliente() const
{
    return idCliente;
}

double cuentaBancaria::getSaldo() const
{
    return saldo;
}

bool cuentaBancaria::getEliminado() const
{
    return eliminado;
}

// --- Setters ---
void cuentaBancaria::setIdCuenta(int idCta)
{
    idCuenta = idCta;
}

void cuentaBancaria::setIdCliente(int idCli)
{
    idCliente = idCli;
}

void cuentaBancaria::setSaldo(double sal)
{
    saldo = sal;
}

void cuentaBancaria::setEliminado(bool elim)
{
    eliminado = elim;
}

// --- Métodos de Operaciones Bancarias ---
// Deposito: Aumenta el saldo si el monto es positivo.
void cuentaBancaria::depositar(double monto)
{
    if (monto > 0)
    {
        saldo += monto;
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
    if (monto > 0 && monto <= saldo)
    {
        saldo -= monto;
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
    cout << "ID Cuenta: " << idCuenta << endl;
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Saldo: $" << saldo << endl;
    // Muestra "Eliminada" o "Activa" basado en el estado booleano
    cout << "Estado: " << (eliminado ? "Eliminada" : "Activa") << endl;
}