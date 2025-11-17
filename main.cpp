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
    - validar dsp el mail para q tenga formato correcto
    */

int main(){
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    iniciarArchivos(); // crea los archivos si no existen
    
    menuTest();

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