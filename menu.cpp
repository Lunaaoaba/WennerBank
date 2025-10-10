#include <iostream>
#include <cstdlib>
#include <cstring>
#include "menu.h"
#include "cuentaBancaria.h"
#include "funciones.h"

using namespace std;

// Función auxiliar para pausar y limpiar el buffer de entrada
void pausa(){
    cout << "\n...";
    cin.ignore(10000, '\n'); 
    cin.get();
}

// Función auxiliar para limpiar la entrada después de un error de cin
void limpiarEntrada(){
    cin.clear(); // LIMPIA EL ESTADO DE ERROR DEL CIN
    cin.ignore(10000, '\n'); // LIMPIA EL BUFFER DE ENTRADA
}

// ----------------------------------------------------------------------
// Implementación del MENÚ PRINCIPAL (menuBase)
// ----------------------------------------------------------------------
void menuBase(){
    int ingreso = 0;

    while (true){
        system("cls"); 
        cout << "--- WENNER BANK ---" << endl << endl;
        cout << "Que desea hacer?" << endl;
        cout << "1. Crear cuenta" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Eliminar cuenta" << endl;
        cout << "4. Listar cuentas" << endl;
        cout << "5. Salir" << endl << endl;
        cout << "Ingrese su opcion: ";
        
        if (!(cin >> ingreso)) {
            cout << "\nERROR: Ingrese un numero valido." << endl;
            limpiarEntrada();
            pausa();
            continue;
        }

        if (ingreso < 1 || ingreso > 5) {
            cout << "\nOpcion no valida, intente de nuevo." << endl;
            pausa();
            continue;
        }

        switch (ingreso){
            case 1:
                crearCuenta();
                break;
            case 2:
                iniciarSesion();
                break;
            case 3:
                eliminarCuenta();
                break;
            case 4:
                listarCuentas();
                break;
            case 5:
                cout << "\nGracias por usar Wenner Bank. ¡Hasta pronto!" << endl;
                return;
        }
        
        // Pausa solo si la opción no fue Salir
        if (ingreso != 5) {
            pausa();
        }
    }
}


// ----------------------------------------------------------------------
// Implementación del MENÚ DE SESIÓN (menuCuenta)
// ----------------------------------------------------------------------
// CORRECCIÓN CRÍTICA: La cuenta DEBE recibirse por referencia (&)
void menuCuenta(cuentaBancaria &cuenta) { 
    int ingreso = 0;
    double monto = 0.0;
    
    while (true) {
        system("cls");
        cout << "--- CUENTA ID: " << cuenta.getIdCuenta() << " ---" << endl;
        cout << "Saldo actual: $" << cuenta.getSaldo() << endl << endl;
        cout << "Seleccione una operacion:" << endl;
        cout << "1. Realizar Deposito" << endl;
        cout << "2. Realizar Retiro" << endl;
        cout << "3. Mostrar Datos de la Cuenta" << endl;
        cout << "4. Cerrar Sesion" << endl << endl;
        cout << "Ingrese su opcion: ";

        if (!(cin >> ingreso)) {
            cout << "\nERROR: Ingrese un numero valido." << endl;
            limpiarEntrada();
            pausa();
            continue;
        }
        
        if (ingreso < 1 || ingreso > 4) {
            cout << "\nOpcion no valida, intente de nuevo." << endl;
            pausa();
            continue;
        }

        // Limpiamos el buffer antes de pedir un monto
        limpiarEntrada();

        switch (ingreso) {
            case 1:
                cout << "\n--- DEPOSITO ---" << endl;
                cout << "Ingrese monto a depositar: $";
                if (cin >> monto && monto > 0) {
                    realizarDeposito(cuenta, monto); 
                } else {
                    cout << "Monto invalido. Debe ser un numero positivo." << endl;
                }
                limpiarEntrada();
                break;
            case 2:
                cout << "\n--- RETIRO ---" << endl;
                cout << "Ingrese monto a retirar: $";
                if (cin >> monto && monto > 0) {
                    realizarRetiro(cuenta, monto); 
                } else {
                    cout << "Monto invalido. Debe ser un numero positivo." << endl;
                }
                limpiarEntrada();
                break;
            case 3:
                system("cls");
                cout << "--- DETALLES DE LA CUENTA ---" << endl;
                cuenta.mostrarDatos();
                break;
            case 4:
                cout << "\nCerrando sesion. Volviendo al menu principal." << endl;
                return; 
        }
        
        pausa();
    }
}
