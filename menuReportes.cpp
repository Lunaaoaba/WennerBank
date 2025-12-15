#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "menuReportes.h"
#include "archivoClientes.h"
#include "archivoEmpleados.h"
#include "archivoCuentas.h"
#include "archivoCuentas.h"
#include "archivoTransacciones.h"
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
        cout << "1. Cliente con mas transacciones realizadas" << endl;
        cout << "2. Monto total transferencias por mes (cliente especifico)" << endl;
        cout << "3. Cantidad de clientes por localidad" << endl;
        cout << "4. Top 5 clientes con mayor monto transferido" << endl;
        cout << "5. Volver" << endl << endl;

        int opcion = validarEntero(1, 5);

        switch(opcion){
            case 1: {
                reporteClienteMasTransacciones();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 2: {
                reporteMontoTransferenciasPorMes();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 3: {
                reporteClientesPorLocalidad();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 4: {
                reporteTop5ClientesMayorMonto();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 5: {
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
        cout << "1. Empleados por localidad" << endl;
        cout << "2. Empleados activos vs dados de baja" << endl;
        cout << "3. Empleados por rango de edad" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                reporteEmpleadosPorLocalidad();
                system("pause");
                break;
            }
            case 2: {
                reporteEmpleadosActivosVsBaja();
                system("pause");
                break;
            }
            case 3: {
                reporteEmpleadosPorRangoEdad();
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

// MENU REPORTES FINANCIEROS

void menuReportesFinancieros(){
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      REPORTES FINANCIEROS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Saldo total de todas las cuentas de clientes" << endl;
        cout << "2. Monto promedio de las transacciones" << endl;
        cout << "3. Ranking de cuentas con mayor saldo" << endl;
        cout << "4. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 4);
        
        switch(opcion){
            case 1: {
                reporteSaldoTotalCuentas();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 2: {
                reportePromedioTransacciones();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
            case 3: {
                reporteRankingCuentasMayorSaldo();
                system("pause");  // ⬅️ AGREGAR
                break;
            }
        }
    }
}



// IMPLEMENTACION REPORTES CLIENTES

void reporteClienteMasTransacciones(){
    FILE* archivoTransacciones = fopen("transacciones.dat", "rb");
    if(archivoTransacciones == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }
    
    Transaccion transaccionActual;
    int clientes[1000];
    int contadores[1000] = {0};
    int totalClientes = 0;

    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivoTransacciones) == 1){
        int idCuentaOrigen = transaccionActual.getIdCuentaOrigen();

        FILE* archivoCuentas = fopen("cuentas.dat", "rb");
        if(archivoCuentas != nullptr){
            cuentaBancaria cuentaActual;
            while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivoCuentas) == 1){
                if(cuentaActual.getIdCuenta() == idCuentaOrigen){
                    int idCliente = cuentaActual.getIdCliente();
                    bool encontrado = false;

                    for(int i = 0; i < totalClientes; i++){
                        if(clientes[i] == idCliente){
                            contadores[i]++;
                            encontrado = true;
                            break;
                        }
                    }
                    if(!encontrado){
                        clientes[totalClientes] = idCliente;
                        contadores[totalClientes] = 1;
                        totalClientes++;
                    }
                    break;
                }
            }
            fclose(archivoCuentas);
        }
    }
    
    fclose(archivoTransacciones);

    int maxTransacciones = 0;
    int idClienteMax = 0;
    
    for(int i = 0; i < totalClientes; i++){
        if(contadores[i] > maxTransacciones){
            maxTransacciones = contadores[i];
            idClienteMax = clientes[i];
        }
    }

    system("cls");
    cout << "========================================" << endl;
    cout << " CLIENTE CON MAS TRANSACCIONES" << endl;
    cout << "========================================" << endl << endl;
    
    if(maxTransacciones == 0){
        cout << "No hay transacciones registradas." << endl << endl;
        return;
    }

    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        Cliente clienteActual;
        while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
            if(clienteActual.getIdCliente() == idClienteMax){
                cout << clienteActual.mostrarDatos() << endl << endl;
                break;
            }
        }
        fclose(archivoClientes);
    }

    cout << "========================================" << endl;
    cout << "Total de transacciones realizadas: " << maxTransacciones << endl;
    cout << "========================================" << endl << endl;
}

void reporteMontoTransferenciasPorMes(){
    system("cls");
    cout << "========================================" << endl;
    cout << " MONTO TOTAL TRANSFERENCIAS POR MES" << endl;
    cout << "========================================" << endl << endl;
    
    // Solicitar ID del cliente
    cout << "Ingrese el ID del cliente: ";
    int idCliente = validarEntero(1, 999999);
    
    // Verificar que el cliente existe
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    
    Cliente clienteBuscado;
    bool clienteEncontrado = false;

    while(fread(&clienteBuscado, sizeof(Cliente), 1, archivoClientes) == 1){
        if(clienteBuscado.getIdCliente() == idCliente && !clienteBuscado.getUsuarioEliminado()){
            clienteEncontrado = true;
            break;
        }
    }
    fclose(archivoClientes);
    
    if(!clienteEncontrado){
        cout << "ERROR: Cliente no encontrado o dado de baja." << endl << endl;
        return;
    }

    cout << "Ingrese mes (1-12): ";
    int mes = validarEntero(1, 12);
    cout << "Ingrese año: ";
    int anio = validarEntero(2020, 2030);
    
    // Buscar todas las cuentas del cliente
    int cuentasCliente[50];
    int totalCuentas = 0;
    
    FILE* archivoCuentas = fopen("cuentas.dat", "rb");
    if(archivoCuentas != nullptr){
        cuentaBancaria cuentaActual;
        while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivoCuentas) == 1){
            if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
                cuentasCliente[totalCuentas] = cuentaActual.getIdCuenta();
                totalCuentas++;
            }
        }
        fclose(archivoCuentas);
    }

    FILE* archivoTransacciones = fopen("transacciones.dat", "rb");
    if(archivoTransacciones == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }
    
    Transaccion transaccionActual;
    double montoTotal = 0.0;
    int cantidadTransacciones = 0;
    
    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivoTransacciones) == 1){
        Fecha fechaTrans = transaccionActual.getFechaTransaccion();
        if(fechaTrans.getMes() == mes && fechaTrans.getAnio() == anio){
            int idCuentaOrigen = transaccionActual.getIdCuentaOrigen();
            
            // Verificar si la cuenta origen pertenece al cliente
            for(int i = 0; i < totalCuentas; i++){
                if(cuentasCliente[i] == idCuentaOrigen){
                    montoTotal += transaccionActual.getMonto();
                    cantidadTransacciones++;
                    break;
                }
            }
        }
    }

    fclose(archivoTransacciones);
    
    // Mostrar resultados
    system("cls");
    cout << "========================================" << endl;
    cout << " MONTO TOTAL TRANSFERENCIAS POR MES" << endl;
    cout << "========================================" << endl << endl;
    cout << "Cliente: " << clienteBuscado.getNombre() << " " << clienteBuscado.getApellido() << endl;
    cout << "ID Cliente: CL-" << idCliente << endl;
    cout << "Periodo: " << mes << "/" << anio << endl << endl;
    cout << "========================================" << endl;
    cout << "Cantidad de transferencias: " << cantidadTransacciones << endl;
    cout << "Monto total transferido: $" << fixed << setprecision(2) << montoTotal << endl;
    cout << "========================================" << endl << endl;
}

