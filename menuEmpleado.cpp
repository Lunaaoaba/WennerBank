#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "menuEmpleado.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCuentas.h"
#include "archivoTransacciones.h"
#include "funciones.h"
#include "config.h"
#include "art.h"

using namespace std;
void menuEmpleado(int legajoEmpleado){
    Empleado empleadoActual;
    ArchivoEmpleados objEmpleados;
    
    if(!objEmpleados.buscarEmpleado("LEGAJO", legajoEmpleado, empleadoActual)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la informaci" << char(162) << "n del empleado.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    
    char legajoFormateado[15];
    formatearId(legajoFormateado, "EMP", legajoEmpleado, 6);
    
    int opcionActual = 0;
    int totalOpciones = 6;
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
            cout << char(186); centrarTexto("MENU EMPLEADO", ' ', 50); cout << char(186);
            rlutil::locate(35, 5);
            cout << char(200); centrarTexto("", char(205), 50); cout << char(188);
            
            rlutil::locate(40, 7);
            colorTexto(6);
            cout << "Empleado: " << empleadoActual.getNombre() << " " << empleadoActual.getApellido();
            colorTexto(7);
            rlutil::locate(40, 8);
            cout << "Legajo: " << legajoFormateado;
            
            for(int i = 0; i < totalOpciones; i++){
                rlutil::locate(45, 11 + i);
                if(i == opcionActual){
                    colorTexto(6);
                    cout << char(175) << " ";
                } else {
                    cout << "  ";
                }
                
                switch(i){
                    case 0: cout << "Listados"; break;
                    case 1: cout << "Gesti" << char(162) << "n de Clientes"; break;
                    case 2: cout << "Gesti" << char(162) << "n de Cuentas"; break;
                    case 3: cout << "Operaciones Bancarias"; break;
                    case 4: cout << "Transacciones"; break;
                    case 5: cout << "Cerrar sesi" << char(162) << "n"; break;
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
                    menuListadosEmpleado(legajoEmpleado);
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    gestionarClientes();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    gestionarCuentas();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    operacionesBancariasEmpleado();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    menuTransaccionesEmpleado();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuListadosEmpleado(int legajoEmpleado){
    ArchivoClientes objClientes;
    Empleado empleadoActual;
    ArchivoEmpleados objEmpleados;
    cuentaBancaria cuentaBanco;
    ArchivoCuentas objCuentas;

    int opcionActual = 0;
    int totalOpciones = 6;
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
            cout << char(186); centrarTexto("LISTADOS", ' ', 50); cout << char(186);
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
                    case 0: cout << "Listar mis detalles"; break;
                    case 1: cout << "Listar detalles cuenta del Banco"; break;
                    case 2: cout << "Listar cuentas bancarias"; break;
                    case 3: cout << "Listar empleados"; break;
                    case 4: cout << "Listar clientes"; break;
                    case 5: cout << "Volver"; break;
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
                    if(objEmpleados.buscarEmpleado("LEGAJO", legajoEmpleado, empleadoActual)){
                        limpiarPantalla();
                        colorTexto(7);
                        
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("MIS DATOS", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        char legajoFormateado[15];
                        formatearId(legajoFormateado, "EM", empleadoActual.getLegajo(), 6);
                        
                        rlutil::locate(35, 8);
                        cout << "Legajo: " << legajoFormateado;
                        rlutil::locate(35, 9);
                        cout << "Nombre: " << empleadoActual.getNombre();
                        rlutil::locate(35, 10);
                        cout << "Apellido: " << empleadoActual.getApellido();
                        rlutil::locate(35, 11);
                        cout << "DNI: " << empleadoActual.getDni();
                        rlutil::locate(35, 12);
                        cout << "Email: " << empleadoActual.getMail();
                        rlutil::locate(35, 13);
                        cout << "Localidad: " << empleadoActual.getLocalidad();
                    }
                    else{
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: No se pudo cargar la informaci" << char(162) << "n.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 17);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    if(objCuentas.buscarCuenta("ID", 1, cuentaBanco)){
                        limpiarPantalla();
                        colorTexto(7);
                        
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("CUENTA DEL BANCO", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        rlutil::locate(35, 8);
                        cout << "ID: CU-000001";
                        rlutil::locate(35, 9);
                        cout << "Nombre: " << cuentaBanco.getNombreCuenta();
                        rlutil::locate(35, 10);
                        cout << "CVU: " << cuentaBanco.getCvu();
                        rlutil::locate(35, 11);
                        cout << "Alias: " << cuentaBanco.getAlias();
                        rlutil::locate(35, 12);
                        colorTexto(2);
                        cout << "Saldo: $" << fixed << setprecision(2) << cuentaBanco.getSaldo();
                        colorTexto(7);
                    }
                    else{
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: No se pudo cargar la cuenta del banco.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 15);
                    cout << "Presione cualquier tecla para continuar...";
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
                    objEmpleados.listarEmpleados();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    objClientes.listarClientes();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void gestionarClientes(){
    ArchivoClientes objClientes;
    
    int opcionActual = 0;
    int totalOpciones = 6;
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
            cout << char(186); centrarTexto("GESTION DE CLIENTES", ' ', 50); cout << char(186);
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
                    case 0: cout << "Crear cliente"; break;
                    case 1: cout << "Modificar cliente"; break;
                    case 2: cout << "Eliminar cliente"; break;
                    case 3: cout << "Restaurar cliente"; break;
                    case 4: cout << "Buscar cliente"; break;
                    case 5: cout << "Volver"; break;
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
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("CREAR CLIENTE", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    Cliente nuevoCliente = objClientes.crearCliente();
                    if(objClientes.guardarClientes(nuevoCliente)){
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(2);
                        cout << char(251) << " Cliente creado exitosamente!";
                        colorTexto(7);
                        rlutil::locate(40, 17);
                        cout << "Presione cualquier tecla para continuar...";
                    }
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("MODIFICAR CLIENTE", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID del cliente: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    objClientes.modificarDatosCliente(id);
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("ELIMINAR CLIENTE", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID del cliente: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    
                    if(id == 1){
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: No se puede eliminar el Cliente Banco.";
                        colorTexto(7);
                        rlutil::locate(40, 17);
                        cout << "Presione cualquier tecla para continuar...";
                        rlutil::anykey();
                    } else {
                        objClientes.eliminarCliente(id);
                        rlutil::anykey();
                    }
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("RESTAURAR CLIENTE", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID del cliente: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    objClientes.restaurarCliente(id);
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("BUSCAR CLIENTE", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID del cliente: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    
                    Cliente clienteEncontrado;
                    if(objClientes.buscarCliente("ID", id, clienteEncontrado)){
                        limpiarPantalla();
                        colorTexto(7);
                        
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("DATOS DEL CLIENTE", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        char idFormateado[15];
                        formatearId(idFormateado, "CL", clienteEncontrado.getIdCliente(), 6);
                        
                        rlutil::locate(35, 8);
                        cout << "ID: " << idFormateado;
                        rlutil::locate(35, 9);
                        cout << "Nombre: " << clienteEncontrado.getNombre();
                        rlutil::locate(35, 10);
                        cout << "Apellido: " << clienteEncontrado.getApellido();
                        rlutil::locate(35, 11);
                        cout << "DNI: " << clienteEncontrado.getDni();
                        rlutil::locate(35, 12);
                        cout << "Email: " << clienteEncontrado.getMail();
                        rlutil::locate(35, 13);
                        cout << "Localidad: " << clienteEncontrado.getLocalidad();
                        
                        if(clienteEncontrado.getUsuarioEliminado()){
                            rlutil::locate(35, 16);
                            colorTexto(3);
                            cout << "[ELIMINADO]";
                            colorTexto(7);
                        }
                    } else {
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: Cliente no encontrado.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 19);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void gestionarCuentas(){
    ArchivoCuentas objCuentas;
    ArchivoClientes objClientes;
    
    int opcionActual = 0;
    int totalOpciones = 6;
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
            cout << char(186); centrarTexto("GESTION DE CUENTAS", ' ', 50); cout << char(186);
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
                    case 0: cout << "Crear cuenta"; break;
                    case 1: cout << "Modificar cuenta"; break;
                    case 2: cout << "Eliminar cuenta"; break;
                    case 3: cout << "Restaurar cuenta"; break;
                    case 4: cout << "Buscar cuenta"; break;
                    case 5: cout << "Volver"; break;
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
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("CREAR CUENTA", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID del cliente: ";
                    colorTexto(7);
                    int idCliente = validarEntero(1, 999999);
                    
                    Cliente clienteTemp;
                    if(objClientes.buscarCliente("ID", idCliente, clienteTemp)){
                        objCuentas.crearCuenta(idCliente);
                    } else {
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: Cliente no encontrado.";
                        colorTexto(7);
                        rlutil::locate(40, 17);
                        cout << "Presione cualquier tecla para continuar...";
                    }
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("MODIFICAR CUENTA", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID de la cuenta: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    objCuentas.modificarDatosCuenta(id);
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("ELIMINAR CUENTA", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID de la cuenta: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    
                    if(id == 1){
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: No se puede eliminar la Cuenta Banco.";
                        colorTexto(7);
                        rlutil::locate(40, 17);
                        cout << "Presione cualquier tecla para continuar...";
                        rlutil::anykey();
                    } else {
                        objCuentas.eliminarCuenta(id);
                        rlutil::anykey();
                    }
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 3: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("RESTAURAR CUENTA", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID de la cuenta: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    objCuentas.restaurarCuenta(id);
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 4: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("BUSCAR CUENTA", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID de la cuenta: ";
                    colorTexto(7);
                    int id = validarEntero(1, 999999);
                    
                    cuentaBancaria cuentaEncontrada;
                    if(objCuentas.buscarCuenta("ID", id, cuentaEncontrada)){
                        limpiarPantalla();
                        colorTexto(7);
                        
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("DATOS DE LA CUENTA", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        char idFormateado[15];
                        formatearId(idFormateado, "CU", cuentaEncontrada.getIdCuenta(), 6);
                        
                        rlutil::locate(35, 8);
                        cout << "ID: " << idFormateado;
                        rlutil::locate(35, 9);
                        cout << "Nombre: " << cuentaEncontrada.getNombreCuenta();
                        rlutil::locate(35, 10);
                        cout << "CVU: " << cuentaEncontrada.getCvu();
                        rlutil::locate(35, 11);
                        cout << "Alias: " << cuentaEncontrada.getAlias();
                        rlutil::locate(35, 12);
                        colorTexto(2);
                        cout << "Saldo: $" << fixed << setprecision(2) << cuentaEncontrada.getSaldo();
                        colorTexto(7);
                        rlutil::locate(35, 13);
                        cout << "ID Cliente: CL-" << setfill('0') << setw(6) << cuentaEncontrada.getIdCliente();
                        
                        if(cuentaEncontrada.getCuentaEliminada()){
                            rlutil::locate(35, 15);
                            colorTexto(3);
                            cout << "[ELIMINADA]";
                            colorTexto(7);
                        }
                    } else {
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: Cuenta no encontrada.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 18);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 5: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void operacionesBancariasEmpleado(){
    ArchivoCuentas objCuentas;
    
    int opcionActual = 0;
    int totalOpciones = 3;
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
            cout << char(186); centrarTexto("OPERACIONES BANCARIAS", ' ', 50); cout << char(186);
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
                    case 0: cout << "Depositar dinero"; break;
                    case 1: cout << "Retirar dinero"; break;
                    case 2: cout << "Volver"; break;
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
                    limpiarPantalla();
                    colorTexto(7);
                    
                    int idCuenta = 1;
                    
                    cuentaBancaria cuenta;
                    if(objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("DEPOSITAR DINERO - CUENTA BANCO", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        char idFormateado[15];
                        formatearId(idFormateado, "CU", cuenta.getIdCuenta(), 6);
                        
                        rlutil::locate(35, 7);
                        cout << "Cuenta: " << cuenta.getNombreCuenta();
                        rlutil::locate(35, 8);
                        cout << "ID: " << idFormateado;
                        rlutil::locate(35, 9);
                        colorTexto(2);
                        cout << "Saldo actual: $" << fixed << setprecision(2) << cuenta.getSaldo();
                        colorTexto(7);
                        
                        rlutil::locate(35, 12);
                        colorTexto(6);
                        cout << "Ingrese el monto a depositar: $";
                        colorTexto(7);
                        double monto = validarDouble(0.01, 999999999.99);
                        
                        objCuentas.depositar(idCuenta, monto);
                    } else {
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: Cuenta del banco no encontrada.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 16);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    int idCuenta = 1;
                    
                    cuentaBancaria cuenta;
                    if(objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
                        rlutil::locate(30, 3);
                        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                        rlutil::locate(30, 4);
                        cout << char(186); centrarTexto("RETIRAR DINERO - CUENTA BANCO", ' ', 60); cout << char(186);
                        rlutil::locate(30, 5);
                        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                        
                        char idFormateado[15];
                        formatearId(idFormateado, "CU", cuenta.getIdCuenta(), 6);
                        
                        rlutil::locate(35, 7);
                        cout << "Cuenta: " << cuenta.getNombreCuenta();
                        rlutil::locate(35, 8);
                        cout << "ID: " << idFormateado;
                        rlutil::locate(35, 9);
                        colorTexto(2);
                        cout << "Saldo disponible: $" << fixed << setprecision(2) << cuenta.getSaldo();
                        colorTexto(7);
                        
                        rlutil::locate(35, 12);
                        colorTexto(6);
                        cout << "Ingrese el monto a retirar: $";
                        colorTexto(7);
                        double monto = validarDouble(0.01, 999999999.99);
                        
                        objCuentas.extraer(idCuenta, monto);
                    } else {
                        limpiarPantalla();
                        rlutil::locate(40, 15);
                        colorTexto(3);
                        cout << "ERROR: Cuenta del banco no encontrada.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 16);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}

void menuTransaccionesEmpleado(){
    ArchivoTransacciones objTransacciones;
    
    int opcionActual = 0;
    int totalOpciones = 3;
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
            cout << char(186); centrarTexto("TRANSACCIONES", ' ', 50); cout << char(186);
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
                    case 0: cout << "Listar todas las transacciones"; break;
                    case 1: cout << "Buscar transacci" << char(162) << "n espec" << char(161) << "fica"; break;
                    case 2: cout << "Volver"; break;
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
                    objTransacciones.listarTransacciones();
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 1: {
                    limpiarPantalla();
                    colorTexto(7);
                    
                    rlutil::locate(30, 3);
                    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                    rlutil::locate(30, 4);
                    cout << char(186); centrarTexto("BUSCAR TRANSACCION", ' ', 60); cout << char(186);
                    rlutil::locate(30, 5);
                    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                    
                    rlutil::locate(35, 8);
                    colorTexto(6);
                    cout << "Ingrese el ID de la transacci" << char(162) << "n: ";
                    colorTexto(7);
                    int idTransaccion = validarEntero(1, 999999);
                    
                    Transaccion encontrada;
                    if(!objTransacciones.buscarTransaccion(idTransaccion, encontrada)){
                        rlutil::locate(35, 10);
                        colorTexto(3);
                        cout << "Transacci" << char(162) << "n no encontrada.";
                        colorTexto(7);
                    }
                    rlutil::locate(35, 18);
                    cout << "Presione cualquier tecla para continuar...";
                    rlutil::anykey();
                    curs = true;
                    rlutil::hidecursor();
                    break;
                }
                case 2: {
                    continuar = false;
                    break;
                }
            }
        }
    }
    
    rlutil::showcursor();
}