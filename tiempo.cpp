#include <iostream>
#include <ctime>
#include "tiempo.h"
#include "funciones.h"

using namespace std;

Tiempo::Tiempo(){
    _hora = 0;
    _minuto = 0;
    _segundo = 0;
}
Tiempo::Tiempo(int hora, int minuto, int segundo){
    _hora = hora;
    _minuto = minuto;
    _segundo = segundo;
}

void Tiempo::setHora(int hora){ _hora = hora; }
void Tiempo::setMinuto(int minuto){ _minuto = minuto; }
void Tiempo::setSegundo(int segundo){ _segundo = segundo; }

int Tiempo::getHora() const{ return _hora; }
int Tiempo::getMinuto() const{ return _minuto; }
int Tiempo::getSegundo() const{ return _segundo; }

void Tiempo::cargarTiempo(){
    cout << "Ingrese hora: ";
    _hora = validarEntero(0, 23);
    cout << "Ingrese minuto: ";
    _minuto = validarEntero(0, 59);
    cout << "Ingrese segundo: ";
    _segundo = validarEntero(0, 59);
}
void Tiempo::cargarTiempoActual(){
    time_t tiempoCrudo = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoCrudo);

    _hora = tiempoLocal->tm_hour;
    _minuto = tiempoLocal->tm_min;
    _segundo = tiempoLocal->tm_sec;
}
string Tiempo::mostrarTiempo() const{
    return to_string(_hora) + ":" + to_string(_minuto) + ":" + to_string(_segundo);
}