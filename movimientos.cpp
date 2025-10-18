#include <iostream>
#include <cstring>
#include <sstream>
#include "movimientos.h"
#include "fecha.h"
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
    string linea = string("Transaccion: ") + _idTransaccion
                    + "\nCuenta Origen: " + _idCuentaOrigen
                    + "\nCuenta Destino: " + _idCuentaDestino
                    + "\nMonto: " + to_string(_monto)
                    + "\nFecha: " + _fechaTransaccion.mostrarFecha()
                    + "\nHora: " + _horaTransaccion.mostrarTiempo();
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
    string linea = string("Prestamo: ") + _idPrestamo
                    + "\nCliente: " + _idCliente
                    + "\nMonto: " + to_string(_monto)
                    + "\nTasa de Interes: " + to_string(_tasaInteres) + "%"
                    + "\nFecha de Inicio: " + _fechaInicio.mostrarFecha()
                    + "\nFecha de Vencimiento: " + _fechaVencimiento.mostrarFecha();
    return linea;
}
