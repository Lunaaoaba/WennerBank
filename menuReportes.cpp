#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "menuReportes.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "ArchivoMovimientos.h"
#include "funciones.h"

using namespace std;

void menuReportes(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "           MENU DE REPORTES" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Reportes de Clientes" << endl;
        cout << "2. Reportes de Empleados" << endl;
        cout << "3. Reportes Financieros" << endl;
        cout << "4. Volver al menu principal" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                menuReportesClientes();
                break;
            }
            case 2: {
                menuReportesEmpleados();
                break;
            }
            case 3: {
                menuReportesFinancieros();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}

// MENU REPORTES DE CLIENTES

void menuReportesClientes(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      REPORTES DE CLIENTES" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Cliente con mas transacciones realizadas (no disponible)" << endl;
        cout << "2. Monto total transferencias por mes (cliente especifico) (no disponible)" << endl;
        cout << "3. Cantidad de clientes por localidad" << endl;
        cout << "4. Top 5 clientes con mayor monto transferido (no disponible)" << endl;
        cout << "5. Clientes con prestamos vigentes (no disponible)" << endl;
        cout << "6. Volver" << endl << endl;

        int opcion = validarEntero(1, 6);

        switch(opcion){
            case 1: {
                reporteClienteMasTransacciones();
                break;
            }
            case 2: {
                reporteMontoTransferenciasPorMes();
                break;
            }
            case 3: {
                reporteClientesPorLocalidad();
                break;
            }
            case 4: {
                reporteTop5ClientesMayorMonto();
                break;
            }
            case 5: {
                reporteClientesConPrestamos();
                break;
            }
            case 6: {
                continuar = false;
                break;
            }
        }
    }
}

// MENU REPORTES DE EMPLEADOS

void menuReportesEmpleados(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      REPORTES DE EMPLEADOS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Empleado con mas operaciones realizadas (no disponible)" << endl;
        cout << "2. Monto total de prestamos por mes (anio especifico) (no disponible)" << endl;
        cout << "3. Promedio de prestamos otorgados por empleado (no disponible)" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                reporteEmpleadoMasOperaciones();
                break;
            }
            case 2: {
                reporteMontoPrestamosPorMes();
                break;
            }
            case 3: {
                reportePromedioPrestamosPorEmpleado();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}

// MENU REPORTES FINANCIEROS

void menuReportesFinancieros(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      REPORTES FINANCIEROS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Saldo total de todas las cuentas de clientes" << endl;
        cout << "2. Monto promedio de las transacciones (no disponible)" << endl;
        cout << "3. Ranking de cuentas con mayor saldo" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                reporteSaldoTotalCuentas();
                break;
            }
            case 2: {
                reportePromedioTransacciones();
                break;
            }
            case 3: {
                reporteRankingCuentasMayorSaldo();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
        }
    }
}



// IMPLEMENTACION REPORTES CLIENTES

void reporteClienteMasTransacciones(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  CLIENTE CON MAS TRANSACCIONES" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere ArchivoMovimientos completo)" << endl << endl;
    system("pause");
}

void reporteMontoTransferenciasPorMes(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  MONTO TRANSFERENCIAS POR MES" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "Ingrese el ID del cliente: ";
    int idCliente = validarEntero(1, 999999);

    Cliente clienteActual;
    if(!buscarCliente("ID", idCliente, clienteActual)){
        cout << "ERROR: Cliente no encontrado." << endl;
        system("pause");
        return;
    }

        cout << endl << "Cliente: " << clienteActual.getNombre() << " " << clienteActual.getApellido() << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere ArchivoMovimientos completo)" << endl << endl;
    system("pause");
}

//dsp pasar a memoria dinamica
void reporteClientesPorLocalidad(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  CLIENTES POR LOCALIDAD" << endl;
    cout << "========================================" << endl << endl;
    
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == NULL){
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }
    
    // Array para contar por localidad (simplificado, máximo 50 localidades)
    char localidades[50][30];
    int contadores[50] = {0};
    int numLocalidades = 0;

    Cliente clienteActual;
    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(!clienteActual.getUsuarioEliminado()){
            // Buscar si la localidad ya existe
            bool encontrada = false;
            for(int i = 0; i < numLocalidades; i++){
                if(strcmp(localidades[i], clienteActual.getLocalidad()) == 0){
                    contadores[i]++;
                    encontrada = true;
                    break;
                }
            }
            
            // Si no existe, agregarla
            if(!encontrada && numLocalidades < 50){
                strcpy(localidades[numLocalidades], clienteActual.getLocalidad());
                contadores[numLocalidades] = 1;
                numLocalidades++;
            }
        }
    }

    fclose(archivo);
    
    cout << "  LOCALIDAD       " << "      CANTIDAD" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < numLocalidades; i++){
        cout  << localidades[i] << "  |   " << contadores[i] << endl;
    }
    
    cout << endl;
    system("pause");
}

