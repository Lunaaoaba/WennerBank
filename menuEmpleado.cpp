#include <iostream>
#include <cstdlib>
#include "menuEmpleado.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "funciones.h"

using namespace std;
void menuEmpleado(int legajoEmpleado){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "         MENU EMPLEADO" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Listados" << endl;
        cout << "2. Gestion de Cuentas" << endl;
        cout << "3. Trasferencias" << endl;
        cout << "4. Cerrar sesion" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                menuListadosEmpleado(legajoEmpleado);
                break;
            }
            case 2: {
                gestionarClientes();
                break;
            }
            case 3: {
                gestionarCuentas();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}

void menuListadosEmpleado(int legajoEmpleado){
    ArchivoClientes objClientes;
    Empleado empleadoActual;
    ArchivoEmpleados objEmpleados;
    cuentaBancaria cuentaBanco;
    ArchivoCuentas objCuentas;



    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "           LISTADOS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Listar mis detalles" << endl;
        cout << "2. Listar detalles cuenta del Banco" << endl;
        cout << "3. Listar cuentas bancarias" << endl;
        cout << "4. Listar empleados" << endl;
        cout << "5. Listar clientes" << endl;
        cout << "6. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 6);

        switch(opcion){
            case 1: {
                if(objEmpleados.buscarEmpleado("LEGAJO", legajoEmpleado, empleadoActual)){
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "         MIS DATOS" << endl;
                    cout << "========================================" << endl << endl;
                    cout << empleadoActual.mostrarDatos() << endl;
                }
                else{
                    cout << "ERROR: No se pudo cargar la informacion." << endl;
                }
                system("pause");
                break;
            }
            case 2: {
                if(objCuentas.buscarCuenta("ID", 1, cuentaBanco)){
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "     CUENTA DEL BANCO" << endl;
                    cout << "========================================" << endl << endl;
                    cout << cuentaBanco.mostrarDatos() << endl;
                }
                else{
                    cout << "ERROR: No se pudo cargar la cuenta del banco." << endl;
                }
                system("pause");
                break;
            }
            case 3: {
                objCuentas.listarCuentas();
                system("pause");
                break;
            }
            case 4: {
                objEmpleados.listarEmpleados();
                system("pause");
                break;
            }
            case 5: {
                objClientes.listarClientes();
                system("pause");
                break;
            }
            case 6: {
                continuar = false;
                break;
            }
        }
    }
}

void gestionarClientes(){
    ArchivoClientes objClientes;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      GESTION DE CLIENTES" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Modificar cliente" << endl;
        cout << "2. Eliminar cliente" << endl;
        cout << "3. Restaurar cliente" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                objClientes.modificarDatosCliente(id);
                system("pause");
                break;
            }
            case 2: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                
                // Verificar que no sea el Cliente Banco (ID 1)
                if(id == 1){
                    cout << "ERROR: No se puede eliminar el Cliente Banco." << endl;
                    system("pause");
                    break;
                }
                
                objClientes.eliminarCliente(id);
                system("pause");
                break;
            }
            case 3: {
                cout << "Ingrese el ID del cliente: ";
                int id = validarEntero(1, 999999);
                objClientes.restaurarCliente(id);
                system("pause");
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}

void gestionarCuentas(){
    ArchivoCuentas objCuentas;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      GESTION DE CUENTAS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Modificar cuenta" << endl;
        cout << "2. Eliminar cuenta" << endl;
        cout << "3. Restaurar cuenta" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                objCuentas.modificarDatosCuenta(id);
                system("pause");
                break;
            }
            case 2: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                
                // Verificar que no sea la Cuenta Banco (ID 1)
                if(id == 1){
                    cout << "ERROR: No se puede eliminar la Cuenta Banco." << endl;
                    system("pause");
                    break;
                }
                
                objCuentas.eliminarCuenta(id);
                system("pause");
                break;
            }
            case 3: {
                cout << "Ingrese el ID de la cuenta: ";
                int id = validarEntero(1, 999999);
                objCuentas.restaurarCuenta(id);
                system("pause");
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}