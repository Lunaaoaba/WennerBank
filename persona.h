#ifndef PERSONA_H
#define PERSONA_H
using namespace std;


class Persona{
    private:
        char _dni[9];
        char _nombre[50];
        char _apellido[50];
        char _localidad [50];
    public:
    //constructores
        Persona();
        Persona(const char* dni, const char* nombre, const char* apellido, const char* localidad);
    //getters
        const char* getDni();
        const char* getNombre();
        const char* getApellido();
        const char* getLocalidad();
    //setters
        void setDni(const char* dni);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setLocalidad(const char* localidad);
    //otros
        void mostrarDatos();
};




#endif