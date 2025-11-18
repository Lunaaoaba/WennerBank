#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H
#include "usuario.h"

using namespace std;


class Cliente : public Usuario{
    protected:
        int _idCliente;
    public:
        Cliente();
        Cliente(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, int idCliente);

        int getIdCliente() const;

        string mostrarDatos() const;
};


class Empleado : public Usuario{
    protected:
        int _legajo;
    public:
        Empleado();
        Empleado(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  int legajo);

        int getLegajo() const;

        string mostrarDatos() const;
};

#endif