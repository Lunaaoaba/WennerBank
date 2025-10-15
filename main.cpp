#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "funciones.h"
#include "fecha.h"
#include "tiempo.h"
#include "menu.h"
using namespace std;


int main(){
    Fecha fechaActual;
    Tiempo tiempoActual;
    fechaActual.cargarFechaActual();
    tiempoActual.cargarTiempoActual();
    cout << "Fecha actual: " << fechaActual.toString() << endl;
    cout << "Hora actual: " << tiempoActual.toString() << endl;
    system("pause");
    return 0;
}


// ----------------------------------------------------------------------

// NOTAS (Luna):
// FECHA: 10/10

// PARA CLASES:
// - CLIENTE DEBE CAMBIAR SU NOMBRE A USUARIO
// - DIVIDIR USUARIO(clase cliente) EN /PERSONA/ CON SUS RESPECTIVOS ATRIBUTOS Y METODOS (por si se agregan "roles" como empleado)
// - PERSONA DEBE TENER AL MENOS: NOMBRE, APELLIDO, DNI, LOCALIDAD
// - USUARIO(clase cliente) DEBE TENER: ID USUARIO, TIPO DE USUARIO (cliente, empleado, admin)
// - USUARIO(clase cliente) DEBE HEREDAR DE PERSONA
// - CUENTA BANCARIA DEBE HEREDAR DE USUARIO Y PERSONA

// FUNCIONES:
// - ORDENAR Y REHACER LAS FUNCIONES MARCADAS COMO REHACER
// - SE DEBEN REHACER LAS FUNCIONES (y casi todo) DE ARCHIVOS PORQUE UTILIZAN OTRA LIBRERIA, NO <cstdio>
// - SE NOTA BASTANTE EL USO DE LA IA
// - SE DEBEN ORDENAR PORQUE NO FIGURAN IGUAL EN EL .H  // X (listo)

// lamentablemente para hacer todo esto hay que rehacer casi todo

// ----------------------------------------------------------------------

// NOTAS (Gabi):
// FECHA: