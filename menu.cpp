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
#include "config.h"

using namespace std;


void menuTest(){
    ArchivoClientes objClientes;
    ArchivoEmpleados objEmpleados;
    ArchivoCuentas objCuentas;
    ArchivoTransacciones objTransacciones;

    int opcion;
    bool continuar = true;
    while(continuar){
        limpiarPantalla();
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
        limpiarPantalla();
        switch (opcion){
            case 1: {
                objClientes.crearCliente();
                break;
            }
            case 2: {
                objClientes.listarClientes();
                break;
            }
            case 3: {
                objClientes.listarTodosClientes();
                break;
            }
            case 4: {
                cout << "Eliminar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.eliminarCliente(id);
                break;
            }
            case 5: {
                cout << "Restaurar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.restaurarCliente(id);
                break;
            }
            case 6: {
                cout << "Modificar Cliente" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objClientes.modificarDatosCliente(id);
                break;
            }
            case 7: {
                objEmpleados.crearEmpleado();
                break;
            }
            case 8: {
                objEmpleados.listarEmpleados();
                break;
            }
            case 9: {
                objEmpleados.listarTodosEmpleados();
                break;
            }
            case 10: {
                cout << "Borrar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.eliminarEmpleado(id);
                break;
            }
            case 11: {
                cout << "Restaurar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.restaurarEmpleado(id);
                break;
            }
            case 12: {
                cout << "Modificar Empleado" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese un ID/Legajo de usuario:" << endl;
                int id = validarEntero(1, 999999);
                objEmpleados.modificarDatosEmpleado(id);
                break;
            }
            case 13: {
                cout << "Crear Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID del cliente:" << endl;
                int idCliente = validarEntero(1, 999999);
                objCuentas.crearCuenta(idCliente);
                break;
            }
            case 14: {
                objCuentas.listarCuentas();
                break;
            }
            case 15: {
                system("cls");
                objCuentas.listarTodasCuentas();
                break;
            }
            case 16: {
                cout << "Eliminar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.eliminarCuenta(idCuenta);
                break;
            }
            case 17: {
                cout << "Restaurar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.restaurarCuenta(idCuenta);
                break;
            }
            case 18: {
                cout << "Modificar Cuenta Bancaria" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                objCuentas.modificarDatosCuenta(idCuenta);
                break;
            }
            case 19: {
                cout << "Listar Transacciones" << endl;
                cout << "---------------------" << endl;
                ArchivoTransacciones archivoTra;
                archivoTra.listarTransacciones();
                break;
            }
            case 20: {
                cout << "Listar Transacciones de una cuenta" << endl;
                cout << "---------------------" << endl;
                cout << "Ingrese el ID de la cuenta:" << endl;
                int idCuenta = validarEntero(1, 999999);
                ArchivoTransacciones archivoTra;
                archivoTra.listarTransaccionesCuenta(idCuenta);
                break;
            }
            case 21: {
                cout << "Saliendo del programa..." << endl << "byebye <3" << endl;
                rlutil::anykey();
                continuar = false;
                break;
            }
        }
    rlutil::anykey();
    }
}


