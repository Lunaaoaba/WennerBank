#ifndef USUARIO_H
#define USUARIO_H
#include "persona.h"
using namespace std;

class Usuario : public Persona{
    private:
        char _mail[50];
        char _contrasena[50];
        bool _eliminado; //es por si el usuario está eliminado, true = si, false = no
    public:
    //constructores
        Usuario();
        Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad, const char* mail, const char* contrasena, bool eliminado);
        Usuario(const char* dni, const char* nombre, const char* apellido, const char* localidad);
        void setMail(const char* mail);
        void setContrasena(const char* contrasena);
        void setEliminado(bool eliminado);
    //getters
        const char* getMail();
        const char* getContrasena();
        bool getEliminado();
};


#endif