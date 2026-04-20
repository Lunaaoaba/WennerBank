#include <iostream>
#include <cstring>
#include <sstream>
#include "transaccion.h"
#include "fecha.h"
#include "funciones.h"

using namespace std;


Transaccion::Transaccion(){
    _idTransaccion = 0;
    _idCuentaOrigen = -1;
    _idCuentaDestino = -1;
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

string Transaccion::mostrarDatos() const{
    string linea = string("Transaccion: ") + to_string(_idTransaccion)
                    + "\nCuenta Origen: " + to_string(_idCuentaOrigen)
                    + "\nCuenta Destino: " + to_string(_idCuentaDestino)
                    + "\nMonto: " + to_string(_monto)
                    + "\nFecha: " + _fechaTransaccion.mostrarFecha()
                    + "\nHora: " + _horaTransaccion.mostrarTiempo();
    return linea;
}