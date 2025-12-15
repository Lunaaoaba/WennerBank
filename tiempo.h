#ifndef TIEMPO_H
#define TIEMPO_H
#include <iostream>
#include <string>

using namespace std;

class Tiempo{
    private:
        int _hora, _minuto, _segundo;
    public:
        Tiempo();
        Tiempo(int hora, int minuto, int segundo);
        
        void setHora(int horas);
        void setMinuto(int minutos);
        void setSegundo(int segundos);
        
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        void cargarTiempo();
        void cargarTiempoActual();
        string mostrarTiempo() const;
};

#endif