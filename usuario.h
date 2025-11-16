#ifndef USUARIO_H
#define USUARIO_H
#include "persona.h"
using namespace std;

class Usuario : public Persona{
    protected:
        char _mail[50];
        char _contrasena[50];
        bool _UsuarioEliminado;
    public:
        Usuario();
        Usuario(int dni, const char* nombre, const char* apellido, const char* localidad, Fecha fechaNacimiento, const char* mail, const char* contrasena, bool UsuarioEliminado);
        //set
        void setMail(const char* mail);
        void setContrasena(const char* contrasena);
        void setUsuarioEliminado(bool UsuarioEliminado);
        //get
        const char* getMail() const;
        const char* getContrasena() const;
        bool getUsuarioEliminado() const;
        //otros
        void cargarDatos();
        string mostrarDatos() const;
};


#endif