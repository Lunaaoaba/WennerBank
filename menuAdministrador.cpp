#include <iostream>
#include <cstdlib>
#include "menuAdministrador.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "administrador.h"
#include "funciones.h"
#include "art.h"

using namespace std;

void menuAdmin(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "       MENU ADMINISTRADOR" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Listados" << endl;
        cout << "2. Busquedas" << endl;
        cout << "3. Empleados" << endl;
        cout << "4. Clientes" << endl;
        cout << "5. Cuentas" << endl;
        cout << "6. Cerrar sesion" << endl << endl;

        int opcion = validarEntero(1, 6);

        switch(opcion){
            case 1: {
                menuListadosAdmin();
                break;
            }
            case 2: {
                menuBusquedasAdmin();
                break;
            }
            case 3: {
                gestionarEmpleados();
                break;
            }
            case 4: {
                gestionarClientesAdmin();
                break;
            }
            case 5: {
                gestionarCuentasAdmin();
                break;
            }
            case 6: {
                continuar = false;
                break;
            }
        }
    }
}

void menuListadosAdmin(){
    ArchivoClientes objClientes;
    ArchivoEmpleados objEmpleados;
    ArchivoCuentas objCuentas;

    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "           LISTADOS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Listar mis datos" << endl;
        cout << "2. Listar todas las cuentas bancarias" << endl;
        cout << "3. Listar cuentas activas" << endl;
        cout << "4. Listar todos los empleados" << endl;
        cout << "5. Listar empleados activos" << endl;
        cout << "6. Listar todos los clientes" << endl;
        cout << "7. Listar clientes activos" << endl;
        cout << "8. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 8);

        switch(opcion){
            case 1: {
                Administrador* admin = Administrador::getInstancia();
                system("cls");
                cout << "========================================" << endl;
                cout << "       MIS DATOS (ADMINISTRADOR)" << endl;
                cout << "========================================" << endl << endl;
                cout << "Nombre: " << admin->getNombre() << endl;
                cout << "Apellido: " << admin->getApellido() << endl;
                cout << "DNI: " << admin->getDni() << endl;
                cout << "Mail: " << admin->getMail() << endl;
                cout << "Legajo: " << admin->getLegajo() << endl;
                cout << "Edad: " << admin->getEdad() << endl;
                cout << "Localidad: " << admin->getLocalidad() << endl;
                cout << "========================================" << endl;
                system("pause");
                break;
            }
            case 2: {
                objCuentas.listarTodasCuentas();
                system("pause");
                break;
            }
            case 3: {
                objCuentas.listarCuentas();
                system("pause");
                break;
            }
            case 4: {
                objEmpleados.listarTodosEmpleados();
                system("pause");
                break;
            }
            case 5: {
                objEmpleados.listarEmpleados();
                system("pause");
                break;
            }
            case 6: {
                objClientes.listarTodosClientes();
                system("pause");
                break;
            }
            case 7: {
                objClientes.listarClientes();
                system("pause");
                break;
            }
            case 8: {
                continuar = false;
                break;
            }
        }
    }
}

void menuBusquedasAdmin(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "           BUSQUEDAS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Buscar cliente" << endl;
        cout << "2. Buscar empleado" << endl;
        cout << "3. Buscar cuenta bancaria" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                buscarClienteMenu();
                break;
            }
            case 2: {
                buscarEmpleadoMenu();
                break;
            }
            case 3: {
                buscarCuentaMenu();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}

void buscarClienteMenu(){
    system("cls");
    cout << "========================================" << endl;
    cout << "        BUSCAR CLIENTE" << endl;
    cout << "========================================" << endl << endl;
    cout << "1. Buscar por ID" << endl;
    cout << "2. Buscar por DNI" << endl;
    cout << "3. Buscar por Mail" << endl;
    cout << "4. Cancelar" << endl << endl;
    
    Cliente clienteEncontrado;
    ArchivoClientes objClientes;
    int opcion = validarEntero(1, 4);
    
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            cout << "Ingrese el ID: ";
            int id = validarEntero(1, 999999);
            encontrado = objClientes.buscarCliente("ID", id, clienteEncontrado);
            break;
        }
        case 2: {
            cout << "Ingrese el DNI: ";
            int dni = validarEntero(10000000, 99999999);
            encontrado = objClientes.buscarCliente("DNI", dni, clienteEncontrado);
            break;
        }
        case 3: {
            char mail[50];
            cout << "Ingrese el Mail: ";
            validarCadena(mail, 50);
            encontrado = objClientes.buscarCliente("MAIL", mail, clienteEncontrado);
            break;
        }
        case 4: {
            return;
        }
    }
    
    system("cls");
    if(encontrado){
        cout << "========================================" << endl;
        cout << "      CLIENTE ENCONTRADO" << endl;
        cout << "========================================" << endl << endl;
        cout << clienteEncontrado.mostrarDatos() << endl;
    }
    else{
        cout << "Cliente no encontrado." << endl;
    }
    system("pause");
}

