#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "cuentaBancaria.h"
#include "tipoUsuario.h"
#include "funciones.h"
#include "art.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "funcionesArchivos.h"

using namespace std;


// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------


// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void InicioPrograma(){
    //inicio de sesion
    bool sesionActiva = false;
    int idUsuarioActivo = -1;
    int tipoUsuarioActivo = 0; // 1: cliente, 2: empleado, 3: admin
    int i = 0;
    while(true){
        if(!sesionActiva){
            system("cls");
            if(i==0) menuBienvenida();
            else{
                
            }
            iniciarSesionCliente(sesionActiva, idUsuarioActivo, tipoUsuarioActivo);
        }
        else{
            switch(tipoUsuarioActivo){
                case 1: // Cliente
                    menuCliente(idUsuarioActivo, sesionActiva);
                    break;
                case 2: // Empleado
                    menuEmpleado(idUsuarioActivo, sesionActiva);
                    break;
                case 3: // Administrador
                    menuAdmin(sesionActiva);
                    break;
                default:
                    cout << "Tipo de usuario no reconocido. Cerrando sesión." << endl;
                    sesionActiva = false;
                    idUsuarioActivo = -1;
                    tipoUsuarioActivo = 0;
                    break;
            }
        }
    i++;
    }
}

void menuBienvenida(){
    system("cls");
    tituloBeta();
    while(rlutil::getkey() != 1){
        system("cls");
        tituloBetaSA();
        cout << "Presione \"ENTER\" para continuar..." << endl;
    }
}

void menuCliente(int idUsuarioActivo, bool& sesionActiva){
    centrarTexto(" Menu Clientes ", char(255), 41);
}

void menuEmpleado(int idUsuarioActivo, bool& sesionActiva){
    centrarTexto(" Menu Empleados ", char(255), 41);
}

void menuAdmin(bool& sesionActiva){
    centrarTexto(" Menu Administrador ", char(255), 41);
}

void iniciarSesionCliente(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual){
    Cliente clienteEncontrado;
    char mail[50];
    char contrasena[50];
    cout << "Ingresar mail: ";
    cin >> mail;
    cout << "Ingresar contrase" << char(164) << "a: ";
    cin >> contrasena;

    if(validarLoginCliente(mail, contrasena, clienteEncontrado)){
        sesionActiva = true;
        idUsuarioActual = clienteEncontrado.getIdCliente();
        tipoUsuarioActual = 1;
        cout << "Inicio de sesión exitoso. Bienvenido, " << clienteEncontrado.getNombre() << "!" << endl;
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;
}

void iniciarSesionEmpleado(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual){
    Empleado empleadoEncontrado;
    int legajo;
    char contrasena[50];

    cout << "Ingresar legajo: ";
    cin >> legajo;
    cout << "Ingresar contrase" << char(164) << "a: ";
    cin >> contrasena;

    if(validarLoginEmpleado(legajo, contrasena, empleadoEncontrado)){
        sesionActiva = true;
        idUsuarioActual = legajo;

        if(legajo == 100000){
            tipoUsuarioActual = 3; // Administrador
            cout << "Inicio de sesión como Administrador." << endl;
        }
        else{
            tipoUsuarioActual = 2; // Empleado regular
            cout << "Inicio de sesión como Empleado. Bienvenido, " << empleadoEncontrado.getNombre() << "!" << endl;
        }
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;
}

void modificacion(){
    cout << "Modificar Cliente:" << endl;
    int id;
    cout << "Ingrese el ID del cliente a modificar: ";
    id = validarEntero("", 0, 999999);
    modificarCliente(id);
}
// -------------------------------------------------------------------------------------------------------


