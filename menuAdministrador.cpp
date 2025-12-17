#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "menuAdministrador.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "archivoTransacciones.h"
#include "menuReportes.h"
#include "administrador.h"
#include "funciones.h"
#include "config.h"
#include "art.h"
#include "menu.h"

using namespace std;

void menuAdmin(){
    int opcionActual = 0;
    int totalOpciones = 8;
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
            cout << char(186); centrarTexto("MENU ADMINISTRADOR", ' ', 50); cout << char(187);
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
                    case 0: cout << "Listados"; break;
                    case 1: cout << "B" << char(163) << "squedas"; break;
                    case 2: cout << "Gesti" << char(162) << "n de Empleados"; break;
                    case 3: cout << "Gesti" << char(162) << "n de Clientes"; break;
                    case 4: cout << "Gesti" << char(162) << "n de Cuentas"; break;
                    case 5: cout << "Transacciones"; break;
                    case 6: cout << "Reportes"; break;
                    case 7: cout << "Cerrar sesi" << char(162) << "n"; break;
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
                    menuListadosAdmin();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    menuBusquedasAdmin();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    gestionarEmpleados();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    gestionarClientesAdmin();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    gestionarCuentasAdmin();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    menuTransaccionesAdmin();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 6: {
                    menuReportes();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 7: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuListadosAdmin(){
    ArchivoClientes objClientes;
    ArchivoEmpleados objEmpleados;
    ArchivoCuentas objCuentas;

    int opcionActual = 0;
    int totalOpciones = 8;
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
            cout << char(186); centrarTexto("LISTADOS", ' ', 60); cout << char(186);
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
                    case 0: cout << "Listar mis datos"; break;
                    case 1: cout << "Listar TODAS las cuentas bancarias"; break;
                    case 2: cout << "Listar cuentas activas"; break;
                    case 3: cout << "Listar TODOS los empleados"; break;
                    case 4: cout << "Listar empleados activos"; break;
                    case 5: cout << "Listar TODOS los clientes"; break;
                    case 6: cout << "Listar clientes activos"; break;
                    case 7: cout << "Volver"; break;
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
                    Administrador* admin = Administrador::getInstancia();
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("MIS DATOS (ADMINISTRADOR)", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    char legajoFormateado[15];
                    formatearId(legajoFormateado, "EMP", admin->getLegajo(), 6);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Nombre: ";
                    colorTexto(7);
                    cout << admin->getNombre() << " " << admin->getApellido();
                    rlutil::locate(35, 9);
                    colorTexto(6);
                    cout << "Legajo: ";
                    colorTexto(7);
                    cout << legajoFormateado;
                    rlutil::locate(35, 10);
                    colorTexto(6);
                    cout << "DNI: ";
                    colorTexto(7);
                    cout << admin->getDni();
                    rlutil::locate(35, 11);
                    colorTexto(6);
                    cout << "Mail: ";
                    colorTexto(7);
                    cout << admin->getMail();
                    rlutil::locate(35, 12);
                    colorTexto(6);
                    cout << "Edad: ";
                    colorTexto(7);
                    cout << admin->getEdad() << " a" << char(164) << "os";
                    rlutil::locate(35, 13);
                    colorTexto(6);
                    cout << "Localidad: ";
                    colorTexto(7);
                    cout << admin->getLocalidad();
                    
                    rlutil::locate(35, 16);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    objCuentas.listarTodasCuentas();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    objCuentas.listarCuentas();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    objEmpleados.listarTodosEmpleados();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    objEmpleados.listarEmpleados();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    objClientes.listarTodosClientes();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 6: {
                    objClientes.listarClientes();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 7: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuBusquedasAdmin(){
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
            cout << char(186); centrarTexto("BUSQUEDAS", ' ', 50); cout << char(186);
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
                    case 0: cout << "Buscar cliente"; break;
                    case 1: cout << "Buscar empleado"; break;
                    case 2: cout << "Buscar cuenta bancaria"; break;
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
                    buscarClienteMenu();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    buscarEmpleadoMenu();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    buscarCuentaMenu();
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

void buscarClienteMenu(){
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("BUSCAR CLIENTE", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(40, 8);
    cout << "1. Buscar por ID";
    rlutil::locate(40, 9);
    cout << "2. Buscar por DNI";
    rlutil::locate(40, 10);
    cout << "3. Buscar por Mail";
    rlutil::locate(40, 11);
    cout << "4. Cancelar";
    
    rlutil::locate(35, 14);
    cout << char(175) << " Opci" << char(162) << "n: ";
    
    Cliente clienteEncontrado;
    ArchivoClientes objClientes;
    int opcion = validarEntero(1, 4);
    
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el ID: ";
            colorTexto(7);
            int id = validarEntero(1, 999999);
            encontrado = objClientes.buscarCliente("ID", id, clienteEncontrado);
            break;
        }
        case 2: {
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el DNI: ";
            colorTexto(7);
            int dni = validarEntero(10000000, 99999999);
            encontrado = objClientes.buscarCliente("DNI", dni, clienteEncontrado);
            break;
        }
        case 3: {
            char mail[50];
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el Mail: ";
            colorTexto(7);
            validarCadena(mail, 50);
            encontrado = objClientes.buscarCliente("MAIL", mail, clienteEncontrado);
            break;
        }
        case 4: {
            return;
        }
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    
    if(encontrado){
        cout << char(186); centrarTexto("CLIENTE ENCONTRADO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        char idFormateado[15];
        formatearId(idFormateado, "CL", clienteEncontrado.getIdCliente(), 6);
        
        rlutil::locate(35, 8);
        colorTexto(6);
        cout << "ID: ";
        colorTexto(7);
        cout << idFormateado;
        rlutil::locate(35, 9);
        colorTexto(6);
        cout << "Nombre: ";
        colorTexto(7);
        cout << clienteEncontrado.getNombre() << " " << clienteEncontrado.getApellido();
        rlutil::locate(35, 10);
        colorTexto(6);
        cout << "DNI: ";
        colorTexto(7);
        cout << clienteEncontrado.getDni();
        rlutil::locate(35, 11);
        colorTexto(6);
        cout << "Mail: ";
        colorTexto(7);
        cout << clienteEncontrado.getMail();
        rlutil::locate(35, 12);
        colorTexto(6);
        cout << "Localidad: ";
        colorTexto(7);
        cout << clienteEncontrado.getLocalidad();
        rlutil::locate(35, 13);
        colorTexto(6);
        cout << "Estado: ";
        if(clienteEncontrado.getUsuarioEliminado()){
            colorTexto(3);
            cout << "DADO DE BAJA";
        } else {
            colorTexto(2);
            cout << "ACTIVO";
        }
        colorTexto(7);
    }
    else{
        cout << char(186); centrarTexto("CLIENTE NO ENCONTRADO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    }
    
    rlutil::locate(35, 16);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void buscarEmpleadoMenu(){
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("BUSCAR EMPLEADO", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(40, 8);
    cout << "1. Buscar por Legajo";
    rlutil::locate(40, 9);
    cout << "2. Buscar por DNI";
    rlutil::locate(40, 10);
    cout << "3. Buscar por Mail";
    rlutil::locate(40, 11);
    cout << "4. Cancelar";
    
    rlutil::locate(35, 14);
    cout << char(175) << " Opci" << char(162) << "n: ";
    
    int opcion = validarEntero(1, 4);
    Empleado empleadoEncontrado;
    ArchivoEmpleados objEmpleados;
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el Legajo: ";
            colorTexto(7);
            int legajo = validarEntero(1, 999999);
            encontrado = objEmpleados.buscarEmpleado("LEGAJO", legajo, empleadoEncontrado);
            break;
        }
        case 2: {
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el DNI: ";
            colorTexto(7);
            int dni = validarEntero(10000000, 99999999);
            encontrado = objEmpleados.buscarEmpleado("DNI", dni, empleadoEncontrado);
            break;
        }
        case 3: {
            char mail[50];
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el Mail: ";
            colorTexto(7);
            validarCadena(mail, 50);
            encontrado = objEmpleados.buscarEmpleado("MAIL", mail, empleadoEncontrado);
            break;
        }
        case 4: {
            return;
        }
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    
    if(encontrado){
        cout << char(186); centrarTexto("EMPLEADO ENCONTRADO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        char legajoFormateado[15];
        formatearId(legajoFormateado, "EMP", empleadoEncontrado.getLegajo(), 6);
        
        rlutil::locate(35, 8);
        colorTexto(6);
        cout << "Legajo: ";
        colorTexto(7);
        cout << legajoFormateado;
        rlutil::locate(35, 9);
        colorTexto(6);
        cout << "Nombre: ";
        colorTexto(7);
        cout << empleadoEncontrado.getNombre() << " " << empleadoEncontrado.getApellido();
        rlutil::locate(35, 10);
        colorTexto(6);
        cout << "DNI: ";
        colorTexto(7);
        cout << empleadoEncontrado.getDni();
        rlutil::locate(35, 11);
        colorTexto(6);
        cout << "Mail: ";
        colorTexto(7);
        cout << empleadoEncontrado.getMail();
        rlutil::locate(35, 12);
        colorTexto(6);
        cout << "Localidad: ";
        colorTexto(7);
        cout << empleadoEncontrado.getLocalidad();
        rlutil::locate(35, 13);
        colorTexto(6);
        cout << "Estado: ";
        if(empleadoEncontrado.getUsuarioEliminado()){
            colorTexto(3);
            cout << "DADO DE BAJA";
        } else {
            colorTexto(2);
            cout << "ACTIVO";
        }
        colorTexto(7);
    }
    else{
        cout << char(186); centrarTexto("EMPLEADO NO ENCONTRADO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    }
    
    rlutil::locate(35, 16);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void buscarCuentaMenu(){
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("BUSCAR CUENTA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(40, 8);
    cout << "1. Buscar por ID";
    rlutil::locate(40, 9);
    cout << "2. Buscar por CVU";
    rlutil::locate(40, 10);
    cout << "3. Buscar por Alias";
    rlutil::locate(40, 11);
    cout << "4. Cancelar";
    
    rlutil::locate(35, 14);
    cout << char(175) << " Opci" << char(162) << "n: ";
    
    int opcion = validarEntero(1, 4);
    cuentaBancaria cuentaEncontrada;
    ArchivoCuentas objCuentas;
    bool encontrado = false;
    
    switch(opcion){
        case 1: {
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el ID: ";
            colorTexto(7);
            int id = validarEntero(1, 999999);
            encontrado = objCuentas.buscarCuenta("ID", id, cuentaEncontrada);
            break;
        }
        case 2: {
            char cvu[11];
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el CVU: ";
            colorTexto(7);
            validarCadenaNumeros(cvu, 10, 10);
            encontrado = objCuentas.buscarCuenta("CVU", cvu, cuentaEncontrada);
            break;
        }
        case 3: {
            char alias[31];
            rlutil::locate(35, 16);
            colorTexto(6);
            cout << "Ingrese el Alias: ";
            colorTexto(7);
            validarCadena(alias, 31);
            mayusculas(alias);
            encontrado = objCuentas.buscarCuenta("ALIAS", alias, cuentaEncontrada);
            break;
        }
        case 4: {
            return;
        }
    }
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    
    if(encontrado){
        cout << char(186); centrarTexto("CUENTA ENCONTRADA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        char idFormateado[15];
        formatearId(idFormateado, "CU", cuentaEncontrada.getIdCuenta(), 6);
        
        rlutil::locate(35, 8);
        colorTexto(6);
        cout << "ID: ";
        colorTexto(7);
        cout << idFormateado;
        rlutil::locate(35, 9);
        colorTexto(6);
        cout << "Nombre: ";
        colorTexto(7);
        cout << cuentaEncontrada.getNombreCuenta();
        rlutil::locate(35, 10);
        colorTexto(6);
        cout << "CVU: ";
        colorTexto(7);
        cout << cuentaEncontrada.getCvu();
        rlutil::locate(35, 11);
        colorTexto(6);
        cout << "Alias: ";
        colorTexto(7);
        cout << cuentaEncontrada.getAlias();
        rlutil::locate(35, 12);
        colorTexto(6);
        cout << "Saldo: ";
        colorTexto(2);
        cout << "$" << fixed << setprecision(2) << cuentaEncontrada.getSaldo();
        colorTexto(7);
        rlutil::locate(35, 13);
        colorTexto(6);
        cout << "Estado: ";
        if(cuentaEncontrada.getCuentaEliminada()){
            colorTexto(3);
            cout << "DADA DE BAJA";
        } else {
            colorTexto(2);
            cout << "ACTIVA";
        }
        colorTexto(7);
    }
    else{
        cout << char(186); centrarTexto("CUENTA NO ENCONTRADA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    }
    
    rlutil::locate(35, 16);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void gestionarEmpleados(){
    ArchivoEmpleados objEmpleados;
    int opcionActual = 0;
    int totalOpciones = 4;
    bool continuar = true;
    bool curs = true;
    int tecla;
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("GESTION DE EMPLEADOS", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i <= totalOpciones; i++){
                rlutil::locate(40, 9 + i);
                if(i == opcionActual){
                    colorTexto(2);
                    cout << char(175) << " ";
                } else {
                    colorTexto(7);
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Crear empleado"; break;
                    case 1: cout << "Modificar empleado"; break;
                    case 2: cout << "Eliminar empleado"; break;
                    case 3: cout << "Restaurar empleado"; break;
                    case 4: cout << "Volver"; break;
                }
            }
            colorTexto(7);
            curs = false;
        }
        
        rlutil::hidecursor();
        tecla = rlutil::getkey();
        
        switch(tecla){
            case 14:
                if(opcionActual > 0){
                    opcionActual--;
                    curs = true;
                }
                break;
            case 15:
                if(opcionActual < totalOpciones){
                    opcionActual++;
                    curs = true;
                }
                break;
            case 1:
                rlutil::showcursor();
                limpiarPantalla();
                
                switch(opcionActual){
                    case 0: {
                        objEmpleados.crearEmpleado();
                        rlutil::anykey();
                        break;
                    }
                    case 1: {
                        cout << "Ingrese el legajo del empleado: ";
                        int legajo = validarEntero(1, 999999);
                        objEmpleados.modificarDatosEmpleado(legajo);
                        rlutil::anykey();
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el legajo del empleado: ";
                        int legajo = validarEntero(1, 999999);
                        
                        Administrador* admin = Administrador::getInstancia();
                        if(legajo == admin->getLegajo()){
                            cout << "ERROR: No se puede eliminar al Administrador." << endl;
                            rlutil::anykey();
                            break;
                        }
                        
                        objEmpleados.eliminarEmpleado(legajo);
                        rlutil::anykey();
                        break;
                    }
                    case 3: {
                        cout << "Ingrese el legajo del empleado: ";
                        int legajo = validarEntero(1, 999999);
                        objEmpleados.restaurarEmpleado(legajo);
                        rlutil::anykey();
                        break;
                    }
                    case 4: {
                        continuar = false;
                        break;
                    }
                }
                curs = true;
                break;
        }
    }
    rlutil::showcursor();
}

void gestionarClientesAdmin(){
    ArchivoClientes objClientes;
    int opcionActual = 0;
    int totalOpciones = 4;
    bool continuar = true;
    bool curs = true;
    int tecla;
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("GESTION DE CLIENTES", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i <= totalOpciones; i++){
                rlutil::locate(40, 9 + i);
                if(i == opcionActual){
                    colorTexto(2);
                    cout << char(175) << " ";
                } else {
                    colorTexto(7);
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Crear cliente"; break;
                    case 1: cout << "Modificar cliente"; break;
                    case 2: cout << "Eliminar cliente"; break;
                    case 3: cout << "Restaurar cliente"; break;
                    case 4: cout << "Volver"; break;
                }
            }
            colorTexto(7);
            curs = false;
        }
        
        rlutil::hidecursor();
        tecla = rlutil::getkey();
        
        switch(tecla){
            case 14:
                if(opcionActual > 0){
                    opcionActual--;
                    curs = true;
                }
                break;
            case 15: 
                if(opcionActual < totalOpciones){
                    opcionActual++;
                    curs = true;
                }
                break;
            case 1: 
                rlutil::showcursor();
                limpiarPantalla();
                
                switch(opcionActual){
                    case 0: {
                        objClientes.crearCliente();
                        rlutil::anykey();
                        break;
                    }
                    case 1: {
                        cout << "Ingrese el ID del cliente: ";
                        int id = validarEntero(1, 999999);
                        objClientes.modificarDatosCliente(id);
                        rlutil::anykey();
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el ID del cliente: ";
                        int id = validarEntero(1, 999999);
                        
                        if(id == 1){
                            cout << "ERROR: No se puede eliminar el Cliente Banco." << endl;
                            rlutil::anykey();
                            break;
                        }
                        
                        objClientes.eliminarCliente(id);
                        rlutil::anykey();
                        break;
                    }
                    case 3: {
                        cout << "Ingrese el ID del cliente: ";
                        int id = validarEntero(1, 999999);
                        objClientes.restaurarCliente(id);
                        rlutil::anykey();
                        break;
                    }
                    case 4: {
                        continuar = false;
                        break;
                    }
                }
                curs = true;
                break;
        }
    }
    rlutil::showcursor();
}

void gestionarCuentasAdmin(){
    ArchivoCuentas objCuentas;
    int opcionActual = 0;
    int totalOpciones = 7;
    bool continuar = true;
    bool curs = true;
    int tecla;
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("GESTION DE CUENTAS", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i <= totalOpciones; i++){
                rlutil::locate(40, 9 + i);
                if(i == opcionActual){
                    colorTexto(2);
                    cout << char(175) << " ";
                } else {
                    colorTexto(7);
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Ver cuenta del Banco"; break;
                    case 1: cout << "Crear cuenta"; break;
                    case 2: cout << "Modificar cuenta"; break;
                    case 3: cout << "Eliminar cuenta"; break;
                    case 4: cout << "Restaurar cuenta"; break;
                    case 5: cout << "Ingresar dinero (Banco)"; break;
                    case 6: cout << "Retirar dinero (Banco)"; break;
                    case 7: cout << "Volver"; break;
                }
            }
            colorTexto(7);
            curs = false;
        }
        
        rlutil::hidecursor();
        tecla = rlutil::getkey();
        
        switch(tecla){
            case 14:
                if(opcionActual > 0){
                    opcionActual--;
                    curs = true;
                }
                break;
            case 15:
                if(opcionActual < totalOpciones){
                    opcionActual++;
                    curs = true;
                }
                break;
            case 1:
                rlutil::showcursor();
                limpiarPantalla();
                
                switch(opcionActual){
                    case 0: {
                        cuentaBancaria cuentaBanco;
                        if(objCuentas.buscarCuenta("ID", 1, cuentaBanco)){
                            limpiarPantalla();
                            colorTexto(7);
                            
                            rlutil::locate(30, 3);
                            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                            rlutil::locate(30, 4);
                            cout << char(186); centrarTexto("CUENTA DEL BANCO", ' ', 60); cout << char(186);
                            rlutil::locate(30, 5);
                            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                            
                            char idFormateado[15];
                            formatearId(idFormateado, "CU", 1, 6);
                            
                            rlutil::locate(35, 8);
                            colorTexto(6);
                            cout << "ID: ";
                            colorTexto(7);
                            cout << idFormateado;
                            rlutil::locate(35, 9);
                            colorTexto(6);
                            cout << "Nombre: ";
                            colorTexto(7);
                            cout << cuentaBanco.getNombreCuenta();
                            rlutil::locate(35, 10);
                            colorTexto(6);
                            cout << "CVU: ";
                            colorTexto(7);
                            cout << cuentaBanco.getCvu();
                            rlutil::locate(35, 11);
                            colorTexto(6);
                            cout << "Alias: ";
                            colorTexto(7);
                            cout << cuentaBanco.getAlias();
                            rlutil::locate(35, 12);
                            colorTexto(6);
                            cout << "Saldo: ";
                            colorTexto(2);
                            cout << "$" << fixed << setprecision(2) << cuentaBanco.getSaldo();
                            colorTexto(7);
                        }
                        else{
                            cout << "ERROR: No se pudo cargar la cuenta del banco." << endl;
                        }
                        rlutil::anykey();
                        break;
                    }
                    case 1: {
                        cout << "Ingrese el ID del cliente: ";
                        int idCliente = validarEntero(1, 999999);
                        objCuentas.crearCuenta(idCliente);
                        rlutil::anykey();
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el ID de la cuenta: ";
                        int id = validarEntero(1, 999999);
                        objCuentas.modificarDatosCuenta(id);
                        rlutil::anykey();
                        break;
                    }
                    case 3: {
                        cout << "Ingrese el ID de la cuenta: ";
                        int id = validarEntero(1, 999999);
                        
                        if(id == 1){
                            cout << "ERROR: No se puede eliminar la Cuenta Banco." << endl;
                            rlutil::anykey();
                            break;
                        }
                        
                        objCuentas.eliminarCuenta(id);
                        rlutil::anykey();
                        break;
                    }
                    case 4: {
                        cout << "Ingrese el ID de la cuenta: ";
                        int id = validarEntero(1, 999999);
                        objCuentas.restaurarCuenta(id);
                        rlutil::anykey();
                        break;
                    }
                    case 5: {
                        cout << "Ingrese el monto a ingresar al Banco: $";
                        double monto = validarDouble(0.01, 999999999.99);
                        if(objCuentas.depositar(1, monto)){
                            cout << "Dinero ingresado exitosamente." << endl;
                        }
                        rlutil::anykey();
                        break;
                    }
                    case 6: {
                        cout << "Ingrese el monto a retirar del Banco: $";
                        double monto = validarDouble(0.01, 999999999.99);
                        if(objCuentas.extraer(1, monto)){
                            cout << "Dinero retirado exitosamente." << endl;
                        }
                        rlutil::anykey();
                        break;
                    }
                    case 7: {
                        continuar = false;
                        break;
                    }
                }
                curs = true;
                break;
        }
    }
    rlutil::showcursor();
}

void menuTransaccionesAdmin(){
    ArchivoTransacciones objTransacciones;
    int opcionActual = 0;
    int totalOpciones = 3;
    bool continuar = true;
    bool curs = true;
    int tecla;
    
    while(continuar){
        if(curs){
            limpiarPantalla();
            colorTexto(7);
            
            rlutil::locate(30, 3);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 4);
            cout << char(186); centrarTexto("GESTIONAR TRANSACCIONES", ' ', 60); cout << char(186);
            rlutil::locate(30, 5);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            for(int i = 0; i <= totalOpciones; i++){
                rlutil::locate(40, 9 + i);
                if(i == opcionActual){
                    colorTexto(2);
                    cout << char(175) << " ";
                } else {
                    colorTexto(7);
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Listar TODAS las transacciones"; break;
                    case 1: cout << "Listar transacciones de una cuenta"; break;
                    case 2: cout << "Buscar transacci" << char(162) << "n espec" << char(161) << "fica"; break;
                    case 3: cout << "Volver"; break;
                }
            }
            colorTexto(7);
            curs = false;
        }
        
        rlutil::hidecursor();
        tecla = rlutil::getkey();
        
        switch(tecla){
            case 14: 
                if(opcionActual > 0){
                    opcionActual--;
                    curs = true;
                }
                break;
            case 15: 
                if(opcionActual < totalOpciones){
                    opcionActual++;
                    curs = true;
                }
                break;
            case 1:
                rlutil::showcursor();
                limpiarPantalla();
                
                switch(opcionActual){
                    case 0: {
                        colorTexto(7);
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("TODAS LAS TRANSACCIONES", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        cout << endl;
                        
                        objTransacciones.listarTransacciones();
                        rlutil::anykey();
                        break;
                    }
                    case 1: {
                        cout << "Ingrese el ID de la cuenta: ";
                        int idCuenta = validarEntero(1, 999999);
                        
                        limpiarPantalla();
                        colorTexto(7);
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("TRANSACCIONES DE LA CUENTA", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        cout << endl;
                        
                        objTransacciones.listarTransaccionesCuenta(idCuenta);
                        rlutil::anykey();
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el ID de la transacci" << char(162) << "n: ";
                        int idTransaccion = validarEntero(1, 999999);
                        
                        Transaccion transEncontrada;
                        if(objTransacciones.buscarTransaccion(idTransaccion, transEncontrada)){
                            limpiarPantalla();
                            colorTexto(7);
                            
                            rlutil::locate(30, 3);
                            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                            rlutil::locate(30, 4);
                            cout << char(186); centrarTexto("TRANSACCION ENCONTRADA", ' ', 60); cout << char(186);
                            rlutil::locate(30, 5);
                            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                            
                            char idFormateado[15];
                            formatearId(idFormateado, "TR", transEncontrada.getIdTransaccion(), 6);
                            
                            char idOrigenFormateado[15];
                            formatearId(idOrigenFormateado, "CU", transEncontrada.getIdCuentaOrigen(), 6);
                            char idDestinoFormateado[15];
                            formatearId(idDestinoFormateado, "CU", transEncontrada.getIdCuentaDestino(), 6);
                            
                            rlutil::locate(35, 8);
                            colorTexto(6);
                            cout << "ID: ";
                            colorTexto(7);
                            cout << idFormateado;
                            rlutil::locate(35, 9);
                            colorTexto(6);
                            cout << "Cuenta Origen: ";
                            colorTexto(7);
                            cout << idOrigenFormateado;
                            rlutil::locate(35, 10);
                            colorTexto(6);
                            cout << "Cuenta Destino: ";
                            colorTexto(7);
                            cout << idDestinoFormateado;
                            rlutil::locate(35, 11);
                            colorTexto(6);
                            cout << "Monto: ";
                            colorTexto(2);
                            cout << "$" << fixed << setprecision(2) << transEncontrada.getMonto();
                            colorTexto(7);
                            rlutil::locate(35, 12);
                            colorTexto(6);
                            cout << "Fecha: ";
                            colorTexto(7);
                            cout << transEncontrada.getFechaTransaccion().mostrarFecha();
                            rlutil::locate(35, 13);
                            colorTexto(6);
                            cout << "Hora: ";
                            colorTexto(7);
                            cout << transEncontrada.getHoraTransaccion().mostrarTiempo();
                        }
                        else{
                            limpiarPantalla();
                            colorTexto(7);
                            rlutil::locate(30, 3);
                            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                            rlutil::locate(30, 4);
                            cout << char(186); centrarTexto("TRANSACCION NO ENCONTRADA", ' ', 60); cout << char(186);
                            rlutil::locate(30, 5);
                            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        }
                        rlutil::anykey();
                        break;
                    }
                    case 3: {
                        continuar = false;
                        break;
                    }
                }
                curs = true;
                break;
        }
    }
    rlutil::showcursor();
}