void InicioPrograma(){
    ArchivoClientes objClientes;
    int idUsuarioActivo = -1;
    int tipoUsuarioActivo = 0;
    bool mostrarBienvenida = true;

    while(true){
        if(tipoUsuarioActivo == 0){
            if(mostrarBienvenida){
                entrada();
                mostrarBienvenida = false;
            }

            rlutil::hidecursor();
            int opcion = 0;
            bool curs = true;
            
            colorTexto(7);
            limpiarPantalla();
            
            rlutil::locate(40, 5);
            cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
            rlutil::locate(40, 6);
            cout << char(186); centrarTexto("WENNER BANK - MENU PRINCIPAL", ' ', 38); cout << char(186);
            rlutil::locate(40, 7);
            cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
            
            rlutil::locate(44, 9);
            cout << "Crear cuenta";
            rlutil::locate(44, 10);
            cout << "Iniciar sesion";
            rlutil::locate(44, 11);
            cout << "Iniciar sesion como empleado";
            rlutil::locate(44, 12);
            cout << "Salir";
            
            while(curs){
                rlutil::locate(42, 9 + opcion);
                cout << (char)175;
                
                int tecla = rlutil::getkey();
                
                rlutil::locate(42, 9 + opcion);
                cout << " ";
                
                switch(tecla){
                    case 14:
                        opcion--;
                        if(opcion < 0) opcion = 3;
                        break;
                        
                    case 15: 
                        opcion++;
                        if(opcion > 3) opcion = 0;
                        break;
                        
                    case 1:
                        curs = false;
                        rlutil::showcursor();
                        limpiarPantalla();
                        
                        switch(opcion){
                            case 0:
                                objClientes.crearCliente();
                                rlutil::anykey();
                                curs = true;
                                rlutil::hidecursor();
                                
                                colorTexto(7);
                                limpiarPantalla();
                                rlutil::locate(40, 5);
                                cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
                                rlutil::locate(40, 6);
                                cout << char(186); centrarTexto("WENNER BANK - MENU PRINCIPAL", ' ', 38); cout << char(186);
                                rlutil::locate(40, 7);
                                cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
                                rlutil::locate(44, 9);
                                cout << "Crear cuenta";
                                rlutil::locate(44, 10);
                                cout << "Iniciar sesion";
                                rlutil::locate(44, 11);
                                cout << "Iniciar sesion como empleado";
                                rlutil::locate(44, 12);
                                cout << "Salir";
                                break;
                                
                            case 1:
                                iniciarSesionCliente(idUsuarioActivo, tipoUsuarioActivo);
                                if(tipoUsuarioActivo == 0){
                                    curs = true;
                                    rlutil::hidecursor();
                                    
                                    colorTexto(7);
                                    limpiarPantalla();
                                    rlutil::locate(40, 5);
                                    cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
                                    rlutil::locate(40, 6);
                                    cout << char(186); centrarTexto("WENNER BANK - MENU PRINCIPAL", ' ', 38); cout << char(186);
                                    rlutil::locate(40, 7);
                                    cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
                                    rlutil::locate(44, 9);
                                    cout << "Crear cuenta";
                                    rlutil::locate(44, 10);
                                    cout << "Iniciar sesion";
                                    rlutil::locate(44, 11);
                                    cout << "Iniciar sesion como empleado";
                                    rlutil::locate(44, 12);
                                    cout << "Salir";
                                }
                                break;
                                
                            case 2: 
                                iniciarSesionEmpleado(idUsuarioActivo, tipoUsuarioActivo);
                                if(tipoUsuarioActivo == 0){
                                    curs = true;
                                    rlutil::hidecursor();
                                    
                                    colorTexto(7);
                                    limpiarPantalla();
                                    rlutil::locate(40, 5);
                                    cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
                                    rlutil::locate(40, 6);
                                    cout << char(186); centrarTexto("WENNER BANK - MENU PRINCIPAL", ' ', 38); cout << char(186);
                                    rlutil::locate(40, 7);
                                    cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
                                    rlutil::locate(44, 9);
                                    cout << "Crear cuenta";
                                    rlutil::locate(44, 10);
                                    cout << "Iniciar sesion";
                                    rlutil::locate(44, 11);
                                    cout << "Iniciar sesion como empleado";
                                    rlutil::locate(44, 12);
                                    cout << "Salir";
                                }
                                break;
                                
                            case 3:
                                limpiarPantalla();
                                cout << "Saliendo del programa..." << endl;
                                rlutil::anykey();
                                exit(0);
                        }
                        break;
                }
                
                if(tipoUsuarioActivo != 0) break;
            }
        }
        else{
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

            idUsuarioActivo = -1;
            tipoUsuarioActivo = 0;
        }
    }
}



