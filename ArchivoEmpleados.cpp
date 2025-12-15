#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <cstdio>
#include <cstring>
#include <iostream>
#include "empleado.h"
#include "administrador.h"
#include "funciones.h"
#include "ArchivoEmpleados.h"
#include "funcionesArchivos.h"

using namespace std;


ArchivoEmpleados::ArchivoEmpleados(const char* nombre){ strcpy(_nombreArchivo, nombre); }   

bool ArchivoEmpleados::guardarEmpleados(const Empleado& empleado){
    FILE* archivo = fopen("empleados.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return false;
    }
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
    fclose(archivo);
    return true;
}

Empleado ArchivoEmpleados::crearEmpleado(){
    char nombre[50], apellido[50], localidad[50], mail[50], contrasena[50];
    int dni, legajo;
    Fecha fechaNacimiento;
    bool estado = false;

    system("cls");
    cout << "----- CREACION DE NUEVO EMPLEADO -----" << endl;
    cout << "Primer paso, ingresar datos del nuevo empleado:" << endl << endl;
    cout << "Ingrese DNI: ";
    dni = validarEntero(1000000, 99999999);
    while(existeDniEmpleado(dni)){
        cout << "ERROR: DNI ya registrado." << endl;
        cout << "Ingrese el DNI: ";
        dni = validarEntero(1000000, 99999999);
    }
    cout << "Ingrese Nombre: ";
    validarCadenaLetras(nombre, 50);
    cout << "Ingrese Apellido: ";
    validarCadenaLetras(apellido, 50);
    cout << "Ingrese Localidad: ";
    validarCadenaLetras(localidad, 50);
    cout << "Ingrese Fecha de Nacimiento:" << endl;
    fechaNacimiento.cargarFecha();
    cout << "Ingrese Mail: ";
    validarCadena(mail, 50);
    while(existeMail(mail)){
        cout << "ERROR: Mail ya registrado." << endl;
        cout << "Ingrese el mail: ";
        validarCadena(mail, 50);
    }
    cout << "Ingrese Contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);

    legajo = generarLegajo();

    Empleado nuevoEmpleado(
        dni,
        nombre,
        apellido,
        localidad,
        fechaNacimiento,
        mail,
        contrasena,
        estado,
        legajo
    );

    int edad = nuevoEmpleado.getEdad();
    if(edad < 18){
        cout << "ERROR: El empleado debe ser mayor de edad (actual: " << edad << " a" << char(164) << "os)." << endl;
        return Empleado(); // empleado vacio
    }

    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << nuevoEmpleado.mostrarDatos() << endl;
    cout << "\nConfirma la creacion del empleado? (S/N): ";
    
    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarEmpleados(nuevoEmpleado)){
            cout << "Empleado creado con exito. Legajo: " << nuevoEmpleado.getLegajo() << endl;
        }
        else{
            cout << "ERROR: No se pudo guardar el nuevo empleado." << endl;
        }
    }
    else cout << "Operacion cancelada." << endl;
    return nuevoEmpleado;
}

bool ArchivoEmpleados::modificarEmpleado(const Empleado& empleadoModificado){
    int pos = posicionEmpleadoPorLegajo(empleadoModificado.getLegajo());

    if(pos < 0){
        if(pos == -1){
            cout << "ERROR: No se encontro el empleado con legajo " << empleadoModificado.getLegajo() << "." << endl;
            return false;
        }
        if(pos == -2){
            cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
            return false;
        }
    }
    FILE* archivo = fopen("empleados.dat", "rb+");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados para modificar." << endl;
        return false;
    }

    fseek(archivo, static_cast<long>(pos) * (long)sizeof(Empleado), SEEK_SET);
    bool exito;
    if (fwrite(&empleadoModificado, sizeof(Empleado), 1, archivo) == 1) exito = true;
    else exito = false;

    fclose(archivo);
    return exito;
} 