//dsp pasar a memoria dinamica
void reporteClientesPorLocalidad(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
    
    Cliente clienteActual;
    char localidades[100][50];
    int contadores[100] = {0};
    int totalLocalidades = 0;

    while(fread(&clienteActual, sizeof(Cliente), 1, archivo) == 1){
        if(!clienteActual.getUsuarioEliminado()){
            const char* localidad = clienteActual.getLocalidad();
            bool encontrada = false;
            
            for(int i = 0; i < totalLocalidades; i++){
                if(strcmp(localidades[i], localidad) == 0){
                    contadores[i]++;
                    encontrada = true;
                    break;
                }
            }
            if(!encontrada){
                strcpy(localidades[totalLocalidades], localidad);
                contadores[totalLocalidades] = 1;
                totalLocalidades++;
            }
        }
    }
    
    fclose(archivo);
    
    system("cls");
    cout << "========================================" << endl;
    cout << "     CLIENTES POR LOCALIDAD" << endl;
    cout << "========================================" << endl << endl;
    
    if(totalLocalidades == 0){
        cout << "No hay clientes activos registrados." << endl << endl;
        return;
    }

    int totalClientes = 0;
    for(int i = 0; i < totalLocalidades; i++){
        cout << localidades[i] << ": " << contadores[i];
        if(contadores[i] == 1){
            cout << " cliente" << endl;
        } else {
            cout << " clientes" << endl;
        }
        totalClientes += contadores[i];
    }
    
    cout << "========================================" << endl;
    cout << "Total de localidades: " << totalLocalidades << endl;
    cout << "Total de clientes activos: " << totalClientes << endl;
    cout << "========================================" << endl << endl;
}

