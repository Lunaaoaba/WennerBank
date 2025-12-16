#define byte windows_byte
#include "rlutil.h"
#undef byte
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream> 
#include "cuentaBancaria.h"
#include "cliente.h"
#include "funciones.h"
#include "funcionesArchivos.h"
#include "archivoClientes.h"
#include "archivoCuentas.h"
#include "archivoTransacciones.h"
#include "config.h"
#include "art.h"

using namespace std;

ArchivoCuentas::ArchivoCuentas(const char* nombre){ strcpy(_nombreArchivo, nombre); }

bool ArchivoCuentas::guardarCuentas(const cuentaBancaria& cuenta){
    FILE* archivo = fopen("cuentas.dat", "ab");
    if(archivo == nullptr){
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
    fwrite(&cuenta, sizeof(cuentaBancaria), 1, archivo);
    fclose(archivo);
    return true;
}

cuentaBancaria ArchivoCuentas::crearCuenta(int idCliente){
    Cliente cliente;
    ArchivoClientes obj;
    if(!obj.buscarCliente("ID", idCliente, cliente)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro el cliente con ID " << idCliente << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return cuentaBancaria();
    }
    if(cliente.getUsuarioEliminado()){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: El cliente con ID " << idCliente << " esta inactivo.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return cuentaBancaria();
    }

    int idCuenta;
    char nombreCuenta[50], cvu[11], alias[31];
    double saldo;
    bool cuentaEliminada = false;

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CREACION DE NUEVA CUENTA BANCARIA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cliente: " << cliente.getNombre() << " " << cliente.getApellido();
    colorTexto(7);
    rlutil::locate(35, 8);
    cout << "ID Cliente: " << idCliente;
    
    rlutil::locate(35, 11);
    cout << "Nombre para la cuenta: ";
    rlutil::locate(60, 11);
    validarCadenaLetras(nombreCuenta, 50);

    rlutil::locate(35, 13);
    cout << "Saldo inicial (min $0.00, max $999999999.99): $ ";
    saldo = validarDouble(0.0, 999999999.99);

    idCuenta = generarIdCuenta();
    generarCvu(cvu);
    generarAlias(alias);

    cuentaBancaria nuevaCuenta(
        idCuenta,
        idCliente,
        nombreCuenta,
        cvu,
        alias,
        saldo,
        cuentaEliminada
    );
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE DATOS", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cliente: " << cliente.getNombre() << " " << cliente.getApellido();
    colorTexto(7);
    
    rlutil::locate(35, 9);
    cout << "ID Cuenta: " << idCuenta;
    rlutil::locate(35, 10);
    cout << "Nombre: " << nombreCuenta;
    rlutil::locate(35, 11);
    cout << "CVU: " << cvu;
    rlutil::locate(35, 12);
    cout << "Alias: " << alias;
    rlutil::locate(35, 13);
    cout << "Saldo inicial: $" << fixed << setprecision(2) << saldo;
    
    rlutil::locate(35, 16);
    colorTexto(6);
    cout << char(175) << " Confirma la creacion de la cuenta? (S/N): ";
    colorTexto(7);
    char confirmacion = validarSiNo();
    
    if(confirmacion == 'S' || confirmacion == 's'){
        if(guardarCuentas(nuevaCuenta)){
            limpiarPantalla();
            rlutil::locate(30, 8);
            cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
            rlutil::locate(30, 9);
            cout << char(186); centrarTexto("CUENTA CREADA CON EXITO", ' ', 60); cout << char(186);
            rlutil::locate(30, 10);
            cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
            
            rlutil::locate(35, 12);
            colorTexto(2);
            cout << char(251) << " ID Cuenta: " << idCuenta;
            colorTexto(7);
            rlutil::locate(35, 13);
            cout << "CVU: " << cvu;
            rlutil::locate(35, 14);
            cout << "Alias: " << alias;
            rlutil::locate(35, 15);
            cout << "Saldo inicial: $" << fixed << setprecision(2) << saldo;
        }
        else{
            rlutil::locate(35, 18);
            colorTexto(3);
            cout << "ERROR: No se pudo guardar la nueva cuenta.";
            colorTexto(7);
            return cuentaBancaria();
        }
    }
    else{
        rlutil::locate(35, 18);
        colorTexto(6);
        cout << "Operacion cancelada.";
        colorTexto(7);
        return cuentaBancaria(); 
    }
    
    return nuevaCuenta;
}

bool ArchivoCuentas::modificarCuenta(const cuentaBancaria& cuentaModificada){
    int pos = posicionCuentaPorId(cuentaModificada.getIdCuenta());

    if(pos < 0){
        if(pos == -1){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se encontro la cuenta con ID " << cuentaModificada.getIdCuenta() << "." << endl;
            colorTexto(7);
            return false;
        }
        if(pos == -2){
            rlutil::locate(1, 1);
            colorTexto(3);
            cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
            colorTexto(7);
            return false;
        }
    }
    FILE* archivo = fopen("cuentas.dat", "rb+");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas para modificar." << endl;
        colorTexto(7);
        return false;
    }

    fseek(archivo, static_cast<long>(pos) * (long)sizeof(cuentaBancaria), SEEK_SET);
    bool exito;
    if (fwrite(&cuentaModificada, sizeof(cuentaBancaria), 1, archivo) == 1) exito = true;
    fclose(archivo);
    colorTexto(7);
    return exito;
}

