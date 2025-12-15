#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "cuentaBancaria.h"
#include "cliente.h"
#include "empleado.h"
#include "funciones.h"
#include "art.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "funcionesArchivos.h"
#include "ArchivoCuentas.h"
#include "menuCliente.h"
#include "menuEmpleado.h"
#include "menuAdministrador.h"
#include "menuReportes.h"
#include "ArchivoTransacciones.h"

using namespace std;


// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------

void menuTest(){
    ArchivoClientes objClientes;
    ArchivoEmpleados objEmpleados;
    ArchivoCuentas objCuentas;
    ArchivoTransacciones objTransacciones;

    int opcion;
    bool continuar = true;
    while(continuar){
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
                // ya es posible implementar
        cout << "13. Crear Cuenta" << endl;
        cout << "14. Listar Cuentas" << endl;
        cout << "15. Listar TODAS las cuentas" << endl;
        cout << "16 Eliminar Cuenta" << endl;
        cout << "17. Restaurar Cuenta" << endl;
        cout << "18. Modificar Cuenta" << endl;
        cout << "---------------------------" << endl;
        cout << "19. Listar Transacciones" << endl;
        cout << "20. Listar Transacciones de una cuenta" << endl;
        cout << "21. Salir" << endl;
        cout << "---------------------------" << endl;
        cout << "Ingrese una opcion: ";
        opcion = validarEntero(1, 21);
        switch (opcion){
            case 1: {
                system("cls");
                objClientes.crearCliente();
                break;
            }
            case 2: {
                system("cls");
                objClientes.listarClientes();
                break;
            }
            case 3: {
                system("cls");
                objClientes.listarTodosClientes();
                break;
            }
            case 4: {
                system("cls");
                cout << "Eliminar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.eliminarCliente(id);
                break;
            }
            case 5: {
                system("cls");
                cout << "Restaurar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.restaurarCliente(id);
                break;
            }
            case 6: {
                system("cls");
                cout << "Modificar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.modificarDatosCliente(id);
                break;
            }
            case 7: {
                system("cls");
                objEmpleados.crearEmpleado();
                break;
            }
            case 8: {
                system("cls");
                objEmpleados.listarEmpleados();
                break;
            }
            case 9: {
                system("cls");
                objEmpleados.listarTodosEmpleados();
                break;
            }
            case 10: {
                system("cls");
                cout << "Borrar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.eliminarEmpleado(id);
                break;
            }
            case 11: {
                system("cls");
                cout << "Restaurar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.restaurarEmpleado(id);
                break;
            }
            case 12: {
                system("cls");
                cout << "Modificar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.modificarDatosEmpleado(id);
                break;
            }
            case 13: {
                system("cls");
                cout << "Crear Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID del cliente:" << endl;
                int idCliente = validarEntero(1, 999999);
                objCuentas.crearCuenta(idCliente);
                break;
            }
            case 14: {
                system("cls");
                objCuentas.listarCuentas();
                break;
            }
            case 15: {
                system("cls");
                objCuentas.listarTodasCuentas();
                break;
            }
            case 16: {
                system("cls");
                cout << "Eliminar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.eliminarCuenta(idCuenta);
                break;
            }
            case 17: {
                system("cls");
                cout << "Restaurar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.restaurarCuenta(idCuenta);
                break;
            }
            case 18: {
                system("cls");
                cout << "Modificar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.modificarDatosCuenta(idCuenta);
                break;
            }
            case 19: {
                system("cls");
                cout << "Listar Transacciones" << endl;
                cout << "---------------------" << endl;
                ArchivoTransacciones archivoTra;
                archivoTra.listarTransacciones();
                break;
            }
            case 20: {
                system("cls");
                cout << "Listar Transacciones de una cuenta" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                ArchivoTransacciones archivoTra;
                archivoTra.listarTransaccionesCuenta(idCuenta);
                break;
            }
            case 21: {
                system("cls");
                cout << "Saliendo del programa..." << endl << "byebye <3" << endl;
                system("pause");
                continuar = false;
                break;
            }
        }
    system("pause");
    }
}

// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void menuBienvenida(){
    system("cls");
    tituloBeta();
    bool continuar = true;
    while(continuar){
        int key = rlutil::getkey();
        tituloBetaSA();
        switch(key){
            case 1: { // ENTER
                continuar = false;
                break;
            }
            case 19: { // F1
                menuReportes();
                continuar = false;
                break;
            }
            default: {
                cout << "Presione \"ENTER\" para continuar..." << endl;
                break;
            }

        }
    }
}


