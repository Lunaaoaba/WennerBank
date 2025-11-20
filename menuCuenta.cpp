#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "menuCuenta.h"
#include "ArchivoCuentas.h"
#include "ArchivoClientes.h"
#include "funciones.h"
#include "art.h"

using namespace std;

void menuCuenta(int idCliente, int idCuenta){
    bool continuar = true;
    while(continuar){
        cuentaBancaria cuenta;
        if(!buscarCuenta("ID", idCuenta, cuenta)){
            cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << "." << endl;
            return;
        }

        system("cls");
        cout << "========================================" << endl;
        cout << "         MENU CUENTA BANCARIA" << endl;
        cout << "========================================" << endl << endl;
        cout << "Cuenta: " << cuenta.getNombreCuenta() << endl;
        cout << "CVU: " << cuenta.getCvu() << endl;
        cout << "Alias: " << cuenta.getAlias() << endl;
        cout << "Saldo: $" << fixed << setprecision(2) << cuenta.getSaldo() << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Ingresar dinero" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Transferir dinero" << endl;
        cout << "4. Mis prestamos" << endl;
        cout << "5. Modificar datos de la cuenta" << endl;
        cout << "6. Cerrar cuenta" << endl;
        cout << "7. Volver al menu principal" << endl << endl;

        int opcion = validarEntero(1, 7);
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
                misPrestamos(idCuenta, idCliente);
                break;
            }
            case 5: {
                modificarDatosCuentaMenu(idCuenta, idCliente);
                break;
            }
            case 6: {
                cerrarCuenta(idCuenta, idCliente);
                break;
            }
            case 7: {
                continuar = false;
                break;
            }
        }
    }
}

void ingresarDinero(int idCuenta){
    system("cls");
    cout << "========================================" << endl;
    cout << "           INGRESAR DINERO" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "Ingrese el monto a depositar: $";
    double monto = validarDouble(0.01, 999999999.99);
    
    if(depositar(idCuenta, monto)){
        system("pause");
    }
    else{
        system("pause");
    }
}

void retirarDinero(int idCuenta){
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        cout << "ERROR: No se pudo cargar la cuenta." << endl;
        system("pause");
        return;
    }
    
    system("cls");
    cout << "========================================" << endl;
    cout << "           RETIRAR DINERO" << endl;
    cout << "========================================" << endl << endl;
    cout << "Saldo disponible: $" << fixed << setprecision(2) << cuenta.getSaldo() << endl << endl;
    
    cout << "Ingrese el monto a retirar: $";
    double monto = validarDouble(0.01, 999999999.99);
    
    if(extraer(idCuenta, monto)){
        system("pause");
    }
    else{
        system("pause");
    }
}

void transferirDinero(int idCuenta){
    bool continuar = true;
    
    while(continuar){

        cuentaBancaria cuentaOrigen;
        if(!buscarCuenta("ID", idCuenta, cuentaOrigen)){
            cout << "ERROR: No se pudo cargar la cuenta." << endl;
            system("pause");
            return;
        }
        system("cls");
        cout << "========================================" << endl;
        cout << "         TRANSFERIR DINERO" << endl;
        cout << "========================================" << endl << endl;
        cout << "Saldo disponible: $" << fixed << setprecision(2) << cuentaOrigen.getSaldo() << endl << endl;
        cout << "1. Transferir por CVU" << endl;
        cout << "2. Transferir por Alias" << endl;
        cout << "3. Cancelar" << endl << endl;

        int opcion = validarEntero(1, 3);

        cuentaBancaria cuentaDestino;
        bool cuentaEncontrada = false;
        switch(opcion){
            case 1: {
                char cvuDestino[11];
                cout << "Ingrese el CVU de la cuenta a transferir: ";
                validarCadenaNumeros(cvuDestino, 10, 10);
                cuentaEncontrada = buscarCuenta("CVU", cvuDestino, cuentaDestino);
                break;
            }
            case 2 : {
                char aliasDestino[31];
                cout << "Ingrese el Alias de la cuenta a transferir: ";
                validarCadena(aliasDestino, 30);
                mayusculas(aliasDestino);
                cuentaEncontrada = buscarCuenta("ALIAS", aliasDestino, cuentaDestino);
                break;
            }
            case 3: {
                continuar = false;
                break;
            }
        }
        if(!cuentaEncontrada){
            cout << "ERROR: No se encontro la cuenta a transferir." << endl;
            system("pause");
            continue;
        }
        if(cuentaDestino.getIdCuenta() == idCuenta){
            cout << "ERROR: No se puede transferir a la misma cuenta." << endl;
            system("pause");
            continue;
        }

        system("cls");
        cout << "========================================" << endl;
        cout << "      CONFIRMAR TRANSFERENCIA" << endl;
        cout << "========================================" << endl << endl;
        cout << "Cuenta destino:" << endl;
        cout << cuentaDestino.mostrarDatos() << endl;
        cout << "Ingrese el monto a transferir: $";
        double monto = validarDouble(0.01, 999999999.99);

        cout << endl << "Confirma la transferencia de $" << fixed << setprecision(2) << monto << " a la cuenta destino? (S/N): ";
        char confirmacion = validarSiNo();

        if(confirmacion == 'S' || confirmacion == 's'){
            if(transferir(idCuenta, cuentaDestino.getIdCuenta(), monto)){
                cout << "Transferencia realizada con exito." << endl;
                cout << "Desea realizar otra transferencia? (S/N): ";
                char otra = validarSiNo();
                if(otra == 'N' || otra == 'n'){
                    continuar = false;
                }
            }
            else{
                cout << "ERROR: No se pudo realizar la transferencia." << endl;
                system("pause");
                continuar = false;
            }
        }
        else{
            cout << "Transferencia cancelada." << endl;
            system("pause");
            continuar = false;
        }
    }
}

