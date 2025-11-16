#ifndef PERSONA_H
#define PERSONA_H
#include "fecha.h"
using namespace std;


class Persona{
    protected:
        int _dni;
        char _nombre[50];
        char _apellido[50];
        char _localidad [50];
        Fecha _fechaNacimiento;
    public:
        Persona();
        Persona(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento);

        void setDni(int dni);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setLocalidad(const char* localidad);
        void setFechaNacimiento(Fecha fechaNacimiento);

        int getDni() const;
        const char* getNombre() const;
        const char* getApellido() const;
        const char* getLocalidad() const;
        Fecha getFechaNacimiento() const;
        int getEdad() const;

        void cargarDatos();
        string mostrarDatos() const;
};

#endif