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

void Fecha::setDia(int dia){ _dia = dia; }
void Fecha::setMes(int mes){ _mes = mes; }
void Fecha::setAnio(int anio){ _anio = anio; }

int Fecha::getDia() const{ return _dia; }
int Fecha::getMes() const{ return _mes; }
int Fecha::getAnio() const{ return _anio; }

void Fecha::cargarFecha(){
    // se ingresa en orden de "aNIo -> mes -> dia" para facilitar la validacion de dias por mes
    cout << "Ingrese a" << char(164) << "o: ";
    _anio = validarEntero(1900, 2025);
    cout << "Ingrese mes: ";
    _mes = validarEntero(1, 12);
    // ajustar dias maximos por mes
    int diaMaximo;
    switch(_mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diaMaximo = 31;
            break;
        case 4: case 6: case 9: case 11:
            diaMaximo = 30;
            break;
        case 2:
            // aNIo biciesto
            if((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0)) diaMaximo = 29;
            // aNIo no biciesto
            else diaMaximo = 28;
            break;
    }
    cout << "Ingrese dia: ";
    _dia = validarEntero(1, diaMaximo);
}

void Fecha::cargarFechaActual(){
    time_t tiempoCrudo = time(nullptr); // almacena tiempo en segundos
    tm* tiempoLocal = localtime(&tiempoCrudo); // convierte a tiempo local
    
    _dia = tiempoLocal->tm_mday;
    _mes = tiempoLocal->tm_mon + 1; // Se suma 1 porque los meses van de 0 a 11
    _anio = tiempoLocal->tm_year + 1900; // Se suma 1900 porque los aNIos se cuentan desde 1900
}

string Fecha::mostrarFecha() const { return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio); }