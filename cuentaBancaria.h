#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream> // Incluir para uso futuro de tipos STL si es necesario

class cuentaBancaria{
private:
    // Atributos privados que representan el estado de la cuenta
    int idCuenta;
    int idCliente;
    double saldo;
    bool eliminado; // Indica si la cuenta está activa (false) o marcada para eliminación (true)

public:
// --- Constructores ---
    // Constructor por defecto
    cuentaBancaria();
    // Constructor con parámetros, con valores por defecto para saldo y eliminado
    cuentaBancaria(int idCta, int idCli, double sal = 0.0, bool elim = false);

// --- Getters (Métodos de acceso constante) ---
    int getIdCuenta() const;
    int getIdCliente() const;
    double getSaldo() const;
    bool getEliminado() const;

// --- Setters (Métodos de modificación) ---
    void setIdCuenta(int idCta);
    void setIdCliente(int idCli);
    void setSaldo(double sal);
    void setEliminado(bool elim);
    
// --- Métodos de Operaciones Bancarias --- 
    // Depositar: Modifica el saldo, no necesita retornar valor
    void depositar(double monto);
    // Retirar: Modifica el saldo, retorna éxito (true) o fallo (false)
    bool retirar(double monto); 

// --- Método auxiliar ---
    // Muestra los datos de la cuenta en consola
    void mostrarDatos() const;
};

#endif // CUENTABANCARIA_H
