#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "rlutil.h"
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


int main(){
    //para usar la �
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Fecha fechaActual;
    Tiempo tiempoActual;
    fechaActual.cargarFechaActual();
    tiempoActual.cargarTiempoActual();
    cout << "Fecha actual: " << fechaActual.mostrarFecha() << endl;
    cout << "Hora actual: " << tiempoActual.mostrarTiempo() << endl;
    /*
        para que funcione crear/mostrar cliente, eliminar los siguientes archivos:
        - func.cpp
        - func.h
        - funcTrsh.cpp
        - funcTrsh.h
    */
    
    //temporal para probar la creacion de objetos
    // cout << "Seleccione el tipo de entidad a crear:" << endl << "1. Cliente" << endl << "2. Empleado" << endl << "3. Cuenta Bancaria" << endl << "Ingrese opcion: ";
    // int tipo;
    // cin >> tipo;
    // switch(tipo){
    //     case 1: {
    //         cout << "crear cliente:" << endl;
    //         Cliente nuevoCliente = crearCliente();
    //         cout << nuevoCliente.mostrarDatos() << endl;
    //         system("pause");
    //         break;
    //     }
    //     case 2: {
    //         cout << "crear empleado:" << endl;
    //         // Empleado nuevoEmpleado = crearEmpleado(); 
    //         // cout << nuevoEmpleado.mostrarDatos() << endl;
    //         system("pause");
    //         break;
    //     }
    //     case 3: {
    //         cout << "crear cuenta bancaria:" << endl;
    //         // CuentaBancaria nuevaCuenta = crearCuentaBancaria();
    //         // cout << nuevaCuenta.mostrarDatos() << endl;
    //         system("pause");
    //         break;
    //     }
    // }

    //--------------------------------------------------------------
    //inicio beta del ingreso al inicio de sesion
    //obviamente esto iria en una funcion de menu

    while(true){
        system("cls");
        tituloBeta();
        cout << "welcome to te program:" << endl;
        int opc;

        cin >> opc;
        
        switch(opc){
            case 1: {
                cout << "crear cliente:" << endl;
                Cliente nuevoCliente = crearCliente();
                cout << nuevoCliente.mostrarDatos() << endl;
                system("pause");
                
                break;
            }
            case 2:
            menuEmpleado();
            break;
        }
        
    if(rlutil::getkey() == 19) menuAdministrador(); // Si se presiona 
    if(rlutil::getkey() == 27) break; // Si se presiona ESC
    }
    cout << "Fin del programa. goodbye to te program" << endl;
    system("pause");
    //--------------------------------------------------------------
    return 0;
}


// FUNCIONES:
// - ORDENAR Y REHACER LAS FUNCIONES MARCADAS COMO REHACER
// - SE DEBEN REHACER LAS FUNCIONES (y casi todo) DE ARCHIVOS PORQUE UTILIZAN OTRA LIBRERIA, NO <cstdio>
// - SE DEBEN ORDENAR PORQUE NO FIGURAN IGUAL EN EL .H  // X (listo)

// lamentablemente para hacer todo esto hay que rehacer casi todo