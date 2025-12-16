#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <windows.h>
#include "menu.h"
#include "funcionesArchivos.h"
#include "config.h"
using namespace std;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// TODAS LAS ANOTACIONES SE ELIMINARAN EN LA VERSION FINAL
// PARA DEJAR EL CODIGO MAS LIMPIO Y SIN TANTOS COMENTARIOS
// Exepciones marcadas con : (*)
// ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡


int main(){
    config();
    // InicioPrograma();

    menuTest();
    rlutil::anykey();

    // color
    // colorTexto();

    // limpia:
    // limpiarPantalla();

    // pausa:
    // rlutil::anykey();
    return 0;
}
