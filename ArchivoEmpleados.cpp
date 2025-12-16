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
#include "config.h"
#include "art.h"

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

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(35, 3);
    cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
    rlutil::locate(35, 4);
    cout << char(186); centrarTexto("REGISTRO DE NUEVO EMPLEADO", ' ', 50); cout << char(186);
    rlutil::locate(35, 5);
    cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
    
    cout << endl << endl;
    rlutil::locate(40, 7);
    cout << "DNI: ";
    rlutil::locate(60, 7);
    dni = validarEntero(10000000, 99999999);
    while(existeDniEmpleado(dni)){
        rlutil::locate(60, 7);
        cout << string(20, ' ');
        rlutil::locate(40, 7);
        cout << string(40, ' ');
        rlutil::locate(40, 7);
        colorTexto(3);
        cout << "ERROR: DNI ya registrado";
        colorTexto(7);
        rlutil::msleep(1500);
        rlutil::locate(40, 7);
        cout << string(40, ' ');
        rlutil::locate(40, 7);
        cout << "DNI: ";
        rlutil::locate(60, 7);
        dni = validarEntero(10000000, 99999999);
    }
    
    rlutil::locate(40, 9);
    cout << "Nombre: ";
    rlutil::locate(60, 9);
    validarCadenaLetras(nombre, 50);
    
    rlutil::locate(40, 11);
    cout << "Apellido: ";
    rlutil::locate(60, 11);
    validarCadenaLetras(apellido, 50);
    
    rlutil::locate(40, 13);
    cout << "Localidad: ";
    rlutil::locate(60, 13);
    validarCadenaLetras(localidad, 50);
    
    rlutil::locate(40, 16);
    cout << "Fecha de Nacimiento:";
    fechaNacimiento.cargarFecha(60, 17);
    
    rlutil::locate(40, 21);
    cout << "Mail: ";
    rlutil::locate(60, 21);
    validarCadena(mail, 50);
    while(existeMail(mail)){
        rlutil::locate(40, 21);
        cout << string(40, ' ');
        rlutil::locate(40, 21);
        colorTexto(3);
        cout << "ERROR: Mail ya registrado";
        colorTexto(7);
        rlutil::msleep(1500);
        rlutil::locate(40, 21);
        cout << string(40, ' ');
        rlutil::locate(40, 21);
        cout << "Mail: ";
        rlutil::locate(60, 21);
        validarCadena(mail, 50);
    }
    
    rlutil::locate(40, 23);
    cout << "Contrase" << char(164) << "a (min 8 caracteres): ";
    rlutil::locate(60, 24);
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
        rlutil::locate(40, 26);
        colorTexto(3);
        cout << "ERROR: El empleado debe ser mayor de edad";
        rlutil::locate(40, 27);
        cout << "(Edad actual: " << edad << " a" << char(164) << "os - Requerido: 18+)";
        colorTexto(7);
        rlutil::locate(40, 29);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return Empleado();
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(35, 3);
    cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
    rlutil::locate(35, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE DATOS", ' ', 50); cout << char(186);
    rlutil::locate(35, 5);
    cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
    
    cout << endl << endl;
    rlutil::locate(40, 7);
    cout << "DNI: ";
    rlutil::locate(65, 7);
    cout << nuevoEmpleado.getDni();
    rlutil::locate(40, 8);
    cout << "Nombre: ";
    rlutil::locate(65, 8);
    cout << nuevoEmpleado.getNombre();
    rlutil::locate(40, 9);
    cout << "Apellido: ";
    rlutil::locate(65, 9);
    cout << nuevoEmpleado.getApellido();
    rlutil::locate(40, 10);
    cout << "Localidad: ";
    rlutil::locate(65, 10);
    cout << nuevoEmpleado.getLocalidad();
    rlutil::locate(40, 11);
    cout << "Fecha de Nacimiento: ";
    rlutil::locate(65, 11);
    cout << nuevoEmpleado.getFechaNacimiento().mostrarFecha() << " (Edad: " << nuevoEmpleado.getEdad() << " a" << char(164) << "os)";
    rlutil::locate(40, 12);
    cout << "Mail: ";
    rlutil::locate(65, 12);
    cout << nuevoEmpleado.getMail();
    rlutil::locate(40, 13);
    cout << "Legajo: ";
    rlutil::locate(65, 13);
    cout << nuevoEmpleado.getLegajo();
    rlutil::locate(40, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la creacion del empleado? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarEmpleados(nuevoEmpleado)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << char(251) << " Empleado creado con " << char(130) << "xito. Legajo: " << nuevoEmpleado.getLegajo();
            colorTexto(7);
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo guardar el nuevo empleado.";
            colorTexto(7);
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
    }
    return nuevoEmpleado;
}