void reporteTop5ClientesMayorMonto(){
    FILE* archivoTransacciones = fopen("transacciones.dat", "rb");
    if(archivoTransacciones == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }
    
    Transaccion transaccionActual;
    int clientes[1000];
    double montosTransferidos[1000] = {0.0};
    int totalClientes = 0;

    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivoTransacciones) == 1){
        int idCuentaOrigen = transaccionActual.getIdCuentaOrigen();

        FILE* archivoCuentas = fopen("cuentas.dat", "rb");
        if(archivoCuentas != nullptr){
            cuentaBancaria cuentaActual;
            while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivoCuentas) == 1){
                if(cuentaActual.getIdCuenta() == idCuentaOrigen){
                    int idCliente = cuentaActual.getIdCliente();
                    bool encontrado = false;

                    for(int i = 0; i < totalClientes; i++){
                        if(clientes[i] == idCliente){
                            montosTransferidos[i] += transaccionActual.getMonto();
                            encontrado = true;
                            break;
                        }
                    }
                    if(!encontrado){
                        clientes[totalClientes] = idCliente;
                        montosTransferidos[totalClientes] = transaccionActual.getMonto();
                        totalClientes++;
                    }
                    break;
                    }
            }
            fclose(archivoCuentas);
        }
    }

    fclose(archivoTransacciones);

    for(int i = 0; i < totalClientes - 1; i++){
        for(int j = 0; j < totalClientes - i - 1; j++){
            if(montosTransferidos[j] < montosTransferidos[j + 1]){
                // Intercambiar montos
                double tempMonto = montosTransferidos[j];
                montosTransferidos[j] = montosTransferidos[j + 1];
                montosTransferidos[j + 1] = tempMonto;
                
                // Intercambiar IDs
                int tempId = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = tempId;
            }
        }
    }
    system("cls");
    cout << "========================================" << endl;
    cout << " TOP 5 CLIENTES CON MAYOR MONTO" << endl;
    cout << "========================================" << endl << endl;

    if(totalClientes == 0){
        cout << "No hay transacciones registradas." << endl << endl;
        return;
    }

    int limite = (totalClientes < 5) ? totalClientes : 5;
    
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        for(int i = 0; i < limite; i++){
            Cliente clienteActual;
            rewind(archivoClientes);
            
            while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
                if(clienteActual.getIdCliente() == clientes[i]){
                    cout << "Top " << (i + 1) << ":" << endl;
                    cout << "Cliente: " << clienteActual.getNombre() << " " << clienteActual.getApellido() << endl;
                    cout << "ID: CL-" << clientes[i] << endl;
                    cout << "Monto total transferido: $" << fixed << setprecision(2) << montosTransferidos[i] << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                }
            }
        }
        fclose(archivoClientes);
    }
    
    cout << "========================================" << endl << endl;


}

// IMPLEMENTACIÓN REPORTES EMPLEADOS

void reporteEmpleadosPorLocalidad(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }
    
    Empleado empleadoActual;
    char localidades[100][50];
    int contadores[100] = {0};
    int totalLocalidades = 0;

    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(!empleadoActual.getUsuarioEliminado()){
            const char* localidad = empleadoActual.getLocalidad();
            bool encontrada = false;
            
            for(int i = 0; i < totalLocalidades; i++){
                if(strcmp(localidades[i], localidad) == 0){
                    contadores[i]++;
                    encontrada = true;
                    break;
                }
            }
            
            if(!encontrada){
                strcpy(localidades[totalLocalidades], localidad);
                contadores[totalLocalidades] = 1;
                totalLocalidades++;
            }
        }
    }
    
    fclose(archivo);
    
    system("cls");
    cout << "========================================" << endl;
    cout << "     EMPLEADOS POR LOCALIDAD" << endl;
    cout << "========================================" << endl << endl;
    
    if(totalLocalidades == 0){
        cout << "No hay empleados activos registrados." << endl << endl;
        return;
    }

    int totalEmpleados = 0;
    for(int i = 0; i < totalLocalidades; i++){
        cout << localidades[i] << ": " << contadores[i];
        if(contadores[i] == 1){
            cout << " empleado" << endl;
        } else {
            cout << " empleados" << endl;
        }
        totalEmpleados += contadores[i];
    }
    
    cout << "========================================" << endl;
    cout << "Total de localidades: " << totalLocalidades << endl;
    cout << "Total de empleados activos: " << totalEmpleados << endl;
    cout << "========================================" << endl << endl;
}

