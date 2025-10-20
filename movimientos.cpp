#include <iostream>
#include <cstring>
#include <sstream>
#include "movimientos.h"
#include "fecha.h"
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

int Transaccion::getIdTransaccion(){ return _idTransaccion; }
int Transaccion::getIdCuentaOrigen(){ return _idCuentaOrigen; }
int Transaccion::getIdCuentaDestino(){ return _idCuentaDestino; }
double Transaccion::getMonto(){ return _monto; }
Fecha Transaccion::getFechaTransaccion(){ return _fechaTransaccion; }
Tiempo Transaccion::getHoraTransaccion(){ return _horaTransaccion; }

void Transaccion::setIdTransaccion(int idTransaccion){ _idTransaccion = idTransaccion; }
void Transaccion::setIdCuentaOrigen(int idCuentaOrigen){ _idCuentaOrigen = idCuentaOrigen; }
void Transaccion::setIdCuentaDestino(int idCuentaDestino){ _idCuentaDestino = idCuentaDestino; }
void Transaccion::setMonto(double monto){ _monto = monto; }
void Transaccion::setFechaTransaccion(Fecha fechaTransaccion){ _fechaTransaccion = fechaTransaccion; }
void Transaccion::setHoraTransaccion(Tiempo horaTransaccion){ _horaTransaccion = horaTransaccion; }

void Transaccion::cargarDatos(){
    cout << "Cargando datos de la transaccion..." << endl;
    cout << "ID Transaccion: ";
    cin >> _idTransaccion;
    cout << "ID Cuenta Origen: ";
    cin >> _idCuentaOrigen;
    cout << "ID Cuenta Destino: ";
    cin >> _idCuentaDestino;
    cout << "Monto: ";
    cin >> _monto;
    cout << "Fecha: ";
    _fechaTransaccion.cargarFecha();
    cout << "Hora: ";
    _horaTransaccion.cargarTiempo();
}

string Transaccion::mostrarDatos() {
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
    _monto = 0.0;
    _tasaInteres = 0.0;
}

Prestamo::Prestamo(int idPrestamo, int idCliente, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento){
    _idPrestamo = idPrestamo;
    _idCliente = idCliente;
    _monto = monto;
    _tasaInteres = tasaInteres;
    _fechaInicio = fechaInicio;
    _fechaVencimiento = fechaVencimiento;
}

int Prestamo::getIdPrestamo(){ return _idPrestamo; }
int Prestamo::getIdCliente(){ return _idCliente; }
double Prestamo::getMonto(){ return _monto; }
double Prestamo::getTasaInteres(){ return _tasaInteres; }
Fecha Prestamo::getFechaInicio(){ return _fechaInicio; }
Fecha Prestamo::getFechaVencimiento(){ return _fechaVencimiento; }

void Prestamo::setIdPrestamo(int idPrestamo){ _idPrestamo = idPrestamo; }
void Prestamo::setIdCliente(int idCliente){ _idCliente = idCliente; }
void Prestamo::setMonto(double monto){ _monto = monto; }
void Prestamo::setTasaInteres(double tasaInteres){ _tasaInteres = tasaInteres; }
void Prestamo::setFechaInicio(Fecha fechaInicio){ _fechaInicio = fechaInicio; }
void Prestamo::setFechaVencimiento(Fecha fechaVencimiento){ _fechaVencimiento = fechaVencimiento; }

void mostrarDatosPrestamo(Prestamo p){
    cout << "ID Prestamo: " << p.getIdPrestamo() << endl;
    cout << "ID Cliente: " << p.getIdCliente() << endl;
    cout << "Monto: $" << p.getMonto() << endl;
    cout << "Tasa de Interes: " << p.getTasaInteres() << "%" << endl;
    cout << "Fecha de Inicio: " << p.getFechaInicio().mostrarFecha() << endl;
    cout << "Fecha de Vencimiento: " << p.getFechaVencimiento().mostrarFecha() << endl;
}
void Prestamo::cargarDatos(){
    cout << "Cargando datos del prestamo..." << endl;
    cout << "ID Prestamo: ";
    cin >> _idPrestamo;
    cout << "ID Cliente: ";
    cin >> _idCliente;
    cout << "Monto: ";
    cin >> _monto;
    cout << "Tasa de Interes (anual %): ";
    cin >> _tasaInteres;
    cout << "Fecha de Inicio:" << endl;
    _fechaInicio.cargarFecha();
    cout << "Fecha de Vencimiento:" << endl;
    _fechaVencimiento.cargarFecha();
}
string Prestamo::mostrarDatos() {
    string linea = string("Prestamo: ") + to_string(_idPrestamo)
                    + "\nCliente: " + to_string(_idCliente)
                    + "\nMonto: " + to_string(_monto)
                    + "\nTasa de Interes: " + to_string(_tasaInteres) + "%"
                    + "\nFecha de Inicio: " + _fechaInicio.mostrarFecha()
                    + "\nFecha de Vencimiento: " + _fechaVencimiento.mostrarFecha();
    return linea;
}
