#ifndef TRANSACCION_H
#define TRANSACCION_H
#include "tiempo.h"
#include "fecha.h"

using namespace std;


class Transaccion{
    private:
        int _idTransaccion;
        int _idCuentaOrigen;
        int _idCuentaDestino;
        double _monto;
        Fecha _fechaTransaccion;
        Tiempo _horaTransaccion;
    public:
        Transaccion();
        Transaccion(int idTransaccion, int idCuentaOrigen, int idCuentaDestino, double monto, Fecha fechaTransaccion, Tiempo horaTransaccion);

        void setIdCuentaOrigen(int idCuentaOrigen);
        void setIdCuentaDestino(int idCuentaDestino);
        void setMonto(double monto);
        void setFechaTransaccion(Fecha fechaTransaccion);
        void setHoraTransaccion(Tiempo horaTransaccion);

        int getIdTransaccion() const;
        int getIdCuentaOrigen() const;
        int getIdCuentaDestino() const;
        double getMonto() const;
        Fecha getFechaTransaccion() const;
        Tiempo getHoraTransaccion() const;

        string mostrarDatos() const;
};

#endif