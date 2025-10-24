#include "ArchivoEmpleados.h"
#include "tipoUsuario.h"
#include "config.h"
#include <cstdio>
using namespace std;

bool guardarEmpleados(const Empleado& empleado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "ab");
    if(archivo == nullptr){
        cout << "Error al abrir el archivo de empleados." << endl;
        return false;
    }
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
    fclose(archivo);
    return true;
}

// int generarLegajoEmpleado(){

// }

Empleado crearEmpleado(){
    Empleado nuevoEmpleado;
    // nuevoEmpleado.cargarDatos();
    // nuevoEmpleado.setLegajo(generarLegajoEmpleado());
    // guardarEmpleados(nuevoEmpleado);
    return nuevoEmpleado;
}