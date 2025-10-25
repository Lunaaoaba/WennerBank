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


int main(){
    //para usar la ñ
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // test
    // NOTA: REEMPLAZAR LOS char(num) POR LOS CARACTERES CORRESPONDIENTES
    cout << "lineas" << endl;
    cout << "\xE2\x95\x90" << endl;
    cout << "\xE2\x95\x91" << endl;
    cout << "esquinas" << endl;
    cout << "\xE2\x95\x94" << endl;
    cout << "\xE2\x95\x97" << endl;
    cout << "\xE2\x95\x9A" << endl;
    cout << "\xE2\x95\x9D" << endl;
    cout << "verticales con esquinas" << endl;
    cout << "\xE2\x95\xA0" << endl;
    cout << "\xE2\x95\x9F" << endl;
    cout << "\xE2\x95\xA3" << endl;
    cout << "\xE2\x95\xA2" << endl;
    cout << "horizontales con esquinas" << endl;
    cout << "\xE2\x95\xA6" << endl;
    cout << "\xE2\x95\xA4" << endl;
    cout << "\xE2\x95\xA9" << endl;
    cout << "\xE2\x95\xA7" << endl;
    cout << "cruces" << endl;
    cout << "\xE2\x95\xAC" << endl;
    cout << "\xE2\x95\xAA" << endl;

    cout << "-------------------" << endl;
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
    
    //--------------------------------------------------------------
    //inicio beta del ingreso al inicio de sesion

    // menuPrincipal();

    system("pause");
    //--------------------------------------------------------------
    return 0;
}


// FUNCIONES:
// - ORDENAR Y REHACER LAS FUNCIONES MARCADAS COMO REHACER
// - SE DEBEN REHACER LAS FUNCIONES (y casi todo) DE ARCHIVOS PORQUE UTILIZAN OTRA LIBRERIA, NO <cstdio>
// - SE DEBEN ORDENAR PORQUE NO FIGURAN IGUAL EN EL .H  // X (listo)

// lamentablemente para hacer todo esto hay que rehacer casi todo