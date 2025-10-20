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
        //get
        int getIdTransaccion();
        int getIdCuentaOrigen();
        int getIdCuentaDestino();
        double getMonto();
        Fecha getFechaTransaccion();
        Tiempo getHoraTransaccion();
        //set
        void setIdTransaccion(int idTransaccion);
        void setIdCuentaOrigen(int idCuentaOrigen);
        void setIdCuentaDestino(int idCuentaDestino);
        void setMonto(double monto);
        void setFechaTransaccion(Fecha fechaTransaccion);
        void setHoraTransaccion(Tiempo horaTransaccion);
        //otros
        void cargarDatos();
        string mostrarDatos();
};

class Prestamo{
    private:
        int _idPrestamo;
        int _idCliente;
        int _legajo;
        double _monto;
        double _tasaInteres; // porcentaje anual
        Fecha _fechaInicio;
        Fecha _fechaVencimiento;
    public:
        Prestamo();
        Prestamo(int idPrestamo, int idCliente, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento);
        //get
        int getIdPrestamo();
        int getIdCliente();
        int getLegajo();
        double getMonto();
        double getTasaInteres();
        Fecha getFechaInicio();
        Fecha getFechaVencimiento();
        //set
        void setIdPrestamo(int idPrestamo);
        void setIdCliente(int idCliente);
        void setLegajo(int legajo);
        void setMonto(double monto);
        void setTasaInteres(double tasaInteres);
        void setFechaInicio(Fecha fechaInicio);
        void setFechaVencimiento(Fecha fechaVencimiento);
        //otros
        void cargarDatos();
        string mostrarDatos();
};



#endif