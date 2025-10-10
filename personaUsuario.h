#ifndef PERSONAUSUARIO_H
#define PERSONAUSUARIO_H
using namespace std;


class Persona{
    private:
        char _nombre[50];
        char _apellido[50];
        char _dni[9];
        char _localidad [50];
    public:
    //constructores
        Persona();
        Persona(const char* nombre, const char* apellido, const char* dni, const char* localidad);
    //getters
        const char* getNombre();
        const char* getApellido();
        const char* getDni();
        const char* getLocalidad();
    //setters
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setDni(const char* dni);
        void setLocalidad(const char* localidad);

};

class Usuario : Persona{ //antes Cliente
    private:
        int _idUsuario;
        bool _eliminado; //es por si el usuario está eliminado, true = si, false = no
        // char _mail[50];
        // char _contrasena[50];
    public:
    //constructores
        Usuario();
        Usuario(const char* nombre, const char* apellido, const char* dni, const char* localidad, int idUsuario, bool  eliminado);
    //setters
        void setIdUsuario(int idUsuario);
        void setEliminado(bool eliminado);
        // void setMail(const char* mail);
        // void setContrasena(const char* contrasena);
    //getters
        int getIdUsuario();
        bool getEliminado();
        // const char* getMail();
        // const char* getContrasena();
    //otros
};


#endif