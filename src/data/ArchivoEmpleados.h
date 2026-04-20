#ifndef ARCHIVOEMPLEADOS_H
#define ARCHIVOEMPLEADOS_H
#include "empleado.h"

class ArchivoEmpleados{
    private:
        char _nombreArchivo[30];
    public:
        ArchivoEmpleados(const char* nombre = "empleados.dat");
        bool guardarEmpleados(const Empleado& empleado);
        Empleado crearEmpleado();

        bool modificarEmpleado(const Empleado& empleadoModificado);
        bool modificarDatosEmpleado(int legajo);

        bool eliminarEmpleado(int legajo);
        bool restaurarEmpleado(int legajo);

        void listarEmpleados();
        void listarTodosEmpleados();

        bool buscarEmpleado(const char* criterio, int valor, Empleado& encontrado);
        bool buscarEmpleado(const char* criterio, const char* valor, Empleado& encontrado);
        bool buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado);

        int generarLegajo();
        int posicionEmpleadoPorLegajo(int legajo);
};

#endif