void buscarEmpleadoMenu(){
    system("cls");
    cout << "========================================" << endl;
    cout << "        BUSCAR EMPLEADO" << endl;
    cout << "========================================" << endl << endl;
    cout << "1. Buscar por Legajo" << endl;
    cout << "2. Buscar por DNI" << endl;
    cout << "3. Buscar por Mail" << endl;
    cout << "4. Cancelar" << endl << endl;
    
    int opcion = validarEntero(1, 4);
    Empleado empleadoEncontrado;
    ArchivoEmpleados objEmpleados;
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            cout << "Ingrese el Legajo: ";
            int legajo = validarEntero(1, 999999);
            encontrado = objEmpleados.buscarEmpleado("LEGAJO", legajo, empleadoEncontrado);
            break;
        }
        case 2: {
            cout << "Ingrese el DNI: ";
            int dni = validarEntero(10000000, 99999999);
            encontrado = objEmpleados.buscarEmpleado("DNI", dni, empleadoEncontrado);
            break;
        }
        case 3: {
            char mail[50];
            cout << "Ingrese el Mail: ";
            validarCadena(mail, 50);
            encontrado = objEmpleados.buscarEmpleado("MAIL", mail, empleadoEncontrado);
            break;
        }
        case 4: {
            return;
        }
    }
    
    system("cls");
    if(encontrado){
        cout << "========================================" << endl;
        cout << "      EMPLEADO ENCONTRADO" << endl;
        cout << "========================================" << endl << endl;
        cout << empleadoEncontrado.mostrarDatos() << endl;
    }
    else{
        cout << "Empleado no encontrado." << endl;
    }
    system("pause");
}

void buscarCuentaMenu(){
    system("cls");
    cout << "========================================" << endl;
    cout << "        BUSCAR CUENTA" << endl;
    cout << "========================================" << endl << endl;
    cout << "1. Buscar por ID" << endl;
    cout << "2. Buscar por CVU" << endl;
    cout << "3. Buscar por Alias" << endl;
    cout << "4. Cancelar" << endl << endl;
    
    int opcion = validarEntero(1, 4);
    cuentaBancaria cuentaEncontrada;
    ArchivoCuentas objCuentas;
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            cout << "Ingrese el ID: ";
            int id = validarEntero(1, 999999);
            encontrado = objCuentas.buscarCuenta("ID", id, cuentaEncontrada);
            break;
        }
        case 2: {
            char cvu[11];
            cout << "Ingrese el CVU: ";
            validarCadenaNumeros(cvu, 10, 10);
            encontrado = objCuentas.buscarCuenta("CVU", cvu, cuentaEncontrada);
            break;
        }
        case 3: {
            char alias[31];
            cout << "Ingrese el Alias: ";
            validarCadena(alias, 31);
            mayusculas(alias);
            encontrado = objCuentas.buscarCuenta("ALIAS", alias, cuentaEncontrada);
            break;
        }
        case 4: {
            return;
        }
    }
    
    system("cls");
    if(encontrado){
        cout << "========================================" << endl;
        cout << "      CUENTA ENCONTRADA" << endl;
        cout << "========================================" << endl << endl;
        cout << cuentaEncontrada.mostrarDatos() << endl;
    }
    else{
        cout << "Cuenta no encontrada." << endl;
    }
    system("pause");
}