void misPrestamos(int idCuenta, int idCliente){
    bool continuar = true;
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "            MIS PRESTAMOS" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Pedir prestamo" << endl;
        cout << "2. Pagar prestamo" << endl;
        cout << "3. Volver" << endl << endl;

        int opcion = validarEntero(1, 3);
        switch(opcion){
            case 1: {
                pedirPrestamo(idCuenta, idCliente);
                break;
            }
            case 2: {
                pagarPrestamo(idCuenta, idCliente);
                break;
            }
            case 3: {
                continuar = false;
                break;
            }
        }
    }
}

void pedirPrestamo(int idCuenta, int idCliente){
    system("cls");
    cout << "========================================" << endl;
    cout << "           PEDIR PRESTAMO" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    (void)idCuenta;
    (void)idCliente;
    system("pause");
}

void pagarPrestamo(int idCuenta, int idCliente){
    system("cls");
    cout << "========================================" << endl;
    cout << "           PAGAR PRESTAMO" << endl;
    cout << "========================================" << endl << endl;
    cout << "Funcion en desarrollo..." << endl;
    (void)idCuenta;
    (void)idCliente;
    system("pause");
}

void modificarDatosCuentaMenu(int idCuenta, int idCliente){
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        cout << "ERROR: No se pudo cargar la cuenta." << endl;
        system("pause");
        return;
    }
    Cliente cliente;
    if(!buscarCliente("ID", idCliente, cliente)){
        cout << "ERROR: No se pudo verificar la identidad." << endl;
        system("pause");
        return;
    }
    bool continuar = true;
    while(continuar){
        system("cls");
        cout << "========================================" << endl;
        cout << "      MODIFICAR DATOS DE CUENTA" << endl;
        cout << "========================================" << endl << endl;
        cout << "1. Cambiar nombre de la cuenta" << endl;
        cout << "2. Regenerar Alias" << endl;
        cout << "3. Volver" << endl << endl;
        
        int opcion = validarEntero(1, 3);

        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                cout << "Ingrese el nuevo nombre: ";
                validarCadenaLetras(nuevoNombre, 50);
                cuenta.setNombreCuenta(nuevoNombre);
                if(modificarCuenta(cuenta)){
                    cout << "Nombre modificado correctamente." << endl;
                }
                system("pause");
                break;
            }
            case 2: {
                char nuevoAlias[31];
                generarAlias(nuevoAlias);
                cuenta.setAlias(nuevoAlias);
                if(modificarCuenta(cuenta)){
                    cout << "Alias regenerado: " << nuevoAlias << endl;
                }
                system("pause");
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
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        cout << "ERROR: No se pudo cargar la cuenta." << endl;
        system("pause");
        return;
    }
    if(idCuenta == 1){
        cout << "ERROR: No se puede cerrar esta cuenta." << endl;
        system("pause");
        return;
    }

    Cliente clienteActual;
    if(!buscarCliente("ID", idCliente, clienteActual)){
        cout << "ERROR: No se pudo verificar la identidad." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "========================================" << endl;
    cout << "           CERRAR CUENTA" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "ADVERTENCIA: Esta accion cerrara la cuenta permanentemente." << endl;
    cout << "Saldo actual: $" << fixed << setprecision(2) << cuenta.getSaldo() << endl << endl;
    
    if(cuenta.getSaldo() > 0){
        cout << "NOTA: El saldo restante sera transferido a la cuenta del banco." << endl << endl;
    }
    
    cout << "Para continuar, ingrese su contrase" << char(164) << "a: ";
    char contrasena[50];
    validarCadenaLargo(contrasena, 8, 50);
    
    if(strcmp(clienteActual.getContrasena(), contrasena) != 0){
        cout << endl << "ERROR: Contrase" << char(164) << "a incorrecta." << endl;
        system("pause");
        return;
    }

    cout << endl << "Esta seguro que desea cerrar la cuenta? (S/N): ";
    char confirmacion = validarSiNo();

    if(confirmacion == 'S' || confirmacion == 's'){
        // Si tiene saldo, transferirlo a la cuenta del banco
        if(cuenta.getSaldo() > 0){
            if(transferir(idCuenta, 1, cuenta.getSaldo())){
                cout << endl << "Saldo transferido a la cuenta del banco exitosamente." << endl;
            }
            else{
                cout << endl << "ADVERTENCIA: No se pudo transferir el saldo." << endl;
            }
        }
        
        // Cerrar la cuenta
        if(eliminarCuenta(idCuenta)){
            cout << "Cuenta cerrada exitosamente." << endl;
            cout << "Sera redirigido al menu principal." << endl;
            system("pause");
            return; // Sale del menú de cuenta
        }
        else{
            cout << "ERROR: No se pudo cerrar la cuenta." << endl;
            system("pause");
        }
    }
    else{
        cout << "Operacion cancelada." << endl;
        system("pause");
    }
}