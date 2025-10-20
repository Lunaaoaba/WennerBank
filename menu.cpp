#include <iostream>
#include <cstdlib>
#include <cstring>
#include "menu.h"
#include "cuentaBancaria.h"
#include "funciones.h"

using namespace std;

// FUNCIONES AUXILIARES
// se eliminarán al final cuando se use rlutil

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

// funcion auxiliar para validar si el ingreso en cin es un numero
bool esNumeroValido(int& numero) {
    if (!(cin >> numero)) {
        limpiarEntrada();
        return false;
    }
    return true;
}

//funcion auxiliar para validar si el cin va del case n1 a n2

bool esOpcionValida(int opcion, int n1, int n2){
    if (opcion >= n1 && opcion <= n2) return true;
    else return false;
}

//funcion auxiliar para validar que el char ingresado no supere el limite
bool esCadenaValida(const char* cadena, int maxLength){
    if(strlen(cadena) < maxLength) return true;
    else return false;
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

// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void menuPrincipal(){
    while (true) {
        menuBienvenida(); // Muestra el menú inicial en un bucle hasta que el usuario elija salir.}
    }
}

// --- 1. FLUJO DE BIENVENIDA Y ACCESO ---
void menuBienvenida() {
    system("cls");
    int opc;

    switch(opc){
        case 1:
            menuCrearUsuario();
            break;
        case 2:
            iniciarSesion();
            break;
        case 3:
            // iniciarSesionEmpleado(); //sin definir aun
            break;
        case 4:
            exit(0);
    }
    cout << "Ingrese su opcion: " << endl;
    cin >> opc;
    if(!esNumeroValido(opc) || !esOpcionValida(opc, 1, 4)){
        cout << "\nERROR: Ingrese un numero valido." << endl;
        limpiarEntrada();
        pausa();
        return;
    }

}

void iniciarSesion(){
    // Pide mail y contraseña.
    // Llama a una función de "funciones.h" para validar las credenciales.
    // Si la validación es exitosa:
    //  - Si es Cliente, llama a menuCliente().
    //  - Si es Empleado, llama a menuEmpleado().
    //  - Si es Admin, llama a menuAdministrador().
    // Si no, muestra un error y vuelve a menuBienvenida().

    system("cls");
    cout << "--- INICIAR SESION ---" << endl;
    char gmail[50], contraseña[50];
    cout << "Ingrese su usuario: " << endl;
    cout << "Gmail: ";
    cin >> gmail;
    cout << "Contraseña: ";
    cin >> contraseña;

    if(esCadenaValida(gmail, 50) && esCadenaValida(contraseña, 50)){
        //switch temporal para probar los menus
        int tipoUsuario;
        switch(tipoUsuario){
        case 1:
            menuCliente();
            break;
        case 2:
            menuEmpleado();
        case 3:
            // esAdmin = true; // variable global para indicar que es admin
            menuAdministrador();
            break;
        case 4:
            cout << "\nERROR: Credenciales invalidas." << endl;
            pausa();
            return;
        }
        cin >> tipoUsuario;
        if(!esNumeroValido(tipoUsuario) || !esOpcionValida(tipoUsuario, 1, 4)){
            cout << "\nERROR: Ingrese un numero valido." << endl;
            limpiarEntrada();
            pausa();
            return;
        }
    }
    else{
        cout << "\nERROR: Credenciales invalidas. Devuelto al menú" << endl;
        pausa();
        menuBienvenida();
        return;
    }
}

void menuCrearUsuario(){
    // Muestra: 1. Crear cuenta de Cliente, 2. Crear cuenta de Empleado (solo si es admin), 3. Volver.
    // Llama a: crearUsuarioCliente(), crearUsuarioEmpleado() o menuBienvenida().
}

