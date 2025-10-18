#include <iostream>
#include <ctime> // libreria para obtener fecha y hora del sistema
#include "tiempo.h"
using namespace std;

Tiempo::Tiempo(){
    _horas = 0;
    _minutos = 0;
    _segundos = 0;
}

Tiempo::Tiempo(int horas, int minutos, int segundos){
    _horas = horas;
    _minutos = minutos;
    _segundos = segundos;
}

int Tiempo::getHoras(){ return _horas; }
int Tiempo::getMinutos(){ return _minutos; }
int Tiempo::getSegundos(){ return _segundos; }

void Tiempo::setHoras(int horas){ _horas = horas; }
void Tiempo::setMinutos(int minutos){ _minutos = minutos; }
void Tiempo::setSegundos(int segundos){ _segundos = segundos; }

void Tiempo::cargarTiempo(){
    cout << "Ingrese horas: ";
    cin >> _horas;
    cout << "Ingrese minutos: ";
    cin >> _minutos;
    cout << "Ingrese segundos: ";
    cin >> _segundos;
}
void Tiempo::cargarTiempoActual(){
    time_t tiempoCrudo = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoCrudo);

    _horas = tiempoLocal->tm_hour;
    _minutos = tiempoLocal->tm_min;
    _segundos = tiempoLocal->tm_sec;
}

string Tiempo::mostrarTiempo(){
    return to_string(_horas) + ":" + to_string(_minutos) + ":" + to_string(_segundos);
}