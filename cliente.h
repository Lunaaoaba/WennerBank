#ifndef CLIENTE_H
#define CLIENTE_H
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

#endif