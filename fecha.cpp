#include <iostream>
#include <ctime> // libreria para obtener fecha y hora del sistema
#include <limits>
#include <string>
#include "Fecha.h"
#include "funciones.h"

using namespace std;


Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 1900;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){ return _dia; }
int Fecha::getMes(){ return _mes; }
int Fecha::getAnio(){ return _anio; }

void Fecha::setDia(int dia){ _dia = dia; }
void Fecha::setMes(int mes){ _mes = mes; }
void Fecha::setAnio(int anio){ _anio = anio; }

void Fecha::cargarFecha(){
    _dia = validarEntero("Ingrese dia: ", 1, 31);
    _mes = validarEntero("Ingrese mes: ", 1, 12);
    _anio = validarEntero("Ingrese anio: ", 1900, 2025);
}
void Fecha::cargarFechaActual(){
    time_t tiempoCrudo = time(nullptr); // almacena tiempo en segundos
    tm* tiempoLocal = localtime(&tiempoCrudo); // convierte a tiempo local
    
    _dia = tiempoLocal->tm_mday;
    _mes = tiempoLocal->tm_mon + 1; // Se suma 1 porque los meses van de 0 a 11
    _anio = tiempoLocal->tm_year + 1900; // Se suma 1900 porque los años se cuentan desde 1900
}
string Fecha::mostrarFecha(){ return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio); }
