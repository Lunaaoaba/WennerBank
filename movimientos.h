#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "tiempo.h"
#include "fecha.h"
using namespace std;

class Transaccion{
    private:
        char _idTransaccion[5]; // 4 digitos + '\0'
        char _idCuentaOrigen[5]; // 4 digitos + '\0'
        char _idCuentaDestino[5]; // 4 digitos + '\0'
        double _monto;
        Fecha _fechaTransaccion;
        Tiempo _horaTransaccion;
    public:
        Transaccion();
        Transaccion(const char* idTransaccion, const char* idCuentaOrigen, const char* idCuentaDestino, double monto, Fecha fechaTransaccion, Tiempo horaTransaccion);

        const char* getIdTransaccion();
        const char* getIdCuentaOrigen();
        const char* getIdCuentaDestino();
        double getMonto();
        Fecha getFechaTransaccion();
        Tiempo getHoraTransaccion();

        void setIdTransaccion(const char* idTransaccion);
        void setIdCuentaOrigen(const char* idCuentaOrigen);
        void setIdCuentaDestino(const char* idCuentaDestino);
        void setMonto(double monto);
        void setFechaTransaccion(Fecha fechaTransaccion);
        void setHoraTransaccion(Tiempo horaTransaccion);

        void cargarDatos();
        string mostrarDatos();
};

class Prestamo{
    private:
        char _idPrestamo[5]; // 4 digitos + '\0'
        char _idCliente[5]; // 4 digitos + '\0'
        double _monto;
        double _tasaInteres; // porcentaje anual
        Fecha _fechaInicio;
        Fecha _fechaVencimiento;
    public:
        Prestamo();
        Prestamo(const char* idPrestamo, const char* idCliente, double monto, double tasaInteres, Fecha fechaInicio, Fecha fechaVencimiento);

        const char* getIdPrestamo();
        const char* getIdCliente();
        double getMonto();
        double getTasaInteres();
        Fecha getFechaInicio();
        Fecha getFechaVencimiento();

        void setIdPrestamo(const char* idPrestamo);
        void setIdCliente(const char* idCliente);
        void setMonto(double monto);
        void setTasaInteres(double tasaInteres);
        void setFechaInicio(Fecha fechaInicio);
        void setFechaVencimiento(Fecha fechaVencimiento);

        void cargarDatos();
        string mostrarDatos();
};



#endif