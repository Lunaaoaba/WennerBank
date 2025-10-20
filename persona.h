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
        //get
        int getDni();
        const char* getNombre();
        const char* getApellido();
        const char* getLocalidad();
        Fecha getFechaNacimiento();
        int getEdad();
        //set
        void setDni(int dni);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setLocalidad(const char* localidad);
        void setFechaNacimiento(Fecha fechaNacimiento);
        //otros
        void cargarDatos();
        string mostrarDatos();
};




#endif