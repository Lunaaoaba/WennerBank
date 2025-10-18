#ifndef PERSONA_H
#define PERSONA_H
#include "fecha.h"
using namespace std;


class Persona{
    protected:
        char _dni[9];
        char _nombre[50];
        char _apellido[50];
        char _localidad [50];
        Fecha _fechaNacimiento;
    public:
        Persona();
        Persona(const char* dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento);

        const char* getDni();
        const char* getNombre();
        const char* getApellido();
        const char* getLocalidad();
        Fecha getFechaNacimiento();
        int getEdad();

        void setDni(const char* dni);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setLocalidad(const char* localidad);
        void setFechaNacimiento(Fecha fechaNacimiento);

        void cargarDatos();
        string mostrarDatos();
};




#endif