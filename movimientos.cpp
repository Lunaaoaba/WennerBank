#include <iostream>
#include <cstring>
#include <sstream>
#include "movimientos.h"
#include "fecha.h"
#include "funciones.h"
using namespace std;

Transaccion::Transaccion(){
    _idTransaccion = 0;
    _idCuentaOrigen = 0;
    _idCuentaDestino = 0;
    _monto = 0.0;
}
Transaccion::Transaccion(int idTransaccion, int idCuentaOrigen, int idCuentaDestino, double monto, Fecha fechaTransaccion, Tiempo horaTransaccion){
    _idTransaccion = idTransaccion;
    _idCuentaOrigen = idCuentaOrigen;
    _idCuentaDestino = idCuentaDestino;
    _monto = monto;
    _fechaTransaccion = fechaTransaccion;
    _horaTransaccion = horaTransaccion;
}

void Transaccion::setIdCuentaOrigen(int idCuentaOrigen){ _idCuentaOrigen = idCuentaOrigen; }
void Transaccion::setIdCuentaDestino(int idCuentaDestino){ _idCuentaDestino = idCuentaDestino; }
void Transaccion::setMonto(double monto){ _monto = monto; }
void Transaccion::setFechaTransaccion(Fecha fechaTransaccion){ _fechaTransaccion = fechaTransaccion; }
void Transaccion::setHoraTransaccion(Tiempo horaTransaccion){ _horaTransaccion = horaTransaccion; }

int Transaccion::getIdTransaccion() const{ return _idTransaccion; }
int Transaccion::getIdCuentaOrigen() const{ return _idCuentaOrigen; }
int Transaccion::getIdCuentaDestino() const{ return _idCuentaDestino; }
double Transaccion::getMonto() const{ return _monto; }
Fecha Transaccion::getFechaTransaccion() const{ return _fechaTransaccion; }
Tiempo Transaccion::getHoraTransaccion() const{ return _horaTransaccion; }

void Transaccion::cargarDatos(){
    cout << "Cargando datos de la transaccion..." << endl;
    cout << "ID Transaccion: ";
    _idTransaccion = validarEntero(1, 99999999); // esto dsp se deberia asignar automaticamente
    cout << "ID Cuenta Origen: ";
    _idCuentaOrigen = validarEntero(1, 99999999);
    cout << "ID Cuenta Destino: ";
    _idCuentaDestino = validarEntero(1, 99999999);
    cout << "Monto: ";
    _monto = validarDouble(0.01, 99999999.99);
    cout << "Fecha: ";
    _fechaTransaccion.cargarFecha();
    cout << "Hora: ";
    _horaTransaccion.cargarTiempo();
}
string Transaccion::mostrarDatos() const{
    string linea = string("Transaccion: ") + to_string(_idTransaccion)
                    + "\nCuenta Origen: " + to_string(_idCuentaOrigen)
                    + "\nCuenta Destino: " + to_string(_idCuentaDestino)
                    + "\nMonto: " + to_string(_monto)
                    + "\nFecha: " + _fechaTransaccion.mostrarFecha()
                    + "\nHora: " + _horaTransaccion.mostrarTiempo();
    return linea;
}


Prestamo::Prestamo(){
    _idPrestamo = 0;
    _idCliente = 0;
    _legajo = 0;
    _monto = 0.0;
    _tasaInteres = 0.0;
    _prestamoVigente = true;
}
Prestamo::Prestamo(int idPrestamo, int idCliente, int legajo, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento, bool prestamoVigente){
    _idPrestamo = idPrestamo;
    _idCliente = idCliente;
    _legajo = legajo;
    _monto = monto;
    _tasaInteres = tasaInteres;
    _fechaInicio = fechaInicio;
    _fechaVencimiento = fechaVencimiento;
    _prestamoVigente = prestamoVigente;
}

int Prestamo::getIdPrestamo(){ return _idPrestamo; }
int Prestamo::getIdCliente(){ return _idCliente; }
int Prestamo::getLegajo(){ return _legajo; }
double Prestamo::getMonto(){ return _monto; }
double Prestamo::getTasaInteres(){ return _tasaInteres; }
Fecha Prestamo::getFechaInicio(){ return _fechaInicio; }
Fecha Prestamo::getFechaVencimiento(){ return _fechaVencimiento; }
bool Prestamo::getPrestamoVigente(){ return _prestamoVigente; }

void Prestamo::setIdPrestamo(int idPrestamo){ _idPrestamo = idPrestamo; }
void Prestamo::setIdCliente(int idCliente){ _idCliente = idCliente; }
void Prestamo::setLegajo(int legajo){ _legajo = legajo; }
void Prestamo::setMonto(double monto){ _monto = monto; }
void Prestamo::setTasaInteres(double tasaInteres){ _tasaInteres = tasaInteres; }
void Prestamo::setFechaInicio(Fecha fechaInicio){ _fechaInicio = fechaInicio; }
void Prestamo::setFechaVencimiento(Fecha fechaVencimiento){ _fechaVencimiento = fechaVencimiento; }
void Prestamo::setPrestamoVigente(bool prestamoVigente){ _prestamoVigente = prestamoVigente; }

void Prestamo::cargarDatos(){
    cout << "Cargando datos del prestamo..." << endl;
    cout << "ID Prestamo: ";
    _idPrestamo = validarEntero(1, 99999999); // esto dsp se deberia asignar automaticamente
    cout << "ID del cliente que solicita el prestamo: ";
    _idCliente = validarEntero(1, 99999999);
    cout << "Legajo de empleado que otorga el prestamo: ";
    _legajo = validarEntero(1, 99999999);
    cout << "Monto: ";
    _monto = validarDouble(0.01, 999999999.99);
    cout << "Tasa de Interes (anual %): ";
    _tasaInteres = validarDouble(0.01, 100.0);
    cout << "Fecha de Inicio:" << endl;
    _fechaInicio.cargarFecha();
    cout << "Fecha de Vencimiento:" << endl;
    _fechaVencimiento.cargarFecha();
    cout << "Prestamo Vigente (1 = Si, 0 = No): ";
    _prestamoVigente = true; // por defecto al cargar un prestamo, esta vigente
}
string Prestamo::mostrarDatos() {
    string linea = string("Prestamo: ") + to_string(_idPrestamo)
                    + "\nCliente: " + to_string(_idCliente)
                    + "\nLegajo: " + to_string(_legajo)
                    + "\nMonto: " + to_string(_monto)
                    + "\nTasa de Interes: " + to_string(_tasaInteres) + "%"
                    + "\nFecha de Inicio: " + _fechaInicio.mostrarFecha()
                    + "\nFecha de Vencimiento: " + _fechaVencimiento.mostrarFecha()
                    + "\nPrestamo Vigente: " + (_prestamoVigente ? "Si" : "No");
    return linea;
}