void iniciarSesionCliente(int& idUsuarioActual, int& tipoUsuarioActual){
    Cliente clienteEncontrado;
    char mail[50], contrasena[50];

    int intentos = 0;
    while(intentos < 3){
        colorTexto(7);
        limpiarPantalla();
        
        rlutil::locate(40, 5);
        cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
        rlutil::locate(40, 6);
        cout << char(186); centrarTexto("INICIO DE SESION - CLIENTE", ' ', 38); cout << char(186);
        rlutil::locate(40, 7);
        cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
        
        rlutil::locate(44, 9);
        cout << "Ingresar mail: ";
        cin.getline(mail, 51);
        
        if(strlen(mail) == 0){
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "El mail no puede estar vacio";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue; 
        }
        
        rlutil::locate(44, 10);
        cout << "Ingresar contrase" << char(164) << "a: ";
        cin.getline(contrasena, 51);
        
        if(strlen(contrasena) == 0){
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "La contrasena no puede estar vacia";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }
        if(strlen(contrasena) < 8){
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "La contrasena debe tener al menos 8 caracteres";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }

        if(validarLoginCliente(mail, contrasena, clienteEncontrado)){
            idUsuarioActual = clienteEncontrado.getIdCliente();
            tipoUsuarioActual = 1;
            
            limpiarPantalla();
            colorTexto(2);
            rlutil::locate(40, 8);
            cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
            rlutil::locate(40, 9);
            cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
            rlutil::locate(40, 10);
            cout << char(186);
            string mensaje = "Bienvenido/a, " + string(clienteEncontrado.getNombre()) + "!";
            centrarTexto(mensaje, ' ', 38);
            cout << char(186);
            rlutil::locate(40, 11);
            cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
            rlutil::locate(40, 12);
            cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
            colorTexto(7);
            rlutil::anykey();
            break;
        }
        else{
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "Datos incorrectos";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
        }
    }
    
    if(tipoUsuarioActual == 0){
        limpiarPantalla();
        rlutil::locate(44, 10);
        colorTexto(3);
        cout << "Demasiados intentos fallidos";
        colorTexto(7);
        rlutil::msleep(2000);
    }
}   

void iniciarSesionEmpleado(int& idUsuarioActual, int& tipoUsuarioActual){
    Empleado empleadoEncontrado;
    int legajo;
    char contrasena[50];

    int intentos = 0;
    while(intentos < 3){
        colorTexto(7);
        limpiarPantalla();
        
        rlutil::locate(40, 5);
        cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
        rlutil::locate(40, 6);
        cout << char(186); centrarTexto("INICIO DE SESION - EMPLEADO", ' ', 38); cout << char(186);
        rlutil::locate(40, 7);
        cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
        
        rlutil::locate(44, 9);
        cout << "Ingresar legajo: ";
        cin >> legajo;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "Debe ingresar un numero";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }
        
        if(legajo < 1 || legajo > 999999){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "El legajo debe estar entre 1 y 999999";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        rlutil::locate(44, 10);
        cout << "Ingresar contrase" << char(164) << "a: ";
        cin.getline(contrasena, 51);
        
        if(strlen(contrasena) == 0){
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "La contrasena no puede estar vacia";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }
        if(strlen(contrasena) < 8){
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "La contrasena debe tener al menos 8 caracteres";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
            continue;
        }

        if(validarLoginEmpleado(legajo, contrasena, empleadoEncontrado)){
            idUsuarioActual = legajo;

            if(legajo == 1){ 
                tipoUsuarioActual = 3;
                
                limpiarPantalla();
                colorTexto(2);
                rlutil::locate(40, 8);
                cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
                rlutil::locate(40, 9);
                cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
                rlutil::locate(40, 10);
                cout << char(186); centrarTexto("Bienvenido/a, Administrador!", ' ', 38); cout << char(186);
                rlutil::locate(40, 11);
                cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
                rlutil::locate(40, 12);
                cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
                colorTexto(7);
            }
            else{
                tipoUsuarioActual = 2;
                
                limpiarPantalla();
                colorTexto(2);
                rlutil::locate(40, 8);
                cout << char(201); centrarTexto("", char(205), 38); cout << char(187);
                rlutil::locate(40, 9);
                cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
                rlutil::locate(40, 10);
                cout << char(186);
                string mensaje = "Bienvenido/a, " + string(empleadoEncontrado.getNombre()) + "!";
                centrarTexto(mensaje, ' ', 38);
                cout << char(186);
                rlutil::locate(40, 11);
                cout << char(186); centrarTexto("", ' ', 38); cout << char(186);
                rlutil::locate(40, 12);
                cout << char(200); centrarTexto("", char(205), 38); cout << char(188);
                colorTexto(7);
            }
            rlutil::anykey();
            break;
        }
        else{
            rlutil::locate(44, 13);
            colorTexto(3);
            cout << "Datos incorrectos";
            colorTexto(7);
            rlutil::msleep(1500);
            intentos++;
        }
    }
    
    if(tipoUsuarioActual == 0){
        limpiarPantalla();
        rlutil::locate(44, 10);
        colorTexto(3);
        cout << "Demasiados intentos fallidos";
        colorTexto(7);
        rlutil::msleep(2000);
    }
}