void reporteEmpleadosActivosVsBaja(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }

    Empleado empleadoActual;
    int activos = 0;
    int inactivos = 0;

    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(empleadoActual.getUsuarioEliminado()) inactivos++;
        else activos++;
    }
    
    fclose(archivo);

    int total = activos + inactivos;
    
    system("cls");
    cout << "========================================" << endl;
    cout << "   EMPLEADOS ACTIVOS VS DADOS DE BAJA" << endl;
    cout << "========================================" << endl << endl;
    cout << "Empleados ACTIVOS:       " << activos << endl;
    cout << "Empleados DADOS DE BAJA: " << inactivos << endl;
    cout << "----------------------------------------" << endl;
    cout << "TOTAL DE EMPLEADOS:      " << total << endl << endl;

    if(total > 0){
        cout << "----------------------------------------" << endl;
        double porcentajeActivos = (static_cast<double>(activos) / static_cast<double>(total)) * 100.0;
        double porcentajeBaja = (static_cast<double>(inactivos) / static_cast<double>(total)) * 100.0;

        cout << "Porcentaje activos:      " << fixed << setprecision(2) << porcentajeActivos << "%" << endl;
        cout << "Porcentaje dados de baja: " << fixed << setprecision(2) << porcentajeBaja << "%" << endl;
    }
    cout << "========================================" << endl << endl;
}

void reporteEmpleadosPorRangoEdad(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de empleados." << endl;
        return;
    }

    Empleado empleadoActual;
    int menores30 = 0;
    int entre30y40 = 0;
    int entre40y50 = 0;
    int mayores50 = 0;

    Fecha fechaHoy;
    fechaHoy.cargarFechaActual();
    int anioActual = fechaHoy.getAnio();
    int mesActual = fechaHoy.getMes();
    int diaActual = fechaHoy.getDia();

    while(fread(&empleadoActual, sizeof(Empleado), 1, archivo) == 1){
        if(!empleadoActual.getUsuarioEliminado()){
            Fecha fechaNac = empleadoActual.getFechaNacimiento();
            int edad = anioActual - fechaNac.getAnio();
            
            if(mesActual < fechaNac.getMes() || (mesActual == fechaNac.getMes() && diaActual < fechaNac.getDia())){
                edad--;
            }

            if(edad < 30){
                menores30++;
            } else if(edad >= 30 && edad < 40){
                entre30y40++;
            } else if(edad >= 40 && edad < 50){
                entre40y50++;
            } else {
                mayores50++;
            }
        }
    }

    fclose(archivo);
    
    int total = menores30 + entre30y40 + entre40y50 + mayores50;
    
    system("cls");
    cout << "========================================" << endl;
    cout << "   EMPLEADOS POR RANGO DE EDAD" << endl;
    cout << "========================================" << endl << endl;

    if(total == 0){
        cout << "No hay empleados activos registrados." << endl << endl;
        return;
    }
    
    cout << "Menores de 30 años: " << menores30 << " empleados" << endl;
    cout << "Entre 30 y 39 años: " << entre30y40 << " empleados" << endl;
    cout << "Entre 40 y 49 años: " << entre40y50 << " empleados" << endl;
    cout << "50 años o más:      " << mayores50 << " empleados" << endl;
    cout << "========================================" << endl;
    cout << "Total de empleados activos: " << total << endl;
    cout << "========================================" << endl << endl;
}

// IMPLEMENTACION REPORTES FINANCIEROS


void reporteSaldoTotalCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return;
    }

    cuentaBancaria cuentaActual;
    double saldoTotal = 0.0;
    int totalCuentas = 0;
    int cuentasActivas = 0;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        totalCuentas++;
        
        if(!cuentaActual.getCuentaEliminada()){
            // Excluir la Cuenta Banco (ID = 1)
            if(cuentaActual.getIdCuenta() != 1){
                saldoTotal += cuentaActual.getSaldo();
                cuentasActivas++;
            }
        }
    }
    fclose(archivo);

    system("cls");
    cout << "========================================" << endl;
    cout << "   SALDO TOTAL DE TODAS LAS CUENTAS" << endl;
    cout << "========================================" << endl << endl;
    
    if(cuentasActivas == 0){
        cout << "No hay cuentas activas registradas." << endl << endl;
        return;
    }

    double saldoPromedio = saldoTotal / static_cast<double>(cuentasActivas);
    
    cout << "Cuentas activas (clientes):  " << cuentasActivas << endl;
    cout << "Cuentas dadas de baja:       " << (totalCuentas - cuentasActivas - 1) << endl;
    cout << "========================================" << endl;
    cout << "Saldo total:                 $" << fixed << setprecision(2) << saldoTotal << endl;
    cout << "Saldo promedio por cuenta:   $" << fixed << setprecision(2) << saldoPromedio << endl;
    cout << "========================================" << endl << endl;
}

