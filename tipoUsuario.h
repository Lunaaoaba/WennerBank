#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H
// #include "persona.h"
#include "usuario.h"
using namespace std;

class Cliente : public Usuario{
    private:
        char _idCliente[5];
    public:
    //constructores
        Cliente();
        Cliente(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* idCliente);
    //set
        void setIdCliente(const char* idCliente);
    //get
        const char* getIdCliente();
    //otros
        void mostrarDatos();
};


class Empleado : public Usuario{
    protected:
        char _legajo[6];
        char _claveOperacion[20];
    public:
    //constructores
        Empleado();
        Empleado(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* legajo, const char* claveOperacion);
    //setters
        void setLegajo(const char* legajo);
        void setClaveOperacion(const char* claveOperacion);
    //getters
        const char* getLegajo();
        const char* getClaveOperacion();
    //otros
        void cargarDatos();
        string toString();

};


#endif