bool ArchivoCuentas::modificarDatosCuenta(int idCuenta){
    cuentaBancaria cuentaAModificar;
    if(idCuenta == 1){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede alterar esta cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    if(!buscarCuenta("ID", idCuenta, cuentaAModificar)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    if(cuentaAModificar.getCuentaEliminada()){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("MODIFICACION DE CUENTA BANCARIA", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Datos actuales de la cuenta:";
    colorTexto(7);
    
    rlutil::locate(40, 9);
    cout << "ID Cuenta: " << cuentaAModificar.getIdCuenta();
    rlutil::locate(40, 10);
    cout << "Nombre: " << cuentaAModificar.getNombreCuenta();
    rlutil::locate(40, 11);
    cout << "CVU: " << cuentaAModificar.getCvu();
    rlutil::locate(40, 12);
    cout << "Alias: " << cuentaAModificar.getAlias();
    rlutil::locate(40, 13);
    cout << "Saldo: $" << fixed << setprecision(2) << cuentaAModificar.getSaldo();

    bool continuar = true;
    while(continuar){
        // Limpiar area de menu y trabajo
        for(int i = 15; i <= 25; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        rlutil::locate(35, 15);
        colorTexto(6);
        cout << "Seleccione el dato a modificar:";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "1. Nombre de la cuenta bancaria";
        rlutil::locate(40, 18);
        cout << "2. Volver a generar Alias";
        rlutil::locate(40, 19);
        cout << "3. Finalizar/Cancelar modificacion";
        
        rlutil::locate(35, 22);
        cout << char(175) << " Opcion: ";
        int opcion = validarEntero(1, 3);
        
        // Limpiar area de trabajo para la operacion
        for(int i = 15; i <= 25; i++){
            rlutil::locate(35, i);
            cout << string(55, ' ');
        }
        
        switch(opcion){
            case 1: {
                char nuevoNombre[50];
                rlutil::locate(35, 17);
                colorTexto(6);
                cout << "Modificar Nombre de la Cuenta";
                colorTexto(7);
                rlutil::locate(40, 19);
                cout << "Actual: " << cuentaAModificar.getNombreCuenta();
                rlutil::locate(40, 20);
                cout << "Nuevo:  ";
                validarCadenaLetras(nuevoNombre, 50);
                cuentaAModificar.setNombreCuenta(nuevoNombre);
                
                rlutil::locate(40, 10);
                cout << string(40, ' ');
                rlutil::locate(40, 10);
                cout << "Nombre: " << nuevoNombre;
                
                rlutil::locate(40, 22);
                colorTexto(2);
                cout << char(251) << " Nombre actualizado!";
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 2: {
                char nuevoAlias[31];
                generarAlias(nuevoAlias);
                cuentaAModificar.setAlias(nuevoAlias);
                
                rlutil::locate(35, 17);
                colorTexto(6);
                cout << "Generar Nuevo Alias";
                colorTexto(7);
                
                rlutil::locate(40, 12);
                cout << string(40, ' ');
                rlutil::locate(40, 12);
                cout << "Alias: " << nuevoAlias;
                
                rlutil::locate(40, 19);
                colorTexto(2);
                cout << char(251) << " Nuevo alias generado: " << nuevoAlias;
                colorTexto(7);
                rlutil::msleep(1500);
                break;
            }
            case 3: {
                rlutil::locate(40, 17);
                colorTexto(6);
                cout << "Finalizando modificacion...";
                colorTexto(7);
                rlutil::msleep(1000);
                continuar = false;
                break;
            }
        }
    }
    
    if(modificarCuenta(cuentaAModificar)){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(2);
        cout << char(251) << " Cuenta modificada correctamente!";
        colorTexto(7);
        return true;
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo modificar la cuenta.";
        colorTexto(7);
        return false;
    }
}

bool ArchivoCuentas::eliminarCuenta(int idCuenta){
    cuentaBancaria cuentaAEliminar;

    if(idCuenta == 1){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se puede eliminar esta cuenta.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }

    if(!buscarCuenta("ID", idCuenta, cuentaAEliminar)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }

    if(cuentaAEliminar.getCuentaEliminada()){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: La cuenta con ID " << idCuenta << " ya se encuentra eliminada.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }

    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE ELIMINACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cuenta a eliminar:";
    colorTexto(7);
    
    char idFormateado[15];
    formatearId(idFormateado, "CU", cuentaAEliminar.getIdCuenta(), 6);
    
    rlutil::locate(40, 9);
    cout << "ID: " << idFormateado;
    rlutil::locate(40, 10);
    cout << "Nombre: " << cuentaAEliminar.getNombreCuenta();
    rlutil::locate(40, 11);
    cout << "CVU: " << cuentaAEliminar.getCvu();
    rlutil::locate(40, 12);
    cout << "Alias: " << cuentaAEliminar.getAlias();
    rlutil::locate(40, 13);
    cout << "Saldo: $" << fixed << setprecision(2) << cuentaAEliminar.getSaldo();
    
    rlutil::locate(30, 16);
    colorTexto(6);
    cout << char(175) << " Confirma la eliminaci" << char(162) << "n de la cuenta? (S/N): ";
    colorTexto(7);

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        cuentaAEliminar.setCuentaEliminada(true);
        if(modificarCuenta(cuentaAEliminar)){
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(2);
            cout << char(251) << " Cuenta con ID " << idFormateado << " eliminada correctamente.";
            colorTexto(7);
            return true;
        }
        else{
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(3);
            cout << "ERROR: No se pudo eliminar la cuenta con ID " << idFormateado << ".";
            colorTexto(7);
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n'){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(6);
        cout << "Operaci" << char(162) << "n cancelada.";
        colorTexto(7);
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "Entrada no reconocida. Operaci" << char(162) << "n cancelada.";
        colorTexto(7);
    }
    return false;
}

bool ArchivoCuentas::restaurarCuenta(int idCuenta){
    cuentaBancaria cuentaARestaurar;
    if(!buscarCuenta("ID", idCuenta, cuentaARestaurar)){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se encontro la cuenta con ID " << idCuenta << ".";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    if(!cuentaARestaurar.getCuentaEliminada()){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: La cuenta con ID " << idCuenta << " se encuentra activa.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return false;
    }
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(30, 3);
    cout << char(201); centrarTexto("", char(205), 60); cout << char(187);
    rlutil::locate(30, 4);
    cout << char(186); centrarTexto("CONFIRMACION DE RESTAURACION", ' ', 60); cout << char(186);
    rlutil::locate(30, 5);
    cout << char(200); centrarTexto("", char(205), 60); cout << char(188);
    
    rlutil::locate(35, 7);
    colorTexto(6);
    cout << "Cuenta a restaurar:";
    colorTexto(7);
    
    char idFormateado[15];
    formatearId(idFormateado, "CU", cuentaARestaurar.getIdCuenta(), 6);
    
    rlutil::locate(40, 9);
    cout << "ID: " << idFormateado;
    rlutil::locate(40, 10);
    cout << "Nombre: " << cuentaARestaurar.getNombreCuenta();
    rlutil::locate(40, 11);
    cout << "CVU: " << cuentaARestaurar.getCvu();
    rlutil::locate(40, 12);
    cout << "Alias: " << cuentaARestaurar.getAlias();
    rlutil::locate(40, 13);
    cout << "Saldo: $" << fixed << setprecision(2) << cuentaARestaurar.getSaldo();
    
    rlutil::locate(30, 16);
    colorTexto(6);
    cout << char(175) << " Confirma la restauraci" << char(162) << "n de la cuenta? (S/N): ";
    colorTexto(7);

    char confirmacion = validarSiNo();
    if(confirmacion == 'S' || confirmacion == 's'){
        cuentaARestaurar.setCuentaEliminada(false);
        if(modificarCuenta(cuentaARestaurar)){
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(2);
            cout << char(251) << " Cuenta con ID " << idFormateado << " restaurada correctamente.";
            colorTexto(7);
            return true;
        }
        else{
            limpiarPantalla();
            rlutil::locate(40, 15);
            colorTexto(3);
            cout << "ERROR: No se pudo restaurar la cuenta con ID " << idFormateado << ".";
            colorTexto(7);
            return false;
        }
    }
    else if (confirmacion == 'N' || confirmacion == 'n'){
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(6);
        cout << "Operaci" << char(162) << "n cancelada.";
        colorTexto(7);
    }
    else{
        limpiarPantalla();
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "Entrada no reconocida. Operaci" << char(162) << "n cancelada.";
        colorTexto(7);
    }
    return false;
}

void ArchivoCuentas::listarCuentasCliente(int idCliente){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    
    cuentaBancaria cuentaActual;
    int contador = 0;
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("CUENTAS DEL CLIENTE ID=" + to_string(idCliente), ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(1, 7);
    
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCliente() == idCliente && !cuentaActual.getCuentaEliminada()){
            char idFormateado[15];
            formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);
            
            cout << "  ID: " << idFormateado << endl;
            cout << "  Nombre: " << cuentaActual.getNombreCuenta() << endl;
            cout << "  CVU: " << cuentaActual.getCvu() << endl;
            cout << "  Alias: " << cuentaActual.getAlias() << endl;
            cout << "  Saldo: $" << fixed << setprecision(2) << cuentaActual.getSaldo() << endl;
            cout << "  " << string(76, char(196)) << endl << endl;
            contador++;
        }
    }
    
    fclose(archivo);
    
    if(contador == 0){
        colorTexto(3);
        cout << "  El cliente no tiene cuentas bancarias activas." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "  Total de cuentas: " << contador << endl;
        colorTexto(7);
    }
}

void ArchivoCuentas::listarCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    cuentaBancaria cuentaActual;
    int i = 0;
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("LISTADO DE CUENTAS BANCARIAS", ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(1, 7);
    
    while (fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(!cuentaActual.getCuentaEliminada()){
            char idFormateado[15];
            formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);
            
            cout << "  ID: " << idFormateado << endl;
            cout << "  Nombre: " << cuentaActual.getNombreCuenta() << endl;
            cout << "  CVU: " << cuentaActual.getCvu() << endl;
            cout << "  Alias: " << cuentaActual.getAlias() << endl;
            cout << "  Saldo: $" << fixed << setprecision(2) << cuentaActual.getSaldo() << endl;
            cout << "  " << string(76, char(196)) << endl << endl;
            i++;
        }
    }
    if(i == 0){
        colorTexto(3);
        cout << "  No hay cuentas bancarias registradas." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "  Total de cuentas bancarias: " << i << endl;
        colorTexto(7);
    }
    fclose(archivo);
}

void ArchivoCuentas::listarTodasCuentas(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(40, 15);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas.";
        colorTexto(7);
        rlutil::locate(40, 17);
        cout << "Presione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }
    cuentaBancaria cuentaActual;
    int i = 0;
    
    limpiarPantalla();
    colorTexto(7);
    
    rlutil::locate(20, 3);
    cout << char(201); centrarTexto("", char(205), 80); cout << char(187);
    rlutil::locate(20, 4);
    cout << char(186); centrarTexto("LISTADO COMPLETO DE CUENTAS BANCARIAS", ' ', 80); cout << char(186);
    rlutil::locate(20, 5);
    cout << char(200); centrarTexto("", char(205), 80); cout << char(188);
    
    rlutil::locate(1, 7);
    
    while (fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        char idFormateado[15];
        formatearId(idFormateado, "CU", cuentaActual.getIdCuenta(), 6);
        
        cout << "  ID: " << idFormateado;
        if(cuentaActual.getCuentaEliminada()){
            colorTexto(3);
            cout << " [ ELIMINADO ]";
            colorTexto(7);
        }
        cout << endl;
        cout << "  Nombre: " << cuentaActual.getNombreCuenta() << endl;
        cout << "  CVU: " << cuentaActual.getCvu() << endl;
        cout << "  Alias: " << cuentaActual.getAlias() << endl;
        cout << "  Saldo: $" << fixed << setprecision(2) << cuentaActual.getSaldo() << endl;
        cout << "  " << string(76, char(196)) << endl << endl;
        i++;
    }
    if(i == 0){
        colorTexto(3);
        cout << "  No hay cuentas bancarias registradas." << endl;
        colorTexto(7);
    }
    else{
        colorTexto(2);
        cout << "  Total de cuentas bancarias: " << i << endl;
        colorTexto(7);
    }
    fclose(archivo);

}

bool ArchivoCuentas::buscarCuenta(const char* criterio, int valor, cuentaBancaria& encontrada){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        colorTexto(7);
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrada, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(criterio, "ID") == 0){
            if(encontrada.getIdCuenta() == valor){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "IDCLIENTE") == 0){
            if(encontrada.getIdCliente() == valor){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "SALDO") == 0){
            if(encontrada.getSaldo() == static_cast<double>(valor)){
                seEncontro = true;
                break;
            }
        }
        else{
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda inv" << char(160) << "lido." << endl;
            colorTexto(7);
        }

        if (seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoCuentas::buscarCuenta(const char* criterio, const char* valor, cuentaBancaria& encontrada){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr){
        rlutil::locate(1, 1);
        colorTexto(3);
        cout << "ERROR: No se pudo abrir el archivo de cuentas." << endl;
        colorTexto(7);
        return false;
    }
    bool seEncontro = false;
    while(fread(&encontrada, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(strcmp(criterio, "CVU") == 0){
            if(strcmp(encontrada.getCvu(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "ALIAS") == 0){
            if(strcmp(encontrada.getAlias(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else if(strcmp(criterio, "NOMBRECUENTA") == 0){
            if(strcmp(encontrada.getNombreCuenta(), valor) == 0){
                seEncontro = true;
                break;
            }
        }
        else{
            colorTexto(3);
            cout << "Criterio de b" << char(163) << "squeda inv" << char(160) << "lido." << endl;
            colorTexto(7);
        }

        if (seEncontro) break;
    }
    fclose(archivo);
    return seEncontro;
}

bool ArchivoCuentas::depositar(int idCuenta, double monto){
    if(monto <= 0){
        colorTexto(3);
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        colorTexto(7);
        return false;
    }
    
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        colorTexto(3);
        cout << "ERROR: No se encontr" << char(162) << " la cuenta." << endl;
        colorTexto(7);
        return false;
    }
    if(cuenta.getCuentaEliminada()){
        colorTexto(3);
        cout << "ERROR: La cuenta est" << char(160) << " cerrada." << endl;
        colorTexto(7);
        return false;
    }
    
    cuenta.setSaldo(cuenta.getSaldo() + monto);

    if(modificarCuenta(cuenta)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;
        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            -1,
            idCuenta,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);

        colorTexto(2);
        cout << char(251) << " Dep" << char(162) << "sito exitoso. Nuevo saldo: $" << fixed << setprecision(2) << cuenta.getSaldo() << endl;
        colorTexto(7);
        return true;
    }
    
    colorTexto(3);
    cout << "ERROR: No se pudo realizar el dep" << char(162) << "sito." << endl;
    colorTexto(7);
    return false;
}

bool ArchivoCuentas::extraer(int idCuenta, double monto){
    if(monto <= 0){
        colorTexto(3);
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        colorTexto(7);
        return false;
    }
    
    cuentaBancaria cuenta;
    if(!buscarCuenta("ID", idCuenta, cuenta)){
        colorTexto(3);
        cout << "ERROR: No se encontr" << char(162) << " la cuenta." << endl;
        colorTexto(7);
        return false;
    }
    if(cuenta.getCuentaEliminada()){
        colorTexto(3);
        cout << "ERROR: La cuenta est" << char(160) << " cerrada." << endl;
        colorTexto(7);
        return false;
    }
    if(cuenta.getSaldo() < monto){
        colorTexto(3);
        cout << "ERROR: Saldo insuficiente." << endl;
        colorTexto(7);
        return false;
    }
    
    cuenta.setSaldo(cuenta.getSaldo() - monto);
    
    if(modificarCuenta(cuenta)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;
        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            idCuenta,
            -1,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);
        colorTexto(2);
        cout << char(251) << " Extracci" << char(162) << "n exitosa. Nuevo saldo: $" << cuenta.getSaldo() << endl;
        colorTexto(7);
        return true;
    }
    
    colorTexto(3);
    cout << "ERROR: No se pudo realizar la extracci" << char(162) << "n." << endl;
    colorTexto(7);
    return false;
}

bool ArchivoCuentas::transferir(int idCuentaOrigen, int idCuentaDestino, double monto){
    if(monto <= 0){
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
        return false;
    }
    if(idCuentaOrigen == idCuentaDestino){
        cout << "ERROR: No se puede transferir a la misma cuenta." << endl;
        return false;
    }

    cuentaBancaria cuentaOrigen, cuentaDestino;
    if(!buscarCuenta("ID", idCuentaOrigen, cuentaOrigen)){
        cout << "ERROR: No se encontro la cuenta origen." << endl;
        return false;
    }
    if(!buscarCuenta("ID", idCuentaDestino, cuentaDestino)){
        cout << "ERROR: No se encontro la cuenta destino." << endl;
        return false;
    }
    if(cuentaOrigen.getCuentaEliminada() || cuentaDestino.getCuentaEliminada()){
        cout << "ERROR: Una de las cuentas esta cerrada." << endl;
        return false;
    }
    if(cuentaOrigen.getSaldo() < monto){
        cout << "ERROR: Saldo insuficiente en cuenta origen." << endl;
        return false;
    }
    
    // Realizar transferencia
    cuentaOrigen.setSaldo(cuentaOrigen.getSaldo() - monto);
    cuentaDestino.setSaldo(cuentaDestino.getSaldo() + monto);
    
    if(modificarCuenta(cuentaOrigen) && modificarCuenta(cuentaDestino)){
        Fecha fechaActual;
        fechaActual.cargarFechaActual();
        Tiempo tiempoActual;
        tiempoActual.cargarTiempoActual();
        ArchivoTransacciones trActual;

        Transaccion nuevaTransaccion(
            trActual.generarIdTransaccion(),
            idCuentaOrigen,
            idCuentaDestino,
            monto,
            fechaActual,
            tiempoActual
        );
        trActual.guardarTransaccion(nuevaTransaccion);

        cout << "Transferencia exitosa." << endl;
        cout << "Saldo cuenta origen: $" << cuentaOrigen.getSaldo() << endl;
        cout << "Saldo cuenta destino: $" << cuentaDestino.getSaldo() << endl;
        return true;
    }
    
    cout << "ERROR: No se pudo completar la transferencia." << endl;
    return false;
}

int ArchivoCuentas::generarIdCuenta(){
    FILE* archivo = fopen("cuentas.dat", "rb");
    int maxId = 0;
    if(archivo == nullptr) return 1;
    
    cuentaBancaria reg;
    while(fread(&reg, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(reg.getIdCuenta() > maxId){
            maxId = reg.getIdCuenta();
        }
    }
    fclose(archivo);
    return maxId + 1;
}

void ArchivoCuentas::generarCvu(char* cvu){
    srand(static_cast<unsigned int>(time(nullptr)));
    bool cvuUnico = false;
    while(!cvuUnico){
        for(int i = 0; i < 10; i++){
            cvu[i] = static_cast<char>('0' + (rand() % 10));  // Dígito aleatorio 0-9
        }
        cvu[10] = '\0';
        if(!existeCvu(cvu)){
            cvuUnico = true;
        }
    }
}

void ArchivoCuentas::generarAlias(char* alias){
    srand(static_cast<unsigned>(time(nullptr)));
    // 35+35+35 = 105
    // 105^3 = 1,157,625 combinaciones posibles
    // orden aleatorio + repeticion de categorias
    const char* sustantivos[35] = {
        "TIGRE", "DRAGON", "FENIX", "COMETA", "RELOJ",
        "LIBRO", "ESPEJO", "CANDADO", "VOLCAN", "CRISTAL",
        "TRUENO", "ROBOT", "PIANO", "FARO", "CASTILLO",
        "PUENTE", "RELAMPAGO", "BRUJULA", "DIAMANTE", "CASCADA",
        "VELA", "PORTAL", "METEORO", "OASIS", "TORRE",
        "LAGO", "TEMPO", "MARCO", "CUBO", "PILAR",
        "CIRCO", "MANTO", "CLAVO", "TORNADO", "AURA"
    };
    const char* adjetivos[35] = {
        "INFINITO", "MAGICO", "VELOZ", "SILENCIOSO", "INVISIBLE",
        "DORADO", "BRILLANTE", "SALVAJE", "HELADO", "ARDIENTE",
        "COSMICO","FRAGIL", "PODEROSO", "OCULTO", "LIBRE",
        "REBELDE", "LEGENDARIO", "RADIANTE", "SECRETO", "DIVINO",
        "SERENO", "TRANQUILO", "FUGAZ", "SUAVE", "AGUDO",
        "LUMINOSO", "TENUE", "VASTO", "PURO", "ARIDO",
        "FIRME", "SOLIDO", "NITIDO", "LIVIANO", "INTENSO"
    };
    const char* verbos[35] = {
        "CORRER", "SALTAR", "VOLAR", "NADAR", "BRILLAR",
        "CANTAR", "BAILAR", "CRECER", "VIAJAR", "LEER",
        "JUGAR", "MIRAR", "BUSCAR", "CREAR", "PENSAR",
        "SENTIR", "VIVIR", "FLUIR", "GIRAR", "TOMAR",
        "ROMPER", "DAR", "MOVER", "GUIAR", "TEJER",
        "LLAMAR", "FORJAR", "GUARDAR", "PULSAR", "SEGUIR",
        "HABLAR", "SOÑAR", "FORMAR", "SUBIR", "BAJAR"
    };

    const char** categorias[3] = {sustantivos, adjetivos, verbos};
    bool aliasUnico = false;
    while(!aliasUnico){
        // Elige 3 palabras al azar       (categoría + posición)
        const char* palabra1 = categorias[rand() % 3] [rand() % 35];
        const char* palabra2 = categorias[rand() % 3] [rand() % 35];
        const char* palabra3 = categorias[rand() % 3] [rand() % 35];

        // Formato: "PALABRA1.PALABRA2.PALABRA3"
        sprintf(alias, "%s.%s.%s", palabra1, palabra2, palabra3);

        if(!existeAlias(alias)){
            aliasUnico = true;
        }
    }
}

// despues rehacer para q use sobrecarga
int ArchivoCuentas::posicionCuentaPorId(int idCuenta){
    FILE* archivo = fopen("cuentas.dat", "rb");
    if(archivo == nullptr) return -2;
    cuentaBancaria cuentaActual;
    int pos = 0;
    while(fread(&cuentaActual, sizeof(cuentaBancaria), 1, archivo) == 1){
        if(cuentaActual.getIdCuenta() == idCuenta){
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}