bool ArchivoEmpleados::modificarDatosEmpleado(int legajo){
    Empleado empleadoAModificar;

    Administrador* admin = Administrador::getInstancia(); 
    if(admin->getLegajo() == legajo){
        cout << "ERROR: No se puede alterar este empleado." << endl;
        return false;
    }
    if(!buscarEmpleado("LEGAJO", legajo, empleadoAModificar)){
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << "." << endl;
        return false;
    }
    if(empleadoAModificar.getUsuarioEliminado()){
        cout << "ERROR: El empleado con legajo " << legajo << " esta eliminado." << endl;
        return false;
    }

    system("cls");
    cout << "----- MODIFICACION DE DATOS DEL EMPLEADO -----" << endl;
    cout << "Datos actuales del empleado:" << endl;
    cout << empleadoAModificar.mostrarDatos() << endl << endl;

    bool continuar = true;
    while(continuar){
        cout << "Seleccione el dato a modificar:" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Localidad" << endl;
        cout << "4. Mail" << endl;
        cout << "5. Contrase" << char(164) << "a" << endl;
        cout << "6. Finalizar/Cancelar modificacion" << endl << endl;
        // dsp cambiar a rlutil
        int opcion = validarEntero(1, 6);
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                cout << "Ingrese el nuevo nombre: ";
                validarCadenaLetras(nuevoNombre, 50);
                empleadoAModificar.setNombre(nuevoNombre);
                break;
            }
            case 2: {
                char nuevoApellido[50];
                cout << "Ingrese el nuevo apellido: ";
                validarCadenaLetras(nuevoApellido, 50);
                empleadoAModificar.setApellido(nuevoApellido);
                break;
            }
            case 3: {
                char nuevaLocalidad[50];
                cout << "Ingrese la nueva localidad: ";
                validarCadenaLetras(nuevaLocalidad, 50);
                empleadoAModificar.setLocalidad(nuevaLocalidad);
                break;
            }
            case 4: {
                char nuevoMail[50];
                cout << "Ingrese el nuevo mail: ";
                validarCadena(nuevoMail, 50);
                while(existeMail(nuevoMail)){
                    cout << "ERROR: Mail ya registrado." << endl;
                    cout << "Ingrese el mail: ";
                    validarCadena(nuevoMail, 50);
                }
                empleadoAModificar.setMail(nuevoMail);
                break;
            }
            case 5: {
                char nuevaContrasena[50];
                cout << "Ingrese la nueva contrase" << char(164) << "a: ";
                validarCadenaLargo(nuevaContrasena, 8, 50);
                empleadoAModificar.setContrasena(nuevaContrasena);
                break;
            }
            case 6: {
                cout << "Modificacion finalizada..." << endl;
                continuar = false;
                break;
            }
        }
    }
    if(modificarEmpleado(empleadoAModificar)){
        cout << "Empleado modificado correctamente." << endl;
        return true;
    }
    else{
        cout << "ERROR: No se pudo modificar el empleado." << endl;
        return false;
    }
}

