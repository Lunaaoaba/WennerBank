#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <windows.h>
#include "funciones.h"
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
// --------------------------------------------------------
/*  Nota: mis cambios no estan finalizados, subo solo para mostrar el avance
        y que los vayan viendo. Mañana sigo con las correcciones:
        Avances q fui haciendo:
        - ArchivoClientes: funciones de busqueda unificadas y corregidas (*)
        - ArchivoEmpleados: funciones de busqueda unificadas y corregidas (falta)
        - Me corregí una falta ortografica en las advertencias :V
        - nose m olvidé qmas deaa

    Nota 2: revisar los comentarios marcados con (!!!) en los archivos

    Nota 3: USAR LAS FUNCIONES DE validarCadena Y validarEntero PARA CUALQUIER INGRESO DE DATOS DESDE CONSOLA */
    
int main(){
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
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
        cout << "3. Borrar Cliente " << endl;
        cout << "4. Modificar Cliente " << endl;
        cout << "5. Crear Empleado" << endl;
        cout << "6. Listar Empleados" << endl;
        cout << "7. Borrar Empleado" << endl;
        cout << "8. Modificar Empleado" << endl;
        cout << "9. Crear Cuenta" << endl;
        cout << "10. Listar Cuentas" << endl;
        cout << "11. Salir" << endl << endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                system("cls");
                crearCliente();
                break;
            case 2:
                system("cls");
                listarClientes();
                break;
            case 3:
                system("cls");
                cout << "Borrar Cliente" << endl;
                // borrarCliente();
                break;
            case 4:
                system("cls");
                modificacion();
                break;
            case 5:
                system("cls");
                crearEmpleado();
                break;
            case 6:
                system("cls");
                listarEmpleados();
                break;
            case 7:
                system("cls");
                cout << "Borrar Empleado" << endl;
                // borrarEmpleado();
                break;
            case 8:
                system("cls");
                cout << "Modificar Empleado" << endl;
                // modificarEmpleado();
                break;
            case 9:
                system("cls");
                cout << "Crear Cuenta" << endl;
                // crearCuenta();
                break;
            case 10:
                system("cls");
                cout << "Listar Cuentas" << endl;
                // listarCuentas();
                break;
            case 11:
                system("cls");
                cout << "Saliendo del programa..." << endl;
                system("pause");
                exit(0);
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