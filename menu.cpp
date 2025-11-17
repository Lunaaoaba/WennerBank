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

void menuTest(){
    int opcion;
    while(true){
        system("cls");
        cout << "---------------------------" << endl;
        cout << "Menu de Pruebas - WennerBank" << endl;
        cout << "---------------------------" << endl;
        cout << "Tipos de id a tener en cuenta:" << endl;
        cout << "CL-xxxxx : ID Cliente" << endl;
        cout << "EM-xxxxx : Legajo Empleado" << endl;
        cout << "CU-xxxxx : ID Cuenta Bancaria" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Listar Clientes" << endl;
        cout << "3. Listar TODOS los clientes" << endl;
        cout << "4. Eliminar Cliente " << endl;
        cout << "5. Restaurar Cliente" << endl;
        cout << "6. Modificar Cliente " << endl;
        cout << "---------------------------" << endl;
        cout << "7. Crear Empleado" << endl;
        cout << "8. Listar Empleados" << endl;
        cout << "9. Listar TODOS los empleados" << endl;
        cout << "10. Eliminar Empleado" << endl;
        cout << "11. Restaurar Empleado" << endl;
        cout << "12. Modificar Empleado" << endl;
        cout << "---------------------------" << endl;
        cout << "13. Crear Cuenta (no implementado)" << endl;
        cout << "14. Listar Cuentas (no implementado)" << endl;
        cout << "15. Salir" << endl;
        cout << "---------------------------" << endl;
        cout << "Ingrese una opcion: ";
        opcion = validarEntero(1, 15);
        switch (opcion){
            case 1: {
                system("cls");
                crearCliente();
                break;
            }
            case 2: {
                system("cls");
                listarClientes();
                break;
            }
            case 3: {
                system("cls");
                listarTodosClientes();
                break;
            }
            case 4: {
                system("cls");
                cout << "Eliminar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                eliminarCliente(id);
                break;
            }
            case 5: {
                system("cls");
                cout << "Restaurar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                restaurarCliente(id);
                break;
            }
            case 6: {
                system("cls");
                cout << "Modificar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                modificarDatosCliente(id);
                break;
            }
            case 7: {
                system("cls");
                crearEmpleado();
                break;
            }
            case 8: {
                system("cls");
                listarEmpleados();
                break;
            }
            case 9: {
                system("cls");
                listarTodosEmpleados();
                break;
            }
            case 10: {
                system("cls");
                cout << "Borrar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                eliminarEmpleado(id);
                break;
            }
            case 11: {
                system("cls");
                cout << "Restaurar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                restaurarEmpleado(id);
                break;
            }
            case 12: {
                system("cls");
                cout << "Modificar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                modificarDatosEmpleado(id);
                break;
            }
            case 13: {
                system("cls");
                cout << "Crear Cuenta (no implementado)" << endl;
                // crearCuenta();
                break;
            }
            case 14: {
                system("cls");
                cout << "Listar Cuentas (no implementado)" << endl;
                // listarCuentas();
                break;
            }
            case 15: {
                system("cls");
                cout << "Saliendo del programa..." << endl << "byebye <3" << endl;
                system("pause");
                exit(0);
            }
        }
    system("pause");
    }
}

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
                    cout << "Tipo de usuario no reconocido. Cerrando sesion." << endl;
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
    (void)idUsuarioActivo;  // Marca como "usado intencionalmente"
    (void)sesionActiva;
    centrarTexto(" Menu Clientes ", char(255), 41);
}

void menuEmpleado(int idUsuarioActivo, bool& sesionActiva){
    (void)idUsuarioActivo;  // Marca como "usado intencionalmente"
    (void)sesionActiva;
    centrarTexto(" Menu Empleados ", char(255), 41);
}

void menuAdmin(bool& sesionActiva){
    (void)sesionActiva;
    centrarTexto(" Menu Administrador ", char(255), 41);
}

void iniciarSesionCliente(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual){
    Cliente clienteEncontrado;
    char mail[50];
    char contrasena[50];
    cout << "Ingresar mail: ";
    validarCadena(mail, 50);
    cout << "Ingresar contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);

    if(validarLoginCliente(mail, contrasena, clienteEncontrado)){
        sesionActiva = true;
        idUsuarioActual = clienteEncontrado.getIdCliente();
        tipoUsuarioActual = 1;
        cout << "Inicio de sesion exitoso. Bienvenido, " << clienteEncontrado.getNombre() << "!" << endl;
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;
}

void iniciarSesionEmpleado(bool& sesionActiva, int& idUsuarioActual, int& tipoUsuarioActual){
    Empleado empleadoEncontrado;
    int legajo;
    char contrasena[50];

    cout << "Ingresar legajo: ";
    legajo = validarEntero(1, 99999999);
    cout << "Ingresar contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);

    if(validarLoginEmpleado(legajo, contrasena, empleadoEncontrado)){
        sesionActiva = true;
        idUsuarioActual = legajo;

        if(legajo == 100000){
            tipoUsuarioActual = 3; // Administrador
            cout << "Inicio de sesion como Administrador." << endl;
        }
        else{
            tipoUsuarioActual = 2; // Empleado regular
            cout << "Inicio de sesion como Empleado. Bienvenido, " << empleadoEncontrado.getNombre() << "!" << endl;
        }
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;
}

// -------------------------------------------------------------------------------------------------------