// --- 2. FLUJO DE CREACIÓN DE USUARIOS ---
void crearUsuarioCliente(){
    // Pide todos los datos (DNI, nombre, mail, contraseña, etc.).
    // Muestra los datos ingresados y pide confirmación (el "Último paso" del PDF).
    // Si el usuario confirma:
    //  - Llama a una función para generar un nuevo idCliente.
    //  - Crea un objeto Cliente.
    //  - Llama a guardarCliente() de "funciones.h".
    //  - Muestra "Usuario creado con éxito" y vuelve a menuBienvenida().
    // Si no confirma, le permite modificar o cancela y vuelve a menuBienvenida().
}

// --- 3. MENÚS PRINCIPALES POR ROL ---
void menuCliente(){
    // Muestra el panel del cliente: "Bienvenido, Fulanito".
    // Opciones: 1. Gestionar mis Cuentas Bancarias, 2. Ver mis Préstamos, 3. Cerrar Sesión.
    // Llama a: menuGestionCuentas() o vuelve a menuBienvenida().
}

void menuEmpleado(){
    // Muestra el panel del empleado.
    // Opciones: 1. Gestionar Clientes, 2. Operaciones Bancarias, 3. Listados, 4. Búsquedas, 5. Cerrar Sesión.
    // Llama a: menuGestionClientes(), menuOperacionesBancarias(), etc.
}

void menuAdministrador(){
    // Muestra el panel del admin.
    // Opciones: 1. Gestionar Clientes, 2. Gestionar Empleados, 3. Operaciones, 4. Listados, 5. Búsquedas, 6. Cerrar Sesión.
    // Llama a las funciones correspondientes.
}

// --- 4. SUB-MENÚS Y ACCIONES DEL CLIENTE ---
void menuGestionCuentas(){
    // Llama a una función para listar las cuentas del cliente actual.
    // Muestra opciones: 1. Ingresar a una cuenta, 2. Crear nueva cuenta, 3. Volver.
    // Llama a: menuOperacionesCuenta() o una función para crear una nueva CuentaBancaria.
}
// -------------------------------------------------------------------------------------------------------

// tachado pq da error
/*
void menuOperacionesCuenta(cuentaBancaria &cuenta, double saldo){
    // Pide el ID de la cuenta a la que se quiere ingresar.
    // Muestra el saldo y los datos de esa cuenta.
    // Opciones: 1. Depositar, 2. Retirar, 3. Realizar Transferencia, 4. Volver.
    // Llama a: realizarDeposito(), realizarRetiro(), realizarTransferencia().
    int op;
    while(true){
        int opc;
        system("cls");
        cout<<"    OPERACIONES"<<endl;
        cout<<"==================="<<endl;
        cout<<"1 -Mostrar saldo"<<endl;
        cout<<"2 -Depositar dinero"<<endl;
        cout<<"3 -Retirar dinero"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                mostrarSaldo(saldo);
                break;
            case 2:
                saldo += realizarDeposito();
                mostrarSaldo(saldo);
                break;
            case 3:
                saldo -= realizarRetiro(saldo);
                mostrarSaldo(saldo);
                break;
            case 0:  
                cout << "Gracias por confiar en Interbank!! \n";
                break;
            default:
                cout << "Opcion no valida, seleccion una opcion correcta";
                break;
            break;
        }
        system("pause");
    }
}
*/
// -------------------------------------------------------------------------------------------------------

void realizarTransferencia(){
    // Pide CVU/Alias de destino.
    // Llama a una función de búsqueda para verificar que la cuenta destino existe.
    // Muestra los datos del destinatario y pide confirmación.
    // Pide el monto.
    // Realiza la lógica de la transferencia (resta de una cuenta, suma a la otra).
    // Llama a modificarCuenta() dos veces para guardar los cambios.
    // Crea y guarda un nuevo objeto Transaccion.
}

// --- 5. SUB-MENÚS Y ACCIONES DE EMPLEADO/ADMINISTRADOR ---
void menuGestionClientes(){
    // Muestra opciones: 1. Crear Cliente, 2. Modificar Cliente, 3. Eliminar Cliente, etc.
    // Llama a: crearUsuarioCliente(), modificarCliente(), eliminarCliente().
}

//CONTINUAR DESPUES, ES MUY ENGORROSO