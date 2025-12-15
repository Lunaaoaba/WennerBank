#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#define byte windows_byte
#include "rlutil.h"
#undef byte

#include <iostream>
#include <cstring>
#include "config.h"
#include "funcionesArchivos.h"
#include "art.h"
#include "funciones.h"
#include "cliente.h"
#include "empleado.h"
#include "cuentaBancaria.h"
#include "transaccion.h"
#include <windows.h>

using namespace std;

// varias funciones en una sola para simplificar el main
void config(){
    // configuraciones obligatorias 
    consola();
    // establece el Background de la consola
    fondoRgb();
    // inicia los archivos necesarios
    iniciarArchivos();

    // agrega usuarios de prueba
    int key = rlutil::getkey();
    // NUMPAD 0 
    if (key == 31){ 
        cout << "Iniciar usuarios de prueba? (S/N): " << endl;
        char respuesta = validarSiNo();
        system("cls");
        if(respuesta == 'S' || respuesta == 's') iniciarUsuarios();
    }
}

void consola(){
    // fuerza el uso de ascii extendido en consola
    SetConsoleCP(850);
    SetConsoleOutputCP(850);
    // habilita secuencias de escape ANSI para uso de colores RGB
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void fondoRgb(){
    cout << "\033[48;2;18;29;68m";
    system("cls");
}

// inicia los archivos si no existen con los datos principales
void iniciarArchivos(){
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if (archivoClientes == nullptr){ // si no existe, lo crea
        archivoClientes = fopen ("clientes.dat", "wb");
        if (archivoClientes == nullptr) {
            cout << "ERROR FATAL: No se pudo crear el archivo de clientes." << endl;
            exit(-1);
        }
        
        Cliente clienteBanco(10000000, "Sistema", "WennerBank", "Central", Fecha(14, 11, 1987), "bancoWennerBank@mail.com", "abcd1234", false, 1);
        fwrite(&clienteBanco, sizeof(Cliente), 1, archivoClientes);

        char localidad1[50] = {'B', 'e', 'l', char(130), 'n', ' ', 'd', 'e', ' ', 'E', 's', 'c', 'o', 'b', 'a', 'r', '\0'};
        Cliente clientePersonal(47379840, "Luna", "Baricalla", localidad1, Fecha(11, 7, 2006), "lunabaricalla@mail.com", "abcd1234", false, 2);
        fwrite(&clientePersonal, sizeof(Cliente), 1, archivoClientes);

        fclose(archivoClientes);
    }
    else fclose(archivoClientes);

// ARCHIVO CUENTAS
    FILE* archivoCuentas = fopen("cuentas.dat", "rb");
    if (archivoCuentas == nullptr){ // si no existe, lo crea
        archivoCuentas = fopen ("cuentas.dat", "wb");
        if (archivoCuentas == nullptr) {
            cout << "ERROR FATAL: No se pudo crear el archivo de cuentas." << endl;
            exit(-1);
        }
        // crear cuenta bancaria del banco
        cuentaBancaria cuentaBanco(
            1, // id cuenta
            1, // id cliente
            "Banco Central", // nombre cuenta
            "0000000000", // cvu
            "BANCO.CENTRAL.WENNER", // alias
            10000000.00, // saldo inicial
            false // cuenta eliminada
        );
        fwrite(&cuentaBanco, sizeof(cuentaBancaria), 1, archivoCuentas);
        fclose(archivoCuentas);
    }
    else fclose(archivoCuentas);

// ARCHIVO EMPLEADOS
    FILE* archivoEmpleados = fopen("empleados.dat", "rb");
    if(archivoEmpleados == nullptr){
        archivoEmpleados = fopen("empleados.dat", "wb");
        if (archivoEmpleados == nullptr){
            cout << "ERROR FATAL: No se pudo crear el archivo de empleados." << endl;
            exit(-1);
        }
        char contrasena[50] = {'c', 'o', 'n', 't', 'r', 'a', 's', 'e', char(164), 'a', '\0'};

        char apellido[50] = {'P', char(130), 'r', 'e', 'z', '\0'};
        Empleado empleado1(11000123, "Jorgito", apellido, "Del Viso", Fecha(1, 1, 1990), "jorgitoperez@gmail.com", contrasena, false, 2);
        fwrite(&empleado1, sizeof(Empleado), 1, archivoEmpleados);

        char nombre[50] = {'M', 'a', 'r', char(161), 'a', '\0'};
        char apellido1[50] = {'G', 'o', 'n', 'z', char(160) , 'l', 'e', 'z', '\0'};
        Empleado empleado2( 12000123, nombre, apellido1, "El Talar", Fecha(5, 5, 1988), "mariagonzalez@gmail.com", contrasena, false, 3);
        fwrite(&empleado2, sizeof(Empleado), 1, archivoEmpleados);

        fclose(archivoEmpleados);
    }
    else fclose(archivoEmpleados);

// ARCHIVO TRANSACCIONES
    FILE* archivoTransacciones = fopen("transacciones.dat", "ab");  // "ab" es mas seguro, crea si no existe
    if(archivoTransacciones != nullptr) fclose(archivoTransacciones);
    else cout << "ERROR FATAL: No se pudo crear el archivo de transacciones." << endl;
}

// inicia usuarios de prueba (clientes y empleados), cuentas bancarias no pq q sean manuales alta paja
void iniciarUsuarios(){
    char contrasena[50] = {'c', 'o', 'n', 't', 'r', 'a', 's', 'e', char(164), 'a', '\0'};

    FILE* archivoClientes = fopen("clientes.dat", "ab");
    if(archivoClientes == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }

    char apellido1[50] = {'P', char(130), 'r', 'e', 'z', '\0'};
    Cliente cliente3(13000123, "Juan", apellido1, "La Plata", Fecha(1, 1, 1990), "juancito_perez_ok@gmail.com", contrasena, false, 3);
    fwrite(&cliente3, sizeof(Cliente), 1, archivoClientes);

    char apellido3[50] = {'R', 'o', 'd', 'r', char(161), 'g', 'u', 'e', 'z', '\0'};
    Cliente cliente5(15000123, "Carlos Alberto", apellido3, "Lanus", Fecha(3, 3, 1992), "el_charly_rodriguez_55@gmail.com", contrasena, false, 5);
    fwrite(&cliente5, sizeof(Cliente), 1, archivoClientes);

    char apellido4[50] = {'F', 'e', 'r', 'n', char(160), 'n', 'd', 'e', 'z', '\0'};
    Cliente cliente6(16000123, "Ana Laura", apellido4, "Avellaneda", Fecha(4, 4, 1993), "anita.laura.fer22@gmail.com", contrasena, false, 6);
    fwrite(&cliente6, sizeof(Cliente), 1, archivoClientes);

    char nombre1[50] = {'J', 'o', 's', char(130), ' ', 'L', 'u', 'i', 's', '\0'};
    char apellido5[50] = {'G', 'a', 'r', 'c', char(161), 'a', ' ', 'L', 'o', 'p', 'e', 'z', '\0'};
    Cliente cliente7(17000123, nombre1, apellido5, "CABA", Fecha(20, 2, 2005), "pepe_garcia_lopez@gmail.com", contrasena, false, 7);
    fwrite(&cliente7, sizeof(Cliente), 1, archivoClientes);

    char nombre2[50] = {'S', 'o', 'f', char(161), 'a', '\0'};
    char apellido6[50] = {'M', 'a', 'r', 't', char(161), 'n', 'e', 'z', ' ', 'S', char(160), 'n', 'c', 'h', 'e', 'z', '\0'};
    Cliente cliente8(18000123, nombre2, apellido6, "CABA", Fecha(22, 3, 2004), "sofi_martinez_sanchez_01@gmail.com", contrasena, false, 8);
    fwrite(&cliente8, sizeof(Cliente), 1, archivoClientes);

    char nombre3[50] = {'M', 'i', 'g', 'u', 'e', 'l', ' ', char(181), 'n', 'g', 'e', 'l', '\0'};
    Cliente cliente9(19000123, nombre3, "Torres Ruiz", "Moron", Fecha(10, 5, 2000), "miguel_angel_torres@gmail.com", contrasena, false, 9);
    fwrite(&cliente9, sizeof(Cliente), 1, archivoClientes);

    char nombre4[50] = {'L', 'u', 'c', char(161), 'a', ' ', 'B', 'e', 'l', char(130), 'n', '\0'};
    char apellido7[50] = {'D', char(161), 'a', 'z', ' ', 'R', 'o', 'm', 'e', 'r', 'o', '\0'};
    Cliente cliente10(20000123, nombre4, apellido7, "Olivos", Fecha(17, 11, 2002), "luli.belen.dr@gmail.com", contrasena, false, 10);
    fwrite(&cliente10, sizeof(Cliente), 1, archivoClientes);

    fclose(archivoClientes);


    FILE* archivoEmpleados = fopen("empleados.dat", "ab");
    if(archivoEmpleados == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }

    Empleado empleado3(21000123, "Isabel Cristina", "Castro Vargas", "CABA", Fecha(1, 1, 1990), "isa_castro_vargas_2000@gmail.com", contrasena, false, 4);
    fwrite(&empleado3, sizeof(Empleado), 1, archivoEmpleados);

    Empleado empleado4(22000123, "Antonio Manuel", "Medina Silva", "Avellaneda", Fecha(2, 2, 1991), "tony_medina_silva@gmail.com", contrasena, false, 5);
    fwrite(&empleado4, sizeof(Empleado), 1, archivoEmpleados);

    char apellido8[50] = {'O', 'r', 't', 'e', 'g', 'a', ' ', 'R', char(161), 'o', 's', '\0'};
    Empleado empleado5(23000123, "David Alejandro", apellido8, "El Talar", Fecha(4, 4, 1993), "davo_ortega_rios_10@gmail.com", contrasena, false, 6);
    fwrite(&empleado5, sizeof(Empleado), 1, archivoEmpleados);

    Empleado empleado6(24000123, "Elena Victoria", "Mendoza Paz", "CABA", Fecha(5, 12, 1994), "vicky_mendoza_paz_star@gmail.com", contrasena, false, 7);
    fwrite(&empleado6, sizeof(Empleado), 1, archivoEmpleados);

    Empleado empleado7(25000123, "Jorge Luis", "Castillo Soto", "CABA", Fecha(30, 4, 1995), "jorge_luis_soto@gmail.com", contrasena, false, 8);
    fwrite(&empleado7, sizeof(Empleado), 1, archivoEmpleados);

    char nombre5[50] = {'T', 'e', 'r', 'e', 's', 'a', ' ', 'D', 'e', ' ', 'J', 'e', 's', char(163), 's', '\0'};
    Empleado empleado8(26000123, nombre5, "Vega Cruz", "El Talar", Fecha(17, 11, 2001), "tere_vega_cruz@gmail.com", contrasena, false, 9);
    fwrite(&empleado8, sizeof(Empleado), 1, archivoEmpleados);

    char nombre6[50] = {'C', 'l', 'a', 'r', 'a', ' ', 'I', 'n', char(130), 's', '\0'};
    char apellido9[50] = {'P', 'o', 'n', 'c', 'e', ' ', 'D', 'e', ' ', 'L', 'e', char(162), 'n', '\0'};   
    Empleado empleado9(27000123, nombre6, apellido9, "El Talar", Fecha(5, 5, 1985), "clarita_ponce_leon@gmail.com", contrasena, false, 10);
    fwrite(&empleado9, sizeof(Empleado), 1, archivoEmpleados);

    Empleado empleado10(28000123, "Roberto Carlos", "De La Fuente", "Avellaneda", Fecha(20, 10, 1990), "roberto_carlos_dlf_music@gmail.com", contrasena, false, 11);
    fwrite(&empleado10, sizeof(Empleado), 1, archivoEmpleados);

    fclose(archivoEmpleados);
}