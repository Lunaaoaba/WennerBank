#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "cuentaBancaria.h"
#include "tipoUsuario.h"
#include "funciones.h"
#include "art.h"

using namespace std;


// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------


// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void InicioPrograma(){
        // system("cls");
        tituloBeta();
        while(rlutil::getkey() != 1){
            system("cls");
            tituloBetaSA();
            // rlutil::locate(1, 10);
            cout << "Presione \"ENTER\" para continuar..." << endl;
        }
        Opciones(); // Muestra el menú inicial en un bucle hasta que el usuario elija salir.
}

void Opciones(){
    while(true){
        cout << "\nMenu Principal:\n";
        int opcion = validarEntero("Ingrese una opcion (1-5): ", 1, 5);
        cout << "- Clientes (1)\n";
        cout << "- Cuentas (2)\n";
        cout << "- Empleados (3)\n";
        cout << "- Administrador (4)\n";
        cout << "- Salir (5)\n";
        switch(opcion){
            case 1:
                Clientes();
                break;
            case 2:
                Cuentas();
                break;
            case 3:
                Empleados();
                break;
            case 4:
                Admin();
                break;
            case 5:
                cout << "Gracias por usar Wenner Bank. ¡Hasta luego!" << endl;
                system("pause");
                exit(0);
        }
    }
}

void Clientes(){
    centrarTexto(" Menu Clientes ", char(255), 41);
    iniciarSesion();
}

void Cuentas(){
    centrarTexto(" Menu Cuentas ", char(255), 41);
}

void Empleados(){
    centrarTexto(" Menu Empleados ", char(255), 41);
}

void Admin(){
    centrarTexto(" Menu Administrador ", char(255), 41);
}

void iniciarSesion(){
    
}


// -------------------------------------------------------------------------------------------------------


