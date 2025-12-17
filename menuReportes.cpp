#define byte windows_byte
#include "rlutil.h"
#undef byte
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
#include "config.h"
#include "art.h"

using namespace std;

void menuReportes(){
    int opcionActual = 0;
    int totalOpciones = 4;
    bool continuar = true;
    bool curs = true;
    
    rlutil::hidecursor();
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(35, 3);
            cout << char(201); centrarTexto("", char(205), 50); cout << char(187);
            rlutil::locate(35, 4);
            cout << char(186); centrarTexto("MENU DE REPORTES", ' ', 50); cout << char(186);
            rlutil::locate(35, 5);
            cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
            
            for(int i = 0; i < totalOpciones; i++){
                rlutil::locate(45, 8 + i);
                if(i == opcionActual){
                    colorTexto(6);
                    cout << char(175) << " ";
                } else {
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Reportes de Clientes"; break;
                    case 1: cout << "Reportes de Empleados"; break;
                    case 2: cout << "Reportes Financieros"; break;
                    case 3: cout << "Volver al men" << char(163) << " principal"; break;
                }
                colorTexto(7);
            }
            curs = false;
        }
        
        int tecla = rlutil::getkey();
        
        if(tecla == 14){  
            opcionActual--;
            if(opcionActual < 0) opcionActual = totalOpciones - 1;
            curs = true;
        }
        else if(tecla == 15){  
            opcionActual++;
            if(opcionActual >= totalOpciones) opcionActual = 0;
            curs = true;
        }
        else if(tecla == 1){  
            rlutil::showcursor();
            
            switch(opcionActual){
                case 0: {
                    menuReportesClientes();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    menuReportesEmpleados();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    menuReportesFinancieros();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuReportesClientes(){
    int opcionActual = 0;
    int totalOpciones = 5;
    bool continuar = true;
    bool curs = true;
    
    rlutil::hidecursor();
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("REPORTES DE CLIENTES", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i < totalOpciones; i++){
                rlutil::locate(35, 8 + i);
                if(i == opcionActual){
                    colorTexto(6);
                    cout << char(175) << " ";
                } else {
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Cliente con m" << char(160) << "s transacciones realizadas"; break;
                    case 1: cout << "Monto total transferencias por mes (cliente espec" << char(161) << "fico)"; break;
                    case 2: cout << "Cantidad de clientes por localidad"; break;
                    case 3: cout << "Top 5 clientes con mayor monto transferido"; break;
                    case 4: cout << "Volver"; break;
                }
                colorTexto(7);
            }
            curs = false;
        }
        
        int tecla = rlutil::getkey();
        
        if(tecla == 14){  
            opcionActual--;
            if(opcionActual < 0) opcionActual = totalOpciones - 1;
            curs = true;
        }
        else if(tecla == 15){  
            opcionActual++;
            if(opcionActual >= totalOpciones) opcionActual = 0;
            curs = true;
        }
        else if(tecla == 1){  
            rlutil::showcursor();
            
            switch(opcionActual){
                case 0: {
                    reporteClienteMasTransacciones();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    reporteMontoTransferenciasPorMes();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    reporteClientesPorLocalidad();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    reporteTop5ClientesMayorMonto();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuReportesEmpleados(){
    int opcionActual = 0;
    int totalOpciones = 4;
    bool continuar = true;
    bool curs = true;
    
    rlutil::hidecursor();
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("REPORTES DE EMPLEADOS", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i < totalOpciones; i++){
                rlutil::locate(40, 8 + i);
                if(i == opcionActual){
                    colorTexto(6);
                    cout << char(175) << " ";
                } else {
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Empleados por localidad"; break;
                    case 1: cout << "Empleados activos vs dados de baja"; break;
                    case 2: cout << "Empleados por rango de edad"; break;
                    case 3: cout << "Volver"; break;
                }
                colorTexto(7);
            }
            curs = false;
        }
        
        int tecla = rlutil::getkey();
        
        if(tecla == 14){  
            opcionActual--;
            if(opcionActual < 0) opcionActual = totalOpciones - 1;
            curs = true;
        }
        else if(tecla == 15){  
            opcionActual++;
            if(opcionActual >= totalOpciones) opcionActual = 0;
            curs = true;
        }
        else if(tecla == 1){  
            rlutil::showcursor();
            
            switch(opcionActual){
                case 0: {
                    reporteEmpleadosPorLocalidad();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    reporteEmpleadosActivosVsBaja();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    reporteEmpleadosPorRangoEdad();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuReportesFinancieros(){
    int opcionActual = 0;
    int totalOpciones = 4;
    bool continuar = true;
    bool curs = true;
    
    rlutil::hidecursor();
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("REPORTES FINANCIEROS", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i < totalOpciones; i++){
                rlutil::locate(35, 8 + i);
                if(i == opcionActual){
                    colorTexto(6);
                    cout << char(175) << " ";
                } else {
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Saldo total de todas las cuentas de clientes"; break;
                    case 1: cout << "Monto promedio de las transacciones"; break;
                    case 2: cout << "Ranking de cuentas con mayor saldo"; break;
                    case 3: cout << "Volver"; break;
                }
                colorTexto(7);
            }
            curs = false;
        }
        
        int tecla = rlutil::getkey();
        
        if(tecla == 14){  
            opcionActual--;
            if(opcionActual < 0) opcionActual = totalOpciones - 1;
            curs = true;
        }
        else if(tecla == 15){  
            opcionActual++;
            if(opcionActual >= totalOpciones) opcionActual = 0;
            curs = true;
        }
        else if(tecla == 1){  
            rlutil::showcursor();
            
            switch(opcionActual){
                case 0: {
                    reporteSaldoTotalCuentas();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    reportePromedioTransacciones();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    reporteRankingCuentasMayorSaldo();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}



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

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("CLIENTE CON MAS TRANSACCIONES", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
    
    if(maxTransacciones == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay transacciones registradas.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }

    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        Cliente clienteActual;
        while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
            if(clienteActual.getIdCliente() == idClienteMax){
                char idFormateado[15];
                formatearId(idFormateado, "CL", idClienteMax, 6);
                
                rlutil::locate(30, 8);
                colorTexto(6);
                cout << "ID: ";
                colorTexto(7);
                cout << idFormateado;
                rlutil::locate(30, 9);
                colorTexto(6);
                cout << "Nombre: ";
                colorTexto(7);
                cout << clienteActual.getNombre() << " " << clienteActual.getApellido();
                rlutil::locate(30, 10);
                colorTexto(6);
                cout << "DNI: ";
                colorTexto(7);
                cout << clienteActual.getDni();
                rlutil::locate(30, 11);
                colorTexto(6);
                cout << "Email: ";
                colorTexto(7);
                cout << clienteActual.getMail();
                break;
            }
        }
        fclose(archivoClientes);
    }

    rlutil::locate(25, 14);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 15);
    colorTexto(2);
    cout << "Total de transacciones realizadas: " << maxTransacciones;
    colorTexto(7);
    rlutil::locate(25, 16);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 19);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteMontoTransferenciasPorMes(){
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("MONTO TOTAL TRANSFERENCIAS POR MES", ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Ingrese el ID del cliente: ";
    colorTexto(7);
    rlutil::showcursor();
    int idCliente = validarEntero(1, 999999);
    
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes == nullptr){
        rlutil::locate(30, 10);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes.";
        colorTexto(7);
        rlutil::hidecursor();
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
        rlutil::locate(30, 10);
        colorTexto(3);
        cout << "ERROR: Cliente no encontrado o dado de baja.";
        colorTexto(7);
        rlutil::hidecursor();
        return;
    }

    rlutil::locate(30, 9);
    colorTexto(6);
    cout << "Ingrese mes (1-12): ";
    colorTexto(7);
    int mes = validarEntero(1, 12);
    rlutil::locate(30, 10);
    colorTexto(6);
    cout << "Ingrese a" << char(164) << "o: ";
    colorTexto(7);
    int anio = validarEntero(2000, 2050);
    rlutil::hidecursor();
    
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
        limpiarPantalla();
        rlutil::locate(30, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones.";
        colorTexto(7);
        return;
    }
    
    Transaccion transaccionActual;
    double montoTotal = 0.0;
    int cantidadTransacciones = 0;
    
    while(fread(&transaccionActual, sizeof(Transaccion), 1, archivoTransacciones) == 1){
        Fecha fechaTrans = transaccionActual.getFechaTransaccion();
        if(fechaTrans.getMes() == mes && fechaTrans.getAnio() == anio){
            int idCuentaOrigen = transaccionActual.getIdCuentaOrigen();
            
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("MONTO TOTAL TRANSFERENCIAS POR MES", ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    char idFormateado[15];
    formatearId(idFormateado, "CL", idCliente, 6);
    
    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Cliente: ";
    colorTexto(7);
    cout << clienteBuscado.getNombre() << " " << clienteBuscado.getApellido();
    rlutil::locate(30, 9);
    colorTexto(6);
    cout << "ID: ";
    colorTexto(7);
    cout << idFormateado;
    rlutil::locate(30, 10);
    colorTexto(6);
    cout << "Periodo: ";
    colorTexto(7);
    cout << mes << "/" << anio;
    
    rlutil::locate(25, 13);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 14);
    colorTexto(6);
    cout << "Cantidad de transferencias: ";
    colorTexto(7);
    cout << cantidadTransacciones;
    rlutil::locate(30, 15);
    colorTexto(6);
    cout << "Monto total transferido: ";
    colorTexto(2);
    cout << "$" << fixed << setprecision(2) << montoTotal;
    colorTexto(7);
    rlutil::locate(25, 16);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 19);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteClientesPorLocalidad(){
    FILE* archivo = fopen("clientes.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de clientes.";
        colorTexto(7);
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CLIENTES POR LOCALIDAD", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    if(totalLocalidades == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay clientes activos registrados.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }

    int totalClientes = 0;
    int lineaActual = 8;
    for(int i = 0; i < totalLocalidades; i++){
        rlutil::locate(35, lineaActual);
        colorTexto(6);
        cout << localidades[i] << ": ";
        colorTexto(7);
        cout << contadores[i];
        if(contadores[i] == 1){
            cout << " cliente";
        } else {
            cout << " clientes";
        }
        totalClientes += contadores[i];
        lineaActual++;
    }
    
    lineaActual++;
    rlutil::locate(30, lineaActual);
    cout << char(196); centrarTexto("", char(196), 60); cout << char(196);
    lineaActual++;
    rlutil::locate(35, lineaActual);
    colorTexto(2);
    cout << "Total de localidades: " << totalLocalidades;
    colorTexto(7);
    lineaActual++;
    rlutil::locate(35, lineaActual);
    colorTexto(2);
    cout << "Total de clientes activos: " << totalClientes;
    colorTexto(7);
    lineaActual++;
    rlutil::locate(30, lineaActual);
    cout << char(196); centrarTexto("", char(196), 60); cout << char(196);
    
    lineaActual += 2;
    rlutil::locate(30, lineaActual);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteTop5ClientesMayorMonto(){
    FILE* archivoTransacciones = fopen("transacciones.dat", "rb");
    if(archivoTransacciones == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones.";
        colorTexto(7);
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
                double tempMonto = montosTransferidos[j];
                montosTransferidos[j] = montosTransferidos[j + 1];
                montosTransferidos[j + 1] = tempMonto;
                
                int tempId = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = tempId;
            }
        }
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("TOP 5 CLIENTES CON MAYOR MONTO", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);

    if(totalClientes == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay transacciones registradas.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }

    int limite = (totalClientes < 5) ? totalClientes : 5;
    
    FILE* archivoClientes = fopen("clientes.dat", "rb");
    if(archivoClientes != nullptr){
        int lineaActual = 8;
        for(int i = 0; i < limite; i++){
            Cliente clienteActual;
            rewind(archivoClientes);
            
            while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1){
                if(clienteActual.getIdCliente() == clientes[i]){
                    char idFormateado[15];
                    formatearId(idFormateado, "CL", clientes[i], 6);
                    
                    rlutil::locate(30, lineaActual);
                    colorTexto(6);
                    cout << "Top " << (i + 1) << ":";
                    colorTexto(7);
                    lineaActual++;
                    rlutil::locate(30, lineaActual);
                    cout << "Cliente: " << clienteActual.getNombre() << " " << clienteActual.getApellido();
                    lineaActual++;
                    rlutil::locate(30, lineaActual);
                    cout << "ID: " << idFormateado;
                    lineaActual++;
                    rlutil::locate(30, lineaActual);
                    colorTexto(2);
                    cout << "Monto total transferido: $" << fixed << setprecision(2) << montosTransferidos[i];
                    colorTexto(7);
                    lineaActual++;
                    rlutil::locate(28, lineaActual);
                    cout << char(196); centrarTexto("", char(196), 62); cout << char(196);
                    lineaActual++;
                    break;
                }
            }
        }
        fclose(archivoClientes);
        
        lineaActual++;
        rlutil::locate(30, lineaActual);
        cout << "Presione cualquier tecla para continuar...";
    }


}

void reporteEmpleadosPorLocalidad(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados.";
        colorTexto(7);
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("EMPLEADOS POR LOCALIDAD", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    if(totalLocalidades == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay empleados activos registrados.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }

    int totalEmpleados = 0;
    int lineaActual = 8;
    for(int i = 0; i < totalLocalidades; i++){
        rlutil::locate(35, lineaActual);
        colorTexto(6);
        cout << localidades[i] << ": ";
        colorTexto(7);
        cout << contadores[i];
        if(contadores[i] == 1){
            cout << " empleado";
        } else {
            cout << " empleados";
        }
        totalEmpleados += contadores[i];
        lineaActual++;
    }
    
    lineaActual++;
    rlutil::locate(30, lineaActual);
    cout << char(196); centrarTexto("", char(196), 60); cout << char(196);
    lineaActual++;
    rlutil::locate(35, lineaActual);
    colorTexto(2);
    cout << "Total de localidades: " << totalLocalidades;
    colorTexto(7);
    lineaActual++;
    rlutil::locate(35, lineaActual);
    colorTexto(2);
    cout << "Total de empleados activos: " << totalEmpleados;
    colorTexto(7);
    lineaActual++;
    rlutil::locate(30, lineaActual);
    cout << char(196); centrarTexto("", char(196), 60); cout << char(196);
    
    lineaActual += 2;
    rlutil::locate(30, lineaActual);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteEmpleadosActivosVsBaja(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados.";
        colorTexto(7);
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("EMPLEADOS ACTIVOS VS DADOS DE BAJA", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
    
    rlutil::locate(30, 8);
    colorTexto(2);
    cout << "Empleados ACTIVOS:       ";
    colorTexto(7);
    cout << activos;
    rlutil::locate(30, 9);
    colorTexto(3);
    cout << "Empleados DADOS DE BAJA: ";
    colorTexto(7);
    cout << inactivos;
    rlutil::locate(25, 10);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 11);
    colorTexto(6);
    cout << "TOTAL DE EMPLEADOS:      ";
    colorTexto(7);
    cout << total;

    if(total > 0){
        rlutil::locate(25, 13);
        cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
        double porcentajeActivos = (static_cast<double>(activos) / static_cast<double>(total)) * 100.0;
        double porcentajeBaja = (static_cast<double>(inactivos) / static_cast<double>(total)) * 100.0;

        rlutil::locate(30, 14);
        colorTexto(6);
        cout << "Porcentaje activos:      ";
        colorTexto(2);
        cout << fixed << setprecision(2) << porcentajeActivos << "%";
        colorTexto(7);
        rlutil::locate(30, 15);
        colorTexto(6);
        cout << "Porcentaje dados de baja: ";
        colorTexto(3);
        cout << fixed << setprecision(2) << porcentajeBaja << "%";
        colorTexto(7);
    }
    rlutil::locate(25, 17);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 20);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteEmpleadosPorRangoEdad(){
    FILE* archivo = fopen("empleados.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de empleados.";
        colorTexto(7);
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("EMPLEADOS POR RANGO DE EDAD", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);

    if(total == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay empleados activos registrados.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }
    
    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Menores de 30 a" << char(164) << "os: ";
    colorTexto(7);
    cout << menores30 << " empleados";
    rlutil::locate(30, 9);
    colorTexto(6);
    cout << "Entre 30 y 39 a" << char(164) << "os: ";
    colorTexto(7);
    cout << entre30y40 << " empleados";
    rlutil::locate(30, 10);
    colorTexto(6);
    cout << "Entre 40 y 49 a" << char(164) << "os: ";
    colorTexto(7);
    cout << entre40y50 << " empleados";
    rlutil::locate(30, 11);
    colorTexto(6);
    cout << "50 a" << char(164) << "os o m" << char(160) << "s:      ";
    colorTexto(7);
    cout << mayores50 << " empleados";
    rlutil::locate(25, 13);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 14);
    colorTexto(2);
    cout << "Total de empleados activos: " << total;
    colorTexto(7);
    rlutil::locate(25, 15);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 18);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteSaldoTotalCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        return;
    }

    cuentaBancaria cuentaActual;
    double saldoTotal = 0.0;
    int totalCuentas = 0;
    int cuentasActivas = 0;

    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        totalCuentas++;
        
        if(!cuentaActual.getCuentaEliminada()){
            if(cuentaActual.getIdCuenta() != 1){
                saldoTotal += cuentaActual.getSaldo();
                cuentasActivas++;
            }
        }
    }
    fclose(archivo);

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("SALDO TOTAL DE TODAS LAS CUENTAS", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
    
    if(cuentasActivas == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay cuentas activas registradas.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }

    double saldoPromedio = saldoTotal / static_cast<double>(cuentasActivas);
    
    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Cuentas activas (clientes):  ";
    colorTexto(7);
    cout << cuentasActivas;
    rlutil::locate(30, 9);
    colorTexto(6);
    cout << "Cuentas dadas de baja:       ";
    colorTexto(7);
    cout << (totalCuentas - cuentasActivas - 1);
    rlutil::locate(25, 11);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 12);
    colorTexto(6);
    cout << "Saldo total:                 ";
    colorTexto(2);
    cout << "$" << fixed << setprecision(2) << saldoTotal;
    colorTexto(7);
    rlutil::locate(30, 13);
    colorTexto(6);
    cout << "Saldo promedio por cuenta:   ";
    colorTexto(2);
    cout << "$" << fixed << setprecision(2) << saldoPromedio;
    colorTexto(7);
    rlutil::locate(25, 14);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 17);
    cout << "Presione cualquier tecla para continuar...";
}

void reportePromedioTransacciones(){
    FILE* archivo = fopen("transacciones.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de transacciones.";
        colorTexto(7);
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("MONTO PROMEDIO DE TRANSACCIONES", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
    
    if(cantidadTransacciones == 0){
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay transacciones registradas.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
        return;
    }
    double promedio = sumaTotal / static_cast<double>(cantidadTransacciones);
    
    rlutil::locate(30, 8);
    colorTexto(6);
    cout << "Total de transacciones:      ";
    colorTexto(7);
    cout << cantidadTransacciones;
    rlutil::locate(25, 10);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    rlutil::locate(30, 11);
    colorTexto(6);
    cout << "Monto promedio:              ";
    colorTexto(2);
    cout << "$" << fixed << setprecision(2) << promedio;
    colorTexto(7);
    rlutil::locate(30, 12);
    colorTexto(6);
    cout << "Monto m" << char(161) << "nimo transferido:    ";
    colorTexto(7);
    cout << "$" << fixed << setprecision(2) << montoMinimo;
    rlutil::locate(30, 13);
    colorTexto(6);
    cout << "Monto m" << char(160) << "ximo transferido:    ";
    colorTexto(7);
    cout << "$" << fixed << setprecision(2) << montoMaximo;
    rlutil::locate(30, 14);
    colorTexto(6);
    cout << "Suma total transferida:      ";
    colorTexto(2);
    cout << "$" << fixed << setprecision(2) << sumaTotal;
    colorTexto(7);
    rlutil::locate(25, 15);
    cout << char(196); centrarTexto("", char(196), 70); cout << char(196);
    
    rlutil::locate(30, 18);
    cout << "Presione cualquier tecla para continuar...";
}

void reporteRankingCuentasMayorSaldo(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
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
        limpiarPantalla();
        colorTexto(7);
        rlutil::locate(25, 3);
        cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
        rlutil::locate(25, 4);
        cout << char(186); centrarTexto("RANKING DE CUENTAS CON MAYOR SALDO", ' ', 70); cout << char(186);
        rlutil::locate(25, 5);
        cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
        rlutil::locate(30, 8);
        colorTexto(3);
        cout << "No hay cuentas activas registradas.";
        colorTexto(7);
        rlutil::locate(30, 11);
        cout << "Presione cualquier tecla para continuar...";
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
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(25, 3);
    cout << char(201); centrarTexto("", char(205), 70); cout << char(187);
    rlutil::locate(25, 4);
    cout << char(186); centrarTexto("RANKING DE CUENTAS CON MAYOR SALDO", ' ', 70); cout << char(186);
    rlutil::locate(25, 5);
    cout << char(200); centrarTexto("", char(205), 70); cout << char(188);
    
    int limite = (totalCuentas < 10) ? totalCuentas : 10;
    
    int lineaActual = 8;
    for(int i = 0; i < limite; i++){
        char idFormateado[15];
        formatearId(idFormateado, "CU", cuentas[i].getIdCuenta(), 6);
        
        rlutil::locate(30, lineaActual);
        colorTexto(6);
        cout << "Top " << (i + 1) << ":";
        colorTexto(7);
        lineaActual++;
        rlutil::locate(30, lineaActual);
        cout << "Cuenta: " << cuentas[i].getNombreCuenta();
        lineaActual++;
        rlutil::locate(30, lineaActual);
        cout << "ID: " << idFormateado;
        lineaActual++;
        rlutil::locate(30, lineaActual);
        cout << "Alias: " << cuentas[i].getAlias();
        lineaActual++;
        rlutil::locate(30, lineaActual);
        colorTexto(2);
        cout << "Saldo: $" << fixed << setprecision(2) << cuentas[i].getSaldo();
        colorTexto(7);
        lineaActual++;
        rlutil::locate(28, lineaActual);
        cout << char(196); centrarTexto("", char(196), 62); cout << char(196);
        lineaActual++;
    }
    
    lineaActual++;
    rlutil::locate(30, lineaActual);
    colorTexto(6);
    cout << "Total de cuentas mostradas: ";
    colorTexto(7);
    cout << limite << " de " << totalCuentas;
    
    lineaActual += 3;
    rlutil::locate(30, lineaActual);
    cout << "Presione cualquier tecla para continuar...";
}