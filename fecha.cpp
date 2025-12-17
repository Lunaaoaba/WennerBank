#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <ctime>
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
    cout << "Ingrese a" << char(164) << "o: ";
    _anio = validarEntero(1900, 2025);
    cout << "Ingrese mes: ";
    _mes = validarEntero(1, 12);
    int diaMaximo;
    switch(_mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diaMaximo = 31;
            break;
        case 4: case 6: case 9: case 11:
            diaMaximo = 30;
            break;
        case 2:
            if((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0)) diaMaximo = 29;
            else diaMaximo = 28;
            break;
    }
    cout << "Ingrese dia: ";
    _dia = validarEntero(1, diaMaximo);
}

// Sobrecarga con posicionamiento para formularios
void Fecha::cargarFecha(int x, int y){
    int lineaActual = y;
    
    // aNIo
    rlutil::locate(x, lineaActual);
    cout << "A" << char(164) << "o:  ";
    rlutil::locate(x + 6, lineaActual);
    _anio = validarEntero(1900, 2025);

    rlutil::locate(x, lineaActual);
    cout << "A" << char(164) << "o:  " << _anio << "    ";
    
    // mes
    lineaActual++;
    rlutil::locate(x, lineaActual);
    cout << "Mes:  ";
    rlutil::locate(x + 6, lineaActual);
    _mes = validarEntero(1, 12);

    rlutil::locate(x, lineaActual);
    cout << "Mes:  " << _mes << "    ";
    
    // dia dependiendo del mes y aNIo
    int diaMaximo;
    switch(_mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diaMaximo = 31;
            break;
        case 4: case 6: case 9: case 11:
            diaMaximo = 30;
            break;
        case 2:
            if((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0)) diaMaximo = 29;
            else diaMaximo = 28;
            break;
        default:
            diaMaximo = 31;
            break;
    }
    
    // dia
    lineaActual++;
    rlutil::locate(x, lineaActual);
    cout << "D" << char(161) << "a:  ";
    rlutil::locate(x + 6, lineaActual);
    _dia = validarEntero(1, diaMaximo);

    rlutil::locate(x, lineaActual);
    cout << "D" << char(161) << "a:  " << _dia << "    ";
}

void Fecha::cargarFechaActual(){
    time_t tiempoCrudo = time(nullptr); // almacena tiempo en segundos
    tm* tiempoLocal = localtime(&tiempoCrudo); // convierte a tiempo local
    
    _dia = tiempoLocal->tm_mday;
    _mes = tiempoLocal->tm_mon + 1; // Se suma 1 porque los meses van de 0 a 11
    _anio = tiempoLocal->tm_year + 1900; // Se suma 1900 porque los aNIos se cuentan desde 1900
}

string Fecha::mostrarFecha() const { return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio); }