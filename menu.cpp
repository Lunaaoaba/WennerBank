#include <iostream>
#include "funciones.h"

using namespace std;

void menuBase(){
    int ingreso;

    while (true){
        cout << "--- WENNER BANK ---" << endl << endl;
        cout << "Que desea hacer?" << endl;
        cout << "1. Crear cuenta" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Eliminar cuenta" << endl;
        cout << "4. Listar cuentas" << endl;
        cout << "5. Salir" << endl << endl;
        cin >> ingreso;
        if(ingreso < 6) cout << "correcto" << endl;
        else{
            cout << "Opcion no valida, intente de nuevo" << endl;
            system("pause");
            system("cls");
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
                cout << "Gracias por usar Wenner Bank" << endl;
                return;
        }
        system("pause");
        system("cls");
    }
}