bool ArchivoEmpleados::eliminarEmpleado(int legajo){
    Empleado empleadoAEliminar;

    Administrador* admin = Administrador::getInstancia(); 
    if(admin->getLegajo() == legajo){
        cout << "ERROR: No se puede alterar este empleado." << endl;
        return false;
    }

    if(!buscarEmpleado("LEGAJO", legajo, empleadoAEliminar)){
        cout << "ERROR: No se encontro el empleado con legajo " << empleadoAEliminar.getLegajo() << "." << endl;
        return false;
    }
    if(empleadoAEliminar.getUsuarioEliminado()){
        cout << "ERROR: El empleado con legajo " << empleadoAEliminar.getLegajo() << " ya se encuentra eliminado." << endl;
        return false;
    }
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Empleado a eliminar:" << endl;
    cout << empleadoAEliminar.mostrarDatos() << endl;
    cout << "\nConfirma la eliminacion del empleado? (S/N): ";

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        empleadoAEliminar.setUsuarioEliminado(true);
        if(modificarEmpleado(empleadoAEliminar)){
            cout << "Empleado con legajo " << legajo << " eliminado correctamente." << endl;
            return true;
        }
        else{
            cout << "ERROR: No se pudo eliminar el empleado con legajo " << legajo << "." << endl;
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n') cout << "Operacion cancelada." << endl;
    else cout << "Entrada no reconocida. Operacion cancelada." << endl;
    return false;
}

bool ArchivoEmpleados::restaurarEmpleado(int legajo){
    Empleado empleadoARestaurar;
    if(!buscarEmpleado("LEGAJO", legajo, empleadoARestaurar)){
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << "." << endl;
        return false;
    }
    if(!empleadoARestaurar.getUsuarioEliminado()){
        cout << "ERROR: El empleado con legajo " << legajo << " se encuentra activo." << endl;
        return false;
    }
    system("cls");
    cout << "----- CONFIRMACION DE DATOS -----" << endl;
    cout << "Empleado a restaurar:" << endl;
    cout << empleadoARestaurar.mostrarDatos() << endl;
    cout << "\nConfirma la restauracion del empleado? (S/N): ";

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        empleadoARestaurar.setUsuarioEliminado(false);
        if(modificarEmpleado(empleadoARestaurar)){
            cout << "Empleado con legajo " << empleadoARestaurar.getLegajo() << " restaurado correctamente." << endl;
            return true;
        }
        else{
            cout << "ERROR: No se pudo restaurar el empleado con legajo " << empleadoARestaurar.getLegajo() << "." << endl;
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n') cout << "Operacion cancelada." << endl;
    else cout << "Entrada no reconocida. Operacion cancelada." << endl;
    return false;
}

// ------ FUNCIONES PARA BUSQUEDA DE EMPLEADOS ------

void ArchivoEmpleados::listarEmpleados(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }
    Empleado empleadoActual;
    int i = 0;
    cout << "----- LISTADO DE EMPLEADOS -----" << endl;
    cout << "--------------------------------" << endl << endl;
    while (fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(!empleadoActual.getUsuarioEliminado()){
            cout << "Empleado: " << empleadoActual.getNombre() << " " << empleadoActual.getApellido() << endl;
            cout << empleadoActual.mostrarDatos() << endl;
            i++;
            cout << endl << "--------------------------------" << endl << endl;
        }
    }
    if(i == 0){
        cout << "ERROR: No hay empleados registrados." << endl;
        cout << "---------------------" << endl << endl;
    }
    cout << "Total de empleados: " << i << endl;
    fclose(archivo);
}

void ArchivoEmpleados::listarTodosEmpleados(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }
    Empleado empleadoActual;
    int i = 0;
    cout << "----- LISTADO DE EMPLEADOS -----" << endl;
    cout << "--------------------------------" << endl << endl;;
    while (fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        cout << "Empleado: " << empleadoActual.getNombre() << " " << empleadoActual.getApellido() << endl;
        cout << empleadoActual.mostrarDatos() << endl;
        if(empleadoActual.getUsuarioEliminado()) cout << "[ EMPLEADO ELIMINADO ]" << endl;
        i++;
        cout << endl << "--------------------------------" << endl << endl;
    }
    if(i == 0){
        cout << "ERROR: No hay empleados registrados." << endl;
        cout << "--------------------------------" << endl;
    }
    cout << "Total de empleados: " << i << endl;
    fclose(archivo);
}

//SOBRECARGA - el q usa int: (ID, DNI, EDAD)
bool ArchivoEmpleados::buscarEmpleado(const char* criterio, int valor, Empleado& encontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Empleado), 1, archivo)){
        if(strcmp(criterio, "LEGAJO") == 0){
            if(encontrado.getLegajo() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "DNI") == 0) {
            if(encontrado.getDni() == valor) seEncontro = true;
        }
        else if(strcmp(criterio, "EDAD") == 0){
            if(encontrado.getEdad() == valor) seEncontro = true;
        }
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//SOBRECARGA - el q usa char: (NOMBRE, APELLIDO, LOCALIDAD)
bool ArchivoEmpleados::buscarEmpleado(const char* criterio, const char* valor, Empleado& encontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrado, sizeof(Empleado), 1, archivo)){
        if(strcmp(criterio, "NOMBRE") == 0){
            if(strcmp(encontrado.getNombre(), valor) == 0) seEncontro = true;
        }
        else if(strcmp(criterio, "APELLIDO") == 0) {
            if(strcmp(encontrado.getApellido(), valor) == 0) seEncontro = true;
        }
        else if(strcmp(criterio, "LOCALIDAD") == 0) {
            if(strcmp(encontrado.getLocalidad(), valor) == 0) seEncontro = true;
        }
        else cout << "Criterio de busqueda no reconocido." << endl;

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoEmpleados::buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    Empleado empleadoActual;
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return false;
    }
    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        Fecha fecha = empleadoActual.getFechaNacimiento();
        if(compararFechas(fecha, fechaNacimiento)){
        empleadoEncontrado = empleadoActual;
        fclose(archivo);
        return true;
        }
    }
    fclose(archivo);
    return false;
}

int ArchivoEmpleados::generarLegajo(){
    FILE* archivo = fopen("empleados.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;

    Empleado empleadoActual;
    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(empleadoActual.getLegajo() > maxId){
            maxId = empleadoActual.getLegajo();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

int ArchivoEmpleados::posicionEmpleadoPorLegajo(int legajo){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr) return -2;
    Empleado empleadoActual;
    int pos = 0;
    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(empleadoActual.getLegajo() == legajo){
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}