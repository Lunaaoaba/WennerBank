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
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------
/*
void menuBienvenida(){
    system("cls");
    cout << "--- BIENVENIDO/A A WENNER BANK ---" << endl;
    cout << "Su banco de confianza." << endl << endl;

    cout << "Seleccione una opcion:" << endl;
    cout << "1. Iniciar sesion como cliente" << endl;
    cout << "2. Iniciar sesion como empleado" << endl;
    cout << "3. Crear usuario" << endl;
    cout << "4. Salir del programa" << endl << endl;
    cout << "Ingrese su opcion: ";
    int ingreso;

    if (!(cin >> ingreso)) {
        cout << "\nERROR: Ingrese un numero valido." << endl;
        limpiarEntrada();
        pausa();
        return;
    }
    if (ingreso < 1 || ingreso > 4) {
        cout << "\nOpcion no valida, intente de nuevo." << endl;
        pausa();
        return;
    }

    switch (ingreso){
        case 1:
            iniciarSesion(); //ingresa el Usuario Cliente
            break;
        case 2:
            crearUsuario(); // solo crea Usuario cliente
            break;
        case 3:
            iniciarSesionEmpleado(); // ingresa el Usuario Empleado o Admin
            break;
        case 4:
            cout << "\nGracias por usar Wenner Bank. ¡Hasta pronto!" << endl;
            exit(0);
        }
    pausa();
}

void iniciarSesion(){
    system("cls");
    cout << "--- INICIAR SESION ---" << endl;
    char gmail[50], contraseña[50];
    cout << "Ingrese su usuario: " << endl;
    cout << "Gmail: ";
    cin >> gmail;
    cout << "Contraseña: ";
    cin >> contraseña;

    cout << "\n¡Inicio de sesion exitoso! Bienvenido/a." << endl;
    // Verificar las credenciales (hacer)
    system("pause");
    //suponiendo que esta todo bien
    menuCliente();
}

void crearUsuario(){
    system("cls");
    cout << "--- CREAR USUARIO ---" << endl;
    char gmail[50], contraseña[50];
    cout << "Ingrese los siguientes datos para crear su usuario:" << endl;
    cout << "Gmail: ";
    cin >> gmail;
    cout << "Contraseña: ";
    cin >> contraseña;

    cout << "\n¡Usuario creado exitosamente! Ahora puede iniciar sesion." << endl;
    // Guardar el nuevo usuario (hacer)
    system("pause");
    menuBienvenida();
}

void iniciarSesionEmpleado(){
    system("cls");
    cout << "--- INICIAR SESION EMPLEADO/ADMIN ---" << endl;
    char usuario[50], contraseña[50];
    cout << "Ingrese su usuario: " << endl;
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Contraseña: ";
    cin >> contraseña;

    cout << "\n¡Inicio de sesion exitoso! Bienvenido/a." << endl;
    // Verificar las credenciales (hacer)
    // si detecta los datos de admin, redirige al menu admin
    system("pause");
    //suponiendo que esta todo bien:

    //if admin
    // menuAdmin();

    //else
    //menuEmpleado();
}

*/