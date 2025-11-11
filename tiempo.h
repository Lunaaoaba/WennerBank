#ifndef TIEMPO_H
#define TIEMPO_H
#include <iostream>
#include <string>
using namespace std;

class Tiempo{
    private:
        int _horas, _minutos, _segundos;
    public:
        Tiempo();
        Tiempo(int horas, int minutos, int segundos);

        int getHoras();
        int getMinutos();
        int getSegundos();

        void setHoras(int horas);
        void setMinutos(int minutos);
        void setSegundos(int segundos);

        void cargarTiempo();
        void cargarTiempoActual();
        string mostrarTiempo();

        // ¡NUEVA DECLARACIÓN!
    bool esIgual(Tiempo otroTiempo);
};

#endif