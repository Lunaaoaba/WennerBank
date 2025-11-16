#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
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

        void cargarDatos();
        string mostrarDatos() const;
};


class Prestamo{
    private:
        int _idPrestamo;
        int _idCliente;
        int _legajo;
        double _monto;
        double _tasaInteres;
        Fecha _fechaInicio;
        Fecha _fechaVencimiento;
        bool _prestamoVigente;
    public:
        Prestamo();
        Prestamo(int idPrestamo, int idCliente, int legajo, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento, bool prestamoVigente);

        int getIdPrestamo();
        int getIdCliente();
        int getLegajo();
        double getMonto();
        double getTasaInteres();
        Fecha getFechaInicio();
        Fecha getFechaVencimiento();
        bool getPrestamoVigente();

        void setIdPrestamo(int idPrestamo);
        void setIdCliente(int idCliente);
        void setLegajo(int legajo);
        void setMonto(double monto);
        void setTasaInteres(double tasaInteres);
        void setFechaInicio(Fecha fechaInicio);
        void setFechaVencimiento(Fecha fechaVencimiento);
        void setPrestamoVigente(bool prestamoVigente);

        void cargarDatos();
        string mostrarDatos();
};

#endif