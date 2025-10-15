#pragma once
#include <string>
using namespace std;
class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    string toString();
};