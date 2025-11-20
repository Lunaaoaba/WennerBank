#include <iostream>
#include <cstdlib>
#include "menuCliente.h"
#include "ArchivoClientes.h"
#include "ArchivoCuentas.h"
#include "funciones.h"
#include "menuCuenta.h"

using namespace std;

void menuCliente(int idCliente){
    bool continuar = true;
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "              MENU CLIENTE" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Ver mis cuentas" << endl;
        cout << "2. Ingresar a una cuenta" << endl;
        cout << "3. Crear nueva cuenta" << endl;
        cout << "4. Ver mis datos personales" << endl;
        cout << "5. Modificar mis datos" << endl;
        cout << "6. Cerrar sesion" << endl << endl;

        int opcion = validarEntero(1, 6);
        switch(opcion){
            case 1: {
                system("cls");
                verMisCuentas(idCliente);
                break;
            }
            case 2: {
                system("cls");
                ingresarACuenta(idCliente);
                break;
            }
            case 3: {
                crearMiCuenta(idCliente);
                break;
            }
            case 4: {
                verMisDatos(idCliente);
                break;
            }
            case 5: {
                modificarMisDatos(idCliente);
                break;
            }
            case 6: {
                continuar = false;
                break;
            }
        }
    }
}

void verMisCuentas(int idCliente){
    system("cls");
    listarCuentasCliente(idCliente);
    system("pause");
}

void ingresarACuenta(int idCliente){
    int intentos = 0;
    const int maxIntentos = 3;

    while(intentos < maxIntentos){
        system("cls");
        cout << "========================================" << endl;
        cout << "      INGRESAR A CUENTA BANCARIA" << endl;
        cout << "========================================" << endl << endl;
        
        cout << "Ingrese el ID de la cuenta: ";
        int idCuenta = validarEntero(1, 999999);

        cuentaBancaria cuentaActual;
        if(!buscarCuenta("ID", idCuenta, cuentaActual)){
            cout << "ERROR: No se encontro ninguna cuenta con ese ID." << endl;
            intentos++;
            cout << "Intentos restantes: " << maxIntentos - intentos << endl;
            system("pause");
            continue;
            }
        if(cuentaActual.getIdCliente() != idCliente){
            cout << "ERROR: Esta cuenta no le pertenece." << endl;
            intentos++;
            cout << "Intentos restantes: " << maxIntentos - intentos << endl;
            system("pause");
            continue;
        }
        if(cuentaActual.getCuentaEliminada()){
            cout << "ERROR: Esta cuenta esta cerrada" << endl;
            intentos++;
            cout << "Intentos restantes: " << maxIntentos - intentos << endl;
            system("pause");
            continue;
        }

        menuCuenta(idCliente, idCuenta);
        return;
    }

    cout << "Ha superado el numero maximo de intentos." << endl;
    system("pause");
}

void crearMiCuenta(int idCliente){
    system("cls");
    crearCuenta(idCliente);
    system("pause");
}

void verMisDatos(int idCliente){
    system("cls");
    Cliente clienteActual;
    if(buscarCliente("ID", idCliente, clienteActual)){
        cout << "========================================" << endl;
        cout << "       MIS DATOS PERSONALES" << endl;
        cout << "========================================" << endl << endl;
        cout << clienteActual.mostrarDatos() << endl;
    }
    else{
        cout << "ERROR: No se pudo cargar la informacion." << endl;
    }
    system("pause");
}

void modificarMisDatos(int idCliente){
    modificarDatosCliente(idCliente);
}