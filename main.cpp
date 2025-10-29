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
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    Fecha fechaActual;
    Tiempo tiempoActual;
    fechaActual.cargarFechaActual();
    tiempoActual.cargarTiempoActual();
    cout << "Fecha actual: " << fechaActual.mostrarFecha() << endl;
    cout << "Hora actual: " << tiempoActual.mostrarTiempo() << endl;

    // crearCliente();
    //--------------------------------------------------------------
    //inicio beta del ingreso al inicio de sesion

    // InicioPrograma();


    centrarTexto("", char(219), char(196), size_t(125));
    system("pause");
    //--------------------------------------------------------------
    return 0;
}