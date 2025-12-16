#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "menuCuenta.h"
#include "ArchivoCuentas.h"
#include "ArchivoClientes.h"
#include "funciones.h"
#include "config.h"
#include "art.h"

using namespace std;

void menuCuenta(int idCliente, int idCuenta){
    cuentaBancaria cuenta;
    ArchivoCuentas objCuentas;
    bool continuar = true;
    
    while(continuar){
        if(!objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
            rlutil::locate(40, 15);
            colorTexto(3);
            cout << "ERROR: No se encontr" << char(162) << " la cuenta con ID " << idCuenta << ".";
            colorTexto(7);
            rlutil::locate(40, 17);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            return;
        }

        limpiarPantalla();
        colorTexto(7);
        
        // Header
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("MENU CUENTA BANCARIA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        // Información de la cuenta
        char idFormateado[15];
        formatearId(idFormateado, "CU", cuenta.getIdCuenta(), 6);
        
        rlutil::locate(35, 7);
        colorTexto(6);
        cout << "Cuenta: " << cuenta.getNombreCuenta();
        colorTexto(7);
        rlutil::locate(35, 8);
        cout << "ID: " << idFormateado;
        rlutil::locate(35, 9);
        cout << "CVU: " << cuenta.getCvu();
        rlutil::locate(35, 10);
        cout << "Alias: " << cuenta.getAlias();
        rlutil::locate(35, 11);
        colorTexto(2);
        cout << "Saldo: $" << fixed << setprecision(2) << cuenta.getSaldo();
        colorTexto(7);
        
        // Opciones
        rlutil::locate(40, 14);
        cout << "1. Ingresar dinero";
        rlutil::locate(40, 15);
        cout << "2. Retirar dinero";
        rlutil::locate(40, 16);
        cout << "3. Transferir dinero";
        rlutil::locate(40, 17);
        cout << "4. Modificar datos de la cuenta";
        rlutil::locate(40, 18);
        cout << "5. Cerrar cuenta";
        rlutil::locate(40, 19);
        cout << "6. Volver al men" << char(163) << " principal";
        
        rlutil::locate(35, 22);
        cout << char(175) << " Opci" << char(162) << "n: ";
        int opcion = validarEntero(1, 6);
        
        switch(opcion){
            case 1: {
                ingresarDinero(idCuenta);
                break;
            }
            case 2: {
                retirarDinero(idCuenta);
                break;
            }
            case 3: {
                transferirDinero(idCuenta);
                break;
            }
            case 4: {
                modificarDatosCuentaMenu(idCuenta, idCliente);
                break;
            }
            case 5: {
                cerrarCuenta(idCuenta, idCliente);
                break;
            }
            case 6: {
                continuar = false;
                break;
            }
        }
    }
}


void ingresarDinero(int idCuenta){
    ArchivoCuentas objCuentas;
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("INGRESAR DINERO", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

    rlutil::locate(35, 8);
    colorTexto(6);
    cout << "Ingrese el monto a depositar: $";
    colorTexto(7);
    double monto = validarDouble(0.01, 999999999.99);

    objCuentas.depositar(idCuenta, monto);
    rlutil::locate(35, 12);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void retirarDinero(int idCuenta){
    cuentaBancaria cuenta;
    ArchivoCuentas objCuentas;
    if(!objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("RETIRAR DINERO", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 8);
    colorTexto(2);
    cout << "Saldo disponible: $" << fixed << setprecision(2) << cuenta.getSaldo();
    colorTexto(7);

    rlutil::locate(35, 10);
    colorTexto(6);
    cout << "Ingrese el monto a retirar: $";
    colorTexto(7);
    double monto = validarDouble(0.01, 999999999.99);

    objCuentas.extraer(idCuenta, monto);
    rlutil::locate(35, 14);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

void transferirDinero(int idCuenta){
    bool continuar = true;

    while(continuar){
        cuentaBancaria cuentaOrigen;
        ArchivoCuentas objCuentas;
        if(!objCuentas.buscarCuenta("ID", idCuenta, cuentaOrigen)){
            rlutil::locate(40, 15);
            colorTexto(3);
            cout << "ERROR: No se pudo cargar la cuenta.";
            colorTexto(7);
            rlutil::locate(40, 17);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            return;
        }
        
        limpiarPantalla();
        colorTexto(7);
        
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("TRANSFERIR DINERO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        rlutil::locate(35, 8);
        colorTexto(2);
        cout << "Saldo disponible: $" << fixed << setprecision(2) << cuentaOrigen.getSaldo();
        colorTexto(7);
        
        rlutil::locate(40, 11);
        cout << "1. Transferir por CVU";
        rlutil::locate(40, 12);
        cout << "2. Transferir por Alias";
        rlutil::locate(40, 13);
        cout << "3. Cancelar";
        
        rlutil::locate(35, 16);
        cout << char(175) << " Opci" << char(162) << "n: ";
        int opcion = validarEntero(1, 3);

        cuentaBancaria cuentaDestino;
        bool cuentaEncontrada = false;
        
        limpiarPantalla();
        colorTexto(7);
        
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("TRANSFERIR DINERO", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        switch(opcion){
            case 1: {
                char cvuDestino[11];
                rlutil::locate(35, 8);
                colorTexto(6);
                cout << "Ingrese el CVU de la cuenta destino: ";
                colorTexto(7);
                validarCadenaNumeros(cvuDestino, 10, 10);
                cuentaEncontrada = objCuentas.buscarCuenta("CVU", cvuDestino, cuentaDestino);
                break;
            }
            case 2 : {
                char aliasDestino[31];
                rlutil::locate(35, 8);
                colorTexto(6);
                cout << "Ingrese el Alias de la cuenta destino: ";
                colorTexto(7);
                validarCadena(aliasDestino, 30);
                mayusculas(aliasDestino);
                cuentaEncontrada = objCuentas.buscarCuenta("ALIAS", aliasDestino, cuentaDestino);
                break;
            }
            case 3: {
                continuar = false;
                break;
            }
        }
        if(continuar == false) continue;

        if(!cuentaEncontrada){
            rlutil::locate(35, 11);
            colorTexto(3);
            cout << "ERROR: No se encontr" << char(162) << " la cuenta destino.";
            colorTexto(7);
            rlutil::locate(35, 13);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continue;
        }
        if(cuentaDestino.getIdCuenta() == idCuenta){
            rlutil::locate(35, 11);
            colorTexto(3);
            cout << "ERROR: No se puede transferir a la misma cuenta.";
            colorTexto(7);
            rlutil::locate(35, 13);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continue;
        }

        limpiarPantalla();
        colorTexto(7);
        
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("CONFIRMAR TRANSFERENCIA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        rlutil::locate(35, 7);
        colorTexto(6);
        cout << "Cuenta destino:";
        colorTexto(7);
        
        char idDestinoFormateado[15];
        formatearId(idDestinoFormateado, "CU", cuentaDestino.getIdCuenta(), 6);
        
        rlutil::locate(40, 9);
        cout << "ID: " << idDestinoFormateado;
        rlutil::locate(40, 10);
        cout << "Nombre: " << cuentaDestino.getNombreCuenta();
        rlutil::locate(40, 11);
        cout << "CVU: " << cuentaDestino.getCvu();
        rlutil::locate(40, 12);
        cout << "Alias: " << cuentaDestino.getAlias();
        
        rlutil::locate(35, 15);
        colorTexto(6);
        cout << "Ingrese el monto a transferir: $";
        colorTexto(7);
        double monto = validarDouble(0.01, 999999999.99);

        rlutil::locate(35, 17);
        colorTexto(6);
        cout << char(175) << " Confirma la transferencia de $" << fixed << setprecision(2) << monto << "? (S/N): ";
        colorTexto(7);
        char confirmacion = validarSiNo();

        if(confirmacion == 'S' || confirmacion == 's'){
            if(objCuentas.transferir(idCuenta, cuentaDestino.getIdCuenta(), monto)){
                limpiarPantalla();
                rlutil::locate(40, 15);
                colorTexto(2);
                cout << char(251) << " Transferencia realizada con " << char(130) << "xito!";
                colorTexto(7);
                rlutil::locate(40, 17);
                colorTexto(6);
                cout << "Desea realizar otra transferencia? (S/N): ";
                colorTexto(7);
                char otra = validarSiNo();
                if(otra == 'N' || otra == 'n'){
                    continuar = false;
                }
            }
            else{
                limpiarPantalla();
                rlutil::locate(40, 15);
                colorTexto(3);
                cout << "ERROR: No se pudo realizar la transferencia.";
                colorTexto(7);
                rlutil::locate(40, 17);
                cout << "Presione cualquier tecla para continuar...";
                rlutil::anykey();
                continuar = false;
            }
        }
        else{
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(6);
            cout << "Transferencia cancelada.";
            colorTexto(7);
            rlutil::locate(40, 17);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            continuar = false;
        }
    }
}

void modificarDatosCuentaMenu(int idCuenta, int idCliente){
    cuentaBancaria cuenta;
    ArchivoCuentas objCuentas;
    if(!objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    Cliente cliente;
    ArchivoClientes objClientes;
    if(!objClientes.buscarCliente("ID", idCliente, cliente)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo verificar la identidad.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    
    bool continuar = true;
    while(continuar){
        limpiarPantalla();
        colorTexto(7);
        
        rlutil::locate(30, 3);
        cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
        rlutil::locate(30, 4);
        cout << char(186); centrarTexto("MODIFICAR DATOS DE CUENTA", ' ', 60); cout << char(186);
        rlutil::locate(30, 5);
        cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
        
        rlutil::locate(40, 8);
        cout << "1. Cambiar nombre de la cuenta";
        rlutil::locate(40, 9);
        cout << "2. Regenerar Alias";
        rlutil::locate(40, 10);
        cout << "3. Volver";
        
        rlutil::locate(35, 13);
        cout << char(175) << " Opci" << char(162) << "n: ";
        int opcion = validarEntero(1, 3);

        switch(opcion){
            case 1: {
                limpiarPantalla();
                colorTexto(7);
                
                rlutil::locate(30, 3);
                cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                rlutil::locate(30, 4);
                cout << char(186); centrarTexto("CAMBIAR NOMBRE", ' ', 60); cout << char(186);
                rlutil::locate(30, 5);
                cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                
                char nuevoNombre[50];
                rlutil::locate(35, 8);
                colorTexto(6);
                cout << "Ingrese el nuevo nombre: ";
                colorTexto(7);
                validarCadenaLetras(nuevoNombre, 50);
                cuenta.setNombreCuenta(nuevoNombre);
                if(objCuentas.modificarCuenta(cuenta)){
                    rlutil::locate(35, 11);
                    colorTexto(2);
                    cout << char(251) << " Nombre modificado correctamente.";
                    colorTexto(7);
                }
                rlutil::locate(35, 13);
                cout << "Presione cualquier tecla para continuar...";
                rlutil::anykey();
                break;
            }
            case 2: {
                limpiarPantalla();
                colorTexto(7);
                
                rlutil::locate(30, 3);
                cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
                rlutil::locate(30, 4);
                cout << char(186); centrarTexto("REGENERAR ALIAS", ' ', 60); cout << char(186);
                rlutil::locate(30, 5);
                cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
                
                char nuevoAlias[31];
                objCuentas.generarAlias(nuevoAlias);
                cuenta.setAlias(nuevoAlias);
                if(objCuentas.modificarCuenta(cuenta)){
                    rlutil::locate(35, 8);
                    colorTexto(2);
                    cout << char(251) << " Alias regenerado: " << nuevoAlias;
                    colorTexto(7);
                }
                rlutil::locate(35, 11);
                cout << "Presione cualquier tecla para continuar...";
                rlutil::anykey();
                break;
            }
            case 3: {
                continuar = false;
                break;
            }
        }
    }
}

void cerrarCuenta(int idCuenta, int idCliente){
    cuentaBancaria cuenta;
    ArchivoCuentas objCuentas;
    if(!objCuentas.buscarCuenta("ID", idCuenta, cuenta)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo cargar la cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    if(idCuenta == 1){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede cerrar esta cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    Cliente clienteActual;
    ArchivoClientes objClientes;
    if(!objClientes.buscarCliente("ID", idCliente, clienteActual)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo verificar la identidad.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CERRAR CUENTA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);

    rlutil::locate(35, 7);
    colorTexto(3);
    cout << "ADVERTENCIA: Esta acci" << char(162) << "n cerrar" << char(160) << " la cuenta permanentemente.";
    colorTexto(7);
    
    rlutil::locate(35, 9);
    colorTexto(2);
    cout << "Saldo actual: $" << fixed << setprecision(2) << cuenta.getSaldo();
    colorTexto(7);

    if(cuenta.getSaldo() > 0){
        rlutil::locate(35, 11);
        colorTexto(6);
        cout << "NOTA: El saldo restante ser" << char(160) << " transferido a la cuenta del banco.";
        colorTexto(7);
    }

    rlutil::locate(35, 14);
    colorTexto(6);
    cout << "Para continuar, ingrese su contrase" << char(164) << "a: ";
    colorTexto(7);
    char contrasena[50];
    validarCadenaLargo(contrasena, 8, 50);

    if(strcmp(clienteActual.getContrasena(), contrasena) != 0){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: Contrase" << char(164) << "a incorrecta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    rlutil::locate(35, 16);
    colorTexto(6);
    cout << char(175) << " Est" << char(160) << " seguro que desea cerrar la cuenta? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();

    if(confirmacion == 'S' || confirmacion == 's'){
        if(cuenta.getSaldo() > 0){
            if(objCuentas.transferir(idCuenta, 1, cuenta.getSaldo())){
                limpiarPantalla();
                rlutil::locate(40, 14);
                colorTexto(2);
                cout << char(251) << " Saldo transferido a la cuenta del banco exitosamente.";
                colorTexto(7);
            }
            else{
                rlutil::locate(35, 18);
                colorTexto(3);
                cout << "ADVERTENCIA: No se pudo transferir el saldo.";
                colorTexto(7);
            }
        }

        if(objCuentas.eliminarCuenta(idCuenta)){
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(2);
            cout << char(251) << " Cuenta cerrada exitosamente.";
            colorTexto(7);
            rlutil::locate(40, 16);
            cout << "Ser" << char(160) << " redirigido al men" << char(163) << " principal.";
            rlutil::locate(40, 18);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
            return;
        }
        else{
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(3);
            cout << "ERROR: No se pudo cerrar la cuenta.";
            colorTexto(7);
            rlutil::locate(40, 17);
            cout << "Presione cualquier tecla para continuar...";
            rlutil::anykey();
        }
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(6);
        cout << "Operaci" << char(162) << "n cancelada.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
    }
}