void reporteTop5ClientesMayorMonto(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  TOP 5 CLIENTES - MAYOR MONTO" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere ArchivoMovimientos completo)" << endl << endl;
    system("pause");
}

void reporteClientesConPrestamos(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  CLIENTES CON PRESTAMOS VIGENTES" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere sistema de Prestamos)" << endl << endl;
    system("pause");
}

// IMPLEMENTACIÓN REPORTES EMPLEADOS

void reporteEmpleadoMasOperaciones(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  EMPLEADO CON MAS OPERACIONES" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere ArchivoMovimientos completo)" << endl << endl;
    system("pause");
}

void reporteMontoPrestamosPorMes(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  MONTO PRESTAMOS POR MES" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "Ingrese el a" << char(164) << "o: ";
    int anio = validarEntero(2020, 2100);
    
    cout << endl << "A" << char(164) << "o seleccionado: " << anio << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere sistema de Prestamos)" << endl << endl;
    system("pause");
}

void reportePromedioPrestamosPorEmpleado(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  PROMEDIO PRESTAMOS POR EMPLEADO" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere sistema de Prestamos)" << endl << endl;
    system("pause");
}

//   IMPLEMENTACION REPORTES FINANCIEROS

void reporteSaldoTotalCuentas(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  SALDO TOTAL DE CUENTAS" << endl;
    cout << "========================================" << endl << endl;
    
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == NULL){
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    double saldoTotal = 0;
    int cantidadCuentas = 0;
    
    cuentaBancaria cuenta;
    while(fread(&cuenta, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuenta.getCuentaEliminada() && cuenta.getIdCuenta() != 1){
            saldoTotal += cuenta.getSaldo();
            cantidadCuentas++;
        }
    }

    fclose(archivo);
    
    cout << "Cantidad de cuentas activas: " << cantidadCuentas << endl;
    cout << "Saldo total: $" << fixed << setprecision(2) << saldoTotal << endl << endl;
    
    system("pause");
}

void reportePromedioTransacciones(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  PROMEDIO DE TRANSACCIONES" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    cout << "(Requiere ArchivoMovimientos completo)" << endl << endl;
    system("pause");
}

void reporteRankingCuentasMayorSaldo(){
    system("cls");
    cout << "========================================" << endl;
    cout << "  RANKING CUENTAS - MAYOR SALDO" << endl;
    cout << "========================================" << endl << endl;
    
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == NULL){
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    cuentaBancaria cuenta;
    int cantidad = 0;
    while(fread(&cuenta, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuenta.getCuentaEliminada() && cuenta.getIdCuenta() != 1){
            cantidad++;
        }
    }

    if(cantidad == 0){
        cout << "No hay cuentas activas." << endl;
        fclose(archivo);
        system("pause");
        return;
    }

    cuentaBancaria* cuentas = new cuentaBancaria[cantidad];
    rewind(archivo);
    int index = 0;
    while(fread(&cuenta, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuenta.getCuentaEliminada() && cuenta.getIdCuenta() != 1){
            cuentas[index] = cuenta;
            index++;
        }
    }
    fclose(archivo);

    for(int i = 0; i < cantidad - 1; i++){
        for(int j = 0; j < cantidad - i - 1; j++){
            if(cuentas[j].getSaldo() < cuentas[j + 1].getSaldo()){
                cuentaBancaria temp = cuentas[j];
                cuentas[j] = cuentas[j + 1];
                cuentas[j + 1] = temp;
            }
        }
    }

    int topMostrar = (cantidad < 10) ? cantidad : 10;

    cout << " POS  |  NOMBRE CUENTA         |  CVU         |  SALDO" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    for(int i = 0; i < topMostrar; i++){
        if(i + 1 < 10){
            cout << "  " << (i + 1) << "   |  ";
        } else {
            cout << " " << (i + 1) << "   |  ";
        }
    
        char nombreTemp[21];
        strncpy(nombreTemp, cuentas[i].getNombreCuenta(), 20);
        nombreTemp[20] = '\0';
        cout << nombreTemp;

        size_t lenNombre = strlen(nombreTemp);
        for(int j = 0; j < (20 - lenNombre); j++){
            cout << " ";
        }

        cout << "  |  " << cuentas[i].getCvu() << "  |  $" << fixed << setprecision(2) << cuentas[i].getSaldo() << endl;
    }
    delete[] cuentas;
    cout << endl;
    system("pause");
}