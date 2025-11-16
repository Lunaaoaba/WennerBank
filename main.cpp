#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <windows.h>
#include "funciones.h"
#include "funcionesArchivos.h"
#include "fecha.h"
#include "tiempo.h"
#include "menu.h"
#include "art.h"
#include "ArchivoClientes.h"
#include "ArchivoCuentas.h"
#include "ArchivoEmpleados.h"
#include "ArchivoMovimientos.h"
using namespace std;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// TODAS LAS ANOTACIONES SE ELIMINARAN EN LA VERSION FINAL
// PARA DEJAR EL CODIGO MAS LIMPIO Y SIN TANTOS COMENTARIOS
// Exepciones marcadas con : (*)
// ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡

/*
notas rapidas:
    - Revisar q en empleados nose pq se guardo un dni con dos ceros al final cuando no ingrese eso
    - validar dsp el mail para q tenga formato correcto
    - revisar pq no anda eliminarEmpleado, revisar modificarEmpleado tmb
    - mover todo este menu de pruebas a una funcion en menu.cpp/.h
    */

int main(){
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    iniciarArchivos(); // crea los archivos si no existen
    int opcion;

    // switch para probar crear cliente y listar clientes
    while(true){
        system("cls");
        cout << "---------------------------" << endl;
        cout << "Menu de Pruebas - WennerBank" << endl;
        cout << "---------------------------" << endl;
        cout << "Tipos de id a tener en cuenta:" << endl;
        cout << "CL-xxxxx : ID Cliente" << endl;
        cout << "EM-xxxxx : Legajo Empleado" << endl;
        cout << "CU-xxxxx : ID Cuenta Bancaria" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Listar Clientes" << endl;
        cout << "3. Listar TODOS los clientes" << endl;
        cout << "4. Borrar Cliente " << endl;
        cout << "5. Restaurar Cliente" << endl;
        cout << "6. Modificar Cliente " << endl << endl;
        cout << "7. Crear Empleado" << endl;
        cout << "8. Listar Empleados" << endl;
        cout << "9. Listar TODOS los empleados" << endl;
        cout << "10. Borrar Empleado" << endl;
        cout << "11. Restaurar Empleado" << endl;
        cout << "12. Modificar Empleado" << endl << endl;
        cout << "13. Crear Cuenta (no implementado)" << endl;
        cout << "14. Listar Cuentas (no implementado)" << endl;
        cout << "15. Salir" << endl << endl;
        cout << "Ingrese una opcion: ";
        opcion = validarEntero(1, 15);
        switch (opcion){
            case 1: {
                system("cls");
                crearCliente();
                break;
            }
            case 2: {
                system("cls");
                listarClientes();
                break;
            }
            case 3: {
                system("cls");
                listarTodosClientes();
                break;
            }
            case 4: {
                system("cls");
                cout << "Borrar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                eliminarCliente(id);
                break;
            }
            case 5: {
                system("cls");
                cout << "Modificar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                modificarDatosCliente(id);
                break;
            }
            case 6: {
                system("cls");
                crearEmpleado();
                break;
            }
            case 7: {
                system("cls");
                listarEmpleados();
                break;
            }
            case 8: {
                system("cls");
                listarTodosEmpleados();
                break;
            }
            case 9: {
                system("cls");
                cout << "Borrar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                eliminarEmpleado(id);
                break;
            }
            case 10: {
                system("cls");
                cout << "Modificar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                modificarDatosEmpleado(id);
                break;
            }
            case 11: {
                system("cls");
                cout << "Crear Cuenta (no implementado)" << endl;
                // crearCuenta();
                break;
            }
            case 12: {
                system("cls");
                cout << "Listar Cuentas (no implementado)" << endl;
                // listarCuentas();
                break;
            }
            case 13: {
                system("cls");
                cout << "Saliendo del programa..." << endl << "byebye <3" << endl;
                system("pause");
                exit(0);
            }
        }
    system("pause");
    }

    // InicioPrograma();
    // system("pause");
    //--------------------------------------------------------------
    return 0;
}



    // Fecha fechaActual;
    // Tiempo tiempoActual;
    // fechaActual.cargarFechaActual();
    // tiempoActual.cargarTiempoActual();
    // cout << "Fecha actual: " << fechaActual.mostrarFecha() << endl;
    // cout << "Hora actual: " << tiempoActual.mostrarTiempo() << endl;