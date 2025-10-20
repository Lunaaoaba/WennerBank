#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H
// #include "persona.h"
#include "usuario.h"
using namespace std;

class Cliente : public Usuario{
    private:
        int _idCliente;
    public:
        Cliente();
        Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente);
        //set
        void setIdCliente(int idCliente);
        //get
        int getIdCliente();
        //otros
        void cargarDatos();
        string mostrarDatos();
};

class Empleado : public Usuario{
    protected:
        int _legajo;
        char _claveOperacion[20];
    public:
        Empleado();
        Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo, const char* claveOperacion);
        //set
        void setLegajo(int legajo);
        void setClaveOperacion(const char* claveOperacion);
        //get
        int getLegajo();
        const char* getClaveOperacion();
        //otros
        void cargarDatos();
        string mostrarDatos();
};


#endif