void reportePromedioTransacciones(){
    FILE* archivo = fopen("transacciones.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de transacciones." << endl;
        return;
    }

    Transaccion transaccionActual;
    double sumaTotal = 0.0;
    int cantidadTransacciones = 0;
    double montoMinimo = 0.0;
    double montoMaximo = 0.0;
    bool primerRegistro = true;

    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivo) == 1){
        double monto = transaccionActual.getMonto();
        sumaTotal += monto;
        cantidadTransacciones++;

        if(primerRegistro){
            montoMinimo = monto;
            montoMaximo = monto;
            primerRegistro = false;
        } else {
            if(monto < montoMinimo) montoMinimo = monto;
            if(monto > montoMaximo) montoMaximo = monto;
        }
    }
    fclose(archivo);
    
    // Mostrar resultados
    system("cls");
    cout << "========================================" << endl;
    cout << "  MONTO PROMEDIO DE TRANSACCIONES" << endl;
    cout << "========================================" << endl << endl;
    
    if(cantidadTransacciones == 0){
        cout << "No hay transacciones registradas." << endl << endl;
        return;
    }
    double promedio = sumaTotal / static_cast<double>(cantidadTransacciones);
    
    cout << "Total de transacciones:      " << cantidadTransacciones << endl;
    cout << "========================================" << endl;
    cout << "Monto promedio:              $" << fixed << setprecision(2) << promedio << endl;
    cout << "Monto mínimo transferido:    $" << fixed << setprecision(2) << montoMinimo << endl;
    cout << "Monto máximo transferido:    $" << fixed << setprecision(2) << montoMaximo << endl;
    cout << "Suma total transferida:      $" << fixed << setprecision(2) << sumaTotal << endl;
    cout << "========================================" << endl << endl;
}

void reporteRankingCuentasMayorSaldo(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return;
    }
    cuentaBancaria cuentas[1000];
    int totalCuentas = 0;

    while(fread(&cuentas[totalCuentas], sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuentas[totalCuentas].getCuentaEliminada() && cuentas[totalCuentas].getIdCuenta() != 1){
            totalCuentas++;
        }
    }
    fclose(archivo);

    if(totalCuentas == 0){
        system("cls");
        cout << "========================================" << endl;
        cout << "  RANKING DE CUENTAS CON MAYOR SALDO" << endl;
        cout << "========================================" << endl << endl;
        cout << "No hay cuentas activas registradas." << endl << endl;
        return;
    }

    for(int i = 0; i < totalCuentas - 1; i++){
        for(int j = 0; j < totalCuentas - i - 1; j++){
            if(cuentas[j].getSaldo() < cuentas[j + 1].getSaldo()){
                cuentaBancaria temp = cuentas[j];
                cuentas[j] = cuentas[j + 1];
                cuentas[j + 1] = temp;
            }
        }
    }
    system("cls");
    cout << "========================================" << endl;
    cout << "  RANKING DE CUENTAS CON MAYOR SALDO" << endl;
    cout << "========================================" << endl << endl;
    
    int limite = (totalCuentas < 10) ? totalCuentas : 10;
    
    for(int i = 0; i < limite; i++){
        cout << "Top " << (i + 1) << ":" << endl;
        cout << "Cuenta: " << cuentas[i].getNombreCuenta() << endl;
        cout << "ID: CU-" << cuentas[i].getIdCuenta() << endl;
        cout << "Alias: " << cuentas[i].getAlias() << endl;
        cout << "Saldo: $" << fixed << setprecision(2) << cuentas[i].getSaldo() << endl;
        cout << "----------------------------------------" << endl;
    }
    
    cout << "========================================" << endl;
    cout << "Total de cuentas mostradas: " << limite << " de " << totalCuentas << endl;
    cout << "========================================" << endl << endl;
}