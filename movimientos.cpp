#include <iostream>
#include <cstring>
#include <sstream>
#include "movimientos.h"
using namespace std;

Transaccion::Transaccion(){
    strcpy(_idTransaccion, "0000");
    strcpy(_idCuentaOrigen, "0000");
    strcpy(_idCuentaDestino, "0000");
    _monto = 0.0;
}

Transaccion::Transaccion(const char* idTransaccion, const char* idCuentaOrigen, const char* idCuentaDestino, double monto, Fecha fechaTransaccion, Tiempo horaTransaccion){
    strcpy(_idTransaccion, idTransaccion);
    strcpy(_idCuentaOrigen, idCuentaOrigen);
    strcpy(_idCuentaDestino, idCuentaDestino);
    _monto = monto;
    _fechaTransaccion = fechaTransaccion;
    _horaTransaccion = horaTransaccion;
}

const char* Transaccion::getIdTransaccion(){ return _idTransaccion; }
const char* Transaccion::getIdCuentaOrigen(){ return _idCuentaOrigen; }
const char* Transaccion::getIdCuentaDestino(){ return _idCuentaDestino; }
double Transaccion::getMonto(){ return _monto; }
Fecha Transaccion::getFechaTransaccion(){ return _fechaTransaccion; }
Tiempo Transaccion::getHoraTransaccion(){ return _horaTransaccion; }

void Transaccion::setIdTransaccion(const char* idTransaccion){ strcpy(_idTransaccion, idTransaccion); }
void Transaccion::setIdCuentaOrigen(const char* idCuentaOrigen){ strcpy(_idCuentaOrigen, idCuentaOrigen); }
void Transaccion::setIdCuentaDestino(const char* idCuentaDestino){ strcpy(_idCuentaDestino, idCuentaDestino); }
void Transaccion::setMonto(double monto){ _monto = monto; }
void Transaccion::setFechaTransaccion(Fecha fechaTransaccion){ _fechaTransaccion = fechaTransaccion; }
void Transaccion::setHoraTransaccion(Tiempo horaTransaccion){ _horaTransaccion = horaTransaccion; }

string Transaccion::toString() {
    string linea = string("Transaccion: ") + _idTransaccion
                    + "\nCuenta Origen: " + _idCuentaOrigen
                    + "\nCuenta Destino: " + _idCuentaDestino
                    + "\nMonto: " + to_string(_monto)
                    + "\nFecha: " + _fechaTransaccion.toString()
                    + "\nHora: " + _horaTransaccion.toString();
    return linea;
}

Prestamo::Prestamo(){
    strcpy(_idPrestamo, "0000");
    strcpy(_idCliente, "0000");
    _monto = 0.0;
    _tasaInteres = 0.0;
}

Prestamo::Prestamo(const char* idPrestamo, const char* idCliente, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento){
    strcpy(_idPrestamo, idPrestamo);
    strcpy(_idCliente, idCliente);
    _monto = monto;
    _tasaInteres = tasaInteres;
    _fechaInicio = fechaInicio;
    _fechaVencimiento = fechaVencimiento;
}

const char* Prestamo::getIdPrestamo(){ return _idPrestamo; }
const char* Prestamo::getIdCliente(){ return _idCliente; }
double Prestamo::getMonto(){ return _monto; }
double Prestamo::getTasaInteres(){ return _tasaInteres; }
Fecha Prestamo::getFechaInicio(){ return _fechaInicio; }
Fecha Prestamo::getFechaVencimiento(){ return _fechaVencimiento; }

void Prestamo::setIdPrestamo(const char* idPrestamo){ strcpy(_idPrestamo, idPrestamo); }
void Prestamo::setIdCliente(const char* idCliente){ strcpy(_idCliente, idCliente); }
void Prestamo::setMonto(double monto){ _monto = monto; }
void Prestamo::setTasaInteres(double tasaInteres){ _tasaInteres = tasaInteres; }
void Prestamo::setFechaInicio(Fecha fechaInicio){ _fechaInicio = fechaInicio; }
void Prestamo::setFechaVencimiento(Fecha fechaVencimiento){ _fechaVencimiento = fechaVencimiento; }

string Prestamo::toString() {
    string linea = string("Prestamo: ") + _idPrestamo
                    + "\nCliente: " + _idCliente
                    + "\nMonto: " + to_string(_monto)
                    + "\nTasa de Interes: " + to_string(_tasaInteres) + "%"
                    + "\nFecha de Inicio: " + _fechaInicio.toString()
                    + "\nFecha de Vencimiento: " + _fechaVencimiento.toString();
    return linea;
}
