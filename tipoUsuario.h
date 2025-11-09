#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H
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
    public:
        Empleado();
        Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo);
        //set
        void setLegajo(int legajo);
        //get
        int getLegajo();
        //otros
        void cargarDatos();
        string mostrarDatos();
};

#endif