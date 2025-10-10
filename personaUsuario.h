#ifndef PERSONAUSUARIO_H
#define PERSONAUSUARIO_H
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

};

class Usuario : Persona{ //antes Cliente
    private:
        char _mail[50];
        char _contrasena[50];
        bool _eliminado; //es por si el usuario está eliminado, true = si, false = no
    public:
    //constructores
        Usuario();
        Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* mail, const char* contrasena, bool eliminado);
        void setMail(const char* mail);
        void setContrasena(const char* contrasena);
        void setEliminado(bool eliminado);
    //getters
        const char* getMail();
        const char* getContrasena();
        bool getEliminado();
    //otros
};


#endif