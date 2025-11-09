#include "ArchivoEmpleados.h"
#include "tipoUsuario.h"
#include "config.h"
#include <cstring>
#include <iostream>
using namespace std;

bool guardarEmpleados(const Empleado& empleado){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return false;
    }
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
    fclose(archivo);
    return true;
}

int generarLegajo(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "rb");
    int maxId = 0;
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

    if(guardarEmpleados(nuevoEmpleado)) cout << "Empleado creado con exito. Legajo: " << nuevoEmpleado.getLegajo() << endl;
    else cout << "ERROR: No se pudo guardar el nuevo empleado." << endl;
    return nuevoEmpleado;
}

// void modificarEmpleado(Empleado* empleadoModificado){
// }

// !!! implementar el filtrado de empleados eliminados
void listarEmpleados(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO_EMPLEADOS, "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }
    Empleado reg;
    int i = 0;
    cout << "Listado de Empleados:" << endl;
    cout << "---------------------" << endl;
    while (fread(&reg, sizeof(Empleado), 1, archivo) == 1){
        cout << reg.mostrarDatos() << endl;
        i++;
        cout << "---------------------" << endl;
    }
    if(i == 0){
        cout << "ERROR: No hay empleados registrados." << endl;
        cout << "---------------------" << endl;
        system("pause");
    }
    cout << "Total de empleados: " << i << endl;
    fclose(archivo);
}
    
    //----------------------------------------------------------------------
    //             FUNCIONES PARA EL EMPLEADO
    // ----------------------------------------------------------------------



// ----------------------------------------------------------------------
//             FUNCIONES PARA BUSQUEDA DE EMPLEADOS
// ----------------------------------------------------------------------

// void buscarEmpleadoLegajo(int legajo, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoDni(int dni, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoNombre(const char* nombre, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoApellido(const char* apellido, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoLocalidad(const char* localidad, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoEdad(int edad, Empleado &empleadoEncontrado){
// }

// void buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado){
// }
