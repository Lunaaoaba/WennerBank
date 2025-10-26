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

int generarLegajo(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "rb");
    int maxId = 100000;
    if(archivo == nullptr) return 1;

    Empleado reg;
    while(fread(&reg, sizeof(Empleado), 1, archivo) == 1) if(reg.getLegajo() > maxId) maxId = reg.getLegajo();
    fclose(archivo);
    return maxId + 1;
}

Empleado crearEmpleado(){
    Empleado nuevoEmpleado;
    nuevoEmpleado.cargarDatos();
    nuevoEmpleado.setLegajo(generarLegajo());
    guardarEmpleados(nuevoEmpleado);
    return nuevoEmpleado;
}

void modificarEmpleado(Empleado* empleadoModificado){

}

void listarEmpleados(){

}

// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE EMPLEADOS
// ----------------------------------------------------------------------
void buscarEmpleadoLegajo(int legajo, Empleado &empleadoEncontrado){

}
void buscarEmpleadoDni(int dni, Empleado &empleadoEncontrado){

}
void buscarEmpleadoNombre(const char* nombre, Empleado &empleadoEncontrado){

}
void buscarEmpleadoApellido(const char* apellido, Empleado &empleadoEncontrado){

}
void buscarEmpleadoLocalidad(const char* localidad, Empleado &empleadoEncontrado){

}
void buscarEmpleadoEdad(int edad, Empleado &empleadoEncontrado){

}
void buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado){

}

//----------------------------------------------------------------------
//             FUNCIONES PARA EL EMPLEADO
// ----------------------------------------------------------------------
