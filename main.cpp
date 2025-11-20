#include <iostream>
#include <windows.h>
#include "menu.h"
#include "funcionesArchivos.h"
using namespace std;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// TODAS LAS ANOTACIONES SE ELIMINARAN EN LA VERSION FINAL
// PARA DEJAR EL CODIGO MAS LIMPIO Y SIN TANTOS COMENTARIOS
// Exepciones marcadas con : (*)
// ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡


int main(){
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    iniciarArchivos(); // crea los archivos si no existen
    
    // menuTest();

    InicioPrograma();

    system("pause");
    //--------------------------------------------------------------
    return 0;
}