bool ArchivoEmpleados::modificarEmpleado(const Empleado& empleadoModificado){
    int pos = posicionEmpleadoPorLegajo(empleadoModificado.getLegajo());

    if(pos < 0){
        if(pos == -1){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se encontro el empleado con legajo " << empleadoModificado.getLegajo() << "." << endl;
            colorTexto(7);
            return false;
        }
        if(pos == -2){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
            colorTexto(7);
            return false;
        }
    }
    FILE* archivo = fopen("empleados.dat", "rb+");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados para modificar." << endl;
        colorTexto(7);
        return false;
    }

    fseek(archivo, static_cast<long>(pos) * (long)sizeof(Empleado), SEEK_SET);
    bool exito;
    if (fwrite(&empleadoModificado, sizeof(Empleado), 1, archivo) == 1) exito = true;
    else exito = false;

    fclose(archivo);
    colorTexto(7);
    return exito;
} 

bool ArchivoEmpleados::modificarDatosEmpleado(int legajo){
    Empleado empleadoAModificar;

    Administrador* admin = Administrador::getInstancia(); 
    if(admin->getLegajo() == legajo){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede alterar este empleado.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    if(!buscarEmpleado("LEGAJO", legajo, empleadoAModificar)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    if(empleadoAModificar.getUsuarioEliminado()){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("MODIFICACION DE DATOS DEL EMPLEADO", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Datos actuales del empleado:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "DNI: " << empleadoAModificar.getDni();
    rlutil::locate(40, 10);
    cout << "Nombre: " << empleadoAModificar.getNombre();
    rlutil::locate(40, 11);
    cout << "Apellido: " << empleadoAModificar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << empleadoAModificar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Fecha de Nacimiento: " << empleadoAModificar.getFechaNacimiento().mostrarFecha();
    rlutil::locate(40, 14);
    cout << "Mail: " << empleadoAModificar.getMail();

    bool continuar = true;
    while(continuar){
        // Limpiar area de menu y trabajo
        for(int i = 16; i <= 28; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        rlutil::locate(35, 16);
        colorTexto(6);
        cout << "Seleccione el dato a modificar:";
        colorTexto(7);
        rlutil::locate(40, 18);
        cout << "1. Nombre";
        rlutil::locate(40, 19);
        cout << "2. Apellido";
        rlutil::locate(40, 20);
        cout << "3. Localidad";
        rlutil::locate(40, 21);
        cout << "4. Mail";
        rlutil::locate(40, 22);
        cout << "5. Contrase" << char(164) << "a";
        rlutil::locate(40, 23);
        cout << "6. Finalizar/Cancelar modificacion";
        
        rlutil::locate(35, 25);
        cout << char(175) << " Opcion: ";
        int opcion = validarEntero(1, 6);
        
        // Limpiar area de trabajo para la operacion
        for(int i = 16; i <= 28; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Nombre";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << empleadoAModificar.getNombre();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadenaLetras(nuevoNombre, 50);
                empleadoAModificar.setNombre(nuevoNombre);
                
                rlutil::locate(40, 10);
                cout << string(40, ' ');
                rlutil::locate(40, 10);
                cout << "Nombre: " << nuevoNombre;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Nombre actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 2: {
                char nuevoApellido[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Apellido";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << empleadoAModificar.getApellido();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadenaLetras(nuevoApellido, 50);
                empleadoAModificar.setApellido(nuevoApellido);
                
                rlutil::locate(40, 11);
                cout << string(40, ' ');
                rlutil::locate(40, 11);
                cout << "Apellido: " << nuevoApellido;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Apellido actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 3: {
                char nuevaLocalidad[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Localidad";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << empleadoAModificar.getLocalidad();
                rlutil::locate(40, 21);
                cout << "Nueva:  ";
                validarCadenaLetras(nuevaLocalidad, 50);
                empleadoAModificar.setLocalidad(nuevaLocalidad);
                
                rlutil::locate(40, 12);
                cout << string(40, ' ');
                rlutil::locate(40, 12);
                cout << "Localidad: " << nuevaLocalidad;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Localidad actualizada!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 4: {
                char nuevoMail[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Mail";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Actual: " << empleadoAModificar.getMail();
                rlutil::locate(40, 21);
                cout << "Nuevo:  ";
                validarCadena(nuevoMail, 50);
                while(existeMail(nuevoMail)){
                    rlutil::locate(40, 21);
                    cout << string(50, ' ');
                    rlutil::locate(40, 21);
                    colorTexto(3);
                    cout << "ERROR: Mail ya registrado";
                    colorTexto(7);
                    rlutil::msleep(1500);
                    rlutil::locate(40, 21);
                    cout << string(50, ' ');
                    rlutil::locate(40, 21);
                    cout << "Nuevo:  ";
                    validarCadena(nuevoMail, 50);
                }
                empleadoAModificar.setMail(nuevoMail);
                
                rlutil::locate(40, 14);
                cout << string(40, ' ');
                rlutil::locate(40, 14);
                cout << "Mail: " << nuevoMail;
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Mail actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 5: {
                char nuevaContrasena[50];
                rlutil::locate(35, 18);
                colorTexto(6);
                cout << "Modificar Contrase" << char(164) << "a";
                colorTexto(7);
                rlutil::locate(40, 20);
                cout << "Nueva contrase" << char(164) << "a: ";
                validarCadenaLargo(nuevaContrasena, 8, 50);
                empleadoAModificar.setContrasena(nuevaContrasena);
                
                rlutil::locate(40, 23);
                colorTexto(2);
                cout << char(251) << " Contrase" << char(164) << "a actualizada!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 6: {
                rlutil::locate(40, 18);
                colorTexto(6);
                cout << "Finalizando modificacion...";
                colorTexto(7);
                rlutil::msleep(1000);
                continuar = false;
                break;
            }
        }
    }
    
    if(modificarEmpleado(empleadoAModificar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(2);
        cout << char(251) << " Empleado modificado correctamente!";
        colorTexto(7);
        return true;
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo modificar el empleado.";
        colorTexto(7);
        return false;
    }
}

bool ArchivoEmpleados::eliminarEmpleado(int legajo){
    Empleado empleadoAEliminar;

    Administrador* admin = Administrador::getInstancia(); 
    if(admin->getLegajo() == legajo){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede eliminar este empleado.";
        colorTexto(7);
        return false;
    }

    if(!buscarEmpleado("LEGAJO", legajo, empleadoAEliminar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << ".";
        colorTexto(7);
        return false;
    }
    if(empleadoAEliminar.getUsuarioEliminado()){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: El empleado ya se encuentra eliminado.";
        colorTexto(7);
        return false;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE ELIMINACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Empleado a eliminar:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "Legajo: " << empleadoAEliminar.getLegajo();
    rlutil::locate(40, 10);
    cout << "DNI: " << empleadoAEliminar.getDni();
    rlutil::locate(40, 11);
    cout << "Nombre: " << empleadoAEliminar.getNombre() << " " << empleadoAEliminar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << empleadoAEliminar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Mail: " << empleadoAEliminar.getMail();
    rlutil::locate(40, 14);
    cout << "Fecha Nacimiento: " << empleadoAEliminar.getFechaNacimiento().mostrarFecha();
    
    rlutil::locate(35, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la eliminacion del empleado? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        empleadoAEliminar.setUsuarioEliminado(true);
        if(modificarEmpleado(empleadoAEliminar)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << char(251) << " Empleado eliminado correctamente!";
            colorTexto(7);
            rlutil::locate(40, 21);
            return true;
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo eliminar el empleado.";
            colorTexto(7);
            rlutil::locate(40, 21);
            return false;
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
        rlutil::locate(40, 21);
        return false;
    }
}

bool ArchivoEmpleados::restaurarEmpleado(int legajo){
    Empleado empleadoARestaurar;
    
    if(!buscarEmpleado("LEGAJO", legajo, empleadoARestaurar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el empleado con legajo " << legajo << ".";
        colorTexto(7);
        return false;
    }
    if(!empleadoARestaurar.getUsuarioEliminado()){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: El empleado se encuentra activo.";
        colorTexto(7);
        return false;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE RESTAURACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Empleado a restaurar:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "Legajo: " << empleadoARestaurar.getLegajo();
    rlutil::locate(40, 10);
    cout << "DNI: " << empleadoARestaurar.getDni();
    rlutil::locate(40, 11);
    cout << "Nombre: " << empleadoARestaurar.getNombre() << " " << empleadoARestaurar.getApellido();
    rlutil::locate(40, 12);
    cout << "Localidad: " << empleadoARestaurar.getLocalidad();
    rlutil::locate(40, 13);
    cout << "Mail: " << empleadoARestaurar.getMail();
    rlutil::locate(40, 14);
    cout << "Fecha Nacimiento: " << empleadoARestaurar.getFechaNacimiento().mostrarFecha();
    
    rlutil::locate(35, 17);
    colorTexto(6);
    cout << char(175) << " Confirma la restauracion del empleado? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        empleadoARestaurar.setUsuarioEliminado(false);
        if(modificarEmpleado(empleadoARestaurar)){
            rlutil::locate(40, 19);
            colorTexto(2);
            cout << char(251) << " Empleado restaurado correctamente!";
            colorTexto(7);
            return true;
        }
        else{
            rlutil::locate(40, 19);
            colorTexto(3);
            cout << "ERROR: No se pudo restaurar el empleado.";
            colorTexto(7);
            return false;
        }
    }
    else{
        rlutil::locate(40, 19);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
        return false;
    }
}

// ------ FUNCIONES PARA BUSQUEDA DE EMPLEADOS ------

void ArchivoEmpleados::listarEmpleados(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        colorTexto(7);
        return;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    cout << char(201); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(187) << endl;
    cout << char(186); 
    centrarTexto("LISTADO DE EMPLEADOS ACTIVOS", ' ', 60); 
    cout << char(186) << endl;
    cout << char(200); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(188) << endl << endl;
    
    Empleado empleadoActual;
    int contador = 0;
    
    while (fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(!empleadoActual.getUsuarioEliminado()){
            char legajoFormateado[20];
            formatearId(legajoFormateado, "EMP-", empleadoActual.getLegajo(), 6);
            
            cout << "Empleado #" << (contador + 1) << endl;
            cout << "Legajo: " << legajoFormateado << endl;
            cout << "DNI: " << empleadoActual.getDni() << endl;
            cout << "Nombre: " << empleadoActual.getNombre() << " " << empleadoActual.getApellido() << endl;
            cout << "Localidad: " << empleadoActual.getLocalidad() << endl;
            cout << "Mail: " << empleadoActual.getMail() << endl;
            cout << "Edad: " << empleadoActual.getEdad() << " a" << char(164) << "os" << endl;
            cout << endl;
            for(int i = 0; i < 60; i++) cout << char(196);
            cout << endl << endl;
            contador++;
        }
    }
    
    if(contador == 0){
        colorTexto(3);
        cout << "No hay empleados registrados." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "Total de empleados: " << contador << endl;
        colorTexto(7);
    }
    
    fclose(archivo);
}

void ArchivoEmpleados::listarTodosEmpleados(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        colorTexto(7);
        return;
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    cout << char(201); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(187) << endl;
    cout << char(186); 
    centrarTexto("LISTADO COMPLETO DE EMPLEADOS", ' ', 60); 
    cout << char(186) << endl;
    cout << char(200); 
    for(int i = 0; i < 60; i++) cout << char(205); 
    cout << char(188) << endl << endl;
    
    Empleado empleadoActual;
    int contador = 0;
    
    while (fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        char legajoFormateado[20];
        formatearId(legajoFormateado, "EMP-", empleadoActual.getLegajo(), 6);
        
        cout << "Empleado #" << (contador + 1);
        if(empleadoActual.getUsuarioEliminado()){
            colorTexto(3);
            cout << " [ ELIMINADO ]";
            colorTexto(7);
        }
        cout << endl;
        cout << "Legajo: " << legajoFormateado << endl;
        cout << "DNI: " << empleadoActual.getDni() << endl;
        cout << "Nombre: " << empleadoActual.getNombre() << " " << empleadoActual.getApellido() << endl;
        cout << "Localidad: " << empleadoActual.getLocalidad() << endl;
        cout << "Mail: " << empleadoActual.getMail() << endl;
        cout << "Edad: " << empleadoActual.getEdad() << " a" << char(164) << "os" << endl;
        cout << endl;
        for(int i = 0; i < 60; i++) cout << char(196);
        cout << endl << endl;
        contador++;
    }
    
    if(contador == 0){
        colorTexto(3);
        cout << "No hay empleados registrados." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "Total de empleados: " << contador << endl;
        colorTexto(7);
    }
    
    fclose(archivo);
}

//SOBRECARGA - el q usa int: (LEGAJO, DNI, EDAD)
bool ArchivoEmpleados::buscarEmpleado(const char* criterio, int valor, Empleado& encontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        colorTexto(7);
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
        else {
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda no reconocido." << endl;
            colorTexto(7);
        }

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

//SOBRECARGA - el q usa char: (NOMBRE, APELLIDO, LOCALIDAD)
bool ArchivoEmpleados::buscarEmpleado(const char* criterio, const char* valor, Empleado& encontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        colorTexto(7);
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
        else {
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda no reconocido." << endl;
            colorTexto(7);
        }

        if(seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoEmpleados::buscarEmpleadoNacimiento(Fecha fechaNacimiento, Empleado &empleadoEncontrado){
    FILE* archivo = fopen("empleados.dat", "rb");
    Empleado empleadoActual;
    if(archivo == nullptr){
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        colorTexto(7);
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