void gestionarEmpleados(){
    ArchivoEmpleados objEmpleados;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      GESTION DE EMPLEADOS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Crear empleado" << endl;
        cout << "2. Modificar empleado" << endl;
        cout << "3. Eliminar empleado" << endl;
        cout << "4. Restaurar empleado" << endl;
        cout << "5. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 5);
        
        switch(opcion){
            case 1: {
                objEmpleados.crearEmpleado();
                system("pause");
                break;
            }
            case 2: {
                cout << "Ingrese el legajo del empleado: ";
                int legajo = validarEntero(1, 999999);
                objEmpleados.modificarDatosEmpleado(legajo);
                system("pause");
                break;
            }
            case 3: {
                cout << "Ingrese el legajo del empleado: ";
                int legajo = validarEntero(1, 999999);
                
                // Verificar que no sea el admin
                Administrador* admin = Administrador::getInstancia();
                if(legajo == admin->getLegajo()){
                    cout << "ERROR: No se puede eliminar al Administrador." << endl;
                    system("pause");
                    break;
                }
                
                objEmpleados.eliminarEmpleado(legajo);
                system("pause");
                break;
            }
            case 4: {
                cout << "Ingrese el legajo del empleado: ";
                int legajo = validarEntero(1, 999999);
                objEmpleados.restaurarEmpleado(legajo);
                system("pause");
                break;
            }
            case 5: {
                continuar = false;
                break;
            }
        }
    }
}

void gestionarClientesAdmin(){
    ArchivoClientes objClientes;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      GESTION DE CLIENTES" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Crear cliente" << endl;
        cout << "2. Modificar cliente" << endl;
        cout << "3. Eliminar cliente" << endl;
        cout << "4. Restaurar cliente" << endl;
        cout << "5. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 5);
        
        switch(opcion){
            case 1: {
                objClientes.crearCliente();
                system("pause");
                break;
            }
            case 2: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                objClientes.modificarDatosCliente(id);
                system("pause");
                break;
            }
            case 3: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                
                // Verificar que no sea el Cliente Banco
                if(id == 1){
                    cout << "ERROR: No se puede eliminar el Cliente Banco." << endl;
                    system("pause");
                    break;
                }
                
                objClientes.eliminarCliente(id);
                system("pause");
                break;
            }
            case 4: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                objClientes.restaurarCliente(id);
                system("pause");
                break;
            }
            case 5: {
                continuar = false;
                break;
            }
        }
    }
}

void gestionarCuentasAdmin(){
    ArchivoCuentas objCuentas;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      GESTION DE CUENTAS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Ver cuenta del Banco" << endl;
        cout << "2. Crear cuenta" << endl;
        cout << "3. Modificar cuenta" << endl;
        cout << "4. Eliminar cuenta" << endl;
        cout << "5. Restaurar cuenta" << endl;
        cout << "6. Ingresar dinero (Banco)" << endl;
        cout << "7. Retirar dinero (Banco)" << endl;
        cout << "8. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 8);
        
        switch(opcion){
            case 1: {
                cuentaBancaria cuentaBanco;
                if(objCuentas.buscarCuenta("ID", 1, cuentaBanco)){
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "       CUENTA DEL BANCO" << endl;
                    cout << "========================================" << endl << endl;
                    cout << cuentaBanco.mostrarDatos() << endl;
                }
                else{
                    cout << "ERROR: No se pudo cargar la cuenta del banco." << endl;
                }
                system("pause");
                break;
            }
            case 2: {
                cout << "Ingrese el ID del cliente: ";
                int idCliente = validarEntero(1, 999999);
                objCuentas.crearCuenta(idCliente);
                system("pause");
                break;
            }
            case 3: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                objCuentas.modificarDatosCuenta(id);
                system("pause");
                break;
            }
            case 4: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                
                // Verificar que no sea la Cuenta Banco
                if(id == 1){
                    cout << "ERROR: No se puede eliminar la Cuenta Banco." << endl;
                    system("pause");
                    break;
                }
                
                objCuentas.eliminarCuenta(id);
                system("pause");
                break;
            }
            case 5: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                objCuentas.restaurarCuenta(id);
                system("pause");
                break;
            }
            case 6: {
                cout << "Ingrese el monto a ingresar al Banco: $";
                double monto = validarDouble(0.01, 999999999.99);
                if(objCuentas.depositar(1, monto)){
                    cout << "Dinero ingresado exitosamente." << endl;
                }
                system("pause");
                break;
            }
            case 7: {
                cout << "Ingrese el monto a retirar del Banco: $";
                double monto = validarDouble(0.01, 999999999.99);
                if(objCuentas.extraer(1, monto)){
                    cout << "Dinero retirado exitosamente." << endl;
                }
                system("pause");
                break;
            }
            case 8: {
                continuar = false;
                break;
            }
        }
    }
}