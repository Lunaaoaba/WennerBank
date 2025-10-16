#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "tipoUsuario.h"
#include <iostream>
using namespace std;

//       ----- UTILIZACION DEL PATRON SINGLETON -----
// fuerza a que solo exista un unico objeto en todo el programa
// la propia clase se encarga de gestionar su unica instancia
// PROPIEDADES:
// DA UNICIDAD: SOLO PUEDE HABER UN ADMINISTRADOR EN EL SISTEMA
// DATOS FIJOS: NO SE GUARDA EN UN ARCHIVO NI ES MODIFICABLE
// ACCESO GLOBAL: SE PUEDE ACCEDER DESDE CUALQUIER PARTE DEL PROGRAMA

class Administrador : public Empleado{
    private:
        // constructor privado para bloquear la creacion de objetos desde fuera
        Administrador();
        // puntero estatico para guardar la direccion de memoria del unico objeto
        static Administrador* instancia;
        // atributos propios del administrador
        char _claveMaestra[20];
        bool _permisosGlobales; // true = tiene permisos globales, false = no tiene permisos globales
    public:
        static Administrador* getInstancia();
        // se bloquea la copia para hacer el singleton mas seguro
        Administrador(const Administrador&) = delete;
        void operator=(const Administrador&) = delete;

        const char* getClaveMaestra();
        bool getPermisosGlobales();

        // METODOS UNICOS DEL ADMINISTRADOR

        void crearEmpleado();
        void modificarEmpleado();
        void eliminarEmpleado();
        void transferirFondos(char tipoUso, double monto, const char* idCuentaOrigen, const char* idCuentaDestino);
        // lo usa para cobrar multas etc y lo pasa automaticamente a la cuenta del banco
        void quitarFondos(double monto, const char* idCuenta); 

        // a funciones para que lo usen empleados y admin

        // void modificarCliente();
        // void eliminarCliente();
        // void ingresarFondos(double monto, const char* idCuenta);
        // void retirarFondos(double monto, const char* idCuenta);

        // void otorgarPrestamo();

        // void mostrarEmpleados();
        // void mostrarClientes();
        // void mostrarCuentas();
        // void mostrarPrestamos();
        // void mostrarMovimientos();
};

#endif