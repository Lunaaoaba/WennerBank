#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "cuentaBancaria.h"
#include "tipoUsuario.h"
#include "funciones.h"
#include "art.h"

using namespace std;


// ----------------------------------------------------------------------
// menu en base al diagrama WennerBank_path.png
// ----------------------------------------------------------------------


// ---------------------------
// --- NUCLEO DEL PROGRAMA ---
// ---------------------------

void menuPrincipal(){
    while (true) {
        system("cls");
        tituloBeta();
        menuOpciones(); // Muestra el menú inicial en un bucle hasta que el usuario elija salir.
    }
}

void menuOpciones(){
    // sujeto a cambios
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Cuentas" << endl;
    cout << "3. Empleados" << endl;
    cout << "4. Administrador" << endl;
    cout << "5. Salir del programa" << endl << endl;

    Opciones();
}

void Opciones(){
    int opcion = validarEntero("Ingrese una opcion (1-5): ", 1, 5);
    switch(opcion){
        case 1:
            Clientes();
            break;
        case 2:
            Cuentas();
            break;
        case 3:
            Empleados();
            break;
        case 4:
            Admin();
            break;
        case 5:
            cout << "Gracias por usar Wenner Bank. ¡Hasta luego!" << endl;
            system("pause");
            exit(0);
    }
}

void Clientes(){
    centrar_texto(" Menu Clientes ", (char)205, 41);
    iniciarSesion();
}

void Cuentas(){
    centrar_texto(" Menu Cuentas ", (char)205, 41);
}

void Empleados(){
    centrar_texto(" Menu Empleados ", (char)205, 41);
}

void Admin(){
    centrar_texto(" Menu Administrador ", (char)205, 41);
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
    char gmail[50], contrasena[50];
    cout << "Ingrese su usuario: " << endl;
    cout << "Gmail: ";
    cin >> gmail;
    cout << "Contraseña: ";
    cin >> contrasena;

    if(esCadenaValida(gmail, 50) && esCadenaValida(contrasena, 50)){
        //switch temporal para probar los menus
        int tipoUsuario;
        switch(tipoUsuario){
        case 1:
            menuCliente();
            break;
        case 2:
            // menuEmpleado();
            break;
        case 3:
            // esAdmin = true; // variable global para indicar que es admin
            // menuAdministrador();
            break;
        case 4:
            cout << "\nERROR: Credenciales invalidas." << endl;
            pausa();
            return;
        }
        cin >> tipoUsuario;
        if(!(validarEntero("Ingrese tipo de usuario (1-Cliente, 2-Empleado, 3-Admin): ", 1, 4))){
            cout << "\nERROR: Ingrese un numero valido." << endl;
            limpiarEntrada();
            pausa();
            return;
        }
    }
    else{
        cout << "\nERROR: Credenciales invalidas. Devuelto al menú" << endl;
        pausa();
        menuOpciones();
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
    cout << "culito";
    system("pause");
    exit(12);
}

void menuAdministrador(){
    // Muestra el panel del admin.
    // Opciones: 1. Gestionar Clientes, 2. Gestionar Empleados, 3. Operaciones, 4. Listados, 5. Búsquedas, 6. Cerrar Sesión.
    // Llama a las funciones correspondientes.
    cout << "admin culito";
    system("pause");
    exit(21);
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
