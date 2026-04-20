#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <windows.h>
#include "menu.h"
#include "funcionesArchivos.h"
#include "config.h"
using namespace std;


int main(){
    config();
    InicioPrograma();
    rlutil::anykey();
    return 0;
}
