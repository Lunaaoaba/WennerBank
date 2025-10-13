#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
using namespace std;

class Transaccion{
    char _idTransaccion[5]; // 4 digitos + '\0'
    char _idCuentaOrigen[5]; // 4 digitos + '\0'
    char _idCuentaDestino[5]; // 4 digitos + '\0'
    double _monto;
    // Fecha _fecha;

};

class Prestamo{
    char _idPrestamo[5]; // 4 digitos + '\0'
    char _idCliente[5]; // 4 digitos + '\0'
    double _monto;
    double _tasaInteres; // porcentaje anual
    // Fecha _fechaInicio;
    // Fecha _fechaVencimiento;

    // Fecha _fecha;

};



#endif