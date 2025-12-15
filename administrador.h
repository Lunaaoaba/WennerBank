#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include "empleado.h"

using namespace std;


//(*)    ----- UTILIZACION DEL PATRON SINGLETON -----
// fuerza a que solo exista un unico objeto en todo el programa
// la propia clase se encarga de gestionar su unica instancia
// PROPIEDADES:
// DA UNICIDAD: SOLO PUEDE HABER UN ADMINISTRADOR EN EL SISTEMA
// DATOS FIJOS: NO SE GUARDA EN UN ARCHIVO NI ES MODIFICABLE
// ACCESO GLOBAL: SE PUEDE ACCEDER DESDE CUALQUIER PARTE DEL PROGRAMA

class Administrador : public Empleado{
    private:
        Administrador();
        static Administrador* instancia;
        bool _permisosGlobales;
    public:
        static Administrador* getInstancia();
        Administrador(const Administrador&) = delete;
        void operator=(const Administrador&) = delete;

        bool getPermisosGlobales() const;
};

#endif
/*
CONSTRUCTOR PRIVADO PARA BLOQUEAR LA CREACION DE OBJETOS DESDE FUERA
Nadie desde fuera de la clase (ni el main, ni el menu) puede usar new Administrador()
o declarar una variable Administrador. Si intentan hacerlo, el compilador dará error.
Es imposible crear un admin por accidente.

VARIABLE ESTATICA (instancia)
se necesita un lugar especial donde guardar ese único administrador.
En <administrador.h: static Administrador* instancia;>
En <administrador.cpp: Administrador* Administrador::instancia = nullptr;>

Esta es una variable global y única que pertenece a la clase, no a un objeto.
Al principio vale nullptr (está vacía), indicando que el Administrador aún no ha nacido.

ACCESO: getInstancia()
Como el constructor es privado, se necesita una función pública y estática (que se pueda usar sin tener un objeto)
para que el resto del programa pueda pedir al administrador (usa memoria dinámica).

COMO LLAMAR AL ADMINISTRADOR:

Administrador* admin = Administrador::getInstancia();

ejemplo de uso:

//...
Administrador* admin = Administrador::getInstancia();
if (admin->getPermisosGlobales() == true){
    cout << "El administrador tiene permisos globales" << endl;
}
else cout << "No tiene permisos globales" << endl;
//...






*/