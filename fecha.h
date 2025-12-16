#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>

using namespace std;

class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        
        void cargarFecha();
        void cargarFecha(int x, int y); // Sobrecarga con posicionamiento
        void cargarFechaActual();
        string mostrarFecha() const;
};

#endif