void InicioPrograma(){
    //inicio de sesion
    ArchivoClientes objClientes;
    int idUsuarioActivo = -1;
    int tipoUsuarioActivo = 0; // 1: cliente, 2: empleado, 3: admin
    bool mostrarBienvenida = true;

    while(true){
        if(tipoUsuarioActivo == 0){
            system("cls");

            if(mostrarBienvenida){
                //rlutil::setBackgroundColor(1);
                menuBienvenida();
                mostrarBienvenida = false;
            }

            system("cls");
            //rlutil::setBackgroundColor(1);
            rlutil::locate(40, 5);
            cout << "========================================" << endl;
            rlutil::locate(40, 6);
            cout << "      WENNER BANK - MENU PRINCIPAL" << endl;
            rlutil::locate(40, 7);
            cout << "========================================" << endl << endl;
            rlutil::locate(40, 8);
            cout << "1. Crear cuenta (Cliente)" << endl;
            rlutil::locate(40, 9);
            cout << "2. Iniciar sesion (Cliente)" << endl;
            rlutil::locate(40, 10);
            cout << "3. Iniciar sesion (Empleado/Admin)" << endl;
            rlutil::locate(40, 11);
            cout << "4. Salir" << endl << endl;

            int opcion = validarEntero(1, 6);
            switch(opcion){
                case 1: {
                    objClientes.crearCliente();
                    system("pause");
                    break;
                }
                case 2: {
                    iniciarSesionCliente(idUsuarioActivo, tipoUsuarioActivo);
                    break;
                }
                case 3: {
                    iniciarSesionEmpleado(idUsuarioActivo, tipoUsuarioActivo);
                    break;
                }
                case 4: {
                    system("cls");
                    cout << "Saliendo del programa..." << endl;
                    cout << ":3" << endl;
                    system("pause");
                    exit(0);
                }
                case 5: {
                    menuTest();
                    break;
                }
                case 6: {
                    menuReportes();
                    break;
                }
            }
        }
        else{
            // Usuario logueado - mostrar menú según tipo
            switch(tipoUsuarioActivo){
                case 1: {
                    menuCliente(idUsuarioActivo);
                    break;
                }
                case 2: {
                    menuEmpleado(idUsuarioActivo);
                    break;
                }
                case 3: {
                    menuAdmin();
                    break;
                }
            }

            // Al salir del menú específico, cerrar sesión
            idUsuarioActivo = -1;
            tipoUsuarioActivo = 0;
        }
    }
}



void iniciarSesionCliente(int& idUsuarioActual, int& tipoUsuarioActual){
    Cliente clienteEncontrado;
    char mail[50], contrasena[50];

    system("cls");
    rlutil::locate(40, 2);
    cout << "========================================" << endl;
    cout << "    INICIO DE SESION - CLIENTE" << endl;
    cout << "========================================" << endl << endl;

    cout << "Ingresar mail: ";
    validarCadena(mail, 50);
    cout << "Ingresar contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);

    if(validarLoginCliente(mail, contrasena, clienteEncontrado)){
        idUsuarioActual = clienteEncontrado.getIdCliente();
        tipoUsuarioActual = 1; // cliente
        system("cls");
        rlutil::locate(40, 2);
        cout << "========================================" << endl;
        cout << "  Bienvenido/a, " << clienteEncontrado.getNombre() << "!" << endl;
        cout << "========================================" << endl;
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;

    system("pause");
}

void iniciarSesionEmpleado(int& idUsuarioActual, int& tipoUsuarioActual){
    Empleado empleadoEncontrado;
    int legajo;
    char contrasena[50];

    system("cls");
    rlutil::locate(40, 2);
    cout << "========================================" << endl;
    cout << "    INICIO DE SESION - EMPLEADO" << endl;
    cout << "========================================" << endl << endl;

    cout << "Ingresar legajo: ";
    legajo = validarEntero(1, 999999);
    cout << "Ingresar contrase" << char(164) << "a: ";
    validarCadenaLargo(contrasena, 8, 50);

    if(validarLoginEmpleado(legajo, contrasena, empleadoEncontrado)){
        idUsuarioActual = legajo;

        if(legajo == 1){ // admin
            tipoUsuarioActual = 3; // admin
            system("cls");
            cout << "========================================" << endl;
            cout << "  Bienvenido/a, Administrador!" << endl;
            cout << "========================================" << endl;
        }
        else{
            tipoUsuarioActual = 2; // empleado normal
            system("cls");
            cout << "========================================" << endl;
            cout << "  Bienvenido/a, " << empleadoEncontrado.getNombre() << "!" << endl;
            cout << "========================================" << endl;
        }
    }
    else cout << "ERROR: Credenciales incorrectas. Intente nuevamente." << endl;

    system("pause");
}

// -------------------------------------------------------------------------------------------------------