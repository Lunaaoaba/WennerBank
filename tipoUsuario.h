#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H
// #include "persona.h"
#include "usuario.h"
using namespace std;

class Cliente : public Usuario{
    private:
        char _idCliente[5];
    public:
        Cliente();
        Cliente(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool estado, const char* idCliente);

        void setIdCliente(const char* idCliente);

        const char* getIdCliente();

        void cargarDatos();
        string mostrarDatos();
};

class Empleado : public Usuario{
    protected:
        char _legajo[6];
        char _claveOperacion[20];
    public:
        Empleado();
        Empleado(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado,  const char* legajo, const char* claveOperacion);

        void setLegajo(const char* legajo);
        void setClaveOperacion(const char* claveOperacion);

        const char* getLegajo();
        const char* getClaveOperacion();

        void cargarDatos();
        string mostrarDatos();
};


#endif